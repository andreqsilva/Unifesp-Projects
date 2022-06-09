#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int info;
    int pos;
    struct elemento *prox;
    struct elemento *ant;
};
typedef struct elemento Elemento;

struct estruturaLDDE {
    Elemento *primeiro;
    Elemento *ultimo;
    int tamanhoLista;
};
typedef struct estruturaLDDE listaLDDE;

void inicializaLista(listaLDDE *listaAux) {
    listaAux->primeiro = NULL;
    listaAux->ultimo = NULL;
    listaAux->tamanhoLista = 0;
}

void insereElementoFinal(listaLDDE *listaAux) {
    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));

    scanf("%d",&novo->info);


    if(listaAux->tamanhoLista == 0) {

        novo->prox = NULL;
        novo->ant = NULL;
        listaAux->primeiro = novo;
        listaAux->ultimo = novo;

        novo->pos = listaAux->tamanhoLista;

    }
    else {
        novo->prox = NULL;
        novo->ant = listaAux->ultimo;
        listaAux->ultimo->prox = novo;
        listaAux->ultimo = novo;

        novo->pos = listaAux->tamanhoLista;
    }
    listaAux->tamanhoLista++;
}

/*void insereElementoInicio(listaLDDE *listaAux) {
    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));

    scanf("%d",&novo->info);
    if(listaAux->tamanhoLista == 0) {
        novo->prox = NULL;
        novo->ant = NULL;
        listaAux->primeiro = novo;
        listaAux->ultimo = novo;
        novo->pos = listaAux->tamanhoLista;
    }
    else {
        listaAux->primeiro->ant = novo;
        novo->prox = listaAux->primeiro;
        novo->ant = NULL;
        listaAux->primeiro = novo;
        novo->pos = listaAux->tamanhoLista;
    }
    listaAux->tamanhoLista++;
}*/

void insereElementoIntermediario(listaLDDE *listaAux, int elemento, int pos) {
    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    Elemento *aux = listaAux->primeiro, *anterior;
    novo->info = elemento;
    int t = 0;

    if(pos > listaAux->ultimo->pos) {

        printf("Ultimo: %d\n", listaAux->ultimo->info);

        novo->prox = NULL;
        novo->ant = listaAux->ultimo;
        listaAux->ultimo->prox = novo;
        listaAux->ultimo = novo;

        pos = 0;

        while(aux!=NULL) {

            aux->pos = pos++;
            aux = aux->prox;
        }

        printf("PASSOU\n");
    }

    else {

    while(aux != NULL && aux->pos != pos) {
        anterior = aux;
        aux = aux->prox;
        t = 1;
    }
    if(t == 1) {
        aux->ant = novo;
        novo->ant = anterior;
        anterior->prox = novo;
        novo->prox = aux;
        novo->pos = pos;

        while(aux!=NULL) {
            aux->pos = ++pos;
            aux = aux->prox;
        }
    }
    else {
        aux->ant = novo;
        novo->prox = listaAux->primeiro;
        listaAux->primeiro = novo;
        listaAux->primeiro->pos = 0;

        while(aux!=NULL) {
            aux->pos = ++pos;
            aux = aux->prox;
        }
    }
    }

    listaAux->tamanhoLista++;


}

void procuraDoze(listaLDDE *listaAux) {
    Elemento *aux = listaAux->primeiro, *proxElemento, *proxProximo;

    int elemento, anterior, proximo, soma;
    int procura = 1, cont = 0;

    printf("To dentro da doze\n\n");

    while(cont < listaAux->tamanhoLista - 2) {

        anterior = aux->info;
        aux = aux->prox;
        proxElemento = aux;
        elemento = aux->info;
        aux = aux->prox;
        proximo = aux->info;
        proxProximo = aux;

        soma = anterior + elemento + proximo;
        if(soma == 12) {

            printf("Anterior: %d\nElemento: %d\nProximo: %d\n", anterior, elemento, proximo);
            printf("Vai entrar na remove\n\n");
            removeElementos(listaAux,anterior,elemento,proximo);
            printf("SAIU\n");
            proxElemento = proxProximo->prox;

        }
        aux = proxElemento;
        procura++;
        cont++;

    }

}

int removeElementos(listaLDDE *listaAux, int anterior, int elemento, int proximo) {
    Elemento *auxRemove = listaAux->primeiro, *auxAnterior, *auxSucessor, *auxElemento, *auxAnteriorAnt;
    int i;

    while(auxRemove != NULL) {

            auxAnterior = auxRemove;
            auxRemove = auxRemove->prox;
            auxElemento = auxRemove;
            auxRemove = auxRemove->prox;
            auxSucessor = auxRemove;
            auxRemove = auxRemove->prox;

        if(auxElemento == listaAux->primeiro->prox) {

            if(auxElemento->info == elemento && auxAnterior->info == anterior && auxSucessor->info == proximo) {

                listaAux->primeiro->prox = auxRemove;
                listaAux->primeiro = auxRemove;

                auxRemove = auxSucessor->prox;

                free(auxAnterior);
                free(auxElemento);
                free(auxSucessor);

                listaAux->tamanhoLista = listaAux->tamanhoLista - 3;

                for(i = 0; auxRemove!=NULL; i++) {
                    auxRemove->pos = i;
                    auxRemove = auxRemove->prox;
                }

                 return 1;

            }

        }

        else {


            if(auxElemento->info == elemento && auxAnterior->info == anterior && auxSucessor->info == proximo) {
                imprimeLista(listaAux);

                printf("AuxAnterior: %d\n", auxAnterior->ant->info);

                auxAnteriorAnt = auxAnterior->ant;
                printf("AuxSucessor: %d\n", auxSucessor->prox->info);
                auxAnteriorAnt->prox = auxSucessor->prox;
                printf("AuxAnterior: %d\n", auxAnterior->prox->info);
                auxRemove->ant = auxAnterior->ant;

                listaAux->tamanhoLista = listaAux->tamanhoLista - 3;


                free(auxAnterior);
                free(auxElemento);
                free(auxSucessor);

                auxRemove = auxAnteriorAnt;



                for(i = 0; auxRemove!=NULL; i++) {
                    auxRemove->pos = i;
                    auxRemove = auxRemove->prox;
                }


                return 1;

            }

        }
        auxAnteriorAnt = auxRemove;

        auxRemove = auxElemento;


    }

}

imprimeLista(listaLDDE *listaAux) {
    Elemento *aux = listaAux->primeiro;


        while(aux != NULL) {
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("\n");

}

int main(void)
{
    listaLDDE listaAux;
    int i, elemento, posicao;

    inicializaLista(&listaAux);
    for(i = 0; i < 10; i++) {
        insereElementoFinal(&listaAux);
    }
    imprimeLista(&listaAux);

    for(i = 0; i < 5 && listaAux.tamanhoLista > 0; i++) {
        scanf("%d %d", &elemento,&posicao);
        insereElementoIntermediario(&listaAux,elemento,posicao);
        procuraDoze(&listaAux);
        printf("Aquiiiiiii\n\n");
        imprimeLista(&listaAux);
    }

    if(listaAux.tamanhoLista > 0) printf("Ih, não foi dessa vez\n");
    else printf("Eba, você ganhou!\n");

    return 0;
}




