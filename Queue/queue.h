#ifndef __QUEUE_H__
#define __QUEUE_H__

// Defini��o da Estrutura de Dados FILA

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
	Node *first,*last;
}Queue;

// Defini��o das assinaturas das fun��es sobre o TAD FILA

//1) Inicializa��o e Libera��o de uma Fila

// 1.a) fun��o que aloca mem�ria para uma Fila, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma lista
Queue *createQueue();

// 1.b) fun��o que aloca mem�ria para um no, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma Node
Node *createNode();

// 1.c) fun��o que aloca mem�ria para um elemento de informa��o Info, inicializando seus campos
//		Entrada: inteiro conte�do do elemento de informa��o
//		Sa�da: ponteiro para um Info
Info *createInfo(int i);

//1.d) fun��o que libera todo o espa�o de mem�ria usado por uma Fila
//		Entrada: ponteiro para uma fila
//		Sa�da: void
void freeQueue(Queue *queue);

//2) Informa��es sobre Fila

// 2.a) Fun��o que verifica se uma Fila � vazia
//		Entrada: ponteiro para uma Fila
//		Sa�da: bool (TRUE se a Fila � vazia, FALSE caso contr�rio
bool isEmptyQueue(Queue * queue);

// 2.b) Fun��o que Imprime o conteudo da Fila
//		Entrada: ponteiro para uma fila
//		Sa�da: bool (TRUE se a fila � vazia, FALSE caso contr�rio
void printQueue(Queue *queue);

// 2.c) Fun��o que verifica o tamanho da Fila
//		Entrada: ponteiro para uma fila
//		Sa�da: inteiro >=0 representando o tamanho da fila, -1 caso a fila seja nula
int lengthQueue(Queue *queue);

//3) Opera��es sobre Fila

// 3.c) Fun��o que insere um elemento da fila (na �ltima posi��o)
//		Entrada: ponteiro para uma fila
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio
bool insertQueue(Queue *queue, Info *inf);

// 3.c) Fun��o que retira um elemento da fila (da primeira posi��o)
//		Entrada: ponteiro para uma fila
//		Sa�da: ponteiro para Info com o elemento retirado
Info *removeQueue(Queue *queue);


#endif // __QUEUE_H__
