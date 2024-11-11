#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSO 0
#define VERDADEIRO 1
#define LETRA 0
#define DIGITO 1
#define OUTRO 2
#define NUM_ESTADOS 3
#define SEM_ESTADO -1
#define MAX_LEN 256

int T[NUM_ESTADOS][3] = {
    {1, SEM_ESTADO, SEM_ESTADO},
    {1, 1, 2},
    {SEM_ESTADO, SEM_ESTADO, SEM_ESTADO}
};

int avance[NUM_ESTADOS][3] = {
    {VERDADEIRO, FALSO, FALSO},
    {VERDADEIRO, VERDADEIRO, VERDADEIRO},
    {FALSO, FALSO, FALSO}
};

int aceita[NUM_ESTADOS] = {FALSO, FALSO, VERDADEIRO};

int letra(char ch) {
    if ( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ) return VERDADEIRO;
    return FALSO;
}

int digito(char ch) {
    if (ch >= 48 && ch <= 57) return VERDADEIRO;
    return FALSO;
}

char proximoChar(FILE *file) {
    return fgetc(file);
}

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "Uso: %s <input.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("Erro ao abrir arquivo de entrada.");
        return EXIT_FAILURE;
    }
	
	FILE *output = fopen("output.txt", "w");
	if (output == NULL) {
		perror("Erro ao abrir arquivo de saída.");
		return EXIT_FAILURE;
	}

	char ch = proximoChar(input);
	char buffer[MAX_LEN];
	int pos;

	while (ch != EOF) {
		int erro = FALSO, estado = 0;
		pos = 0;
		
		if (!letra(ch)) {
			fputc(ch, output);
			erro = VERDADEIRO;
			ch = proximoChar(input);
		}
		
		while (!aceita[estado] && !erro) {
			int tipo = OUTRO;
			if (letra(ch)) tipo = LETRA;
			else if (digito(ch)) tipo = DIGITO;
						
			int novoEstado = T[estado][tipo];
	
			if (pos < MAX_LEN - 1) {
				buffer[pos++] = ch;
			}
		
			if (avance[estado][tipo]) ch = proximoChar(input);
			estado = novoEstado;
		}

		buffer[pos] = '\0';
		if (aceita[estado]) {
			fputs("ID", output);
			fputc(buffer[pos - 1], output);
		} else {
			fputs(buffer, output);
        }
	}

	fclose(output);
    fclose(input);
    return 0;
}
