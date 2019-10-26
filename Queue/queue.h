#ifndef __QUEUE_H__
#define __QUEUE_H__

// Definição da Estrutura de Dados FILA

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

// Definição das assinaturas das funções sobre o TAD FILA

//1) Inicialização e Liberação de uma Fila

// 1.a) função que aloca memória para uma Fila, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma lista
Queue *createQueue();

// 1.b) função que aloca memória para um no, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma Node
Node *createNode();

// 1.c) função que aloca memória para um elemento de informação Info, inicializando seus campos
//		Entrada: inteiro conteúdo do elemento de informação
//		Saída: ponteiro para um Info
Info *createInfo(int i);

//1.d) função que libera todo o espaço de memória usado por uma Fila
//		Entrada: ponteiro para uma fila
//		Saída: void
void freeQueue(Queue *queue);

//2) Informações sobre Fila

// 2.a) Função que verifica se uma Fila é vazia
//		Entrada: ponteiro para uma Fila
//		Saída: bool (TRUE se a Fila é vazia, FALSE caso contrário
bool isEmptyQueue(Queue * queue);

// 2.b) Função que Imprime o conteudo da Fila
//		Entrada: ponteiro para uma fila
//		Saída: bool (TRUE se a fila é vazia, FALSE caso contrário
void printQueue(Queue *queue);

// 2.c) Função que verifica o tamanho da Fila
//		Entrada: ponteiro para uma fila
//		Saída: inteiro >=0 representando o tamanho da fila, -1 caso a fila seja nula
int lengthQueue(Queue *queue);

//3) Operações sobre Fila

// 3.c) Função que insere um elemento da fila (na última posição)
//		Entrada: ponteiro para uma fila
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário
bool insertQueue(Queue *queue, Info *inf);

// 3.c) Função que retira um elemento da fila (da primeira posição)
//		Entrada: ponteiro para uma fila
//		Saída: ponteiro para Info com o elemento retirado
Info *removeQueue(Queue *queue);


#endif // __QUEUE_H__
