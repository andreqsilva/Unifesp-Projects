/* Implementação de um sudoku */

#include <stdio.h>
#include <stdlib.h>
#define RED  "\x1b[31m"
#define GREEN  "\x1b[32m"
#define RESET  "\x1b[0m"
#define YELLOW "\x1b[33m"
#define BLUE  "\x1b[34m"

int imprime_S(int S[6][6], int H[6][6], int vetor_m[], int vetor_n[], int fixos);
int zera_matriz(int m[6][6]);
int teste(int S[6][6], int H[6][6], int cont[6][6], int m, int n, int v, int vetor_m[], int vetor_n[], int fixos);
int soma_cont(int S[6][6], int cont[6][6], int m, int n);
int valores_fixos_lilian(int S[6][6], int H[6][6], int cont[6][6], int vetor_m[], int vetor_n[]);
int valores_fixos(int S[6][6], int H[6][6],  int cont[6][6], int m, int n, int v, int vetor_m[], int vetor_n[], int doty);

int main()
{
    int fixos, fim_jogo = 0, u = 0, S[6][6] = {0}, doty = 0, luna = 0; //S é a matriz principal, e H uma matriz auxiliar
    int m, n , v, H[6][6] = {0}, cecilia = 0, cont[6][6] = {0}, soma = 0, vetor_m[36], vetor_n[36], c, comando = 0;
    
    printf(YELLOW "BEM VINDO AO SUDOKU !! DIVIRTA-SE\n" RESET);
    while(comando != 3)
    {
        printf(YELLOW "Escolha uma das opcoes: \n" RESET);
        printf(BLUE "[1]DEFINIR VALORES FIXOS\n[2]VALORES FIXOS DA LILIAN\n[3]INICIAR O JOGO\n" RESET);
        printf("Comando: ");
        scanf("%d", &comando);
        system("clear");
        while(comando < 1 || comando > 3)
        {
            do{
            printf(YELLOW "Escolha uma das opcoes: \n" RESET);
            printf(BLUE "[1]DEFINIR VALORES FIXOS\n[2]VALORES FIXOS DA LILIAN\n[3]INICIAR O JOGO\n" RESET);
            printf("Comando: ");
            scanf("%d", &comando);
            system("clear");
            }while(comando < 1 || comando > 3);
        }
        switch(comando)
        {
            case 1:
                zera_matriz(S);
                zera_matriz(H);
                do{
                    printf(YELLOW "Quantos valores fixos deseja definir? " RESET);
                    scanf("%d", &fixos);
                }while(fixos < 0 || fixos > 36);
                for(int i = 0; i < fixos; i++)
                {
                    do
                    {
                        printf("Digite valores entre " BLUE "0" RESET " e " BLUE "5" RESET " para a %dº posicao fixa: ", u + 1);
                        scanf("%d %d", &m, &n);
                    }while(m < 0 || n < 0 || m > 5 || n > 5);
                    do{
                        printf("Digite um valor entre " BLUE "1" RESET " e "BLUE  "6" RESET": ");
                        scanf("%d", &v);
                    }while(v < 1 || v > 6);
                    u++;
                    doty = valores_fixos(S, H, cont, m, n, v, vetor_m, vetor_n, doty);
                    system("clear");
                    printf("Você definiu esses valores como fixos: \n");
                    imprime_S(S, H, vetor_m, vetor_n, fixos);
                    doty++;
                }
                luna++;
                break;
            case 2:
                zera_matriz(S);
                zera_matriz(H);
                valores_fixos_lilian(S, H, cont, vetor_m, vetor_n);
                fixos = 15;
                printf("Você definiu esses valores como fixos:\n");
                imprime_S(S, H, vetor_m, vetor_n, fixos);
                luna++;
                break;
            case 3:
                if(luna == 0) 
                {
                    zera_matriz(S);
                    zera_matriz(H);
                    valores_fixos_lilian(S, H, cont, vetor_m, vetor_n);
                    fixos = 15;
                }
                printf(YELLOW "***** BOM JOGO *****\n" RESET);
                imprime_S(S, H, vetor_m, vetor_n, fixos);
                while(fim_jogo == 0)
                    {
                        c = 0;
                        do
                        {
                            printf("Digite valores entre " BLUE "0" RESET " e " BLUE "5" RESET " para a posicao: ");
                            scanf("%d %d", &m, &n);
                        }while(m < 0 || n < 0 || m > 5 || n > 5);
                        do{
                            printf("Digite um valor entre " BLUE "1" RESET " e " BLUE "6" RESET ": ");
                            scanf("%d", &v);
                        }while(v < 1 || v > 6);
                        for(int i = 0; i < fixos; i++)
                        {
                            if(m == vetor_m[i] && n == vetor_n[i])
                            {
                                printf(RED "Valores fixos nao podem ser alterados\n" RESET);
                                c = 1;
                                break;
                            }
                        }
                        if(c == 0)
                        {
                        system("clear");
                        S[m][n] = v;
                        soma = teste(S, H, cont, m, n, v, vetor_m, vetor_n, fixos);
                        printf(BLUE "****** SUDOKU ******\n" RESET);
                        imprime_S(S, H, vetor_m, vetor_n, fixos);
                        printf("\n");
                        if(soma == 36)
                        {
                            for(int i = 0; i < 6; i++)
                            {
                                for(int j = 0; j < 6; j++)
                                {
                                    if(S[i][j] != H[i][j])
                                    {
                                        fim_jogo = 0;
                                        j = 6;
                                        i = 6;
                                    }
                                    else
                                        fim_jogo = 1;
                                }
                            }
                        }
                    }
               }
            printf(YELLOW "Parabéns!! Você venceu :)" RESET);
            break;
        }
    }
    
}
int imprime_S(int S[6][6], int H[6][6], int vetor_m[], int vetor_n[], int fixos)
{
    int t = 0, c;
    for(int i = 0;i < 6;i++)
    {
        for(int j = 0;j < 6;j++)
        {
            c = 0;
            for(int t = 0; t < fixos; t++)
            {
                if(i == vetor_m[t] && j == vetor_n[t])
                {
                   c = 1;
                   break;
                }
            }
            if(S[i][j] == 0)
            {
                if(j == 2)
                    printf("   |");
                else if(j == 5)
                {
                    if(i == 1 || i == 3)
                    {
                        printf("   |\n");
                        printf("--------------------\n");
                    }
                    else
                        printf("   |\n");
                }
                else
                printf("   ");
            }
            else if(c == 1)
            {
                if(j == 2)
                    printf(" %d |", S[i][j]);
                else if(j == 5)
                {
                    if(i == 1 || i == 3)
                    {
                        printf(" %d |\n", S[i][j]);
                        printf("--------------------\n");
                    }
                    else
                        printf(" %d |\n", S[i][j]);
                }
                else
                printf(" %d ", S[i][j]);
            }
            else
            {
                if(j == 2)
                {
                    if(S[i][j] != H[i][j])
                        printf(RED " %d " RESET "|", S[i][j]);
                    else
                         printf(GREEN " %d " RESET "|" , S[i][j]);
                }
                else if(j == 5)
                {
                    if(i == 1 || i == 3)
                    {
                        if(S[i][j] != H[i][j])
                        {
                            printf(RED " %d " RESET "|\n", S[i][j]);
                            printf("--------------------\n");
                        }
                        else
                        {
                            printf(GREEN " %d " RESET "|\n", S[i][j]);
                            printf("--------------------\n");
                        }
                    }
                    else
                    {
                        if(S[i][j] != H[i][j])
                            printf(RED " %d " RESET "|\n", S[i][j]);
                        else
                            printf(GREEN " %d " RESET "|\n", S[i][j]);
                    }
                }
                else
                {
                    if(S[i][j] != H[i][j])
                        printf(RED " %d " RESET, S[i][j]);
                    else
                         printf(GREEN " %d " RESET, S[i][j]);
                }
            }
        }
    }
    printf("--------------------\n");
}

int valores_fixos(int S[6][6], int H[6][6], int cont[6][6], int m, int n, int v, int vetor_m[], int vetor_n[], int doty)
{
    S[m][n] = v, vetor_m[doty] = m, vetor_n[doty] = n, H[m][n] = v, cont[m][n] = 1;
    return doty; 
}
int valores_fixos_lilian(int S[6][6], int H[6][6], int cont[6][6], int vetor_m[], int vetor_n[])
{
    int m, n, v;
    S[0][2] = 4, vetor_m[0] = 0, vetor_n[0] = 2, H[0][2] = 4, cont[0][2] = 1;
    S[0][3] = 2, vetor_m[1] = 0, vetor_n[1] = 3, H[0][3] = 2, cont[0][3] = 1;
    S[0][4] = 3, vetor_m[2] = 0, vetor_n[2] = 4, H[0][4] = 3, cont[0][4] = 1;
    S[1][1] = 2, vetor_m[3] = 1, vetor_n[3] = 1, H[1][1] = 2, cont[1][1] = 1;
    S[1][4] = 1, vetor_m[4] = 1, vetor_n[4] = 4, H[1][4] = 1, cont[1][4] = 1;
    S[2][0] = 2, vetor_m[5] = 2, vetor_n[5] = 0, H[2][0] = 2, cont[2][0] = 1;
    S[2][5] = 3, vetor_m[6] = 2, vetor_n[6] = 5, H[2][5] = 3, cont[2][5] = 1;
    S[3][0] = 3, vetor_m[7] = 3, vetor_n[7] = 0, H[3][0] = 3, cont[2][0] = 1;
    S[3][3] = 4, vetor_m[8] = 3, vetor_n[8] = 3, H[3][3] = 4, cont[3][3] = 1;
    S[3][5] = 1, vetor_m[9] = 3, vetor_n[9] = 5, H[3][5] = 1, cont[3][5] = 1;
    S[4][1] = 5, vetor_m[10] = 4, vetor_n[10] = 1, H[4][1] = 5, cont[4][1] = 1;
    S[4][4] = 4, vetor_m[11] = 4, vetor_n[11] = 4, H[4][4] = 4, cont[4][4] = 1;
    S[5][1] = 3, vetor_m[12] = 5, vetor_n[12] = 1, H[5][1] = 3, cont[5][1] = 1;
    S[5][2] = 6, vetor_m[13] = 5, vetor_n[13] = 2, H[5][2] = 6, cont[5][2] = 1;
    S[5][3] = 1, vetor_m[14] = 5, vetor_n[14] = 3, H[5][3] = 1, cont[5][3] = 1;
}
int teste(int S[6][6], int H[6][6], int cont[6][6], int m, int n, int v, int vetor_m[], int vetor_n[], int fixos)
{
    int a, b, e;
    a = m, b = n, e = v;
    int cecilia, soma, c;
    int quadrante_1(int H[6][6], int m, int n, int v), quadrante_2(int H[6][6], int m, int n, int v);
    int quadrante_3(int H[6][6], int m, int n, int v), quadrante_4(int H[6][6], int m, int n, int v);
    int quadrante_5(int H[6][6], int m, int n, int v), quadrante_6(int H[6][6], int m, int n, int v);
    for(int i = 0; i < 6; i++)
    {
        for(int x = 0; x <6; x++)
        {
            cecilia = 0, soma = 0;
            m = i; n = x, v = S[i][x], c = 0;
            for(int t = 0; t < fixos; t++)
                {
                    if(m == vetor_m[t] && n == vetor_n[t])
                    {
                        c = 1;
                        break;
                    }
                    else
                        c = 0;
                }
            if(v == 0){
                c = 1;
                cecilia = 1;
                }
            if(c == 1)
                printf("");
            else
            {
                if((m == 0 || m == 1) && (n == 0 || n == 1 || n == 2))
                {
                    cecilia = quadrante_1(S, m, n, v);
                }
                else if((m == 0 || m == 1) && (n == 3 || n == 4 || n == 5))
                {
                    cecilia = quadrante_2(S, m, n, v);
                }
                else if((m == 2 || m == 3) && (n == 0 || n == 1 || n == 2))
                {
                    cecilia = quadrante_3(S, m, n, v);
                }
                else if((m == 2 || m == 3) && (n == 3 || n == 4 || n == 5))
                {
                    cecilia = quadrante_4(S, m, n, v);
                }
                else if((m == 4 || m == 5) && (n == 0 || n == 1 || n == 2))
                {   
                cecilia = quadrante_5(S, m, n, v);
                }
                else if((m == 4 || m == 5) && (n == 3 || n == 4 || n == 5))
                {
                    cecilia = quadrante_6(S, m, n, v);
                }   
                for(int j = 0; j < 6; j++)
                {
                    if(j == n)
                        printf("");
                    else if(v == S[m][j])
                    {
                        cecilia = 1;
                    }
                    if(j == m)
                        printf("");
                    else if(v == S[j][n])
                        cecilia = 1;
                }
                
           }
            if(cecilia == 0)
                {
                    H[m][n] = v;
                    soma_cont(H, cont, m, n);
                }
                else
                {
                    H[m][n] = 0;
                }
                if(m == a && n == b)
                       e = cecilia;
        }
    }
    soma = 0;
    if(e == 0)  
        soma = soma_cont(H, cont, a, b);
    return soma;
}
int soma_cont(int S[6][6], int cont[6][6], int m, int n)
{
    int soma = 0;
    cont[m][n] = 1;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            soma += cont[i][j];
        }
    }
    return soma;
}
int quadrante_1(int H[6][6], int m, int n, int v)
{
    int cecilia = 0;
    for(int i = 0; i < 2; i++)
       {
            for(int j = 0; j < 3; j++)
            {
                if(i == m && j == n)
                    printf("");
                else if(v == H[i][j])
                {
                    cecilia = 1;
                }
             }
        }
    return cecilia;
}
int quadrante_2(int H[6][6], int m, int n, int v)
{
    int cecilia = 0;
    for(int i = 0; i < 2; i++)
       {
            for(int j = 3; j < 6; j++)
            {
                if(i == m && j == n)
                    printf("");
                else if(v == H[i][j])
                {
                    cecilia = 1;
                }
             }
        }
    return cecilia;
}
int quadrante_3(int H[6][6], int m, int n, int v)
{
    int cecilia = 0;
    for(int i = 2; i < 4; i++)
       {
            for(int j = 0; j < 3; j++)
            {
                if(i == m && j == n)
                    printf("");
                else if(v == H[i][j])
                {
                    cecilia = 1;
                }
             }
        }
    return cecilia;
}
int quadrante_4(int H[6][6], int m, int n, int v)
{
    int cecilia = 0;
    for(int i = 2; i < 4; i++)
       {
            for(int j = 3; j < 6 ; j++)
            {
                if(i == m && j == n)
                    printf("");
                else if(v == H[i][j])
                {
                    cecilia = 1;
                }
             }
        }
    return cecilia;
}
int quadrante_5(int H[6][6], int m, int n, int v)
{
    int cecilia = 0;
    for(int i = 4; i < 6; i++)
       {
            for(int j = 0; j < 3; j++)
            {
                if(i == m && j == n)
                    printf("");
                else if(v == H[i][j])
                {
                    cecilia = 1;
                }
             }
        }
    return cecilia;
}
int quadrante_6(int H[6][6], int m, int n, int v)
{
    int cecilia = 0;
    for(int i = 4; i < 6; i++)
       {
        for(int j = 3; j < 6; j++)
        {
            if(i == m && j == n)
                    printf("");
                else if(v == H[i][j])
                {
                    cecilia = 1;
                }
        }
    }
    return cecilia;
}
int zera_matriz(int m[6][6])
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            m[i][j] = 0;
        }
    }
}

