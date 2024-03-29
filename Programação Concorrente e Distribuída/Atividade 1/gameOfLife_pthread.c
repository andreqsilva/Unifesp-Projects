/* Código pthread

  Para definir a versão (Game of Life/High Life), alterar o valor de V,
  sendo 0 para Game of Life e 1 para High Life

  André Fernando Quaresma da Silva
  Jonatas Carrocine

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"

#define V 0        // versão: game of life 0, high life 1
#define N 2048     // tamanho da matriz
#define T 2        // número de threads
#define G 2000     // número de gerações

int grid[N][N] = {{0}};
int newgrid[N][N] = {{0}};
float timeGeneration;
pthread_barrier_t barrier;

// rotorna o tempo decorrido entre start e end
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
  printf("\n");
}

void zeros(int grid[N][N], int *id) { // zerar matriz
  int i, j;
  int pos = *id;
  int q = (N/T) + 1;
  for (i = 0; i < q; i++) {
    if (pos >= N) break;
    for (j = 0; j < N; j++) {
      grid[pos][j] = 0;
    }
    pos += T;
  }
}

void setInitGrid(int grid[N][N]) { // geração inicial
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

// obtém a quantidade de vizinhos
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

// atualiza a próxima geração
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

// retorna a quantidade de gerações vivas que a thread computou
int findLivingGenerations(int grid[N][N], int newgrid[N][N], int *id) {
  int i, j, neighbors, livingGenerations = 0;
  int pos = *id;        // linhas que a thread irá trabalhar
  int q = (N/T) + 1;    // quantidade de repetições da thread
  for (i = 0; i < q; i++) {
    if (pos >= N) break;
    for (j = 0; j < N; j++) {
      neighbors = getNeighbors(grid, pos, j);
      updateNeighbors(grid, newgrid, pos, j, neighbors);
      if (newgrid[pos][j]) livingGenerations++;
    }
    pos += T;
  }
  return livingGenerations;
}

void *runGenerations(void *args) {
  struct timespec start;
  struct timespec end;
  int generation, neighbors;
  long livingGenerations;
  int *id = (int*)args;

  clock_gettime(CLOCK_REALTIME, &start);
  for (generation = 0; generation < G; generation++) {
    if (generation%2 == 0) {
      zeros(newgrid, id);
      pthread_barrier_wait(&barrier);
      livingGenerations = findLivingGenerations(grid, newgrid, id);
    } else {
      zeros(grid, id);
      pthread_barrier_wait(&barrier);
      livingGenerations = findLivingGenerations(newgrid, grid, id);
    }
    pthread_barrier_wait(&barrier);
    printf("Geração %d: %ld\n", generation+1, livingGenerations);

    /* //imprime uma matriz para cada geração
    pthread_barrier_wait(&barrier);
    if (*id == 0) {
      if (generation%2 == 0)
        imprime(newgrid);
      else imprime(grid);
    }
    pthread_barrier_wait(&barrier);
*/

  }
  clock_gettime(CLOCK_REALTIME, &end);
  timeGeneration = time_diff(&start, &end);
  pthread_exit((void*)livingGenerations);
}

int main(int argc, char **argv) {
  pthread_t th[T];
  int i, j, id[T];
  int rc;
  void *result;
  int livingGenerations = 0;

  pthread_barrier_init(&barrier, NULL, T);
  setInitGrid(grid);
  //imprime(grid);

  for (i = 0; i < T; i++) {
    id[i] = i;
    rc = pthread_create(&th[i], NULL, &runGenerations, (void*)&id[i]);
    if (rc) {
      printf("ERROR: create=%d\n", rc);
      exit(-1);
    }
  }

  for (i = 0; i < T; i++) {
    rc = pthread_join(th[i], &result);
    if (rc) {
      printf("ERROR: join=%d\n", rc);
      exit(-1);
    }
    livingGenerations += (long)result;
    //printf("livingGenerations=%ld\n", (long)result);
  }

  printf("\nGeração final %d: %d\n", G, livingGenerations);
  printf("timeGeneration: %0.3fs\n", timeGeneration);

  pthread_barrier_destroy(&barrier);
  pthread_exit(NULL);
  return 0;
}
