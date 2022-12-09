#include "similaridade.h"


int main(){
    printf("-------------------------------------------------------------------------------------------\n");
    srand(time(NULL));
    printf("%.15lf\n", calculaSimilaridadeHumanoChimpanzeAlgoritmoBoyerMoore(3, 4, 3));
    printf("%.15lf\n", calculaSimilaridadeHumanoCachorroAlgoritmoBoyerMoore(3, 4, 3));
    printf("%.15lf\n", calculaSimilaridadeChimpanzeCachorroAlgoritmoBoyerMoore(3, 4, 3));
    printf("-------------------------------------------------------------------------------------------\n");
    printf("%.15lf\n", calculaSimilaridadeHumanoChimpanzeAlgoritmoKnuthMorrisPratt(3, 4, 3));
    printf("%.15lf\n", calculaSimilaridadeHumanoCachorroAlgoritmoKnuthMorrisPratt(3, 4, 3));
    printf("%.15lf\n", calculaSimilaridadeChimpanzeCachorroAlgoritmoKnuthMorrisPratt(3, 4, 3));
    printf("-------------------------------------------------------------------------------------------\n");
    //printf("%.15lf\n", calculaSimilaridadeHumanoChimpanzeAlgoritmoShiftAnd(1, 4, 5));
    //printf("%.15lf\n", calculaSimilaridadeHumanoCachorroAlgoritmoShiftAnd(1, 4, 5));
    //printf("%.15lf\n", calculaSimilaridadeChimpanzeCachorroAlgoritmoShiftAnd(1, 4, 5));
    return 0;
}