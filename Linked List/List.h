#ifndef __LIST_H__
#define __LIST_H__

// Definição da Estrutura de Dados Lista Ligada

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

// Definição das assinaturas das funções sobre o TAD LISTA LIGADA

//1) Inicialização e Liberação de uma lista

// 1.a) função que aloca memória para uma lista, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma lista
List *createList();
// 1.b) função que aloca memória para um no, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma Node
Node *createNode();
// 1.c) função que aloca memória para um elemento de informação Info, inicializando seus campos
//		Entrada: inteiro conteúdo do elemento de informação
//		Saída: ponteiro para um Info
Info *createInfo(int i);
//1.d) função que libera todo o espaço de memória espaço de memória usado por uma lista
//		Entrada: ponteiro para uma lista
//		Saída: void
void freeList(List *lst);

//2) Informações sobre lista

// 2.a) Função que verifica se uma list é vazia
//		Entrada: ponteiro para uma lista
//		Saída: bool (TRUE se a lista é vazia, FALSE caso contrário
bool isEmptyList(List * lst);

// 2.b) Função que Imprime o conteudo da lista
//		Entrada: ponteiro para uma lista
//		Saída: bool (TRUE se a lista é vazia, FALSE caso contrário
void printList(List *lst);

// 2.c) Função que verifica o tamanho da lista
//		Entrada: ponteiro para uma lista
//		Saída: inteiro >=0 representando o tamanho da lista, -1 caso a lista seja nula
int length(List *lst);

// 2.d) Função que encontra um elemento na lista
//		Entrada: ponteiro para uma lista
//		Saída: ponteiro para Info com o elemento encontrado, NULL caso contrário
Info* find(List *lst, Info *inf);

// 2.e) Função que encontra a posição de um elemento na lista
//		Entrada: ponteiro para uma lista
//		Saída: 	-inteiro maior que 0 (Zero) que representa a posição do elemento na lista.
//				-0 (Zero) caso o elemento não se encontre
int posList(List *lst, Info *inf);

// 2.f) Função verifica se um elemento está presente na lista
//		Entrada: ponteiro para uma lista
//		Saída: 	- inteiro maior que 0 (Zero) caso o elemento esteja presente na lista
//				-0 (Zero) caso contrário
int isInList(List *lst, Info *inf);


//3) Operações sobre lista

// 3.a) Função que insere um elemento na primeira posição da lista
//		Entrada: ponteiro para uma lista não nula
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário
bool insertFirst(List *lst, Info *inf);

// 3.b) Função que insere um elemento na última posição da lista
//		Entrada: ponteiro para uma lista
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário
bool insertLast(List *lst, Info *inf);

// 3.c) Função que deleta o elemento da primeira posição da lista
//		Entrada: ponteiro para uma lista
//		Saída: ponteiro para Info com o elemento deletado
Info *deleteFirst(List *lst);

// 3.d) Função que deleta o elemento da lista
//		Entrada: ponteiro para uma lista e um ponteiro para Info representando o elemento a ser deletado
//		Saída: ponteiro para Info com o elemento deletado
Info *deleteInfo(List *lst, Info *inf);

// 3.e) Função que deleta o elemento de uma posição específica da lista
//		Entrada: ponteiro para uma lista e um inteiro indicando a posição do elemento a ser deletado
//		Saída: ponteiro para Info com o elemento deletado
Info* deletePosition(List *lst, int pos);

// 3.f) Função que inverte uma lista
//		Entrada: ponteiro para uma lista
//		Saída: void.
void reverseList(List *lst);

// 3.g) Função que ordena crescente uma lista
//		Entrada: ponteiro para uma lista
//		Saída: void.
void sortList(List *lst);

// 3.h) Função que deleta o elemento da primeira posição da lista
//		Entrada: ponteiro para uma lista
//		Saída: ponteiro para Info com o elemento deletado
Info *deleteLast(List *lst);

#endif // __LIST_H__
