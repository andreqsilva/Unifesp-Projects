/* Versão para testes

  André Fernando Quaresma da Silva
  Jonatas Carrocine

  $ gcc cliente-servidor-testes.c -o cliente-servidor-testes -lpthread
  $ ./cliente-servidor-testes <numero_de_clientes>
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define ONLINE 1
#define OFFLINE 0

int n_request = 100; // número máximo de requisições
int server_status = ONLINE;
int SOMA = 0;
int request = 0;
int respond = 0;

void critical_section(int i) {
  int local = SOMA;
  sleep(rand()%2);
  SOMA = local + 1;
  printf("Cliente[%d] SOMA=%d\n", i, SOMA);
}

void *client(void *args) {
  int *i = (int*)args;
  while (server_status == ONLINE) {
    /* pré-protocolo */
    while (respond != *i) {
      request = *i;
      if (server_status == OFFLINE) break;
    }
    if (server_status == ONLINE) {
      critical_section(*i);
      respond = 0;
    }
  }
  //printf("thread[%d] saiu\n", *i);
  pthread_exit(NULL);
}

void *server(void *args) {
  int *i = (int*)args;
  while (SOMA < n_request) {
    while (request == 0); // await request != 0
    respond = request;
    while (respond != 0); // await respond == 0
    request = 0;
  }
  server_status = OFFLINE;
  //printf("thread[%d] saiu\n", *i);
  pthread_exit(NULL);
}

int main(int argc, char **argv) {
  int n_clientes, rc, i;

  if (argc < 2) {
    perror("<numero_de_threads>");
    exit(0);
  }
  n_clientes = atoi(argv[1]);

  int id[n_clientes];
  id[0] = 0;
  pthread_t servidor;
  pthread_t clientes[n_clientes];

  // inicia o servidor
  rc = pthread_create(&servidor, NULL, &server, (void*)&id[0]);
  if (rc) {
    printf("ERROR: create=%d\n", rc);
    exit(-1);
  }

  // inicia os clientes
  for (i = 1; i < n_clientes+1; i++) {
    id[i] = i;
    rc = pthread_create(&clientes[i-1], NULL, &client, (void*)&id[i]);
    if (rc) {
      printf("ERROR: create=%d\n", rc);
      exit(-1);
    }
  }

  rc = pthread_join(servidor, NULL);
  if (rc) {
    printf("ERROR: join=%d\n", rc);
    exit(-1);
  }

  for (i = 1; i < n_clientes+1; i++) {
    rc = pthread_join(clientes[i-1], NULL);
    if (rc) {
      printf("ERROR: join=%d\n", rc);
      exit(-1);
    }
  }

  printf("Requisições=%d\nSOMA=%d\n", n_request, SOMA);
  pthread_exit(NULL);
  return 0;
}
