#include <stdio.h>
#include <stdlib.h>

struct elemento
{
  int info;
  int quantidade;
  float preco;
  float lucro;
  struct elemento *prox;
};
typedef struct elemento Elemento;

struct listaDE
{
  Elemento *primeiro;
  Elemento *ultimo;
  int tamanhoLista;
};
typedef struct listaDE listaDE;

void inicializaLista(listaDE *listaAux) {
    listaAux->primeiro = NULL;
    listaAux->ultimo = NULL;
    listaAux->tamanhoLista = 0;
}

void insereElementoFinal(listaDE *listaAux, int info, int q, float p) {

    Elemento *novoElem = malloc(sizeof(Elemento));
    Elemento *anterior, *aux = listaAux->primeiro;
    novoElem->info = info;
    int t;

    if(listaAux->tamanhoLista == 0) {
        novoElem->prox = NULL;
        listaAux->primeiro = novoElem;
        listaAux->ultimo = novoElem;

    }
    else {
        t = 0;
	    while(aux != NULL && aux->preco >= p) {
		    anterior = aux;
		    aux = aux->prox;
		    t = 1;
	    }
	    if(t == 1) {
	        anterior->prox = novoElem;
	        novoElem->prox = aux;
	    }
	    else {
	        novoElem->prox = listaAux->primeiro;
	        listaAux->primeiro = novoElem;
	    }

    }

    novoElem->quantidade = q;
    novoElem->preco = p;

    listaAux->tamanhoLista++;

}

void imprime(listaDE *listaAux) {
    Elemento *imp;
    for(imp = listaAux->primeiro; imp != NULL; imp = imp->prox) {
        printf("%d %f\n",imp->info, imp->lucro);
    }
}

int procuraElemento(listaDE *listaAux, int valor) {
    Elemento *aux = listaAux->primeiro;
    while(aux != NULL) {
        if(aux->info == valor) {
            return 1;
        }
        else
            aux = aux->prox;
    }
    return -1;
}

int implementaElemento(listaDE *listaAux, int valor, int quantidade) {
    Elemento *aux = listaAux->primeiro;
    while(aux != NULL) {
        if(aux->info == valor) {
            aux->quantidade += quantidade;
            return 1;
        }
        else
            aux = aux->prox;
    }
    return -1;
}

void removeElemento(listaDE *listaAux, int valor) {
    Elemento *anterior, *remover = listaAux->primeiro;

    while(remover != NULL && remover->info != valor) {
        anterior = remover;
        remover = remover->prox;
    }
    anterior->prox = remover->prox;
    free(remover);
    listaAux->tamanhoLista--;
}

int compra(listaDE *listaAux, int codigo) {
    Elemento *jogo = listaAux->primeiro;
    while(jogo != NULL) {
        if(jogo->info == codigo) {
            if(jogo->quantidade == 0) { printf("Não há\n"); return 0;}
            else {
                jogo->lucro += jogo->preco;
                jogo->quantidade--;
                return 1;
            }
        }
        else
            jogo = jogo->prox;
    }
}


int main ()
{
    int variavel, testes, t = 0, codigo, quantidade;
    float preco;
    listaDE listaAux;
    inicializaLista(&listaAux);

    scanf("%d",&testes);
    while(t < testes) {
        scanf("%d",&variavel);
        switch(variavel) {
            case 1:
                scanf("%d %d %f",&codigo, &quantidade, &preco);
                if(procuraElemento(&listaAux,codigo) == 1) printf("O jogo já está cadastrado\n");
                else {
                    insereElementoFinal(&listaAux,codigo,quantidade,preco);
                }
            break;
            case 2:
                scanf("%d %d",&codigo, &quantidade);
                if(procuraElemento(&listaAux,codigo) == -1) printf("Não há\n");
                else {
                    implementaElemento(&listaAux,codigo,quantidade);
                }
            break;
            case 3:
                scanf("%d",&codigo);
                if(procuraElemento(&listaAux,codigo) == -1) printf("Não há\n");
                else compra(&listaAux,codigo);

            break;
            case 4:
                scanf("%d",&codigo);
                if(procuraElemento(&listaAux,codigo) == -1) printf("Não há\n");
                else removeElemento(&listaAux,codigo);
            break;


        }
        t++;
    }

    imprime(&listaAux);
  return 0;
}




