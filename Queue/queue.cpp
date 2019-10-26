#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

//1) Inicialização e Liberação de uma Fila

// 1.a) função que aloca memória para uma Fila, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma lista
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

// 1.b) função que aloca memória para um no, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma Node
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
// 1.c) função que aloca memória para um elemento de informação Info, inicializando seus campos
//		Entrada: inteiro conteúdo do elemento de informação
//		Saída: ponteiro para um Info
Info *createInfo(int i)
{
    Info *ptr;
    if(ptr=(Info *)malloc(sizeof(Info))){
        ptr->value=i;
        return ptr;
    }
    return NULL;
}

//1.d) função que libera todo o espaço de memória usado por uma Fila
//		Entrada: ponteiro para uma fila
//		Saída: void

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

//2) Informações sobre Fila

// 2.a) Função que verifica se uma Fila é vazia
//		Entrada: ponteiro para uma Fila
//		Saída: bool (TRUE se a Fila é vazia, FALSE caso contrário

bool isEmptyQueue(Queue * queue)
{
    return (!queue || queue->size==0);
}

// 2.b) Função que Imprime o conteudo da Fila
//		Entrada: ponteiro para uma fila
//		Saída: bool (TRUE se a fila é vazia, FALSE caso contrário
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

// 2.c) Função que verifica o tamanho da Fila
//		Entrada: ponteiro para uma fila
//		Saída: inteiro >=0 representando o tamanho da fila, -1 caso a fila seja nula
int lengthQueue(Queue *queue)
{
	if (!queue) return -1;
	return queue->size;
}

//3) Operações sobre Fila

// 3.c) Função que insere um elemento da fila (na última posição)
//		Entrada: ponteiro para uma fila
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário

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


// 3.c) Função que retira um elemento da fila (da primeira posição)
//		Entrada: ponteiro para uma fila
//		Saída: ponteiro para Info com o elemento retirado
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


