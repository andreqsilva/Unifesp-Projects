/* 
	André Fernando Quaresma da Silva
	Jonatas Carrocine
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"

#define V 0        // versão: game of life 0, high life 1
#define N 2048    // tamanho da matriz
#define T 2        // número de threads
#define G 2000     // número de gerações

int grid[N][N] = {{0}};
int newgrid[N][N] = {{0}};

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

void zeros(int grid[N][N]) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      grid[i][j] = 0;
    }
  }
}

void setInitGrid(int grid[N][N]) {
  int lin, col;
  zeros(grid);
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

int runGenerations_critical() {
  int generation, i, j, neighbors, livingGenerations;
  for (generation = 0; generation < G; generation++) {
    livingGenerations = 0;

    if (generation%2 == 0) zeros(newgrid);
    else zeros(grid);
    #pragma omp parallel shared(generation) private(i,j,neighbors) num_threads(T)
    #pragma omp for
      for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
          if (generation%2 == 0) {
            neighbors = getNeighbors(grid, i, j);
            updateNeighbors(grid, newgrid, i, j, neighbors);
            #pragma omp critical
            {
                if (newgrid[i][j]){
                  livingGenerations++;
                }
            }
          } else {
            neighbors = getNeighbors(newgrid, i, j);
            updateNeighbors(newgrid, grid, i, j, neighbors);
            #pragma omp critical
            {
              if (grid[i][j]) {
                livingGenerations++;
              }
            }
          }
        }
      }
  }
  return livingGenerations;
}

int main(int argc, char **argv) {
  int livingGenerations;
  setInitGrid(grid);
  //imprime(grid);
  livingGenerations = runGenerations_critical();
    printf("Geração final %d: %d\n", G, livingGenerations);
  return 0;
}
