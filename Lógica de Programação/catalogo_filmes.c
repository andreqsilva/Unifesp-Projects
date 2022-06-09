/* Implementação de um serviço de catálogo de filmes */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#define RED  "\x1b[31m"
#define GREEN  "\x1b[32m"
#define RESET  "\x1b[0m"
#define YELLOW "\x1b[33m"
#define BLUE  "\x1b[34m"

typedef struct
{
    char Nome_filme[50], Genero[20], Diretor[20], Atores[150], Sinopse[500];
    int Codigo_filme, Duracao , clas;
}Filme;

typedef struct
{
    int dia, mes, ano;
}Data_lancamento;

void preenche(Filme filme[], Data_lancamento data[], int p);
void filmes(Filme filme[], Data_lancamento data[], int disponivel[]);
void filmes_genero(Filme filme[], Data_lancamento data[], int disponivel[]);
void filmes_ano(Filme filme[], Data_lancamento data[], int disponivel[]);
void alterar_dados(Filme filme[], Data_lancamento[], int codigo, int disponivel[], int i);
void nome_filme(Filme filme[], Data_lancamento data[]);

int main()
{
    Filme filme[20];
    Data_lancamento data[20];


    int disponivel[20], c, p, u, l, escolha, codigo, a;
    char nome;

    //Ficção
    strcpy(filme[0].Nome_filme, "Interestelar");
    strcpy(filme[0].Genero, "Ficção");
    strcpy(filme[0].Diretor, "Christopher Nolan");
    strcpy(filme[0].Atores, "Matthew McConaughey, Anne Hathaway  e Jessica Chastain");
    strcpy(filme[0].Sinopse, "Muitas aventuras e emoções num filme onde\na unica certeza é que você não vai entender nada no final.");

    filme[0].Codigo_filme = 1234;
    data[0].dia = 06;
    data[0].mes = 11;
    data[0].ano = 2014;
    filme[0].clas = 5;
    disponivel[0] = 1;
    //////////////////////////////////////////////////////////////////////////////////////
    strcpy(filme[1].Nome_filme, "Contato");
    strcpy(filme[1].Genero, "Ficção");
    strcpy(filme[1].Diretor, "Robert Zemeckis");
    strcpy(filme[1].Atores, "Jodie Foster e Matthew McConaughey");
    strcpy(filme[1].Sinopse, "Após anos de espera, a cientista Ellie Arroway,\nenfim, confirma sua teoriasobre civilização\nextraterrestre ao descobrir como construiruma máquina\ncapaz de fazer viagens intergalácticas.\n");

    filme[1].Codigo_filme = 1235;
    data[1].dia = 19;
    data[1].mes = 9;
    data[1].ano = 1997;
    filme[1].clas = 5;
    disponivel[1] = 1;

    //Drama

    strcpy(filme[4].Nome_filme, "As Vantagens De Ser Invisivel");
    strcpy(filme[4].Genero, "Drama");
    strcpy(filme[4].Diretor, " Stephen Chbosky");
    strcpy(filme[4].Atores, "Logan Lerman, Emma Watso e Ezra Miller");
    strcpy(filme[4].Sinopse, "Um jovem tímido se esconde em seu próprio mundo\naté conhecer dois irmãos que o ajudam\na viver novas experiências.");
    filme[4].Codigo_filme = 1236;
    data[4].dia = 18;
    data[4].mes = 10;
    data[4].ano = 2012;
    filme[4].clas = 4;
    disponivel[4] = 1;
    //////////////////////////////////////////////////////////////////////////////////////
    strcpy(filme[5].Nome_filme, "Na Natureza Selvagem");
    strcpy(filme[5].Genero, "Drama");
    strcpy(filme[5].Diretor, "Sean Penn");
    strcpy(filme[5].Atores, "Emile Hirsch");
    strcpy(filme[5].Sinopse, "Depois que assistir este filme,\nvocê vai querer largar tudo e\nfugir pra Amazônia.");

    filme[5].Codigo_filme = 1237;
    data[5].dia = 22;
    data[5].mes = 02;
    data[5].ano = 2008;
    filme[5].clas = 5;
    disponivel[5] = 1;

    //Terror

    strcpy(filme[8].Nome_filme, "Atividade Paranormal");
    strcpy(filme[8].Genero, "Terror");
    strcpy(filme[8].Diretor, "Oren Peli");
    strcpy(filme[8].Atores, "Katie Featherston e Micah Sloat");
    strcpy(filme[8].Sinopse, "Logo após se mudarem para uma nova casa,\nKatie e Micah ficam intrigados com o que\nparece ser uma presença sobrenatural\nque está agindo sobre o lugar.");

    filme[8].Codigo_filme = 1238;
    data[8].dia = 15;
    data[8].mes = 10;
    data[8].ano = 2007;
    filme[8].clas = 3;
    disponivel[8] = 1;
    /////////////////////////////////////////////////
    strcpy(filme[9].Nome_filme, "Assim Na Terra Como No Inferno");
    strcpy(filme[9].Genero, "Terror");
    strcpy(filme[9].Diretor, " John Erick Dowdle");
    strcpy(filme[9].Atores, "Perdita Weeks, Ben Feldman e Edwin Hodge");
    strcpy(filme[9].Sinopse, "Um grupo de arqueólogos está em busca de um\ntesouro perdido e, para isso, explora o\ndesconhecido labirinto de ossos\nnas catacumbas abaixo de Paris.");

    filme[9].Codigo_filme = 1239;
    data[9].dia = 13;
    data[9].mes = 11;
    data[9].ano = 2014;
    filme[9].clas = 2;
    disponivel[9] = 1;

    //Comédia

    strcpy(filme[12].Nome_filme, "As Branquelas");
    strcpy(filme[12].Genero, "Comédia");
    strcpy(filme[12].Diretor, "Keenen Ivory Wayans");
    strcpy(filme[12].Atores, "Marlon Wayans, Shawn Wayans e Terry Crews");
    strcpy(filme[12].Sinopse, "Não importa se você já assistiu 112389482 vezes, assista novamente.");

    filme[12].Codigo_filme = 1240;
    data[12].dia = 27;
    data[12].mes = 8;
    data[12].ano = 2004;
    filme[12].clas = 5;
    disponivel[12] = 1;
    /////////////////////////////////////////////////////
    strcpy(filme[13].Nome_filme, "Gente Grande 2");
    strcpy(filme[13].Genero, "Comédia");
    strcpy(filme[13].Diretor, "Dennis Dugan");
    strcpy(filme[13].Atores, "Adam Sandler");
    strcpy(filme[13].Sinopse, "Nesse filme, Gente Grande 2, o\nnosso querido Adam Sandler, mais uma vez,\ninterpreta ele mesmo: Adam Sandler, (Rogérinho do Ingá, 2018)");

    filme[13].Codigo_filme = 1241;
    data[13].dia = 16;
    data[13].mes = 8;
    data[13].ano = 2013;
    filme[13].clas = 4;
    disponivel[13] = 1;

    //Ação

    strcpy(filme[16].Nome_filme, "Vingadores Ultimato");
    strcpy(filme[16].Genero, "Ação");
    strcpy(filme[16].Diretor, "Anthony Russo e Joe Russo");
    strcpy(filme[16].Atores, "Robert Downey Jr., Chris Evans e Chris Hemsworth");
    strcpy(filme[16].Sinopse, "Stark morreu.");

    filme[16].Codigo_filme = 1242;
    data[16].dia = 25;
    data[16].mes = 04;
    data[16].ano = 2019;
    filme[16].clas = 5;
    disponivel[16] = 1;
    //////////////////////////////////////////////////////////////
    strcpy(filme[17].Nome_filme, "San Andreas");
    strcpy(filme[17].Genero, "Ação");
    strcpy(filme[17].Diretor, "Brad Peyton");
    strcpy(filme[17].Atores, "Alexandra Daddario e Dwayne Johnson");
    strcpy(filme[17].Sinopse, "Depois de um terremoto de grande\nintensidade destruir a Califórnia, um\npiloto de helicóptero especializado em\nresgate inicia uma difícil jornada\npara encontrar sua filha e sua ex-esposa.");

    filme[17].Codigo_filme = 1243;
    data[17].dia = 18;
    data[17].mes = 05;
    data[17].ano = 2015;
    filme[17].clas = 3;
    disponivel[17] = 1;

    ///////////////////////////////////////////
    disponivel[2] = 0;
    disponivel[3] = 0;
    disponivel[6] = 0;
    disponivel[7] = 0;
    disponivel[10] = 0;
    disponivel[11] = 0;
    disponivel[14] = 0;
    disponivel[15] = 0;
    disponivel[18] = 0;
    disponivel[19] = 0;

    do
    {
        printf(YELLOW "VOCÊ ESTÁ NO PAINEL DE CONTROLE\nPOR FAVOR, ESCOLHA UMA DAS OPÇÕES...\n" RESET);
        printf(YELLOW "[1]" RESET " Netflix;\n"
        YELLOW "[2]" RESET" Usuário;\n"
        YELLOW "[3]" RESET " "RED "Sair.\n\n" RESET);

        do{
            printf(BLUE "Escolha uma das opções... " RESET);
            scanf("%d", &escolha);
            if(escolha < 1 || escolha > 3)
                printf(RED "Escolhe uma opção entre 1 e 3\n" RESET);
            }while(escolha < 1 || escolha > 3);
        system("clear");
        switch(escolha)
        {
            case 1:

                printf(RED "NETFLIX...\n" RESET);


                do
                {

                    printf(YELLOW "[1]" RESET " Cadastrar um filme;\n"
                    YELLOW "[2]" RESET " Alterar dados de um filme;\n"
                    YELLOW "[3]" RESET " Remover um filme;\n"
                    YELLOW "[4]" RESET " " RED "Sair.\n\n" RESET);

                    do{
                        printf(BLUE "Escolha uma das opções... " RESET);
                        scanf("%d", &c);
                        if(c < 1 || c > 4)
                            printf(RED "Escolhe uma opção entre 1 e 4\n" RESET);
                    }while(c < 1 || c > 4);
                    system("clear");
                    switch(c)
                    {
                        case 1:
                            printf(GREEN "Posições livres...\n" RESET);
                            for(int i = 0; i < 20; i++)
                            {
                                if(disponivel[i] == 0)
                                    printf(GREEN "| %d | " RESET, i+1);
                            }
                            printf("\n");

                            do{
                                printf(BLUE "Escolha uma posição livre para cadastra-lo " RESET);
                                scanf("%d", &p);
                                p = p - 1;
                                if(disponivel[p] == 1)
                                    printf(RED "Posição já preenchida!\n" RESET);
                                else if(p < 0 || p > 19)
                                    printf(RED "Informe uma posição entre 1 e 20\n" RESET);
                            }while(disponivel[p] == 1 || p < 0 || p > 19);
                                preenche(filme, data, p);
                                disponivel[p] = 1;
                            break;

                        case 2:
                            printf(YELLOW "Filmes cadastrados...\n" RESET);
                            for(int u = 0; u < 20; u++)
                            {
                                if(disponivel[u] == 1)
                                {
                                    printf("codigo " YELLOW "[%d]" RESET "" GREEN " %s\n" RESET, filme[u].Codigo_filme, filme[u].Nome_filme);
                                }
                            }

                            do{
                            printf(BLUE "Qual o codigo do filme? " RESET);
                            scanf("%d", &codigo);
                            for(l = 0; l < 20; l++)
                            {
                                if(filme[l].Codigo_filme == codigo)
                                {
                                    printf("%s\n", filme[l].Nome_filme);
                                    a = 1;
                                    break;
                                }
                            else
                                a = 0;
                            }

                            if(a == 0)
                                 printf(RED "Filme não cadastrado!\n" RESET);
                            }while(a == 0);

                            altera_dados(filme, data, codigo, disponivel, l);
                            break;

                        case 3:

                            printf(GREEN "Posições preenchidas...\n" RESET);
                            for(int i = 0; i < 20; i++)
                            {
                                if(disponivel[i] == 1)
                                    printf(GREEN "| %d |" RESET "" BLUE" %s\n" RESET, i+1, filme[i].Nome_filme);
                            }
                            printf("\n");

                            do{
                                printf(BLUE "Em que posição está o filme que deseja remover? " RESET);
                                scanf("%d", &p);
                                p = p - 1;
                                if(disponivel[p] != 1)
                                    printf(RED "Escolha uma posição preenchida...\n" RESET);
                            }while(disponivel[p] != 1 || p < 0 || p > 19);

                            printf(YELLOW "%s" RESET " removido com sucesso!\n\n", filme[p].Nome_filme);

                            disponivel[p] = 0;
                            break;

                        case 4:
                            c = 4;
                    }
                }while(c != 4);
                break;

            case 2:

                printf(GREEN "USUÁRIO...\n" RESET);

                do
                {
                    printf(YELLOW "[1]" RESET " Buscar filme por gênero;\n"
                    YELLOW "[2]" RESET " Filmes por ordem crescente de lançamento;\n"
                    YELLOW "[3]" RESET " Buscar filme pelo nome;\n"
                    YELLOW "[4]" RESET " Ver todos os filmes\n"
                    YELLOW "[5]" RESET " " RED "Sair.\n\n" RESET);

                    do{
                        printf(BLUE "Escolha uma das opções... " RESET);
                        scanf("%d", &u);
                        if(u < 1 || u > 5)
                            printf(RED "Escolhe uma opção entre 1 e 4\n" RESET);
                    }while(u < 1 || u > 5);
                    system("clear");

                    switch(u)
                    {
                        case 1:
                            filmes_genero(filme, data, disponivel);
                            break;

                        case 2:
                            filmes_ano(filme, data, disponivel);
                            break;

                        case 3:
                            nome_filme(filme, data);
                            break;

                        case 4:
                            filmes(filme, data, disponivel);
                            break;
                    }

                }while(u != 5);
                break;

            case 3:
                escolha = 3;
            }
        }while(escolha != 3);


    return 0;
}

void preenche(Filme filme[], Data_lancamento data[], int p)
{
    int a, i;

    getchar();
    printf("Nome do filme: ");
    scanf("%[^\n]", filme[p].Nome_filme);

    getchar();
    printf("Gênero: ");
    scanf("%[^\n]", filme[p].Genero);
    if(filme[p].Genero[0] >= 97 && filme[p].Genero[0] <= 122)
        filme[p].Genero[0] = filme[p].Genero[0] - 32;

    do{
        a = 0;
        printf("Códido do filme: ");
        scanf("%d", &filme[p].Codigo_filme);

        for(i = 0; i < 20; i++)
        {
            if(p == i)
                printf("");
            else
            {
                if(filme[i].Codigo_filme == filme[p].Codigo_filme)
                {
                    printf(RED "Insira um código que ainda não foi cadastrado!\n" RESET);
                    a = 1;
                    i = 20;
                }
            }
        }
    }while(a == 1);

    getchar();
    printf("Diretor: ");
    scanf("%[^\n]", filme[p].Diretor);

    getchar();
    printf("Atores principais: ");
    scanf("%[^\n]", filme[p].Atores);



    do
    {
        printf("Classificação do filme: ");
        scanf("%d", &filme[p].clas);

        if(filme[p].clas > 5 || filme[p].clas < 0)
            printf(GREEN "Notas de 0 a 5\n" RESET);
    }while(filme[p].clas > 5 || filme[p].clas < 0);

    printf("Dia do lançamento: ");
    scanf("%d", &data[p].dia);
    printf("Mes: ");
    scanf("%d", &data[p].mes);
    printf("Ano: ");
    scanf("%d", &data[p].ano);

    getchar();
    printf("Sinopse: ");
    scanf("%[^\n]", filme[p].Sinopse);

    printf(YELLOW "     FILME CADASTRADO COM SUCESSO!!\n" RESET);

    printf("======================== %d ========================\n", p+1);
    printf(BLUE "        %s\n\n" RESET, filme[p].Nome_filme);
    printf(RED"%s      " RESET " "YELLOW "codigo" RESET "[%d]\n", filme[p].Genero, filme[p].Codigo_filme);
    printf("Direção: %s\nEstrelado por: %s\n", filme[p].Diretor, filme[p].Atores);
    printf("Data de lançamento : %d/%d/%d\n", data[p].dia, data[p].mes, data[p].ano);
    printf("Classificação: ");
    for(int j = 0;j < filme[p].clas;j++)
    {
        if(filme[p].clas < 3)
            printf(RED "★" RESET);
        else if(filme[p].clas >= 3 && filme[p].clas <= 4)
            printf(GREEN "★" RESET);
        else
            printf(YELLOW "★" RESET);

    }
    printf("\n\n");

    printf(GREEN "          SINOPSE\n" RESET);
    printf("%s\n", filme[p].Sinopse);

    printf("\n");

}

filmes(Filme filme[], Data_lancamento data[], int disponivel[])
{
    for(int i = 0; i < 20; i++)
    {
        if(disponivel[i] == 1)
        {
            printf("======================== %d ========================\n", i+1);
            printf(BLUE "        %s\n\n" RESET, filme[i].Nome_filme);
            printf(RED"%s      " RESET " "YELLOW "codigo" RESET "[%d]\n", filme[i].Genero, filme[i].Codigo_filme);
            printf("Direção: %s\nEstrelado por: %s\n", filme[i].Diretor, filme[i].Atores);
            printf("Data de lançamento : %d/%d/%d\n", data[i].dia, data[i].mes, data[i].ano);
            printf("Classificação: ");
                for(int j = 0;j < filme[i].clas;j++)
                {
                    if(filme[i].clas < 3)
                        printf(RED "★" RESET);
                    else if(filme[i].clas >= 3 && filme[i].clas <= 4)
                        printf(GREEN "★" RESET);
                    else
                        printf(YELLOW "★" RESET);

                }
                printf("\n\n");

            printf(GREEN "          SINOPSE\n" RESET);
            printf("%s\n", filme[i].Sinopse);

            printf("\n");
        }
        else
        {
            printf("======================== %d ========================\n", i+1);
            printf("[Vazio]\n");
        }
    }

}

void filmes_genero(Filme filme[], Data_lancamento data[], int disponivel[])
{
    char genero[20], busca_inteligente[10];
    int t = 0, *a = NULL, b = 0, u = 0, *d = NULL;
    Filme gen[20];

    for(int n = 0; n < 20; n++)
    {
        strcpy(gen[u].Genero, ".");
    }

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            d = strstr(gen[j].Genero, filme[i].Genero);

            if(d)
            {
                d = 1;
                j = 20;
            }
            else
            {
                d = 0;
            }
        }

        if(d == 0)
        {
            strcpy(gen[u].Genero, filme[i].Genero);
            u++;
        }
    }
    printf(BLUE "ESTES SÃO OS GÊNEROS DISPONIVEIS...\n" RESET);
    for(int i = 0; i < u-1; i++)
    {
        printf(GREEN " |%s |" RESET, gen[i].Genero);
    }

    printf("\n");

    getchar();
    printf("Que gênero deseja buscar? ");
    scanf("%[^\n]", genero);

    if(genero[0] >= 97 && genero[0] <= 122)
        genero[0] = genero[0] - 32;

    printf(YELLOW "             %s\n" RESET, genero);


    for(int i = 0; i < 20; i++)
    {
        a = strstr(filme[i].Genero, genero);
        if(a)
        {
            printf("======================== %d ========================\n", i+1);
            printf(BLUE "        %s\n\n" RESET, filme[i].Nome_filme);
            printf(RED"%s      " RESET " "YELLOW "codigo" RESET "[%d]\n", filme[i].Genero, filme[i].Codigo_filme);
            printf("Direção: %s\nEstrelado por: %s\n", filme[i].Diretor, filme[i].Atores);
            printf("Data de lançamento : %d/%d/%d\n", data[i].dia, data[i].mes, data[i].ano);
            printf("Classificação: ");
                for(int j = 0;j < filme[i].clas;j++)
                {
                    if(filme[i].clas < 3)
                        printf(RED "★" RESET);
                    else if(filme[i].clas >= 3 && filme[i].clas <= 4)
                        printf(GREEN "★" RESET);
                    else
                        printf(YELLOW "★" RESET);

                }
                printf("\n\n");

            printf(GREEN "          SINOPSE\n" RESET);
            printf("%s\n", filme[i].Sinopse);

            printf("\n");

            b = 1;

        }

    }

    if(b != 1)
        printf(RED "Não foi possível identificar esse gênero :(\n\n" RESET);


}

void filmes_ano(Filme filme[], Data_lancamento data[], int disponivel[])
{
    int i = 0;
    int u, z = 0, cont = 0, r = 0;
    char aux;


    Filme aux_1[20];
    Filme ordem_filme[20];
    Data_lancamento aux_2[20];
    Data_lancamento ordem_data[20];



    for(i = 0; i < 20; i++)
    {
        if(disponivel[i] == 1)
        {
            ordem_filme[r] = filme[i];
            ordem_data[r] = data[i];
            r++;
            cont++;
        }
    }


    for(i = 0; i < cont; i++)
    {
        for(u = i+1; u < cont; u++)
        {
            if(ordem_data[i].ano > ordem_data[u].ano)
            {
                aux_1[i] = ordem_filme[i];
                aux_2[i] = ordem_data[i];

                ordem_data[i] = ordem_data[u];
                ordem_filme[i] = ordem_filme[u];

                ordem_data[u] = aux_2[i];
                ordem_filme[u] = aux_1[i];
            }
        }
    }

    printf(YELLOW "FILMES POR ORDEM CRESCENTE DE LANÇAMENTO:\n" RESET);
    for(i = 0; i < cont; i++)
    {
            printf("======================== %d ========================\n", i+1);
            printf(BLUE "        %s\n\n" RESET, ordem_filme[i].Nome_filme);
            printf(RED"%s      " RESET " "YELLOW "codigo" RESET "[%d]\n", ordem_filme[i].Genero, ordem_filme[i].Codigo_filme);
            printf("Direção: %s\nEstrelado por: %s\n", ordem_filme[i].Diretor, ordem_filme[i].Atores);
            printf("Data de lançamento : %d/%d/%d\n", ordem_data[i].dia, ordem_data[i].mes, ordem_data[i].ano);
            printf("Classificação: ");
            for(int j = 0;j < ordem_filme[i].clas;j++)
            {
                if(ordem_filme[i].clas < 3)
                    printf(RED "★" RESET);
                else if(ordem_filme[i].clas >= 3 && ordem_filme[i].clas <= 4)
                    printf(GREEN "★" RESET);
                else
                    printf(YELLOW "★" RESET);
            }
            printf("\n\n");

            printf(GREEN "          SINOPSE\n" RESET);
            printf("%s\n", ordem_filme[i].Sinopse);

            printf("\n");

    }
    printf("\n");

}

void altera_dados(Filme filme[], Data_lancamento data[], int codigo, int disponivel[], int i)
{
    int a, e, j, y;

        printf(YELLOW "[1]" RESET " Nome;\n"
        YELLOW "[2]" RESET " Gênero;\n"
        YELLOW "[3]" RESET " Código;\n"
        YELLOW "[4]" RESET " Diretor;\n"
        YELLOW "[5]" RESET " Atores principais;\n"
        YELLOW "[6]" RESET " Data de lançamento;\n"
        YELLOW "[7]" RESET " Classificação;\n"
        YELLOW "[8]" RESET " Sinopse;\n"
        YELLOW "[9]" RESET" Alterar tudo.\n\n");

        do{
            printf("O que deseja alterar...\n");
            scanf("%d", &e);
            if(e < 1 || e > 9)
                printf(RED "Comenado inválido" RESET);
        }while(e < 1 || e > 9);

        switch(e)
        {
            case 1:
                printf("Informe o nome do filme: ");
                getchar();
                scanf("%[^\n]", filme[i].Nome_filme);
                printf(YELLOW "Nome alterado com sucesso!\n\n" RESET);
                break;

            case 2:
                printf("Informe o gênero do filme: ");
                getchar();
                printf("Gênero: ");
                scanf("%[^\n]", filme[i].Genero);
                if(filme[i].Genero[0] >= 97 && filme[i].Genero[0] <= 122)
                    filme[i].Genero[0] = filme[i].Genero[0] - 32;
                printf(YELLOW "Gênero alterado com sucesso!\n\n" RESET);
                break;

            case 3:

                do{
                    y = 0;
                    printf(YELLOW "Códido do filme: " RESET);
                    scanf("%d", &filme[i].Codigo_filme);

                for(j = 0; j < 20; j++)
                {
                    if(i == j)
                        printf("");
                    else
                    {
                        if(filme[j].Codigo_filme == filme[i].Codigo_filme)
                        {
                            printf(RED "Insira um código que ainda não foi cadastrado!\n" RESET);
                            y = 1;
                            j = 20;

                        }
                    }
                }
                }while(y == 1);
                printf(YELLOW "Codido alterado com sucesso!!\n\n" RESET);
                break;

            case 4:
                printf("Informe o nome do diretor: ");
                getchar();
                scanf("%[^\n]", filme[i].Diretor);
                printf(YELLOW "Diretor alterado com sucesso!\n\n" RESET);
                break;

            case 5:
                printf("Atores principais: ");
                getchar();
                scanf("%[^\n]", filme[i].Atores);
                printf(YELLOW "Atores alterados com sucesso!\n\n" RESET);
                break;

            case 6:
                printf("Dia de lançamento: ");
                scanf("%d", &data[i].dia);
                printf("Mês: ");
                scanf("%d", &data[i].mes);
                printf("Ano: ");
                scanf("%d", &data[i].ano);
                printf(YELLOW "Data alterada com sucesso!\n\n" RESET);
                break;

            case 7:
                 do
                 {
                    printf("Classificação do filme: ");
                    scanf("%d", &filme[i].clas);

                    if(filme[i].clas > 5 || filme[i].clas < 0)
                        printf(GREEN "Notas de 0 a 5\n" RESET);
                }while(filme[i].clas > 5 || filme[i].clas < 0);

                printf(YELLOW "Classificação alterada com sucesso!\n\n" RESET);
                break;

            case 8:
                printf("Escreva a sinopse do filme: ");
                scanf("%[^\n]", filme[i].Sinopse);
                printf(YELLOW "Sinopse alterada com sucesso!\n\n" RESET);
                break;

            case 9:
                getchar();
                printf("Nome do filme: ");
                scanf("%[^\n]", filme[i].Nome_filme);
                getchar();
                printf("Gênero: ");
                scanf("%[^\n]", filme[i].Genero);

                do{
                    y = 0;
                    printf(YELLOW "Códido do filme: " RESET);
                    scanf("%d", &filme[i].Codigo_filme);

                for(j = 0; j < 20; j++)
                {
                    if(i == j)
                        printf("");
                    else
                    {
                        if(filme[j].Codigo_filme == filme[i].Codigo_filme)
                        {
                            printf(RED "Insira um código que ainda não foi cadastrado!\n" RESET);
                            y = 1;
                            j = 20;

                        }
                    }
                }
                }while(y == 1);

                getchar();
                printf("Diretor: ");
                scanf("%[^\n]", filme[i].Diretor);

                getchar();
                printf("Atores principais: ");
                scanf("%[^\n]", filme[i].Atores);


                printf("Dia do lançamento: ");
                scanf("%d", &data[i].dia);
                printf("Mes: ");
                scanf("%d", &data[i].mes);
                printf("Ano: ");
                scanf("%d", &data[i].ano);

                do
                 {
                    printf("Classificação do filme: ");
                    scanf("%d", &filme[i].clas);

                    if(filme[i].clas > 5 || filme[i].clas < 0)
                        printf(GREEN "Notas de 0 a 5\n" RESET);
                }while(filme[i].clas > 5 || filme[i].clas < 0);

                getchar();
                printf("Sinopse: ");
                scanf("%[^\n]", filme[i].Sinopse);

                printf(YELLOW "Dados alterados com sucesso!!\n" RESET);
                break;
        }
            printf("======================== %d ========================\n", i+1);
            printf(BLUE "        %s\n\n" RESET, filme[i].Nome_filme);
            printf(RED"%s      " RESET " "YELLOW "codigo" RESET "[%d]\n", filme[i].Genero, filme[i].Codigo_filme);
            printf("Direção: %s\nEstrelado por: %s\n", filme[i].Diretor, filme[i].Atores);
            printf("Data de lançamento : %d/%d/%d\n", data[i].dia, data[i].mes, data[i].ano);
            printf("Classificação: ");
                for(int j = 0;j < filme[i].clas;j++)
                {
                    if(filme[i].clas < 3)
                        printf(RED "★" RESET);
                    else if(filme[i].clas >= 3 && filme[i].clas <= 4)
                        printf(GREEN "★" RESET);
                    else
                        printf(YELLOW "★" RESET);

                }
                printf("\n\n");

            printf(GREEN "          SINOPSE\n" RESET);
            printf("%s\n", filme[i].Sinopse);

            printf("\n");
}

void nome_filme(Filme filme[], Data_lancamento data[])
{
    char nome[50], aux[50];
    int a, b = 0, p;
    int i = 0;

    printf("Nome do filme: ");
    getchar();
    scanf("%[^\n]", nome);


    for(int t = 0; nome[t] != '\0'; t++)
    {
        if(t == 0)
        {
            if(nome[t] >= 97 && nome[t] <= 122)
                nome[t] = nome[t] - 32;
        }
        else if(nome[t] == ' ')
        {
            if(nome[t+1] >= 97 && nome[t+1] <= 122)
                nome[t+1] = nome[t+1] - 32;
        }

    }

    printf("%s\n", nome);

    for(i = 0; i < 20; i++)
    {
        a = strstr(filme[i].Nome_filme, nome);

        if(a)
        {
            p = i;
            for(int j = 0; nome[j] != '\0'; j++)
            {
                if(nome[j] >= 65 && nome[j] <= 90)
                    nome[j] = nome[j] + 32;
            }

            for(int j = 0; nome[j] != '\0'; j++)
            {
                if(nome[j] == ' ')
                    nome[j] = '.';
            }
            b = 1;
            i = 20;
        }
    }

    if(b != 1)
        printf(YELLOW "Filme não encontrado\n" RED);
    else
    {
        sprintf(aux, "%s.jpg", nome);

        printf("======================== %d ========================\n", p+1);
        printf(BLUE "        %s\n\n" RESET, filme[p].Nome_filme);
        printf(RED"%s      " RESET " "YELLOW "codigo" RESET "[%d]\n", filme[p].Genero, filme[p].Codigo_filme);
        printf("Direção: %s\nEstrelado por: %s\n", filme[p].Diretor, filme[p].Atores);
        printf("Data de lançamento : %d/%d/%d\n", data[p].dia, data[p].mes, data[p].ano);
        printf("Classificação: ");
        for(int j = 0;j < filme[p].clas;j++)
        {
            if(filme[p].clas < 3)
                printf(RED "★" RESET);
            else if(filme[p].clas >= 3 && filme[p].clas <= 4)
                printf(GREEN "★" RESET);
            else
                printf(YELLOW "★" RESET);
        }
        printf("\n\n");

        printf(GREEN "          SINOPSE\n" RESET);
        printf("%s\n", filme[p].Sinopse);
        printf("\n");

        system(aux);
    }

}

