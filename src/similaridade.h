#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct{
    int *vetorA;
    int *vetorB;
    int n;
}Similaridade;

double calculaSimilaridadeHumanoChimpanze(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);

double calculaSimilaridadeHumanoCachorro(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);

double calculaSimilaridadeChimpanzeCachorro(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);