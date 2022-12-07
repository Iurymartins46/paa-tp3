#include "similaridade.h"

typedef struct{
    char *padrao;
}ProdutoCartesianoBases;


void inserirProdutoCartesianoBases(char **padrao, char *resultadoProdutoCartesiano);

void calculaProdutoCartesiano(ProdutoCartesianoBases **produtoCartesianoBases, int tamanho);

void calculaProdutoCartesianoAuxiliar(ProdutoCartesianoBases **produtoCartesianoBases, char *resultadoProdutoCartesiano, char **basesNitrogenadas, int tamanho, int tamanhoAuxiliar, int *quantidadeBasesNitrogenadas);

void inicializaSimilaridade(Similaridade *similaridade, int n);

double calculaSimilaridade(Similaridade *similaridade);

double calculaSimilaridadeInterna(char *arquivoDNA1, char *arquivoDNA2, int quantidadeSimulacoes, int n, int tamanhoProdutoCartesiano);

char** escolhePadroes(ProdutoCartesianoBases *produtoCartesianoBases, int n, int quantidadeTotalProdutosCartesianos, int tamanhoProdutoCartesiano);

void leituraDados(Similaridade *similaridade, char *nomeArquivo, char **padroesDNA, int arquivo);


void inserirProdutoCartesianoBases(char **padrao, char *resultadoProdutoCartesiano){
    (*padrao) = (char*)malloc(sizeof(char));
    strcpy((*padrao), resultadoProdutoCartesiano);
}

void calculaProdutoCartesiano(ProdutoCartesianoBases **produtoCartesianoBases, int tamanho){
    int i;
    int quantidadeBasesNitrogenadas = 0;
    char **basesNitrogenadas = (char**)malloc(4 * sizeof(char*));
    for(i = 0; i < 4; i++){
        basesNitrogenadas[i] = (char*)malloc(sizeof(char));
    }
    strcpy(basesNitrogenadas[0], "A");
    strcpy(basesNitrogenadas[1], "C");
    strcpy(basesNitrogenadas[2], "G");
    strcpy(basesNitrogenadas[3], "T");
    calculaProdutoCartesianoAuxiliar(produtoCartesianoBases, "", basesNitrogenadas, tamanho, 0, &quantidadeBasesNitrogenadas);
}

void calculaProdutoCartesianoAuxiliar(ProdutoCartesianoBases **produtoCartesianoBases, char *resultadoProdutoCartesiano, char **basesNitrogenadas, int tamanho, int tamanhoAuxiliar, int *quantidadeBasesNitrogenadas){
    if(tamanho == tamanhoAuxiliar){
        inserirProdutoCartesianoBases(&((*produtoCartesianoBases)[(*quantidadeBasesNitrogenadas)].padrao), resultadoProdutoCartesiano);
        (*quantidadeBasesNitrogenadas)++;
    }
    else{
        tamanhoAuxiliar += 1;
        int i;
        char aux1[1000];
        for(i = 0; i < 4; i++){
            strcpy(aux1, resultadoProdutoCartesiano);
            strcat(aux1, basesNitrogenadas[i]);
            calculaProdutoCartesianoAuxiliar(produtoCartesianoBases, aux1, basesNitrogenadas, tamanho, tamanhoAuxiliar, quantidadeBasesNitrogenadas);
        }
    }
}

char** escolhePadroes(ProdutoCartesianoBases *produtoCartesianoBases, int n, int quantidadeTotalProdutosCartesianos, int tamanhoProdutoCartesiano){
    int i, j, posicao;
    bool adicionar;
    char **padroes = (char**)malloc(n * sizeof(char*));
    for(i = 0; i < n; i++){
        padroes[i] = (char*)malloc(sizeof(char));
    }
    i = 0;
    do{
        posicao = rand() % quantidadeTotalProdutosCartesianos;
        if(i == 0){
            strcpy(padroes[i], produtoCartesianoBases[posicao].padrao);
            i++;
        }
        else{
            adicionar = true;
            for(j = 0; j < i; j++){
                if(0 == strncmp(padroes[j], produtoCartesianoBases[posicao].padrao, tamanhoProdutoCartesiano)){
                    adicionar = false;
                    break;
                }
            }
            if(adicionar){
                strcpy(padroes[i], produtoCartesianoBases[posicao].padrao);
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
    similaridade->vetorA = (int*)malloc(n * sizeof(int));
    similaridade->vetorB = (int*)malloc(n * sizeof(int));
}

double calculaSimilaridade(Similaridade *similaridade){
    int i;
    double normaA, normaB;
    int aux = 0;
    double auxA = 0;
    double auxB = 0;
    for(i = 0; i < similaridade->n; i++){
        aux += (similaridade->vetorA[i] * similaridade->vetorB[i]);
        auxA += (similaridade->vetorA[i] * similaridade->vetorA[i]);
        auxB += (similaridade->vetorB[i] * similaridade->vetorB[i]); 
    }
    normaA = sqrt(auxA);
    normaB = sqrt(auxB);
    return (aux / (normaA * normaB));
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
    int i, quantidadeTotalProdutosCartesianos = 1;
    char **padroesDNA;
    ProdutoCartesianoBases *produtoCartesianoBases;
    Similaridade similaridade;
    for(i = 0; i < tamanhoProdutoCartesiano; i++){
        quantidadeTotalProdutosCartesianos *= 4;
    }
    produtoCartesianoBases = (ProdutoCartesianoBases*)malloc(quantidadeTotalProdutosCartesianos * sizeof(ProdutoCartesianoBases));
    calculaProdutoCartesiano(&produtoCartesianoBases, tamanhoProdutoCartesiano);
    srand(time(NULL));
    for(i = 0; i < quantidadeSimulacoes; i++){
        inicializaSimilaridade(&similaridade, n);
        padroesDNA = escolhePadroes(produtoCartesianoBases, n, quantidadeTotalProdutosCartesianos, tamanhoProdutoCartesiano);
        leituraDados(&similaridade, arquivoDNA1, padroesDNA, 1);
        leituraDados(&similaridade, arquivoDNA2, padroesDNA, 2);
        totalSimilaridade += calculaSimilaridade(&similaridade);
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
        // Chamar o algorito que verifica padroes, e outras funções se necessario
    }
    fclose(file);
}
