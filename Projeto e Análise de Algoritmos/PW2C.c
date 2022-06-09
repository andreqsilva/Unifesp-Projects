#include <stdio.h>
#include <math.h>

int quantidadeMoedas(int valor, int t) {
    int quantidade = 0, aux;
    while (1) {
        if (valor == 0) break;
        aux = floor (valor / (int) pow (2, t));
        valor -= aux * (int) pow (2, t);
        quantidade += aux;
        t--;
    }
  return quantidade;
}

int minimo(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    else if(b <= a && b <= c) return b;
    else return c;
}

int procuraSolucao(int valor, int log, int vetSolucao[], int indice) {
    int  logEsq, logDir, troco, trocoEsq, trocoDir, qAtual = 0, qEsquerda = 0, qDireita = 0;
  
    if((int)pow(2,log) == valor)
        return 1;
    else {
        qAtual = quantidadeMoedas(valor,log);  //quantidade de moedas para aquele valor
        
        trocoEsq = fabs(valor - (int)pow(2,(log))); //troco para valor maior que o exato
        logEsq = (int)floor((log10(trocoEsq)/log10(2))); //log2(trocoEsq)
        trocoDir = fabs(valor - (int)pow(2,(log+1)));
        logDir = (int)floor((log10(trocoDir)/log10(2)));

        
        qEsquerda = 1 + procuraSolucao(trocoEsq,logEsq,vetSolucao,indice++);
        qDireita = 1 + procuraSolucao(trocoDir,logDir,vetSolucao,indice++);
        

        vetSolucao[indice] = minimo(qAtual,qEsquerda,qDireita);
    }
}

int main() {
    int valor, log, t, vetSolucao[1000], indice = 0;
    scanf("%d", &valor);
    log = (int)floor((log10(valor)/log10(2))); //log2(valor)
    
    printf("%d\n",procuraSolucao(valor,log,vetSolucao,indice));
    
    return 0;
    
}
