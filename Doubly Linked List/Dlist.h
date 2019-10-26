#ifndef __DLIST_H__
#define __DLIST_H__

// Defini��o da Estrutura de Dados Lista Duplamente Ligada

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

//1) Inicializa��o e Libera��o de uma Lista Dupla Dupla

// 1.a) fun��o que aloca mem�ria para uma Lista Dupla Dupla, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma Lista Dupla Dupla
DList *createDList();

// 1.b) fun��o que aloca mem�ria para um no, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma Node
Node *createNode();

// 1.c) fun��o que aloca mem�ria para um elemento de informa��o Info, inicializando seus campos
//		Entrada: inteiro conte�do do elemento de informa��o
//		Sa�da: ponteiro para um Info
Info *createInfo(int i);

//1.d) fun��o que libera todo o espa�o de mem�ria espa�o de mem�ria usado por uma Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: void

void freeDList(DList *lst);

//2) Informa��es sobre Lista Dupla

// 2.a) Fun��o que verifica se uma lista Dupla � vazia
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: bool (TRUE se a Lista Dupla � vazia, FALSE caso contr�rio

bool isEmptyDList(DList * lst);

// 2.b) Fun��o que Imprime o conteudo da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: void
void printDList(DList *lst);

// 2.c) Fun��o que verifica o tamanho da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: inteiro >=0 representando o tamanho da Lista Dupla, -1 caso a Lista Dupla seja nula
int lengthDList(DList *lst);

// 2.d) Fun��o que encontra um elemento na Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: ponteiro para Info com o elemento encontrado, NULL caso contr�rio
Info* findDList(DList *lst, Info *inf);

// 2.e) Fun��o que encontra a posi��o de um elemento na Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: 	-inteiro maior que 0 (Zero) que representa a posi��o do elemento na Lista Dupla.
//				-0 (Zero) caso o elemento n�o se encontre
int posDList(DList *lst, Info *inf);

// 2.f) Fun��o verifica se um elemento est� presente na Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: 	- inteiro maior que 0 (Zero) caso o elemento esteja presente na Lista Dupla
//				-0 (Zero) caso contr�rio
int isInDList(DList *lst, Info *inf);


//3) Opera��es sobre Lista Dupla

// 3.a) Fun��o que insere um elemento na primeira posi��o da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla n�o nula
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio

bool insertFirstDList(DList *lst, Info *inf);

// 3.b) Fun��o que insere um elemento na �ltima posi��o da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio

bool insertLastDList(DList *lst, Info *inf);

// 3.c) Fun��o que insere um elemento de informa��o em uma posi��o da lista
//		Entrada: ponteiro para uma Lista Dupla (lst), elemento de informa��o (info) e a posi��o (pos)
//		na qual o elemento ser� inserido
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio)

bool insertPositionDList(DList *lst, Info *inf,int pos);

// 3.d) Fun��o que deleta o elemento da primeira posi��o da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: ponteiro para Info com o elemento deletado
Info *deleteFirstDList(DList *lst);

// 3.e) Fun��o que deleta o elemento da �ltima posi��o da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: ponteiro para Info com o elemento deletado
Info *deleteLastDList(DList *lst);

// 3.f) Fun��o que deleta o elemento de uma posi��o espec�fica da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla e um inteiro indicando a posi��o do elemento a ser deletado
//		Sa�da: ponteiro para Info com o elemento deletado

Info* deletePositionDList(DList *lst, int pos);

// 3.g) Fun��o que deleta o elemento da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla e um ponteiro para Info representando o elemento a ser deletado
//		Sa�da: ponteiro para Info com o elemento deletado
Info* deleteInfoDList(DList *lst, Info *inf);

// 3.h) Fun��o que inverte uma Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: void.
void reverseDList(DList *lst);

// 3.i) Fun��o que ordena crescente uma Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: void.
void sortDList(DList *lst);

#endif // __LIST_H__
