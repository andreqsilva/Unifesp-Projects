/* Código mpi

  Para definir a versão (Game of Life/High Life), alterar o valor de V,
  sendo 0 para Game of Life e 1 para High Life

  $ mpicc gameoflife-mpi.c -o gameoflife-mpi -lm
  $ mpiexec -np <numeros_processos> ./gameoflife-mpi

  André Fernando Quaresma da Silva
  Jonatas Carrocine

*/

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"

#define V 0        // versão: game of life 0, high life 1
#define N 2048     // tamanho da matriz
#define G 2000     // número de gerações

void zeros(int **matrix, int nRows) {
  int i, j;
  for (i = 0; i < nRows; i++) {
    for (j = 0; j < N; j++) {
      matrix[i][j] = 0;
    }
  }
}

void join(int **grid, int *recvbuffer, int nRows) {
  int i, j;
  for (i = 0; i < nRows+2; i++) {
    for (j = 0; j < N; j++) {
      if (i == 0 || i == nRows+1) grid[i][j] = 0;
      else grid[i][j] = recvbuffer[((i - 1) * N) + j];
    }
  }
}

void setInitGrid(int *grid) {
  int lin, col;

  for (lin = 0; lin < N; lin++) {
    for (col = 0; col < N; col++) {
      grid[(lin * N) + col] = 0;
    }
  }
  // GLIDER
  lin = 1, col = 1;
  grid[(lin * N) + col + 1] = 1;
  grid[((lin + 1) * N) + col + 2] = 1;
  grid[((lin + 2) * N) + col] = 1;
  grid[((lin + 2) * N) + col + 1] = 1;
  grid[((lin + 2) * N) + col + 2] = 1;

  //R-pentomino
  lin = 10; col = 30;
  grid[(lin * N) + col + 1] = 1;
  grid[(lin * N) + col + 2] = 1;
  grid[((lin + 1) * N) + col] = 1;
  grid[((lin + 1) * N) + col + 1] = 1;
  grid[((lin + 2) * N) + col + 1] = 1;
}

int getNeighbors(int **grid, int i, int j) {
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

void updateNeighbors(int **grid, int **newgrid, int i, int j, int neighbors) {
  if (grid[i][j]) { // celula viva
    if (neighbors == 2 || neighbors == 3) newgrid[i][j] = 1;
    else newgrid[i][j] = 0;
  }
  else { //celula morta
    if (V == 0) { // Game of life
      if (neighbors == 3) newgrid[i][j] = 1;
      else newgrid[i][j] = 0;
    } else if (V == 1) { // High life
      if (neighbors == 3 || neighbors == 6) newgrid[i][j] = 1;
      else newgrid[i][j] = 0;
    }
  }
}

int findLivingGenerations(int **grid, int **newgrid, int nRows) {
  int i, j, neighbors, livingGenerations = 0;
  for (i = 1; i < nRows+1; i++) {
    for (j = 0; j < N; j++) {
      neighbors = getNeighbors(grid, i, j);
      updateNeighbors(grid, newgrid, i, j, neighbors);
      if (newgrid[i][j]) livingGenerations++;
    }
  }
  return livingGenerations;
}

int main(int argc, char **argv) {
  int procID, nProcs, master = 0;
  int i, j, generation, livingGenerations;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &procID);
  MPI_Comm_size(MPI_COMM_WORLD, &nProcs);

  tempoInicio = MPI_Wtime(); //Tempo inicial da execução do programa

  int nRows, localSize, vecRows[nProcs];
  int sendcounts[nProcs], begin[nProcs];

  for (i = 0; i < nProcs; i++) {
    localSize = N/nProcs;
    begin[i] = i * localSize;

    if (i == nProcs-1) vecRows[i] = N - begin[i];
    else vecRows[i] = floor((float)N/nProcs);

    sendcounts[i] = vecRows[i] * N;
    if (i > 0) begin[i] = (vecRows[i-1] * N * i);
  }

  nRows = vecRows[procID];

  int *recvbuffer = (int *) malloc(nRows * N * sizeof(int));

  // Compartilha o pedaço da matriz inicial com o processo responsável //
  if (procID == master) {
    int *initialgrid = (int *) malloc(N * N * sizeof(int));
    setInitGrid(initialgrid);
    MPI_Scatterv(initialgrid, sendcounts, begin, MPI_INT, recvbuffer,
                (nRows*N), MPI_INT, master, MPI_COMM_WORLD);
    free(initialgrid);
  } else {
    MPI_Scatterv(NULL, sendcounts, begin, MPI_INT, recvbuffer,
                (nRows*N), MPI_INT, master, MPI_COMM_WORLD);
  }

  int **grid = malloc((nRows + 2) * sizeof(int *));
  int **newgrid = malloc((nRows + 2) * sizeof(int *));

  for (i = 0; i < nRows+2; i++) {
    grid[i] = malloc(N * sizeof(int));
    newgrid[i] = malloc(N * sizeof(int));
  }
  zeros(newgrid, nRows+2);

  join(grid, recvbuffer, nRows);

  int nextProc, previousProc, finalLivingGenerations;
  if (procID == 0) previousProc = nProcs - 1;
  else previousProc = procID - 1;
  nextProc = (procID + 1) % nProcs;

  MPI_Request request;
  for (generation = 0; generation < G; generation++) {
    MPI_Barrier(MPI_COMM_WORLD);
    if (generation%2 == 0) {
      MPI_Isend(grid[1], N, MPI_INT, previousProc, 12, MPI_COMM_WORLD, &request);
      MPI_Isend(grid[nRows], N, MPI_INT, nextProc, 12, MPI_COMM_WORLD, &request);
      MPI_Recv(grid[nRows+1], N, MPI_INT, nextProc, 12, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      MPI_Recv(grid[0], N, MPI_INT, previousProc, 12, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      livingGenerations = findLivingGenerations(grid, newgrid, nRows);
    } else {
      MPI_Isend(newgrid[1], N, MPI_INT, previousProc, 12, MPI_COMM_WORLD, &request);
      MPI_Isend(newgrid[nRows], N, MPI_INT, nextProc, 12, MPI_COMM_WORLD, &request);
      MPI_Recv(newgrid[nRows+1], N, MPI_INT, nextProc, 12, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      MPI_Recv(newgrid[0], N, MPI_INT, previousProc, 12, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      livingGenerations = findLivingGenerations(newgrid, grid, nRows);
    }

    if (generation == G-1) {
      MPI_Reduce(&livingGenerations, &finalLivingGenerations,
                 1, MPI_INT, MPI_SUM, master, MPI_COMM_WORLD);
    }
  }

  tempoFinal = MPI_Wtime(); //Tempo do término da execução do programa

  if (procID == master) {
    printf("Geração final %d: %d\n", G, finalLivingGenerations);
    printf("Tempo: %.04fs\n", (tempoFinal - tempoInicio));
  }

  free(grid);
  free(newgrid);
  MPI_Finalize();
}

