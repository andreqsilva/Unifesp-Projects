#include <stdio.h>
#include <stdlib.h>

void exchange(int *A, int i, int j, int *C) {
	int aux = A[j];
	A[j] = A[i];
	A[i] = aux; 
	
	aux = C[j];		//o numero dos candidatos acompanha o numero de votos
	C[j] = C[i];
	C[i] = aux;
}

int partition(int *A, int p, int r, int *C) {
	int i, j, x;
	x = A[r];
	i = p-1;
	
	for(j = p; j <= r-1; j++) {
		if(A[j] >= x) { 	//ordena em ordem decrescente
			i++;
			exchange(A,i,j,C);
		}
	}
	exchange(A,i+1,r,C);
	return i+1;
}

void quickSort(int *A, int p, int r, int *C) {
	int q;
	if(p < r) {
		q = partition(A,p,r,C);
		quickSort(A,p,q-1,C);
		quickSort(A,q+1,r,C);
	}
}

int primeiroTurno(int *V, int nroEleitores, int nroCandidatos, int M[][3]) {
	int i, j, votosValidos = 0;
	
	for(i = 0; i < nroEleitores; i++) {
		for(j = 0; j < nroCandidatos; j++) {
			if(M[i][0] == j+1) { 
				V[j]++;		//voto para o candidato em questao
				votosValidos++;
				break;
			}
		}
	}
	return votosValidos;
}

int segundoTurno(int *V, int *C, int nroEleitores, int nroCandidatos, int M[][3]) {
	int i, j, votosValidos = 0;
	
	for(i = 0; i < nroEleitores; i++) {
		for(j = 0; j < 3; j++) {
			if(M[i][j] == C[0]) {	
				V[0]++;
				votosValidos++;
				break;
			}
			else if(M[i][j] == C[1]) {
				V[1]++;
				votosValidos++;
				break;
			}
		}
	}
	
	return votosValidos;
}

int main() {
	int i, j, nroEleitores, nroCandidatos, votosValidos, *V, *C;	//C -> candidatos, V -> votos

	scanf("%d %d", &nroEleitores, &nroCandidatos);
	int M[nroEleitores][3];
	
	C = (int*) malloc(nroCandidatos*sizeof(int));
	for(i = 0; i < nroCandidatos; i++)
		C[i] = i+1;		//numero de cada candidato
		
	V = (int*) malloc(nroCandidatos*sizeof(int));
	
	/*
	M = (int**) malloc(nroEleitores*sizeof(int));
	for(i = 0; i < nroEleitores; i++) {
		M[i] = (int*) malloc(3*sizeof(int));
	}
	*/
	
	for(i = 0; i < nroEleitores; i++) {
		for(j = 0; j < 3; j++)
			scanf("%d", &M[i][j]);
	}
	
	votosValidos = primeiroTurno(V,nroEleitores,nroCandidatos,M);
	quickSort(V,0,nroCandidatos-1,C);
	
	double porcentPrimeiro;
	porcentPrimeiro = (double)V[0]/votosValidos;	//vencedor do 1° turno
	if(votosValidos > 0) {
        printf("%d %.2lf\n", C[0], porcentPrimeiro*100);
        
        if(porcentPrimeiro < 0.5) { 	//vencedor com menos de 50% dos votos validos
			int *V2 = (int*) malloc(2*sizeof(int));
			
			votosValidos = segundoTurno(V2,C,nroEleitores,2,M);
			if(V2[0] == V2[1]) {		//verifica empate
				if(C[0] < C[1]) {
					porcentPrimeiro = (double)V2[0]/votosValidos;
					printf("%d %.2lf\n", C[0], porcentPrimeiro*100);
				}
				else {
					porcentPrimeiro = (double)V2[1]/votosValidos;
					printf("%d %.2lf\n", C[1], porcentPrimeiro*100);
				}
			}
			else {
				quickSort(V2,0,1,C);
				porcentPrimeiro = (double)V2[0]/votosValidos;
				printf("%d %.2lf\n", C[0], porcentPrimeiro*100);
			}
		}		
	}
    else printf("0\n");	
 
}
