#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *arquivo;

    char texto[100];
    gets(texto);

    arquivo = fopen("arq.txt","w");
    fputs(texto,texto);

    fclose();
}
