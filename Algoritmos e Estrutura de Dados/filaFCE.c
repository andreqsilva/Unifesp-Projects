#include <stdio.h>
#include <stdlib.h>
#define tamanhoMAX 10

struct filaCircular {
    int primeiro;
    int ultimo;
    int elemento[tamanhoMAX];
};
typedef struct filaCircular tipoFC;

void inicializaFila(tipoFC *filaAux) {
    int i;
    filaAux->primeiro = -1;
    filaAux->ultimo = -1;
    for(i = 0;i < tamanhoMAX;i++) {
        filaAux->elemento[i] = 0;
    }
}

int filaCheia(tipoFC *filaAux) {
    if((filaAux->ultimo + 1) % tamanhoMAX == filaAux->primeiro) return 1; //fila está cheia
    else return 0;
}

int filaVazia(tipoFC *filaAux) {
    if((filaAux->primeiro == filaAux->ultimo) && (filaAux->ultimo == -1)) return 1; //fila vazia;
    else return 0;
}

int insereElemento(tipoFC *filaAux, int info) {
    int i;
    if(filaCheia(filaAux)) return -1;
    else {
        if(filaVazia(filaAux)) {
            filaAux->primeiro = filaAux->primeiro + 1;
            filaAux->ultimo = filaAux->ultimo + 1;
            filaAux->elemento[filaAux->primeiro] = info;
            filaAux->elemento[filaAux->ultimo] = info;
        }
        else {
            filaAux->ultimo = filaAux->ultimo + 1;
            for(i = filaAux->ultimo; i != 0; i--) {
                filaAux->elemento[i % tamanhoMAX] = filaAux->elemento[i-1];
            }
            filaAux->elemento[filaAux->primeiro] = info;


            //filaAux->elemento[(filaAux->primeiro + 1) % tamanhoMAX]  = info;
            //filaAux->elemento[(filaAux->ultimo + 1) % tamanhoMAX] = info;
            //filaAux->ultimo = (filaAux->ultimo + 1) % tamanhoMAX;
        }
    }
}

void removeElemento(tipoFC *filaAux) {
    if(filaVazia(filaAux)) printf("A fila está vazia\n");
    else {
        if(filaAux->primeiro == filaAux->ultimo) {
            inicializaFila(filaAux);
        }
        else {
            filaAux->elemento[filaAux->ultimo] = 0;
            filaAux->ultimo = (filaAux->ultimo - 1);
        }
    }

}

void conclui(tipoFC *filaAux) {
    int aux;
    if(filaVazia(filaAux)) printf("A fila está vazia\n");
    else {
        aux = filaAux->elemento[filaAux->primeiro];
        filaAux->elemento[filaAux->primeiro] = filaAux->elemento[filaAux->ultimo];
        filaAux->elemento[filaAux->ultimo] = aux;
    }

}

void imprime(tipoFC *filaAux) {
    int i = filaAux->primeiro, j;
    for(j = 0;j < tamanhoMAX;j++) {
        if(filaAux->elemento[i] >= 1)
            printf("%d ",filaAux->elemento[i]);
        i = (i + 1) % tamanhoMAX;
    }
    printf("\n");
}

int main(void) {
    tipoFC filaAux;
    int i = 0, info, OP, operacoes;

    inicializaFila(&filaAux);

    scanf("%d",&operacoes);
    while(i < operacoes) {
        scanf("%d",&OP);
        switch(OP) {
            case 1:
                scanf("%d",&info);
                insereElemento(&filaAux,info);
                break;
            case 2:
                removeElemento(&filaAux);
                break;
            case 3:
                conclui(&filaAux);
                break;
        }
        //imprime(&filaAux);
        i++;
    }

    imprime(&filaAux);

    return 0;
}
