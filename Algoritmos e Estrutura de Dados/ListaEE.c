#include <stdio.h>
#define N 100

struct info {
    int valor;
    int prox;
};
typedef struct info Info;

struct listaEE {
    int tamanhoLista;
    int primeiro;
    int ultimo;
    //0 ocupado, 1 livre
    int posLivre[N];
    Info elemento[N];
};
typedef struct listaEE listaEE;

void inicializa(listaEE *listaAux) {
    int i;
    listaAux->tamanhoLista = 0;
    listaAux->primeiro = -1;
    listaAux->ultimo = -1;
    for(i = 0;i < N;i++) {
        listaAux->elemento[i].valor = 0;
        listaAux->elemento[i].prox = -1;
        listaAux->posLivre[i] = 1;
    }
}

int proxPosLivre(listaEE *listaAux) {
    int i = 0;
    for(i = 0; i < N;i++) {
        if(listaAux->posLivre[i] == 1)
            return i;
    }
    return -1;
}

void insereElementoFinal(listaEE *listaAux, int element, int posicao) {
    if(posicao!= -1) {
        //Lê valores para lista
        listaAux->elemento[posicao].valor = element;
        //atualiza elementos da lista
        if(listaAux->tamanhoLista == 0)
            listaAux->primeiro = posicao;
        else
            listaAux->elemento[listaAux->ultimo].prox = posicao;
        listaAux->elemento[posicao].prox = -1;
        listaAux->ultimo = posicao;
        listaAux->posLivre[posicao] = 0;
        listaAux->tamanhoLista++;
    }
}

void ordemElementos(listaEE *listaAux) {
    int i, j, valorAux;
    for(i = 0; i < N; i++) {
        for(j = i+1; j < listaAux->tamanhoLista; j++) {
            if(listaAux->posLivre[i] == 0 && listaAux->posLivre[j] == 0 && listaAux->elemento[i].valor >= listaAux->elemento[j].valor) {
                valorAux = listaAux->elemento[i].valor;
                listaAux->elemento[i].valor = listaAux->elemento[j].valor;
                listaAux->elemento[j].valor = valorAux;
            }
        }
    }
}

void removeElemento(listaEE *listaAux, int posicao) {
    int i, sucessor;
    if(listaAux->tamanhoLista > 0) {
        if(listaAux->tamanhoLista == 1) {
            listaAux->primeiro = -1;
            listaAux->ultimo = -1;
        }
        else {
            for(i = 0; i < N;i++) {
                if(posicao == listaAux->elemento[i].prox) {
                    sucessor = i;
                    break;
                }
            }
            listaAux->elemento[i].prox = listaAux->elemento[posicao].prox;
            listaAux->elemento[posicao].prox = -1;
        }

    /*if(listaAux->ultimo == posicao) {
        listaAux->ultimo = i;
        listaAux->elemento[i].prox = listaAux->elemento[posicao].prox;
    }

    if(listaAux->primeiro == posicao) {
        listaAux->primeiro = listaAux->elemento[posicao].prox;
        listaAux->elemento[i].prox = listaAux->elemento[posicao].prox;
    } */
    /*if(listaAux->tamanhoLista == 0) {
        listaAux->primeiro = -1;
        listaAux->ultimo = -1;
    }*/

        listaAux->posLivre[posicao] = 1;
        listaAux->elemento[posicao].valor = 0;
        listaAux->tamanhoLista--;
    }
}

int procuraElemento(listaEE *listaAux, int element) {
    int j;
    for(j = 0;j < N;j++) {
        if(listaAux->posLivre[j] == 0) {
            if(element == listaAux->elemento[j].valor) {
                return j;
            }
        }
    }
    return -1;
}

int main()
{
    listaEE listaAux;
    int i, t, escolha_1, escolha_2, ano[N], p, livre, j, printAno = 2012, x, n;

    for(i = 0;i < N;i++){
        ano[i] = 0;
    }

    inicializa(&listaAux);

    scanf("%d", &t);
    x = 0;
    while(x < t) {
        scanf("%d %d", &escolha_1, &escolha_2);
        switch(escolha_1) {
            case 1:
                if(listaAux.tamanhoLista == 10) {
                    printf("Dia cheio\n");
                    ordemElementos(&listaAux);
                    for(i = 0; i < N; i++) {
                        if(listaAux.posLivre[i] == 0) {
                            printf("%d ", listaAux.elemento[i].valor);
                        }
                    }
                    printf("\n");
                    }
                else {
                    livre = proxPosLivre(&listaAux);
                    insereElementoFinal(&listaAux,escolha_2,livre);
                    p = listaAux.elemento[livre].valor / 10000;
                    for(j = 0;j < 15;j++) {
                        if(p == j) {
                            ano[j+1]++;
                            break;
                        }
                    }

                    ordemElementos(&listaAux);
                    for(i = 0; i < N; i++) {
                        if(listaAux.posLivre[i] == 0) {
                            printf("%d ", listaAux.elemento[i].valor);
                        }
                    }
                    printf("\n");

                }
                break;

            case 2:
                n = procuraElemento(&listaAux,escolha_2);
                if(n != -1) {
                    removeElemento(&listaAux,n);
                    ordemElementos(&listaAux);
                    for(i = 0; i < N; i++) {
                        if(listaAux.posLivre[i] == 0) {
                            printf("%d ", listaAux.elemento[i].valor);
                        }
                    }
                    printf("\n");

                }
                else {
                    printf("Não foi reservado\n");
                    ordemElementos(&listaAux);
                    for(i = 0; i < N; i++) {
                        if(listaAux.posLivre[i] == 0) {
                            printf("%d ", listaAux.elemento[i].valor);
                        }
                    }
                    printf("\n");
                }
                break;
        }
        x++;
    }

    for(i = 2; i < 10; i++) {
        printf("%d: %d\n", printAno++, ano[i]);
    }
}
