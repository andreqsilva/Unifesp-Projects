#include <stdio.h>

int verificaNotP(int valor, int notP[], int k) {
	int i;
	for(i = 0; i < k; i++) {
		if(valor == notP[i])
			return 0;
	}
	return 1;
}

int verificaPretendentes(int A[], int P[], int notP[], int candidato, int n, int k) {
	int i;
	for(i = 0; i < n; i++) {
		if(verificaNotP(A[i],notP,k)) {
			if(candidato == P[i])
				return 1;
		}
	}
	return 0;
}

void subconjuntos(int A[], int P[], int segundaEtapa[], int notP[], int n, int k, int *m) {
	int i;
	*m = 0;
	for(i = 0; i < n; i++) {
		if(verificaNotP(A[i],notP,k)) {
			//printf("A[i] %d %d\n", i, A[i]);
			segundaEtapa[*m] = A[i];
			*m += 1;
			if(verificaPretendentes(A,P,notP,A[i],n,k) == 0) {
				//printf("não pertence\n");
				//printf("m = %d\n", *m);
				notP[k] = A[i];
				k++;
				subconjuntos(A,P,segundaEtapa,notP,n,k,m);
				//printf("break\n");
				break;
			}
		}
	}
	//printf("return m = %d\n", *m);
}

int main() {
	int n;
	scanf("%d",&n);
	int A[n];
	int k = 0, i, m, a, p;
	int P[n];
	int segundaEtapa[n];
	int notP[n];
	
	for(i = 0; i < n; i++) {
	    scanf("%d %d", &a, &p);
		A[i] = a;
		P[i] = p;
	}
	
	subconjuntos(A,P,segundaEtapa,notP,n,k,&m);
	
	//printf("m = %d\n", m);
	
	for(i = 0; i < m; i++) {
		printf("%d ", segundaEtapa[i]);
	}
	printf("\n");
}
