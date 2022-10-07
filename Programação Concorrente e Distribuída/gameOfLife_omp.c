/* Código omp
  $ gcc -fopenmp gameOfLife_omp.c -o gameOfLife_omp
  $ time ./gameOfLife_omp

  André Fernando Quaresma da Silva
  Jonatas Carrocine
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"

#define V 0        // versão: game of life 0, high life 1
#define N 2048     // tamanho da matriz
#define T 1        // número de threads
#define G 2000     // número de gerações

int grid[N][N] = {{0}};
int newgrid[N][N] = {{0}};
float timeGeneration;

float time_diff(struct timespec *start, struct timespec *end){
    return (end->tv_sec - start->tv_sec) + 1e-9*(end->tv_nsec - start->tv_nsec);
}

void imprime(int grid[N][N]) {
  int i = 0, j = 0;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (grid[i][j]) {
        printf(RED "%d" RESET, grid[i][j]);
      } else {
        printf(BLUE "%d" RESET, grid[i][j]);
      }
      if (j == N-1) {
        printf("\n");
      } else {
        printf(" ");
      }
    }
  }
}

void zeros(int grid[N][N], int id) {
  int i, j;
  int pos = id;
  int q = N/T;
  for (i = 0; i < q; i++) {
    for (j = 0; j < N; j++) {
      grid[pos][j] = 0;
    }
    pos += T;
  }
}

void setInitGrid(int grid[N][N]) {
  int lin, col;

  for (lin = 0; lin < N; lin++) {
    for (col = 0; col < N; col++) {
      grid[lin][col] = 0;
    }
  }
  // GLIDER
  lin = 1, col = 1;
  grid[lin][col+1] = 1;
  grid[lin+1][col+2] = 1;
  grid[lin+2][col] = 1;
  grid[lin+2][col+1] = 1;
  grid[lin+2][col+2] = 1;

  //R-pentomino
  lin = 10; col = 30;
  grid[lin][col+1] = 1;
  grid[lin][col+2] = 1;
  grid[lin+1][col] = 1;
  grid[lin+1][col+1] = 1;
  grid[lin+2][col+1] = 1;
}

int getNeighbors(int grid[N][N], int i, int j) {
  int neighbors = 0;
  int up, bottom, right, left, bottomRight, bottomLeft, upRight, upLeft;

  // up //
  if (i == 0) up = grid[N-1][j];
  else up = grid[i-1][j];

  // bottom //
  if (i == N-1) bottom = grid[0][j];
  else bottom = grid[i+1][j];

  // right //
  if (j == N-1) right = grid[i][0];
  else right = grid[i][j+1];

  // left //
  if (j == 0) left = grid[i][N-1];
  else left = grid[i][j-1];

  // upRight //
  if (i == 0) {
    if (j == N-1) upRight = grid[N-1][0];
    else upRight = grid[N-1][j+1];
  } else {
    if (j == N-1) upRight = grid[i-1][0];
    else upRight = grid[i-1][j+1];
  }

  // upLeft //
  if (i == 0) {
    if (j == 0) upLeft = grid[N-1][N-1];
    else upLeft = grid[N-1][j-1];
  } else {
    if (j == 0) upLeft = grid[i-1][N-1];
    else upLeft = grid[i-1][j-1];
  }

  // bottomRight //
  if (i == N-1) {
    if (j == N-1) bottomRight = grid[0][0];
    else bottomRight = grid[0][j+1];
  } else {
    if (j == N-1) bottomRight = grid[i+1][0];
    else bottomRight = grid[i+1][j+1];
  }

  // bottomLeft //
  if (i == N-1) {
    if (j == 0) bottomLeft = grid[0][N-1];
    else bottomLeft = grid[0][j-1];
  } else {
    if (j == 0) bottomLeft = grid[i+1][N-1];
    else bottomLeft = grid[i+1][j-1];
  }

  if (up) neighbors++;
  if (bottom) neighbors++;
  if (right) neighbors++;
  if (left) neighbors++;
  if (upRight) neighbors++;
  if (upLeft) neighbors++;
  if (bottomRight) neighbors++;
  if (bottomLeft) neighbors++;

  return neighbors;
}

void updateNeighbors(int grid[N][N], int newgrid[N][N], int i, int j, int neighbors) {
  if (grid[i][j]) { // celula viva
    if (neighbors == 2 || neighbors == 3) newgrid[i][j] = 1;
    else newgrid[i][j] = 0;
  }
  else { //celula morta
    if (V == 0) { // Game of life
      if (neighbors == 3) newgrid[i][j] = 1;
    } else if (V == 1) { // High life
      if (neighbors == 3 || neighbors == 6) newgrid[i][j] = 1;
    }
  }
}

int findLivingGenerations(int grid[N][N], int newgrid[N][N], int id) {
  int i, j, neighbors, livingGenerations = 0;
  int pos = id;
  int q = N/T;
  for (i = 0; i < q; i++) {
    for (j = 0; j < N; j++) {
      neighbors = getNeighbors(grid, pos, j);
      updateNeighbors(grid, newgrid, pos, j, neighbors);
      if (newgrid[pos][j]) livingGenerations++;
    }
    pos += T;
  }
  return livingGenerations;
}

int runGenerations() {
  struct timespec start;
  struct timespec end;
  int generation, neighbors;
  int soma, livingGenerations;
  int id;

  omp_set_num_threads(T);

  clock_gettime(CLOCK_REALTIME, &start);
  for (generation = 0; generation < G; generation++) {
    soma = 0;
    #pragma omp parallel private(id)
    {
    id = omp_get_thread_num();
    if (generation%2 == 0) {
      zeros(newgrid, id);
      livingGenerations = findLivingGenerations(grid, newgrid, id);
    } else {
      zeros(grid, id);
      livingGenerations = findLivingGenerations(newgrid, grid, id);
    }
      soma += livingGenerations;
    }
    //printf("geração %d: %d\n", generation+1, soma);
  }
  clock_gettime(CLOCK_REALTIME, &end);
  timeGeneration = time_diff(&start, &end);
  return soma;
}

int main(int argc, char **argv) {
  int livingGenerations;

  setInitGrid(grid);
  livingGenerations = runGenerations();

  printf("Geração %d: %d\n", G, livingGenerations);
  printf("timeGeneration: %0.3fs\n", timeGeneration);
  return 0;
}
