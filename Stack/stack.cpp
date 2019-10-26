#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

//1) Inicialização e Liberação de uma Pilha

// 1.a) função que aloca memória para uma Pilha, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma pilha
Stack *createStack()
{
    Stack *ptr;
    if(ptr=(Stack *)malloc(sizeof(Stack))){
        ptr->size=0;
        ptr->first=NULL;
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

//1.d) função que libera todo o espaço de memória usado por uma Pilha
//		Entrada: ponteiro para uma Pilha
//		Saída: void
void freeStack(Stack *stack)
{
    Node *ptr;
    if (!stack) return;
    while(stack->first)
    {
        ptr=stack->first->next;
        free(stack->first->info);
        free(stack->first);
        stack->first=ptr;
    }
    free(stack);
}


//2) Informações sobre Pilha

// 2.a) Função que verifica se uma Pilha é vazia
//		Entrada: ponteiro para uma Pilha
//		Saída: bool (TRUE se a Pilha é vazia, FALSE caso contrário
bool isEmptyStack(Stack * stack)
{
    return (!stack || stack->size==0);
}

// 2.b) Função que Imprime o conteudo da Pilha
//		Entrada: ponteiro para uma Pilha
//		Saída: bool (TRUE se a Pilha é vazia, FALSE caso contrário
void printStack(Stack *stack)
{

    Node *ptr;

    if(isEmptyStack(stack)) return;
    printf("\n TOP[ ");
    ptr=stack->first;

    //inicia do primeiro elemento da lista
    while(ptr != NULL)
    {
      printf("(%d) ",ptr->info->value);
      ptr = ptr->next;
    }
	printf(" ]BOTTOM");
}

// 2.c) Função que verifica o tamanho da Pilha
//		Entrada: ponteiro para uma Pilha
//		Saída: inteiro >=0 representando o tamanho da Pilha, -1 caso a Pilha seja nula
int lengthStack(Stack *stack)
{
	if (!stack) return -1;
	return stack->size;
}

//3) Operações sobre Pilha

// 3.a) Função que insere um elemento da Pilha (na primeira posição)
//		Entrada: ponteiro para uma Pilha
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário
bool push(Stack *stack, Info *inf)
{
	Node *ptr;
    if(!stack || !(ptr=createNode())) return false;
    ptr->info=inf;
    ptr->next=stack->first;
    stack->first=ptr;
    stack->size++;
    return true;
}

// 3.b) Função que retira um elemento da Pilha (da primeira posição)
//		Entrada: ponteiro para uma Pilha
//		Saída: ponteiro para Info com o elemento retirado
Info *pop(Stack *stack)
{
	Node *ptr;
  	Info *inf;
	if (isEmptyStack(stack)) return NULL;
	ptr=stack->first;
	stack->first=ptr->next;
  	inf=ptr->info;
  	free(ptr);
  	stack->size--;
  	return inf;
}

