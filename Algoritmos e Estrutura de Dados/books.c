#include <stdio.h>
#include <stdlib.h>
#define N 100

struct listaES {
    int ultimo;
    int tamanhoLista;
    int lista[N];
};
typedef struct listaES lista;

//funções da lista
void inicializaLista(lista *reserva);
void insereElemento(lista *reserva, int livro);

void inicializaLista(lista *reserva) {
    int i = 0;
    reserva->tamanhoLista = 0;
    for(i = 0;i < N;i++) {
        reserva->lista[i] = 0;
    }
    reserva->ultimo = 0;
}

void insereElemento(lista *reserva, int livro) {
    reserva->tamanhoLista++;
    reserva->lista[reserva->tamanhoLista-1] = livro;
    
    reserva->ultimo = reserva->tamanhoLista-1;
}

//remove livro
void retiraElemento(lista *reserva, int r);

void retiraElemento(lista *reserva, int r) {
    int i = 0, j = 0;
    for(i = 0; i < reserva->tamanhoLista; i++) {
        if(reserva->lista[i] == r) {
            for(j = i;j < reserva->tamanhoLista;j++) {
                reserva->lista[j] = reserva->lista[j+1];
            }
        }
    }
    reserva->tamanhoLista = reserva->tamanhoLista-1;
    reserva->ultimo = reserva->tamanhoLista-1;
}

int main()
{
    int r, n, operacoes = 0, escolha, livro, reservas = 0, retidas = 0, i, c;
    lista reserva;
    inicializaLista(&reserva);
    
    scanf("%d", &n);
    
    while(operacoes < n) {
        scanf("%d %d", &escolha, &livro);
        switch(escolha) {
            case(1):
                if(reserva.tamanhoLista == 10) {
                    printf("Lista de reserva cheia\n");
                }
                else {
                    insereElemento(&reserva,livro);
                    printf("Sua reserva foi realizada\n");
                    reservas++;
                }
                break;
            case(2):
                c = 0;
                for(i = 0;i < reserva.tamanhoLista;i++) {
                    if(livro == reserva.lista[i]) 
                        c = 1;
                }
                if(c == 0)
                    printf("Voce nao possui reserva desse livro\n");
                else {
                    retiraElemento(&reserva,livro);
                    printf("O livro foi retirado com sucesso\n");
                    retidas++;
                }
                break;
        }
        operacoes++;
    }
    
    printf("Voce realizou %d reservas e %d retiradas\n", reservas, retidas);

    return 0;
}
