#include "similaridade.h"


#define NO_OF_CHARS 256 // Usado na implementação do algoritimo Boyer-Moore

void inicializaSimilaridade(Similaridade *similaridade, int n);

double calculaSimilaridade(Similaridade *similaridade);

double calculaSimilaridadeInterna(char *arquivoDNA1, char *arquivoDNA2, int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);

char** escolhePadroes(int n, int tamanhoProdutoCartesiano);

void leituraDados(Similaridade *similaridade, char *nomeArquivo, char **padroesDNA, int arquivo);

int maximo(int a, int b);

void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS]);

int search( char *txt,  char *pat);

void algoritimoBoyerMoore(Similaridade *similaridade, char *DNA, char **padroesDNA, int arquivo);



char** escolhePadroes(int n, int tamanhoProdutoCartesiano){
    int i, j, posicao;
    bool adicionar;
    char *padraoAuxiliar;
    padraoAuxiliar = (char*)malloc(tamanhoProdutoCartesiano * sizeof(char));
    char **padroes = (char**)malloc(n * sizeof(char*));
    for(i = 0; i < n; i++){
        padroes[i] = (char*)malloc(tamanhoProdutoCartesiano * sizeof(char));
    }
    i = 0;
    char a[5] = "A";
    char c[5] = "C";
    char g[5] = "G";
    char t[5] = "T";
    do{
        strcpy(padraoAuxiliar, "");
        for(j = 0; j < tamanhoProdutoCartesiano; j++){
            posicao = rand() % 4;
            if(posicao == 0){
                strcat(padraoAuxiliar, a);
            }
            else if(posicao == 1){
                strcat(padraoAuxiliar, c);
            }
            else if(posicao == 2){
                strcat(padraoAuxiliar, g);
            }
            else if(posicao == 3){
                strcat(padraoAuxiliar, t);
            }
        }
        if(i == 0){
            strcpy(padroes[i], padraoAuxiliar);
            i++;
        }
        else{
            adicionar = true;
            for(j = 0; j < i; j++){
                if(0 == strncmp(padroes[j], padraoAuxiliar, tamanhoProdutoCartesiano)){
                    adicionar = false;
                    break;
                }
            }
            if(adicionar){
                strcpy(padroes[i], padraoAuxiliar);
                i++;
            }
        }
    } while (i < n);
    return padroes;
}

void inicializaSimilaridade(Similaridade *similaridade, int n){
    //free(similaridade->vetorA);
    //free(similaridade->vetorB);
    similaridade->n = n;
    similaridade->vetorA = (int*)calloc(n, sizeof(int));
    similaridade->vetorB = (int*)calloc(n, sizeof(int));
}

double calculaSimilaridade(Similaridade *similaridade){
    int i;
    double normaA, normaB, auxMultiplicacaoNorma;
    long long int aux = 0;
    long long int auxA = 0;
    long long int auxB = 0;
    for(i = 0; i < similaridade->n; i++){
        aux += ((long long int)similaridade->vetorA[i] * (long long int)similaridade->vetorB[i]);
        auxA += ((long long int)similaridade->vetorA[i] * (long long int)similaridade->vetorA[i]);
        auxB += ((long long int)similaridade->vetorB[i] * (long long int)similaridade->vetorB[i]);
    }
    normaA = sqrt((double)auxA);
    normaB = sqrt((double)auxB);
    auxMultiplicacaoNorma = (normaA * normaB);
    if(auxMultiplicacaoNorma == 0){
        return 0;
    }
    return (aux / auxMultiplicacaoNorma);
}

double calculaSimilaridadeHumanoChimpanze(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano){
    char arquivoDNAHumano[50] = "tests/human.txt";
    char arquivoDNAChimpanze[50] = "tests/chimpanzee.txt";
    return calculaSimilaridadeInterna(arquivoDNAHumano, arquivoDNAChimpanze, quantidadeSimulacoes, n, tamanhoProdutoCartesiano);
    return 0;
}

double calculaSimilaridadeHumanoCachorro(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano){
    char arquivoDNAHumano[50] = "tests/human.txt";
    char arquivoDNACachorro[50] = "tests/dog.txt";
    return calculaSimilaridadeInterna(arquivoDNAHumano, arquivoDNACachorro, quantidadeSimulacoes, n, tamanhoProdutoCartesiano);
}

double calculaSimilaridadeChimpanzeCachorro(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano){
    char arquivoDNAChimpanze[50] = "tests/chimpanzee.txt";
    char arquivoDNACachorro[50] = "tests/dog.txt";
    return calculaSimilaridadeInterna(arquivoDNAChimpanze, arquivoDNACachorro, quantidadeSimulacoes, n, tamanhoProdutoCartesiano);
}

double calculaSimilaridadeInterna(char *arquivoDNA1, char *arquivoDNA2, int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano){
    double totalSimilaridade = 0;
    int i;
    char **padroesDNA;
    Similaridade similaridade;
    srand(time(NULL));
    for(i = 0; i < quantidadeSimulacoes; i++){
        inicializaSimilaridade(&similaridade, n);
        padroesDNA = escolhePadroes(n, tamanhoProdutoCartesiano);
        leituraDados(&similaridade, arquivoDNA1, padroesDNA, 1);
        leituraDados(&similaridade, arquivoDNA2, padroesDNA, 2);
        totalSimilaridade = calculaSimilaridade(&similaridade);
        free(&(similaridade.vetorA));
        free(&(similaridade.vetorB));
    }
    return totalSimilaridade / quantidadeSimulacoes;
}

void leituraDados(Similaridade *similaridade, char *nomeArquivo, char **padroesDNA, int arquivo){
    char DNA[20000];
    FILE *file;
    file = fopen(nomeArquivo, "r");
    if(file == NULL){
        printf("\nErro na abertura do arquivo de entrada !!!!!!!!\n\n");
        exit(1);
    }
    while (fscanf(file, "%s", &DNA) != EOF){
        algoritimoBoyerMoore(similaridade, DNA, padroesDNA, arquivo);
    }
    fclose(file);
}

//--------------------------------- Implementação do algoritimo Boyer-Moore ---------------------------------
void algoritimoBoyerMoore(Similaridade *similaridade, char *DNA, char **padroesDNA, int arquivo){
    int i;
    int quantidadeOcorrencias;
    for(i = 0; i < similaridade->n; i++){
        quantidadeOcorrencias = search(DNA, padroesDNA[i]);
        if(arquivo == 1){
            similaridade->vetorA[i] += quantidadeOcorrencias;
        }
        else{
            similaridade->vetorB[i] += quantidadeOcorrencias;
        }
    }
}

int maximo(int a, int b){
    return (a > b)? a: b;
}

void badCharHeuristic( char *str, int size, int badchar[NO_OF_CHARS]){
    int i;
    for (i = 0; i < NO_OF_CHARS; i++){
        badchar[i] = -1;
    }
    for (i = 0; i < size; i++){
        badchar[(int) str[i]] = i;
    }
}
 
int search( char *txt,  char *pat){
    int quantidadeOcorrencias = 0;
    int m = strlen(pat);
    int n = strlen(txt);
    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);
    int s = 0;
    while(s <= (n - m)){
        int j = m-1;
        while(j >= 0 && pat[j] == txt[s+j]){
            j--;
        }
        if (j < 0){
            quantidadeOcorrencias += 1;
            s += (s+m < n)? m-badchar[txt[s+m]] : 1;
        }
        else{
            s += maximo(1, j - badchar[txt[s+j]]);
        }
    }
    return quantidadeOcorrencias;
}
