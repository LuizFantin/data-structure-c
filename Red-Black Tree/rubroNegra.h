

#ifndef _H_RUBRONEGRA
#define _H_RUBRONEGRA

/*Declara��o das bibliotecas*/
#include<stdio.h>
#include<stdlib.h>

/*Defini��o das cores*/
#define RUBRO 1
#define NEGRO 0

/*Estrutura de um n�*/
typedef struct node{
    void *chave;
    int cor;
    struct node *esq, *dir, *pai;
}RN;

/*Estrutura de uma �rvore*/
typedef struct tnode{
    RN *raiz;
    RN *sentinela;
}arvore;


/* funcao: RN *nodeRN()
   *  acao:        funcao que cria um novo no o qual dever� ser inserido na �rvore
   *  entrada:     elemento de informa��o do novo n�
   *  saida:       ponteiro para um n�
*/
RN *nodeRN(void *inf, arvore *T);

/* funcao: RN *nodeSentinela()
   *  acao:        funcao que cria o n� sentinela
   *  entrada:     void
   *  saida:       ponteiro para um n� sentinela
*/
RN *nodeSentinela();

/* funcao: arvore *criaArvore()
   *  acao:        funcao que cria uma nova �rvore (estrutura que aponta para a raiz
                   de uma arvore RN bem como para o n� sentinela)
   *  entrada:     void
   *  saida:       ponteiro para uma arvore
*/
arvore *criaArvore();

/* funcao: void rotEsq(arvore *T, RN *x)
   *  acao:        funcao que realiza rota��o esquerda sobre uma �rvore
   *  entrada:     ponteiro para a arvore e ponteiro para um n�
   *  saida:       void
*/
void rotEsq(arvore *T, RN *x);

/* funcao: void rotDir(arvore *T, RN *x)
   *  acao:        funcao que realiza rota��o direita sobre uma �rvore
   *  entrada:     ponteiro para a arvore e ponteiro para um n�
   *  saida:       void
*/
void rotDir(arvore *T, RN *x);

/* funcao: RN *buscaRN(arvore *T, RN *z, int chave)
   *  acao:        funcao que busca por um n� na �rvore
   *  entrada:     ponteiro para a arvore e ponteiro para um n�
   *  saida:       ponteiro para um n�
*/
RN *buscaRN(arvore *T, RN *z, void *chave, int (*compara)(void*, void*));

/* funcao: void consertaInsertRN(arvore *T, RN *z)
   *  acao:        fun��o que avalia e reestabelece as propriedades da �rvore RN para o n� inserido
   *  entrada:     ponteiro para a arvore e ponteiro para um n�
   *  saida:       void
*/
void consertaInsertRN(arvore *T, RN *z);

/* funcao: void insertRN(arvore *T, int inf)
   *  acao:        funcao que insere um novo n� na �rvore
   *  entrada:     ponteiro para a arvore eelemento de informa��o a ser inserido
   *  saida:       void
*/
void insertRN(arvore *T, void *inf, int (*compara)(void*, void*));

/* funcao: void transplantRN(arvore *T, RN *u, RN *v)
   *  acao:        funcao que realiza os reapontamentos necess�rios na remo��o de determinado n�
   *  entrada:     ponteiro para a arvore e ponteiros para dois n�s distintos
   *  saida:       void
*/
void transplantRN(arvore *T, RN *u, RN *v);

/* funcao: RN *menor(arvore *T, RN *x)
   *  acao:        funcao que busca o sucessor de um n�
                   (sucessor = filho mais a esquerda da sub�rvore direita de determinada �rvore)
   *  entrada:     ponteiro para a arvore e ponteiro para um n�
   *  saida:       ponteiro para um n�
*/
RN *menor(arvore *T, RN *x);

/* funcao: void consertaDeleteRN(arvore *T,RN *x)
   *  acao:        fun��o que avalia e reestabelece as propriedades da �rvore RN para o n� inserido
   *  entrada:     ponteiro para a arvore e ponteiro para um n�
   *  saida:       void
*/
void consertaDeleteRN(arvore *T,RN *x);

/* funcao: void deleteRN(arvore *T, int inf)
   *  acao:        funcao que remove um n� da �rvore
   *  entrada:     ponteiro para a arvore e elemento de informa��o a ser removido
   *  saida:       void
*/
void deleteRN(arvore *T, void *inf, int (*compara)(void*, void*));

#endif // RNH
