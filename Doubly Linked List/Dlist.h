#ifndef __DLIST_H__
#define __DLIST_H__

// Definição da Estrutura de Dados Lista Duplamente Ligada

typedef struct
{
	int value;
}Info;
typedef struct tnode
{
	struct tnode *next, *prev;
	Info *info;
}Node;
typedef struct
{
	int size;
	Node *first;
}DList;

//1) Inicialização e Liberação de uma Lista Dupla Dupla

// 1.a) função que aloca memória para uma Lista Dupla Dupla, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma Lista Dupla Dupla
DList *createDList();

// 1.b) função que aloca memória para um no, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma Node
Node *createNode();

// 1.c) função que aloca memória para um elemento de informação Info, inicializando seus campos
//		Entrada: inteiro conteúdo do elemento de informação
//		Saída: ponteiro para um Info
Info *createInfo(int i);

//1.d) função que libera todo o espaço de memória espaço de memória usado por uma Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: void

void freeDList(DList *lst);

//2) Informações sobre Lista Dupla

// 2.a) Função que verifica se uma lista Dupla é vazia
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: bool (TRUE se a Lista Dupla é vazia, FALSE caso contrário

bool isEmptyDList(DList * lst);

// 2.b) Função que Imprime o conteudo da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: void
void printDList(DList *lst);

// 2.c) Função que verifica o tamanho da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: inteiro >=0 representando o tamanho da Lista Dupla, -1 caso a Lista Dupla seja nula
int lengthDList(DList *lst);

// 2.d) Função que encontra um elemento na Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: ponteiro para Info com o elemento encontrado, NULL caso contrário
Info* findDList(DList *lst, Info *inf);

// 2.e) Função que encontra a posição de um elemento na Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: 	-inteiro maior que 0 (Zero) que representa a posição do elemento na Lista Dupla.
//				-0 (Zero) caso o elemento não se encontre
int posDList(DList *lst, Info *inf);

// 2.f) Função verifica se um elemento está presente na Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: 	- inteiro maior que 0 (Zero) caso o elemento esteja presente na Lista Dupla
//				-0 (Zero) caso contrário
int isInDList(DList *lst, Info *inf);


//3) Operações sobre Lista Dupla

// 3.a) Função que insere um elemento na primeira posição da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla não nula
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário

bool insertFirstDList(DList *lst, Info *inf);

// 3.b) Função que insere um elemento na última posição da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário

bool insertLastDList(DList *lst, Info *inf);

// 3.c) Função que insere um elemento de informação em uma posição da lista
//		Entrada: ponteiro para uma Lista Dupla (lst), elemento de informação (info) e a posição (pos)
//		na qual o elemento será inserido
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário)

bool insertPositionDList(DList *lst, Info *inf,int pos);

// 3.d) Função que deleta o elemento da primeira posição da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: ponteiro para Info com o elemento deletado
Info *deleteFirstDList(DList *lst);

// 3.e) Função que deleta o elemento da última posição da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: ponteiro para Info com o elemento deletado
Info *deleteLastDList(DList *lst);

// 3.f) Função que deleta o elemento de uma posição específica da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla e um inteiro indicando a posição do elemento a ser deletado
//		Saída: ponteiro para Info com o elemento deletado

Info* deletePositionDList(DList *lst, int pos);

// 3.g) Função que deleta o elemento da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla e um ponteiro para Info representando o elemento a ser deletado
//		Saída: ponteiro para Info com o elemento deletado
Info* deleteInfoDList(DList *lst, Info *inf);

// 3.h) Função que inverte uma Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: void.
void reverseDList(DList *lst);

// 3.i) Função que ordena crescente uma Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: void.
void sortDList(DList *lst);

#endif // __LIST_H__
