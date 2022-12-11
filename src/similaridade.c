#include "similaridade.h"


#define NO_OF_CHARS 256 // Usado na implementação do algoritimo Boyer-Moore

void inicializaSimilaridade(Similaridade *similaridade, int n);

double calculaSimilaridade(Similaridade *similaridade);

double calculaSimilaridadeInterna(char *arquivoDNA1, char *arquivoDNA2, int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano, int algoritmo);

char** escolhePadroes(int n, int tamanhoProdutoCartesiano);

void leituraDados(Similaridade *similaridade, char *nomeArquivo, char **padroesDNA, int arquivo, int algoritmo);

void funcaoFree(int **poenteiro);

int maximo(int a, int b);

void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS]);

int boyerMooreSearch( char *txt,  char *pat);

void algoritmoBoyerMoore(Similaridade *similaridade, char *DNA, char **padroesDNA, int arquivo);

void algoritmoKnuthMorrisPratt(Similaridade *similaridade, char *DNA, char **padroesDNA, int arquivo);

int KMPSearch(char* pat, char* txt);

void computeLPSArray(char* pat, int M, int* lps);

void algoritmoShiftAnd(Similaridade *similaridade, char *DNA, char **padroesDNA, int arquivo);

int searchShiftAnd(char *texto, char *padrao);

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

double calculaSimilaridadeHumanoChimpanzeAlgoritmoBoyerMoore(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano){
    char arquivoDNAHumano[50] = "tests/human.txt";
    char arquivoDNAChimpanze[50] = "tests/chimpanzee.txt";
    return calculaSimilaridadeInterna(arquivoDNAHumano, arquivoDNAChimpanze, quantidadeSimulacoes, n, tamanhoProdutoCartesiano, 1);
    return 0;
}

double calculaSimilaridadeHumanoCachorroAlgoritmoBoyerMoore(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano){
    char arquivoDNAHumano[50] = "tests/human.txt";
    char arquivoDNACachorro[50] = "tests/dog.txt";
    return calculaSimilaridadeInterna(arquivoDNAHumano, arquivoDNACachorro, quantidadeSimulacoes, n, tamanhoProdutoCartesiano, 1);
}

double calculaSimilaridadeChimpanzeCachorroAlgoritmoBoyerMoore(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano){
    char arquivoDNAChimpanze[50] = "tests/chimpanzee.txt";
    char arquivoDNACachorro[50] = "tests/dog.txt";
    return calculaSimilaridadeInterna(arquivoDNAChimpanze, arquivoDNACachorro, quantidadeSimulacoes, n, tamanhoProdutoCartesiano, 1);
}

double calculaSimilaridadeHumanoChimpanzeAlgoritmoKnuthMorrisPratt(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano){
    char arquivoDNAHumano[50] = "tests/human.txt";
    char arquivoDNAChimpanze[50] = "tests/chimpanzee.txt";
    return calculaSimilaridadeInterna(arquivoDNAHumano, arquivoDNAChimpanze, quantidadeSimulacoes, n, tamanhoProdutoCartesiano, 2);
}

double calculaSimilaridadeHumanoCachorroAlgoritmoKnuthMorrisPratt(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano){
    char arquivoDNAHumano[50] = "tests/human.txt";
    char arquivoDNACachorro[50] = "tests/dog.txt";
    return calculaSimilaridadeInterna(arquivoDNAHumano, arquivoDNACachorro, quantidadeSimulacoes, n, tamanhoProdutoCartesiano, 2);
}

double calculaSimilaridadeChimpanzeCachorroAlgoritmoKnuthMorrisPratt(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano){
    char arquivoDNAChimpanze[50] = "tests/chimpanzee.txt";
    char arquivoDNACachorro[50] = "tests/dog.txt";
    return calculaSimilaridadeInterna(arquivoDNAChimpanze, arquivoDNACachorro, quantidadeSimulacoes, n, tamanhoProdutoCartesiano, 2);
}

double calculaSimilaridadeHumanoChimpanzeAlgoritmoShiftAnd(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano){
    char arquivoDNAHumano[50] = "tests/human.txt";
    char arquivoDNAChimpanze[50] = "tests/chimpanzee.txt";
    return calculaSimilaridadeInterna(arquivoDNAHumano, arquivoDNAChimpanze, quantidadeSimulacoes, n, tamanhoProdutoCartesiano, 3);
    return 0;
}

double calculaSimilaridadeHumanoCachorroAlgoritmoShiftAnd(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano){
    char arquivoDNAHumano[50] = "tests/human.txt";
    char arquivoDNACachorro[50] = "tests/dog.txt";
    return calculaSimilaridadeInterna(arquivoDNAHumano, arquivoDNACachorro, quantidadeSimulacoes, n, tamanhoProdutoCartesiano, 3);
}

double calculaSimilaridadeChimpanzeCachorroAlgoritmoShiftAnd(int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano){
    char arquivoDNAChimpanze[50] = "tests/chimpanzee.txt";
    char arquivoDNACachorro[50] = "tests/dog.txt";
    return calculaSimilaridadeInterna(arquivoDNAChimpanze, arquivoDNACachorro, quantidadeSimulacoes, n, tamanhoProdutoCartesiano, 3);
}

double calculaSimilaridadeInterna(char *arquivoDNA1, char *arquivoDNA2, int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano, int algoritmo){
    double totalSimilaridade = 0;
    double tot;
    int i;
    char **padroesDNA;
    Similaridade similaridade;
    for(i = 0; i < quantidadeSimulacoes; i++){
        inicializaSimilaridade(&similaridade, n);
        padroesDNA = escolhePadroes(n, tamanhoProdutoCartesiano);
        leituraDados(&similaridade, arquivoDNA1, padroesDNA, 1, algoritmo);
        leituraDados(&similaridade, arquivoDNA2, padroesDNA, 2, algoritmo);
        totalSimilaridade += calculaSimilaridade(&similaridade);
        funcaoFree(&similaridade.vetorA);
        funcaoFree(&similaridade.vetorB);
    }
    return totalSimilaridade / quantidadeSimulacoes;
}

void funcaoFree(int **poenteiro){
    free((*poenteiro));
}

// A variavel do tipo int 'arquivo' se comporta como uma fleg:
// 1 representa que esta lendo o arquivoDNA1, e os dados extraidos serão gardados no vetorA
// 2 representa que esta lendo o arquivoDNA2, e os dados extraidos serão gardados no vetorB
void leituraDados(Similaridade *similaridade, char *nomeArquivo, char **padroesDNA, int arquivo, int algoritmo){
    char DNA[20000];
    FILE *file;
    file = fopen(nomeArquivo, "r");
    if(file == NULL){
        printf("\nErro na abertura do arquivo de entrada !!!!!!!!\n\n");
        exit(1);
    }
    if(algoritmo == 1){
        while (fscanf(file, "%s", &DNA) != EOF){
            algoritmoBoyerMoore(similaridade, DNA, padroesDNA, arquivo);
        }
    }
    else if(algoritmo == 2){
        while (fscanf(file, "%s", &DNA) != EOF){
            algoritmoKnuthMorrisPratt(similaridade, DNA, padroesDNA, arquivo);
        }
    }
    else if(algoritmo == 3){
        while (fscanf(file, "%s", &DNA) != EOF){
            algoritmoShiftAnd(similaridade, DNA, padroesDNA, arquivo);
        }
    }
    fclose(file);
}

//--------------------------------- Implementação do algoritimo Boyer-Moore ---------------------------------
void algoritmoBoyerMoore(Similaridade *similaridade, char *DNA, char **padroesDNA, int arquivo){
    int i;
    int quantidadeOcorrencias;
    for(i = 0; i < similaridade->n; i++){
        quantidadeOcorrencias = boyerMooreSearch(DNA, padroesDNA[i]);
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

int boyerMooreSearch( char *txt,  char *pat){
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

//------------------------------ Implementação do algoritimo  Knuth-Morris-Pratt ------------------------------

void algoritmoKnuthMorrisPratt(Similaridade *similaridade, char *DNA, char **padroesDNA, int arquivo){
    int i;
    int quantidadeOcorrencias;
    for(i = 0; i < similaridade->n; i++){
        quantidadeOcorrencias = KMPSearch(padroesDNA[i], DNA);
        if(arquivo == 1){
            similaridade->vetorA[i] += quantidadeOcorrencias;
        }
        else{
            similaridade->vetorB[i] += quantidadeOcorrencias;
        }
    }
}

int KMPSearch(char* pat, char* txt){
    int quantidadeOcorrencias = 0;
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int*)malloc(M * sizeof(int));
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            quantidadeOcorrencias += 1;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return quantidadeOcorrencias;
}

void computeLPSArray(char* pat, int M, int* lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

//----------------------------------- Implementação do algoritimo Shift-And  -----------------------------------

void algoritmoShiftAnd(Similaridade *similaridade, char *DNA, char **padroesDNA, int arquivo){
    int i;
    int quantidadeOcorrencias;
    for(i = 0; i < similaridade->n; i++){
        quantidadeOcorrencias = searchShiftAnd(DNA, padroesDNA[i]);
        if(arquivo == 1){
            similaridade->vetorA[i] += quantidadeOcorrencias;
        }
        else{
            similaridade->vetorB[i] += quantidadeOcorrencias;
        }
    }
}

int searchShiftAnd(char *texto, char *padrao){
    int quantidadeCasamento = 0;
    int tamanhoPadrao = strlen(padrao);
    int tamanhoTexto = strlen(texto);
    if (tamanhoPadrao > tamanhoTexto)     // se padrao > texto retorna pra main sem casamentos
        return 0;

    int M[NO_OF_CHARS], R = 0;
    for (int i = 0; i < NO_OF_CHARS; i++)       // pré - processamento
        M[i] = 0;
    for (int i = 1; i <= tamanhoPadrao; i++)
        M[padrao[i-1] + 127] |= 1 << (tamanhoPadrao - i);
    for (int i = 0; i < tamanhoTexto; i++) {              // busca pelo padrão no texto
        R = ((R >> 1) | (1 << (tamanhoPadrao - 1))) & M[texto[i] + 127];
        if ((R & 1) != 0){
        if (i - tamanhoPadrao + 2 > 0)  // encontrou
            quantidadeCasamento++;
        }
    }

    return quantidadeCasamento;
}