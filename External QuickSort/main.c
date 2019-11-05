/*Erika Barbosa Gomes
  Everson Henrich da Silva
  Luiz Fantin Neto
  Milena Tavares Roas */

#include "quickSortExt.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    int matricula;
    char nome[20];
}Aluno;


int comparaMat(void *a, void *b)
{
    Aluno* elemento1 = (Aluno*)a;
    Aluno* elemento2 = (Aluno*)b;
    
    if(elemento1->matricula == elemento2->matricula)
        return 0;
    else if(elemento1->matricula > elemento2->matricula)
        return 1;
    else
        return -1;
}

int comparaNome(void *a, void *b)
{
    Aluno* elemento1 = (Aluno*)a;
    Aluno* elemento2 = (Aluno*)b;

    return strcmp(elemento1->nome,elemento2->nome);
}


int gerarArquivoInt(FILE *arq, int nElem)
{
    int i = 0;
    char c;
    Aluno *value = (Aluno*)calloc(nElem, sizeof(Aluno));

    srand(time(NULL));
    rewind(arq);

    for(i = 0; i < nElem; i++)
    {
        value[i].matricula = rand()%1000;
    }
    return fwrite(value, sizeof(Aluno), nElem, arq);
}



int main()
{
    FILE *arq = fopen("test1.bin", "wb+");
    Aluno value;
    int li = 0;
    int i = 0;
    int j = 0;
    short int o = 0;

    printf("%d valores gerados.\n", gerarArquivoInt(arq, 50));
    printf("Arquivo antes do quickSortExterno\n");

    while(li < 50)
    {
        lerInf(arq, (void*)(&value), &li, sizeof(Aluno), &o);
        printf("%d - \t%d\n", li, value.matricula);
    }

    quickSortExterno(arq, 0, 49, 15, sizeof(Aluno), comparaMat);

    li = 0;
    printf("==========================\n");
    printf("Arquivo apos quickSortExterno\n");

    while(li < 50)
    {
        lerInf(arq, (void*)(&value), &li, sizeof(Aluno), &o);
        printf("%d - \t%d\n", li, value.matricula);
    }
    
    return 0;
}