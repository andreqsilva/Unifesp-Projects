#include<stdio.h>
#define N 100

struct listaESC
{
    int tamanhoLista;
    int primeiro;
    int lista[N];
    int n;
    int paes;
};

typedef struct listaESC listaESC;

void inicializaLista (listaESC *listaAux)
{
    int i;
    // zera a lista
    listaAux->tamanhoLista=0;
    listaAux->primeiro=0;

    for (i=0; i<N; i++) listaAux->lista[i]=0;
}

void insereElemento(listaESC *listaAux)
{
// insere elemento ao final da lista

    if (listaAux->tamanhoLista <= listaAux->n)
        scanf("%d", &listaAux->lista[(listaAux->primeiro + listaAux->tamanhoLista) % listaAux->n]);

// atualiza a lista
listaAux->tamanhoLista++;

}


void removePrimeiroElemento (listaESC *listaAux)
{
// insere elemento ao final da lista

    if (listaAux->tamanhoLista == 1)
    {
        listaAux->primeiro = 0;
        listaAux->tamanhoLista--;

    }
    else if (listaAux->tamanhoLista > 1) {

        listaAux->primeiro = (listaAux->primeiro + 1) % N;
        listaAux->tamanhoLista--;
    }

}

int listaPaes(listaESC *listaAux) {
    int i = listaAux->primeiro;
    int c = 0, passadas = 0;

    while (c != listaAux->paes){
        i = (i + 1) % listaAux->n;

        c++;
        if(i == 0) passadas++;

    }
        printf("Passadas na lista: %d\n", passadas);

        if(c > 0) return i - 1;
        else return i;
}

void removeElementoInt(listaESC *listaAux, int posicao) {
    int i, j, t = 0;
    listaESC listaRemove;

    for(i = 0; i < listaAux->tamanhoLista; i++) {
        listaRemove.lista[i] = listaAux->lista[i];
    }

    if (listaAux->tamanhoLista == 1) {
        listaAux->primeiro = 0;
        listaAux->tamanhoLista--;

    }
    else {
        for(i = 0; i < listaAux->tamanhoLista; i++) {
            if(i == posicao) {
                for(j = 0; j < listaAux->tamanhoLista; j++) {
                    if(j == i) {
                        listaAux->lista[t] = listaRemove.lista[j+1];
                        j++;
                    }
                    else {
                        listaAux->lista[t] = listaAux->lista[j];
                    }
                    t++;
                }
                i = listaAux->tamanhoLista;
            }

        }
    }

    listaAux->tamanhoLista--;
}

void imprime (listaESC *listaAux)
{

    int i = listaAux->primeiro;

    do{
        printf("%d ", listaAux->lista[i]);
        i = (i + 1) % listaAux->n;
    }
    while (i != (listaAux->primeiro + listaAux->tamanhoLista) % listaAux->n);
        printf("\n");
}


int main()
{
    listaESC listaAux;
    int i;

    scanf("%d",&listaAux.n);

    inicializaLista(&listaAux);

    for(i = 0; i < listaAux.n; i++) {
        insereElemento(&listaAux);
    }

    imprime(&listaAux);

    scanf("%d",&listaAux.paes);

    removeElementoInt(&listaAux,listaPaes(&listaAux));
    imprime(&listaAux);


    return 0;
}
