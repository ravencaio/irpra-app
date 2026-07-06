#include <stdio.h>
#include "caminho.h"

static void rm_newline(char *str){
    size_t len = strlen(str);
    if (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')){
        str[len - 1] = '\0';
    }
}

static int create_file(){
    FILE *fptr = fopen(FILE_NAME, "w");
    if (fptr == NULL){ fprintf(stderr, "Erro ao criar arquivo de configuracao\n"); fclose(fptr); return 1;}
    fprintf(fptr, "");
    fclose(fptr);
}
int read_file(Caminho *caminhos, size_t *total_caminhos){
    FILE *fptr = fopen(FILE_NAME, "r");
    if (fptr == NULL){ fprintf(stderr, "Criando novo arquivo de configuracao\n"); create_file(); return 1;}
    
    char buffer[MAX_LINE_SIZE];
    int i = 0;

    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        rm_newline(buffer);
        if (strlen(buffer) == 0) continue;

        Caminho novo_caminho;
        novo_caminho.apelido = strtok(buffer, ";");
        novo_caminho.diretorio = strtok(NULL, ";");

        if (!(novo_caminho.apelido) || !(novo_caminho.diretorio)) {continue;}
        
        caminhos[*total_caminhos] = novo_caminho;
        (*total_caminhos)++;
    }
    

    fclose(fptr);
}
