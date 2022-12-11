#include "similaridade.h"


int main(){
    srand(time(NULL));


    printf("---------------------- Similaridade Humano x Chimpanze ------------------------------\n");
    clock_t boyerMoore = clock();
    printf("BoyerMoore: %.15lf\n", calculaSimilaridadeHumanoChimpanzeAlgoritmoBoyerMoore(5, 5, 5));
    clock_t finalBoyerMoore = clock();

    clock_t knuthMorrisPratt = clock();
    printf("KnuthMorrisPratt: %.15lf\n", calculaSimilaridadeHumanoChimpanzeAlgoritmoKnuthMorrisPratt(5, 5, 5));
    clock_t finalKnuthMorrisPratt = clock();

    clock_t shiftAnd = clock();
    printf("ShiftAnd: %.15lf\n", calculaSimilaridadeHumanoChimpanzeAlgoritmoShiftAnd(5, 5, 5));
    clock_t finalShiftAnd = clock();

    float humanoChipamzeBoyerMoore = ((float)(finalBoyerMoore-boyerMoore)) / (CLOCKS_PER_SEC);
    float humanoChipamzeKnuthMorrisPratt = ((float)(finalKnuthMorrisPratt-knuthMorrisPratt)) / (CLOCKS_PER_SEC);
    float humanoChipamzeShiftAnd = ((float)(finalShiftAnd-shiftAnd)) / (CLOCKS_PER_SEC);

    printf("---------------------- Similaridade Humano x Cachorro -------------------------------\n");
    boyerMoore = clock();
    printf("BoyerMoore: %.15lf\n", calculaSimilaridadeHumanoCachorroAlgoritmoBoyerMoore(5, 5, 5));
    finalBoyerMoore = clock();

    knuthMorrisPratt = clock();
    printf("KnuthMorrisPratt: %.15lf\n", calculaSimilaridadeHumanoCachorroAlgoritmoKnuthMorrisPratt(5, 5, 5));
    finalKnuthMorrisPratt = clock();

    shiftAnd = clock();
    printf("ShiftAnd: %.15lf\n", calculaSimilaridadeHumanoCachorroAlgoritmoShiftAnd(5, 5, 5));
    finalShiftAnd = clock();

    float humanoCachorroBoyerMoore = ((float)(finalBoyerMoore-boyerMoore)) / (CLOCKS_PER_SEC);
    float humanoCachorroKnuthMorrisPratt = ((float)(finalKnuthMorrisPratt-knuthMorrisPratt)) / (CLOCKS_PER_SEC);
    float humanoCachorroShiftAnd = ((float)(finalShiftAnd-shiftAnd)) / (CLOCKS_PER_SEC);

    printf("---------------------- Similaridade Chimpanze x Cachorro ----------------------------\n");
    boyerMoore = clock();
    printf("BoyerMoore: %.15lf\n", calculaSimilaridadeChimpanzeCachorroAlgoritmoBoyerMoore(5, 5, 5));
    finalBoyerMoore = clock();

    knuthMorrisPratt = clock();
    printf("KnuthMorrisPratt: %.15lf\n", calculaSimilaridadeChimpanzeCachorroAlgoritmoKnuthMorrisPratt(5, 5, 5));
    finalKnuthMorrisPratt = clock();

    shiftAnd = clock();
    printf("ShiftAnd: %.15lf\n", calculaSimilaridadeChimpanzeCachorroAlgoritmoShiftAnd(5, 5, 5));
    finalShiftAnd = clock();

    float chimpanzeCachorroBoyerMoore = ((float)(finalBoyerMoore-boyerMoore)) / (CLOCKS_PER_SEC);
    float chimpanzeCachorroKnuthMorrisPratt = ((float)(finalKnuthMorrisPratt-knuthMorrisPratt)) / (CLOCKS_PER_SEC);
    float chimpanzeCachorroShiftAnd = ((float)(finalShiftAnd-shiftAnd)) / (CLOCKS_PER_SEC);

    printf("-------------------------------------------------------------------------------------\n");

    printf("\n------- Tempo de Execucao: Similaridade Humano x Chimpanze: ------\n");
    printf("Boyer-Moore: %.2lf s\n", humanoChipamzeBoyerMoore);
    printf("Knuth-Morris-Pratt: %.2lf s\n", humanoChipamzeKnuthMorrisPratt);
    printf("Shift-And: %.2lf s\n", humanoChipamzeShiftAnd);
    printf("------------------------------------------------------------------\n");

    printf("\n------- Tempo de Execucao: Similaridade Humano x Cachorro: -------\n");
    printf("Boyer-Moore: %.2lf s\n", humanoCachorroBoyerMoore);
    printf("Knuth-Morris-Pratt: %.2lf s\n", humanoCachorroKnuthMorrisPratt);
    printf("Shift-And: %.2lf s\n", humanoCachorroShiftAnd);
    printf("------------------------------------------------------------------\n");

    printf("\n----- Tempo de Execucao: Similaridade Chimpanze x Cachorro: ------\n");
    printf("Boyer-Moore: %.2lf s\n", chimpanzeCachorroBoyerMoore);
    printf("Knuth-Morris-Pratt: %.2lf s\n", chimpanzeCachorroKnuthMorrisPratt);
    printf("Shift-And: %.2lf s\n", chimpanzeCachorroShiftAnd);
    printf("------------------------------------------------------------------\n");

    printf("\n------------------ Tempo de Execucao Total -----------------------\n");
    printf("Boyer-Moore: %.2lf s\n", chimpanzeCachorroBoyerMoore + humanoCachorroBoyerMoore + humanoChipamzeBoyerMoore);
    printf("Knuth-Morris-Pratt: %.2lf s\n", chimpanzeCachorroKnuthMorrisPratt + humanoCachorroKnuthMorrisPratt +  humanoChipamzeKnuthMorrisPratt);
    printf("Shift-And: %.2lf s\n", chimpanzeCachorroShiftAnd + humanoCachorroShiftAnd + humanoChipamzeShiftAnd);
    printf("------------------------------------------------------------------\n");
    return 0;
}
