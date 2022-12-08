#include "similaridade.h"


int main(){
    printf("-------------------------------------------------------------------------------------------\n");
    printf("%.15lf\n", calculaSimilaridadeHumanoChimpanze(1, 4, 10));
    printf("-------------------------------------------------------------------------------------------\n");
    printf("%.15lf\n", calculaSimilaridadeHumanoCachorro(1, 4, 10));
    printf("-------------------------------------------------------------------------------------------\n");
    printf("%.15lf\n", calculaSimilaridadeChimpanzeCachorro(1, 4, 10));
    return 0;
}