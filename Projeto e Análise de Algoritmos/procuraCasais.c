#include <stdio.h>
#include <stdlib.h>

void procuraCasais(int A[], int I[], int F[], int C[], int f, int m, int n, int k) { // f = participante de F analisado
    int i;
    for(i = 0; i < n; i++) {
        if(A[i] == f) { 
            I[i]--;         //diminui numero de interssados
            if(I[i] == 0) { //se o numer de interssados == 0, incremente em F o seu candidato de interesse
                F[m] = C[i];
                m++;
            }
            break;
        }
    }
    
    k++;
    if(k < m)   
        procuraCasais(A,I,F,C,F[k],m,n,k);  //vai para o proximo participante em F
}

int contaCrush(int C[], int I[], int F[], int n) {
    int i, m = 0;
    for(i = 0; i < n; i++) {    //conta numero de interessados
        I[C[i]-1] += 1;
    }
    
    for(i = 0; i < n; i++) {    //cria lista dos participantes com interessados zerados na contagem
        if(I[i] == 0) {
            F[m] = C[i];
            m++;    //tamanho do array
        }
    }
    
    return m;
}

int main() {
    int m, n, i, a, c;
    scanf("%d", &n);
    int A[n];   //lista de participantes
    int C[n];   //lista de interesse
    int I[n];   //quantidade de interessados
    int F[n];   //interesses dos participantes sem nenhum interesse
    
    for(i = 0; i < n; i++) {
        I[i] = 0;
    }
    
    for(i = 0; i < n; i++) {
        scanf("%d %d",&a,&c);
        A[i] = a;
        C[i] = c;
    }
    
    m = contaCrush(C,I,F,n);
    procuraCasais(A,I,F,C,F[0],m,n,0);
    
    for(i = 0; i < n; i++) {
        if(I[i] > 0)
            printf("%d ", A[i]);
    }
    printf("\n");

}
