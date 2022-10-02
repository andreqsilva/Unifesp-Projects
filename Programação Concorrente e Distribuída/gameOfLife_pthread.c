#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"

#define N 2048  // tamanho da matriz
#define T 2   // número de threads
#define G 100  // número de gerações

int grid[N][N] = {{0}};
int newgrid[N][N] = {{0}};

pthread_barrier_t barrier;

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

int get_neighbors_thiago(int grid[N][N], int row, int column)
{
  int border_limit = N - 1;

  int row_up = row - 1;
  int row_down = row + 1;
  int column_left = column - 1;
  int column_right = column + 1;

  if(row_up < 0) row_up = border_limit;
  if(row_down > border_limit) row_down = 0;
  if(column_left < 0) column_left = border_limit;
  if(column_right > border_limit) column_right = 0;

  int neighbors = 0;

  if(grid[row_up][column_left] == 1) neighbors++;
  if(grid[row_up][column] == 1) neighbors++;
  if(grid[row_up][column_right] == 1) neighbors++;
  if(grid[row][column_right] == 1) neighbors++;
  if(grid[row][column_left] == 1) neighbors++;
  if(grid[row_down][column_left] == 1) neighbors++;
  if(grid[row_down][column] == 1) neighbors++;
  if(grid[row_down][column_right] == 1) neighbors++;

  return neighbors;
}

// NÃO TÁ FUNCIONANDO //
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
    if (j == 0) upLeft = grid[0][N-1];
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

  // up = grid[i-1][j];
  // bottom = grid[i+1][j];
  // right = grid[i][j+1];
  // left = grid[i][j-1];
  // upRight = grid[i-1][j+1];
  // upLeft = grid[i-1][j-1];
  // bottomRight = grid[i+1][j+1];
  // bottomLeft = grid[i+1][j-1];

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
    if (neighbors == 3) newgrid[i][j] = 1;
  }
}

int findLivingGenerations(int grid[N][N], int newgrid[N][N], int *id) {
  int i, j, neighbors, livingGenerations = 0;
  int pos = *id;
  int q = N/T;
  for (i = 0; i < q; i++) {
    for (j = 0; j < N; j++) {
      neighbors = get_neighbors_thiago(grid, pos, j);
      updateNeighbors(grid, newgrid, pos, j, neighbors);
      if (newgrid[pos][j]) livingGenerations++;
    }
    pos += T;
  }
  return livingGenerations;
}


void *runGenerations(void *args) {
  int generation, neighbors;
  long livingGenerations;
  int *id = (int*)args;

  for (generation = 0; generation < G; generation++) {
    livingGenerations = 0;
    if (generation%2 == 0) {
        if (*id == 0) zeros(newgrid); // dividr
        pthread_barrier_wait(&barrier);
        livingGenerations = findLivingGenerations(grid,newgrid,id);
    } else {
      if (*id == 0) zeros(grid); // dividir
      pthread_barrier_wait(&barrier);
      livingGenerations = findLivingGenerations(newgrid,grid,id);
    }

      pthread_barrier_wait(&barrier);
  }

  pthread_exit((void*)livingGenerations);
  //pthread_exit(NULL);
}

int main(int argc, char **argv) {
  pthread_t th[T];
  int i, j, pos[T];
  int rc;
  void *result;
  int livingGenerations = 0;

  pthread_barrier_init(&barrier, NULL, T);
  setInitGrid(grid);

  for (i = 0; i < T; i++) {
    pos[i] = i;
    rc = pthread_create(&th[i], NULL, &runGenerations, (void*)&pos[i]);
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

  printf("Gerações vivas = %d\n", livingGenerations);

  pthread_barrier_destroy(&barrier);
  pthread_exit(NULL);
  return 0;
}
