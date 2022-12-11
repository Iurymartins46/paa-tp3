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

double calculaSimilaridadeHumanoChimpanzeAlgoritmoBoyerMoore(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);

double calculaSimilaridadeHumanoCachorroAlgoritmoBoyerMoore(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);

double calculaSimilaridadeChimpanzeCachorroAlgoritmoBoyerMoore(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);

double calculaSimilaridadeHumanoChimpanzeAlgoritmoKnuthMorrisPratt(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);

double calculaSimilaridadeHumanoCachorroAlgoritmoKnuthMorrisPratt(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);

double calculaSimilaridadeChimpanzeCachorroAlgoritmoKnuthMorrisPratt(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);

double calculaSimilaridadeHumanoChimpanzeAlgoritmoShiftAnd(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);

double calculaSimilaridadeHumanoCachorroAlgoritmoShiftAnd(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);

double calculaSimilaridadeChimpanzeCachorroAlgoritmoShiftAnd(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);