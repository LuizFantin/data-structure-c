//Erika Barbosa Gomes
//Everson Henrich da Silva
//Luiz Fantin Neto
//Milena Tavares Roas

#ifndef _H_QUICKSORTEXT
#define _H_QUICKSORTEXT

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

/*  void lerSup: 
        Ação: Lê nBytes do arquivo apontado por arqLS na posição lS*nBytes distante do início do arquivo, armazena os dados lidos em reg, decrementa lS e
altera ordem para 0.
        Argumentos:
            - FILE *arqLS - ponteiro para o arquivo onde será realizada a leitura.
            - void *reg - ponteiro da variável que armazenará os dados lidos.
            - int *lS - ponteiro para inteiro que indica a posição a ser lida.
            - int nBytes - variável que indica o tamanho dos registros.
            - short int *ordem - ponteiro para inteiro (short) que indica qual será a próxima leitura(1 para lerSup e 0 para lerInf).
        Retorno: Sem retorno.
*/
void lerSup(FILE *arqlS, void *reg, int *lS, int nBytes, short int *ordem);

/*  void lerInf: 
        Ação: Lê nBytes do arquivo apontado por arqLI na posição lI*nBytes distante do início do arquivo, armazena os dados lidos em reg, incrementa lI e
altera ordem para 1.
        Argumentos:
            - FILE *arqLI - ponteiro para o arquivo onde será realizada a leitura.
            - void *reg - ponteiro da variável que armazenará os dados lidos.
            - int *lI - ponteiro para inteiro que indica a posição a ser lida.
            - int nBytes - variável que indica o tamanho dos registros.
            - short int *ordem - ponteiro para inteiro (short) que indica qual será a próxima leitura(1 para lerSup e 0 para lerInf).
        Retorno: Sem retorno.
*/
void lerInf(FILE *arqlI, void *reg, int *lI, int nBytes, short int *ordem);

/*  void escSup:
        Ação: Escreve nBytes da variável reg no arquivo apontado por arqES na posição eS*nBytes distante do início do arquivo e decrementa eS.
        Argumentos:
            - FILE *arqES - ponteiro para o arquivo onde será realizada a escrita.
            - void *reg - ponteiro da variável que terá seus dados escritos no arquivo.
            - int *eS - ponteiro para inteiro que indica a posição a ser escrita.
            - int nBytes - variável que indica o tamanho dos registros.
        Retorno: Sem retorno.
*/
void escSup(FILE *arqES, void *reg, int *eS, int nBytes);

/*  void escInf: 
        Ação: Escreve nBytes da variável reg no arquivo apontado por arqEI na posição eI*nBytes distante do início do arquivo e incrementa eI.
        Argumentos:
            - FILE *arqEI - ponteiro para o arquivo onde será realizada a escrita.
            - void *reg - ponteiro da variável que terá seus dados escritos no arquivo.
            - int *eI - ponteiro para inteiro que indica a posição a ser escrita.
            - int nBytes - variável que indica o tamanho dos registros.
        Retorno: Sem retorno.
*/
void escInf(FILE *arqEI, void *reg, int *eI, int nBytes);

/*  void inserirArea:
        Ação: Insere a variável reg de forma ordenada na área da memória primária apontada por area e incrementa areaOcupada.
        Argumentos:
            - void *area - ponteiro da área da memória primária.
            - int *areaOcupada - ponteiro para inteiro da variável que armazena a area ocupada da memória primária.
            - void *reg - ponteiro da variável que será armazenada na área.
            - int nBytes - variável que indica o tamanho dos registros.
            - int(*comp)(void*,void*) - ponteiro para a função de comparação.
        Retorno: Sem retorno.
*/
void inserirArea(void *area, int *areaOcupada, void *reg, int nBytes, int(*comp)(void*,void*));

/*  void rmvPrimeiroArea:
        Ação: Remove o primeiro elemento armazenado na área da memória primária apontada por area e decrementa areaOcupada.
        Argumentos:
            - void *area - ponteiro da área da memória primária.
            - int *areaOcupada - ponteiro para inteiro da variável que armazena a area ocupada da memória primária.
            - int nBytes - variável que indica o tamanho dos registros.
        Retorno: Sem retorno.
*/
void rmvPrimeiroArea(void *area, int *areaOcupada, int nBytes);

/*  void particao:
        Ação: Particiona o arquivo apontado por arq em três subarquivo:
        área 1 - Registros com o valor menor ou igual que o registro com o menor valor da área 2.
        área 2 - Registros ordenados.
        área 3 - Registros com o valor maior ou igual que o registro com o maior valor da área 2.
        Argumentos:
            - FILE *arq - ponteiro para o arquivo a ser particionado.
            - int inicio - inteiro que indica o primeiro elemento do vetor a ser particionado.
            - int fim - inteiro que indica o último elemento do vetor a ser particionado.
            - int *i - ponteiro para inteiro que indica o início da área 2.
            - int *j - ponteiro para inteiro que indica o fim da área 2.
            - int tamArea - inteiro que indica o tamanho da área na memória principal.
            - int nBytes - variável que indica o tamanho dos registros.
            - int(*comp)(void*,void*) - ponteiro para a função de comparação.
        Retorno: 0 se a partição for concluída com sucesso.
                -1 se houver falha na alocação de memória primária.
*/
int particao(FILE *arq,int inicio, int fim, int *i, int *j, int tamArea, int nBytes, int(*comp)(void*,void*));

/*  void quickSortExterno:
        Ação: Ordena os registros do arquivo apontado por arq.
        Argumentos:
            - FILE *arq - ponteiro para o arquivo a ser ordenado.
            - int inicio - inteiro que indica o primeiro registro do arquivo a ser ordenado.
            - int fim - inteiro que indica o último registro do arquivo a ser ordenado.
            - int tamArea - inteiro que indica o tamanho da área na memória primária.
            - int nBytes - variável que indica o tamanho dos registros.
            - int(*comp)(void*,void*) - ponteiro para a função de comparação.
        Retorno: 0 se a chamada recursiva for concluída com sucesso.
                -1 se houver falha na alocação de memória primária.
*/
int quickSortExterno(FILE *arq, int inicio, int fim, int tamArea, int nBytes, int (comp)(void*,void*));

#endif
