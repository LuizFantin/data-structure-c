#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

//1) Inicialização e Liberação de uma lista

// 1.a) função que aloca memória para uma lista, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma lista
List *createList()
{
    List *ptr;
    if(ptr=(List *)malloc(sizeof(List))){
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

//1.d) função que libera todo o espaço de memória espaço de memória usado por uma lista
//		Entrada: ponteiro para uma lista
//		Saída: void

void freeList(List *lst)
{
    Node *ptr;
    if (!lst) return;
    while(lst->first)
    {
        ptr=lst->first->next;
        free(lst->first->info);
        free(lst->first);
        lst->first=ptr;
    }
    free(lst);
}




//2) Informações sobre lista

// 2.a) Função que verifica se uma list é vazia
//		Entrada: ponteiro para uma lista
//		Saída: bool (TRUE se a lista é vazia, FALSE caso contrário

bool isEmptyList(List * lst)
{
    return (!lst || lst->size==0);
}

// 2.b) Função que Imprime o conteudo da lista
//		Entrada: ponteiro para uma lista
//		Saída: bool (TRUE se a lista é vazia, FALSE caso contrário
void printList(List *lst) {

    Node *ptr;

    if(isEmptyList(lst)) return;
    printf("\n[ ");
    ptr=lst->first;

    //inicia do primeiro elemento da lista
    while(ptr != NULL)
    {
      printf("(%d) ",ptr->info->value);
      ptr = ptr->next;
    }
	printf(" ]");
}

// 2.c) Função que verifica o tamanho da lista
//		Entrada: ponteiro para uma lista
//		Saída: inteiro >=0 representando o tamanho da lista, -1 caso a lista seja nula
int lengthList(List *lst)
{
	if (!lst) return -1;
	return lst->size;
}

// 2.d) Função que encontra um elemento na lista
//		Entrada: ponteiro para uma lista
//		Saída: ponteiro para Info com o elemento encontrado, NULL caso contrário
Info* findList(List *lst, Info *inf) {

	Node *ptr;
	//if list is empty
	if(isEmptyList(lst)) return NULL;
	ptr=lst->first;
   //navigate through list
   while(ptr->info->value!=inf->value) {

      //if it is last node
      if(ptr->next == NULL) {
         return NULL;
      } else {
         //go to next link
         ptr=ptr->next;
      }
   }

   //if data found, return the current Link
   return ptr->info;
}

// 2.e) Função que encontra a posição de um elemento na lista
//		Entrada: ponteiro para uma lista
//		Saída: 	-inteiro maior que 0 (Zero) que representa a posição do elemento na lista.
//				-0 (Zero) caso o elemento não se encontre
int posList(List *lst, Info *inf)
{
	int pos;
	Node *ptr;
	if (isEmptyList(lst)) return 0;
	pos=1;
	ptr=lst->first;
	while(ptr!=NULL)
	{
		if(ptr->info->value==inf->value)return pos;
		pos++;
		ptr=ptr->next;
	}
	return 0;
}

// 2.f) Função verifica se um elemento está presente na lista
//		Entrada: ponteiro para uma lista
//		Saída: 	- inteiro maior que 0 (Zero) caso o elemento esteja presente na lista
//				-0 (Zero) caso contrário
int isInList(List *lst, Info *inf)
{
	return posList(lst,inf);
}


//3) Operações sobre lista

// 3.a) Função que insere um elemento na primeira posição da lista
//		Entrada: ponteiro para uma lista não nula
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário

bool insertFirstList(List *lst, Info *inf)
{
    Node *ptr;
    if(!lst || !(ptr=createNode())) return false;
    ptr->info=inf;
    ptr->next=lst->first;
    lst->first=ptr;
    lst->size++;
    return true;
}

// 3.b) Função que insere um elemento na última posição da lista
//		Entrada: ponteiro para uma lista
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário

bool insertLastList(List *lst, Info *inf)
{
    Node *ptr, *aux;
    if(!lst || !(ptr=createNode())) return false;
    ptr->info=inf;
    
    if(lst->first==NULL)
    {
    	lst->first=ptr;
    }
    else
	{
		aux=lst->first;
		while(aux->next!=NULL) aux=aux->next;
		aux->next=ptr;
	}
	lst->size++;
    return true;
}


// 3.c) Função que deleta o elemento da primeira posição da lista
//		Entrada: ponteiro para uma lista
//		Saída: ponteiro para Info com o elemento deletado
Info *deleteFirstList(List *lst) {

  Node *ptr;
  Info *inf;
  if (isEmptyList(lst)) return NULL;
  ptr=lst->first;
  lst->first=ptr->next;
  inf=ptr->info;
  free(ptr);
  lst->size--;
  return inf;
}

// 3.d) Função que deleta o elemento da lista
//		Entrada: ponteiro para uma lista e um ponteiro para Info representando o elemento a ser deletado
//		Saída: ponteiro para Info com o elemento deletado
Info* deleteInfoList(List *lst, Info *inf) {

	Node *ptr, *pptr;
	Info *auxInf;
	//if list is empty
	if (isEmptyList(lst)) return NULL;

	ptr=lst->first;
   //navigate through list
   while(ptr->info->value != auxInf->value) {

      //if it is last node
      if(ptr->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         pptr = ptr;
         //move to next link
         ptr = ptr->next;
      }
   }

   //found a match, update the link
   if(ptr == lst->first) {
      //change first to point to next link
      lst->first = ptr->next;
   } else {
      //bypass the current link
      pptr->next = ptr->next;
   }
	auxInf=ptr->info;
	free(ptr);
	lst->size--;
   	return auxInf;
}

// 3.e) Função que deleta o elemento de uma posição específica da lista
//		Entrada: ponteiro para uma lista e um inteiro indicando a posição do elemento a ser deletado
//		Saída: ponteiro para Info com o elemento deletado
Info* deletePositionList(List *lst, int pos)
{
	Node *pptr,*ptr;
	Info *inf;
	int cont=1;

	if (isEmptyList(lst) || pos>lst->size || pos<=0){
		printf("\nImpossivel retirar elemento!\n");
		return NULL;
	}
	if(pos==1)
	{
		ptr=lst->first;
		lst->first=ptr->next;
	} 
	else
	{
		pptr=lst->first;
		for(cont=1;cont<pos-1;cont++,pptr=pptr->next);	
		ptr=pptr->next;
		pptr->next=ptr->next;
	}
	inf=ptr->info;
	free(ptr);
	lst->size--;
	return inf;
}

// 3.f) Função que inverte uma lista
//		Entrada: ponteiro para uma lista
//		Saída: void.
void reverseList(List *lst) {

   Node *prev= NULL;
   Node *current = lst->first;
   Node *next;

   if (isEmptyList(lst)) return;

   while (current != NULL) {
      next  = current->next;
      current->next = prev;
      prev = current;
      current = next;
   }

   lst->first=prev;
}

// 3.g) Função que ordena crescente uma lista
//		Entrada: ponteiro para uma lista
//		Saída: void.
void sortList(List *lst) {

   int i, j, k;
   Info *tempInfo;
   Node *current;
   Node *next;

	k = lst->size ;
	if (isEmptyList(lst)) return;

	for ( i = 0 ; i < (lst->size-1); i++, k-- )
	{
      current = lst->first;
      next=lst->first->next;
      for ( j = 1 ; j < k ; j++ )
	  {
         if ( current->info->value> next->info->value ) {
            tempInfo = current->info;
            current->info = next->info;
            next->info = tempInfo;
         }
         current = current->next;
         next = next->next;
      }
   }
}
// 3.h) Função que deleta o elemento da última posição da lista
//		Entrada: ponteiro para uma lista
//		Saída: ponteiro para Info com o elemento deletado
Info *deleteLastList(List *lst) {

  Node *ptr,*pptr;
  Info *inf;
  if (isEmptyList(lst)) return NULL;
  ptr=lst->first;
  if(lst->size==1){
  	
  	lst->first=ptr->next;
  }
  else
  {
  	pptr=ptr;
  	ptr=ptr->next;
  	while(ptr->next!=NULL)
	{
  		pptr=ptr;
  		ptr=ptr->next;
	}
	pptr->next=ptr->next;
  }
  inf=ptr->info;
  free(ptr);
  lst->size--;
  return inf;
}

