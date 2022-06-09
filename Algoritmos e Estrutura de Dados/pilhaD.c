#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int valor;
    struct elemento *ant;
};
typedef struct elemento tipoElemento;

struct pilha {
    int tamanhoPilha;
    tipoElemento *topo;
};
typedef struct pilha tipoPilha;

void inicializa(tipoPilha *pilhaAux) {
    pilhaAux->topo = NULL;
    pilhaAux->tamanhoPilha = 0;
}

void empilhar(tipoPilha *pilhaAux, int valor) {
    tipoElemento *novo = malloc(sizeof(tipoElemento));
    novo->valor = valor;
    novo->ant = pilhaAux->topo;
    pilhaAux->topo = novo;

    pilhaAux->tamanhoPilha++;
}

void desempilhar(tipoPilha *pilhaAux) {
    tipoElemento *removeElemento;

    removeElemento = pilhaAux->topo;
    pilhaAux->topo = pilhaAux->topo->ant;


    free(removeElemento);
    pilhaAux->tamanhoPilha--;
}

void verifica(tipoPilha *pilhaAux, int elemento) {
    if(elemento == pilhaAux->topo->valor) desempilhar(pilhaAux);
    else printf("Não foi possível remover esse carro agora\n");
}

int procuraElemento(tipoPilha *pilhaAux, int elemento) {
    tipoElemento *aux = pilhaAux->topo;

    while(aux != NULL) {
        if(aux->valor == elemento) return 0;
        aux = aux->ant;
    }
    return -1;
}

void imprime(tipoPilha *pilhaAux) {
    tipoElemento *aux = pilhaAux->topo;
    while(aux != NULL) {
        if(aux->ant == NULL)
            printf("%d\n", aux->valor);
        else printf("%d ", aux->valor);
        aux = aux->ant;
    }
}

int main()
{
    tipoPilha pilhaAux;
    inicializa(&pilhaAux);
    int c, op, valor, cont = 0;

    scanf("%d",&c);
    while(cont < c) {
        scanf("%d %d",&op,&valor);
        switch(op) {
            case 1:
                empilhar(&pilhaAux,valor);
                break;
            case 2:
                if(procuraElemento(&pilhaAux,valor) == 0)
                    verifica(&pilhaAux,valor);
                break;
        }
        imprime(&pilhaAux);
        cont++;
    }
    return 0;
}
