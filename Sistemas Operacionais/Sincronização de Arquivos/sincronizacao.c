#define _DEFAULT_SOURCE
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>

#define MODIFICADO 0
#define NAO_MODIFICADO 1
#define BSIZE (4*1024)

// gcc -Wall -o sincronizacao sincronizacao.c -lpthread
// ./sincronizacao ./minhapasta/ documento ./backup_minhapasta/

int status_arquivo;

struct targs {
    char dir_origem[BSIZE];
    char file[BSIZE];
    char dir_destino[BSIZE];
};
typedef struct targs targs_t;

void concatena(char *s1, char *s2, char *s3) {
    int i, j;

    for(i = 0; s1[i] != '\0'; ++i) {
        s3[i] = s1[i];
    }
    
    for(j = 0; s2[j] != '\0'; ++j, ++i) {
        s3[i] = s2[j];
    }
    s3[i] = '\0';
}

void *atualiza_backup(void *args) {
    targs_t ta = *(targs_t *)args;
    int aguardar;
    char dir_file_origem[BSIZE];
    char dir_file_destino[BSIZE];
    
    concatena(ta.dir_origem, ta.file, dir_file_origem);    
    concatena(ta.dir_destino, ta.file, dir_file_destino);
    
    while(1) {
        do {
            aguardar = 0;    
            if(status_arquivo == NAO_MODIFICADO) {
                aguardar = 1;
            }
            
        }while(aguardar == 1);

        mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

        int fd_origem = open(dir_file_origem, O_RDONLY);    //aberto apenas para leitura
        int fd_destino = open(dir_file_destino, O_WRONLY | O_CREAT | O_TRUNC, mode);    //aberto apenas para escrita | cria o arquivo | trunca
        
        int n;
        char bloco[BSIZE];
        while(1) {
            n = read(fd_origem, bloco, BSIZE);
            if(n > 0) {
                write(fd_destino, bloco, n);
            }
            else {
                break;
            }
        }

        printf("O arquivo %s foi atualizado... \n\n", ta.file);
        status_arquivo = NAO_MODIFICADO;
        
        sleep(1); 
   }  
}

void *verificacao_periodica(void *args) {
    targs_t ta = *(targs_t *)args;
    int mtime_0, mtime_1;
    int n , i = 0;    
    
    struct stat buff;
    struct dirent **namelist;
    
    while(1) {
        printf("_________________________[%d]____________________________ \n\n", i);
        n = scandir(ta.dir_origem, &namelist, NULL, alphasort);   //retorna o número de entradas do diretório selecionado

        if(n == -1) {
            perror("scandir");
            exit(EXIT_FAILURE);
        }

        while(n--) {     //percorre a lista dos arquivos no atual diretório em ordem reversa
            char dir_file[BSIZE];
            concatena(ta.dir_origem, namelist[n]->d_name, dir_file);
            stat(dir_file, &buff);    //recupera informações sobre o arquivo apontado pelo nome do caminho
            printf("%s: a:%ld m:%ld c:%ld \n", namelist[n]->d_name, 
                                               buff.st_atime, buff.st_mtime, buff.st_ctime);
            
            if(strcmp(namelist[n]->d_name, ta.file) == 0) {  //se o arquivo for o "file"
                if(i == 0 || mtime_0 != mtime_1) {
                    mtime_0 = buff.st_mtime;
                    mtime_1 = buff.st_mtime;
                    status_arquivo = MODIFICADO;
                }
                else {
                    mtime_1 = buff.st_mtime;
                }            
            }            
            
            free(namelist[n]);          
        }
        
        i++;
        free(namelist);
        printf("\n");
    
        sleep(1);
    }
}

int main(int argc, char **argv) {
    pthread_t pth_verificacao;
    pthread_t pth_backup;
    targs_t ta[1];
    
    if(argc != 4) {
        printf("%s <dir_origem> <file> <dir_destino> \n", argv[0]);
        return 0;
    }

    strcpy(ta[0].dir_origem, argv[1]);     //diretorio origem
    strcpy(ta[0].file, argv[2]);           //file a ser sincronizado
    strcpy(ta[0].dir_destino, argv[3]);    //diretorio destino

    pthread_create(&pth_verificacao, NULL, (void*)verificacao_periodica, (void*)&ta[0]);
    pthread_create(&pth_backup, NULL, (void*)atualiza_backup, (void*)&ta[0]);

    pthread_join(pth_verificacao, NULL);
    pthread_join(pth_backup, NULL);
       
    return 0;
}
