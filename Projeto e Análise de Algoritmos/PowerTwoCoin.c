#include <stdio.h>
#include <math.h>

int quantidadeMoedas(int valor, int nroMoedas, int t) {
    int quantidade = nroMoedas, aux;
	while(1) {
	    if(valor == 0) break;
		aux = floor(valor / (int)pow(2,t));
		valor -= aux * (int)pow(2,t);
		quantidade += aux;
		t--;
	   }
    return quantidade;
}

int minimo(int a, int b) {
    if(a < b) return a;
	else return b;
}
    
int minimo4(int a, int b, int c, int d) {
    if(a <= b && a <= c && a <= d) return a;
    else if(b <= a && b <= c && b <= d) return b;
    else if(c <= a && c <= b && c <= d) return c;
    else return d;
}

int main() {
    int valor, quantidade, t, troco, log, newValor;
	int qExato = 0, qTrocoExato = 1, qTrocoMaior = 2, qTrocoMenor = 2, aux, trocoAux;
	scanf("%d", &valor);
	log = (int)floor((log10(valor)/log10(2)));                   //log2(valor)
	if((int)pow(2,log) == valor) quantidade = 1;                 //valor é uma potencia de 2 
	else {
		qExato = quantidadeMoedas(valor,qExato,log);            
		
		troco = fabs(valor - (int)pow(2,(log+1)));               //valor do troco para uma potencia de maior valor  
		t = (int)floor((log10(troco)/log10(2)));                 //log2(troco)
		qTrocoExato = quantidadeMoedas(troco,qTrocoExato,t);     
		    
		aux = (int)pow(2,t);                                     //guarda valor de 2^log2(troco)
		trocoAux = fabs(troco-aux);                             
		qTrocoMenor = quantidadeMoedas(trocoAux,qTrocoMenor,t); 
		    
		aux = (int)pow(2,t+1);                                   //guarda valor de 2^(log2(troco) + 1)
		trocoAux = fabs(troco-aux);
		qTrocoMaior = quantidadeMoedas(trocoAux,qTrocoMaior,t+1);
		
		quantidade = minimo4(qExato,qTrocoExato,qTrocoMenor,qTrocoMaior); //menor quantidade encontrada
    }
	    
	printf("%d\n", quantidade);
	return 0;
}
