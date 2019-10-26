#ifndef __STACK_H__
#define __STACK_H__

// Definição da Estrutura de Dados PILHA

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
}Stack;

// Definição das assinaturas das funções sobre o TAD PILHA

//1) Inicialização e Liberação de uma Pilha

// 1.a) função que aloca memória para uma Pilha, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma pilha
Stack *createStack();

// 1.b) função que aloca memória para um no, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma Node
Node *createNode();

// 1.c) função que aloca memória para um elemento de informação Info, inicializando seus campos
//		Entrada: inteiro conteúdo do elemento de informação
//		Saída: ponteiro para um Info
Info *createInfo(int i);

//1.d) função que libera todo o espaço de memória usado por uma Pilha
//		Entrada: ponteiro para uma Pilha
//		Saída: void
void freeStack(Stack *stack);

//2) Informações sobre Pilha

// 2.a) Função que verifica se uma Pilha é vazia
//		Entrada: ponteiro para uma Pilha
//		Saída: bool (TRUE se a Pilha é vazia, FALSE caso contrário
bool isEmptyStack(Stack * stack);

// 2.b) Função que Imprime o conteudo da Pilha
//		Entrada: ponteiro para uma Pilha
//		Saída: bool (TRUE se a Pilha é vazia, FALSE caso contrário
void printStack(Stack *stack);

// 2.c) Função que verifica o tamanho da Pilha
//		Entrada: ponteiro para uma Pilha
//		Saída: inteiro >=0 representando o tamanho da Pilha, -1 caso a Pilha seja nula
int lengthStack(Stack *stack);

//3) Operações sobre Pilha

// 3.c) Função que insere um elemento da Pilha (na primeira posição)
//		Entrada: ponteiro para uma Pilha
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário
bool push(Stack *stack, Info *inf);

// 3.c) Função que retira um elemento da Pilha (da primeira posição)
//		Entrada: ponteiro para uma Pilha
//		Saída: ponteiro para Info com o elemento retirado
Info *pop(Stack *stack);


#endif // __STACK_H__
