#include "similaridade.h"

typedef struct{
    char *padrao;
}ProdutoCartesianoBases;


void inserirProdutoCartesianoBases(char **padrao, char *resultadoProdutoCartesiano);

void calculaProdutoCartesiano(ProdutoCartesianoBases **produtoCartesianoBases, int tamanho);

void calculaProdutoCartesianoAuxiliar(ProdutoCartesianoBases **produtoCartesianoBases, char *resultadoProdutoCartesiano, char **basesNitrogenadas, int tamanho, int tamanhoAuxiliar, int *quantidadeBasesNitrogenadas);

void inicializaSimilaridade(Similaridade *similaridade, int n);

double calculaSimilaridade(Similaridade *similaridade);


void inserirProdutoCartesianoBases(char **padrao, char *resultadoProdutoCartesiano){
    (*padrao) = (char*)malloc(sizeof(char));
    strcpy((*padrao), resultadoProdutoCartesiano);
}

void calculaProdutoCartesiano(ProdutoCartesianoBases **produtoCartesianoBases, int tamanho){
    int i, j;
    int quantidadeBasesNitrogenadas = 0;
    char **basesNitrogenadas = (char**)malloc(4 * sizeof(char*));
    for(i = 0; i < 4; i++){
        basesNitrogenadas[i] = (char*)malloc(sizeof(char));
    }
    strcpy(basesNitrogenadas[0], "A");
    strcpy(basesNitrogenadas[1], "C");
    strcpy(basesNitrogenadas[2], "G");
    strcpy(basesNitrogenadas[3], "T");
    calculaProdutoCartesianoAuxiliar(produtoCartesianoBases, "", basesNitrogenadas, tamanho, 0, &quantidadeBasesNitrogenadas);
}

void calculaProdutoCartesianoAuxiliar(ProdutoCartesianoBases **produtoCartesianoBases, char *resultadoProdutoCartesiano, char **basesNitrogenadas, int tamanho, int tamanhoAuxiliar, int *quantidadeBasesNitrogenadas){
    if(tamanho == tamanhoAuxiliar){
        inserirProdutoCartesianoBases(&((*produtoCartesianoBases)[(*quantidadeBasesNitrogenadas)].padrao), resultadoProdutoCartesiano);
        (*quantidadeBasesNitrogenadas)++;
    }
    else{
        tamanhoAuxiliar += 1;
        int i;
        char aux1[1000];
        for(i = 0; i < 4; i++){
            strcpy(aux1, resultadoProdutoCartesiano);
            strcat(aux1, basesNitrogenadas[i]);
            calculaProdutoCartesianoAuxiliar(produtoCartesianoBases, aux1, basesNitrogenadas, tamanho, tamanhoAuxiliar, quantidadeBasesNitrogenadas);
        }
    }
}

void inicializaSimilaridade(Similaridade *similaridade, int n){
    free(similaridade->vetorA);
    free(similaridade->vetorB);
    similaridade->n = n;
    similaridade->vetorA = (int*)malloc(n * sizeof(int));
    similaridade->vetorB = (int*)malloc(n * sizeof(int));
}

double calculaSimilaridade(Similaridade *similaridade){
    int i;
    double normaA, normaB;
    int aux = 0;
    double auxA = 0;
    double auxB = 0;
    for(i = 0; i < similaridade->n; i++){
        aux += (similaridade->vetorA[i] * similaridade->vetorB[i]);
        auxA += (similaridade->vetorA[i] * similaridade->vetorA[i]);
        auxB += (similaridade->vetorB[i] * similaridade->vetorB[i]); 
    }
    normaA = sqrt(auxA);
    normaB = sqrt(auxB);
    return (aux / (normaA * normaB));
}



//----------------------- Implementações das funções de "similaridade.h" -----------------------

