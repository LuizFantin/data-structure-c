#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>


void lerSup(FILE *arqLS, int *reg, int *lS, int nBytes, short int *ordem);
void lerInf(FILE *arqLI, int *reg, int *lI, int nBytes, short int *ordem);
void escSup(FILE *arqES, int *reg, int *eS, int nBytes);
void escInf(FILE *arqEI, int *reg, int *eI, int nBytes);
void inserirArea(int *reg, int *area, int *areaOcupada);
void removerPrimArea(int *area, int *areaOcupada);
int particao(FILE *arq,int inicio, int fim, int *i, int*j, int tamArea);
