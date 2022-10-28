#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

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
	while (1) {
		while (respond != *i) {
			request = *i;
		}
		critical_section(*i);
		respond = 0;
	}
}

void *server(void *args) {
	int *i = (int*)args;
	while (1) {
		while (request == 0); // await request != 0
		respond = request;
		while (respond != 0); // await respond == 0
		request = 0;
	}
}

int main(int argc, char **argv) {
	int n_clientes, rc, i;

	if (argc < 2) {
		perror("<numero de threads>");
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

    // incia os clientes
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

	pthread_exit(NULL);
	return 0;
}