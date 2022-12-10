#include "similaridade.h"


int main(){
    srand(time(NULL));

    printf("-------------------------------------------------------------------------------------------\n");
    clock_t tempoIncialBoyerMoore = clock();
    printf("Similaridade Humano x Chimpanze: %.15lf\n", calculaSimilaridadeHumanoChimpanzeAlgoritmoBoyerMoore(5, 5, 5));
    printf("Similaridade Humano x Cachorro: %.15lf\n", calculaSimilaridadeHumanoCachorroAlgoritmoBoyerMoore(5, 5, 5));
    printf("Similaridade Chimpanze x Cachorro: %.15lf\n", calculaSimilaridadeChimpanzeCachorroAlgoritmoBoyerMoore(5, 5, 5));
    clock_t tempoFinalBoyerMoore = clock();

    printf("-------------------------------------------------------------------------------------------\n");
    clock_t tempoIncialKnuthMorrisPratt = clock();
    printf("Similaridade Humano x Chimpanze: %.15lf\n", calculaSimilaridadeHumanoChimpanzeAlgoritmoKnuthMorrisPratt(5, 5, 5));
    printf("Similaridade Humano x Cachorro: %.15lf\n", calculaSimilaridadeHumanoCachorroAlgoritmoKnuthMorrisPratt(5, 5, 5));
    printf("Similaridade Chimpanze x Cachorro: %.15lf\n", calculaSimilaridadeChimpanzeCachorroAlgoritmoKnuthMorrisPratt(5, 5, 5));
    clock_t tempoFinalKnuthMorrisPratt = clock();

    printf("-------------------------------------------------------------------------------------------\n");
    clock_t tempoIncialAlgoritmoShiftAnd = clock();
    //printf("Similaridade Humano x Chimpanze: %.15lf\n", calculaSimilaridadeHumanoChimpanzeAlgoritmoShiftAnd(1, 4, 5));
    //printf("Similaridade Humano x Cachorro: %.15lf\n", calculaSimilaridadeHumanoCachorroAlgoritmoShiftAnd(1, 4, 5));
    //printf("Similaridade Chimpanze x Cachorro: %.15lf\n", calculaSimilaridadeChimpanzeCachorroAlgoritmoShiftAnd(1, 4, 5));
    clock_t tempoFinalAlgoritmoShiftAnd = clock();

    printf("\n------- Tempo de Execucao de cada Algoritmo ------\n");
    printf("BoyerMoore: %f s\n", ((float)(tempoFinalBoyerMoore-tempoIncialBoyerMoore)) / (CLOCKS_PER_SEC));
    printf("KnuthMorrisPratt: %f s\n", ((float)(tempoFinalKnuthMorrisPratt-tempoIncialKnuthMorrisPratt)) /(CLOCKS_PER_SEC));
    printf("ShiftAnd: %f s\n", ((float)(tempoFinalAlgoritmoShiftAnd-tempoIncialAlgoritmoShiftAnd)) /(CLOCKS_PER_SEC));
    return 0;
}
