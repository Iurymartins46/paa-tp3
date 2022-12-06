#include "similaridade.h"

float calculaSimilaridade(Similaridade *similaridade);

void inicializaSimilaridade(Similaridade *similaridade);

void inicializaSimilaridade(Similaridade *similaridade, int n){
    free(similaridade->vetorA);
    free(similaridade->vetorB);
    similaridade->n = n;
    similaridade->vetorA = (int*)malloc(n * sizeof(int));
    similaridade->vetorB = (int*)malloc(n * sizeof(int));
}

float calculaSimilaridade(Similaridade *similaridade){
    int i, normaA, normaB;
    int aux = 0;
    int auxA = 0;
    int auxB = 0;
    for(i = 0; i < similaridade->n; i++){
        aux += (similaridade->vetorA[i] * similaridade->vetorB[i]);
        auxA += (similaridade->vetorA[i] ^ 2);
        auxB += (similaridade->vetorB[i] ^ 2); 
    }
    normaA = sqrt((double)auxA);
    normaB = sqrt((double)auxB);
    return (aux / (normaA * normaB));
}