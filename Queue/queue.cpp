#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

//1) Inicializa��o e Libera��o de uma Fila

// 1.a) fun��o que aloca mem�ria para uma Fila, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma lista
Queue *createQueue()
{
    Queue *ptr;
    if(ptr=(Queue *)malloc(sizeof(Queue))){
        ptr->size=0;
        ptr->first=ptr->last=NULL;
        return ptr;
    }
    return NULL;
}

// 1.b) fun��o que aloca mem�ria para um no, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma Node
Node *createNode()
{
    Node *ptr;
    if(ptr=(Node *)malloc(sizeof(Node))){
        ptr->info=NULL;
        ptr->next=NULL;
        return ptr;
    }
    return NULL;
}
// 1.c) fun��o que aloca mem�ria para um elemento de informa��o Info, inicializando seus campos
//		Entrada: inteiro conte�do do elemento de informa��o
//		Sa�da: ponteiro para um Info
Info *createInfo(int i)
{
    Info *ptr;
    if(ptr=(Info *)malloc(sizeof(Info))){
        ptr->value=i;
        return ptr;
    }
    return NULL;
}

//1.d) fun��o que libera todo o espa�o de mem�ria usado por uma Fila
//		Entrada: ponteiro para uma fila
//		Sa�da: void

void freeQueue(Queue *queue)
{
    Node *ptr;
    if (!queue) return;
    while(queue->first)
    {
        ptr=queue->first->next;
        free(queue->first->info);
        free(queue->first);
        queue->first=ptr;
    }
    free(queue);
}

//2) Informa��es sobre Fila

// 2.a) Fun��o que verifica se uma Fila � vazia
//		Entrada: ponteiro para uma Fila
//		Sa�da: bool (TRUE se a Fila � vazia, FALSE caso contr�rio

bool isEmptyQueue(Queue * queue)
{
    return (!queue || queue->size==0);
}

// 2.b) Fun��o que Imprime o conteudo da Fila
//		Entrada: ponteiro para uma fila
//		Sa�da: bool (TRUE se a fila � vazia, FALSE caso contr�rio
void printQueue(Queue *queue) {

    Node *ptr;

    if(isEmptyQueue(queue)) return;
    printf("\n[ ");
    ptr=queue->first;

    //inicia do primeiro elemento da lista
    while(ptr != NULL)
    {
      printf("(%d) ",ptr->info->value);
      ptr = ptr->next;
    }
	printf(" ]");
}

// 2.c) Fun��o que verifica o tamanho da Fila
//		Entrada: ponteiro para uma fila
//		Sa�da: inteiro >=0 representando o tamanho da fila, -1 caso a fila seja nula
int lengthQueue(Queue *queue)
{
	if (!queue) return -1;
	return queue->size;
}

//3) Opera��es sobre Fila

// 3.c) Fun��o que insere um elemento da fila (na �ltima posi��o)
//		Entrada: ponteiro para uma fila
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio

bool insertQueue(Queue *queue, Info *inf)
{
    Node *ptr;
    if(!queue || !(ptr=createNode())) return false;
    ptr->info=inf;
    ptr->next=NULL;
    if(lengthQueue(queue)==0){
    	queue->first=ptr;
    }else 
	{
		queue->last->next=ptr;
	}
	queue->last=ptr;
	queue->size++;
    return true;
}


// 3.c) Fun��o que retira um elemento da fila (da primeira posi��o)
//		Entrada: ponteiro para uma fila
//		Sa�da: ponteiro para Info com o elemento retirado
Info *removeQueue(Queue *queue) {

  Node *ptr;
  Info *inf;
  if (isEmptyQueue(queue)) return NULL;
  ptr=queue->first;
  queue->first=ptr->next;
  inf=ptr->info;
  free(ptr);
  queue->size--;
  return inf;
}


