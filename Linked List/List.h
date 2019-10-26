#ifndef __LIST_H__
#define __LIST_H__

// Defini��o da Estrutura de Dados Lista Ligada

typedef struct
{
	int value;
}Info;
typedef struct tnode
{
	struct tnode *next;
	Info *info;
}Node;
typedef struct
{
	int size;
	Node *first;
}List;

// Defini��o das assinaturas das fun��es sobre o TAD LISTA LIGADA

//1) Inicializa��o e Libera��o de uma lista

// 1.a) fun��o que aloca mem�ria para uma lista, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma lista
List *createList();
// 1.b) fun��o que aloca mem�ria para um no, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma Node
Node *createNode();
// 1.c) fun��o que aloca mem�ria para um elemento de informa��o Info, inicializando seus campos
//		Entrada: inteiro conte�do do elemento de informa��o
//		Sa�da: ponteiro para um Info
Info *createInfo(int i);
//1.d) fun��o que libera todo o espa�o de mem�ria espa�o de mem�ria usado por uma lista
//		Entrada: ponteiro para uma lista
//		Sa�da: void
void freeList(List *lst);

//2) Informa��es sobre lista

// 2.a) Fun��o que verifica se uma list � vazia
//		Entrada: ponteiro para uma lista
//		Sa�da: bool (TRUE se a lista � vazia, FALSE caso contr�rio
bool isEmptyList(List * lst);

// 2.b) Fun��o que Imprime o conteudo da lista
//		Entrada: ponteiro para uma lista
//		Sa�da: bool (TRUE se a lista � vazia, FALSE caso contr�rio
void printList(List *lst);

// 2.c) Fun��o que verifica o tamanho da lista
//		Entrada: ponteiro para uma lista
//		Sa�da: inteiro >=0 representando o tamanho da lista, -1 caso a lista seja nula
int length(List *lst);

// 2.d) Fun��o que encontra um elemento na lista
//		Entrada: ponteiro para uma lista
//		Sa�da: ponteiro para Info com o elemento encontrado, NULL caso contr�rio
Info* find(List *lst, Info *inf);

// 2.e) Fun��o que encontra a posi��o de um elemento na lista
//		Entrada: ponteiro para uma lista
//		Sa�da: 	-inteiro maior que 0 (Zero) que representa a posi��o do elemento na lista.
//				-0 (Zero) caso o elemento n�o se encontre
int posList(List *lst, Info *inf);

// 2.f) Fun��o verifica se um elemento est� presente na lista
//		Entrada: ponteiro para uma lista
//		Sa�da: 	- inteiro maior que 0 (Zero) caso o elemento esteja presente na lista
//				-0 (Zero) caso contr�rio
int isInList(List *lst, Info *inf);


//3) Opera��es sobre lista

// 3.a) Fun��o que insere um elemento na primeira posi��o da lista
//		Entrada: ponteiro para uma lista n�o nula
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio
bool insertFirst(List *lst, Info *inf);

// 3.b) Fun��o que insere um elemento na �ltima posi��o da lista
//		Entrada: ponteiro para uma lista
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio
bool insertLast(List *lst, Info *inf);

// 3.c) Fun��o que deleta o elemento da primeira posi��o da lista
//		Entrada: ponteiro para uma lista
//		Sa�da: ponteiro para Info com o elemento deletado
Info *deleteFirst(List *lst);

// 3.d) Fun��o que deleta o elemento da lista
//		Entrada: ponteiro para uma lista e um ponteiro para Info representando o elemento a ser deletado
//		Sa�da: ponteiro para Info com o elemento deletado
Info *deleteInfo(List *lst, Info *inf);

// 3.e) Fun��o que deleta o elemento de uma posi��o espec�fica da lista
//		Entrada: ponteiro para uma lista e um inteiro indicando a posi��o do elemento a ser deletado
//		Sa�da: ponteiro para Info com o elemento deletado
Info* deletePosition(List *lst, int pos);

// 3.f) Fun��o que inverte uma lista
//		Entrada: ponteiro para uma lista
//		Sa�da: void.
void reverseList(List *lst);

// 3.g) Fun��o que ordena crescente uma lista
//		Entrada: ponteiro para uma lista
//		Sa�da: void.
void sortList(List *lst);

// 3.h) Fun��o que deleta o elemento da primeira posi��o da lista
//		Entrada: ponteiro para uma lista
//		Sa�da: ponteiro para Info com o elemento deletado
Info *deleteLast(List *lst);

#endif // __LIST_H__
