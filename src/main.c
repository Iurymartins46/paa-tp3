#include "similaridade.h"


int main(){
    printf("-------------------------------------------------------------------------------------------\n");
    srand(time(NULL));
    printf("Similaridade Humano x Chimpanze: %.15lf\n", calculaSimilaridadeHumanoChimpanzeAlgoritmoBoyerMoore(5, 5, 5));
    printf("Similaridade Humano x Cachorro: %.15lf\n", calculaSimilaridadeHumanoCachorroAlgoritmoBoyerMoore(5, 5, 5));
    printf("Similaridade Chimpanze x Cachorro: %.15lf\n", calculaSimilaridadeChimpanzeCachorroAlgoritmoBoyerMoore(5, 5, 5));
    printf("-------------------------------------------------------------------------------------------\n");
    printf("Similaridade Humano x Chimpanze: %.15lf\n", calculaSimilaridadeHumanoChimpanzeAlgoritmoKnuthMorrisPratt(5, 5, 5));
    printf("Similaridade Humano x Cachorro: %.15lf\n", calculaSimilaridadeHumanoCachorroAlgoritmoKnuthMorrisPratt(5, 5, 5));
    printf("Similaridade Chimpanze x Cachorro: %.15lf\n", calculaSimilaridadeChimpanzeCachorroAlgoritmoKnuthMorrisPratt(5, 5, 5));
    printf("-------------------------------------------------------------------------------------------\n");
    //printf("Similaridade Humano x Chimpanze: %.15lf\n", calculaSimilaridadeHumanoChimpanzeAlgoritmoShiftAnd(1, 4, 5));
    //printf("Similaridade Humano x Cachorro: %.15lf\n", calculaSimilaridadeHumanoCachorroAlgoritmoShiftAnd(1, 4, 5));
    //printf("Similaridade Chimpanze x Cachorro: %.15lf\n", calculaSimilaridadeChimpanzeCachorroAlgoritmoShiftAnd(1, 4, 5));
    printf("------- FIM ------\n");
    return 0;
}
