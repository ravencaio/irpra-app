#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "caminho.h"
#include "file.h"



int main(int argc, char *argv[]) {
    Caminho caminhos[MAX_SIZE] = {};
    size_t total_caminhos = 0;
    
    if(argc < 2){
        fprintf(stderr, "Uso do app: irpra <apelido>");
        read_file(caminhos, &total_caminhos);
        return 1;
    }

    read_file(caminhos, &total_caminhos);

    for(int i=0; i < total_caminhos; i++){
        if (strcmp(argv[1], caminhos[i].apelido) == 0){
            printf(caminhos[i].diretorio);
            return 0;
        }
    }
    
    fprintf(stderr, "Erro: atalho pra \"%s\" nao encontrado!", argv[1]);
    return 1;
}