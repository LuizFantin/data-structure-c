#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DList.h"

//1) Inicialização e Liberação de uma Lista Dupla Dupla

// 1.a) função que aloca memória para uma Lista Dupla Dupla, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma Lista Dupla Dupla
DList *createDList()
{
    DList *ptr;
    if(ptr=(DList *)malloc(sizeof(DList))){
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
        ptr->next=ptr->prev=NULL;
        ptr->info=NULL;
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

//1.d) função que libera todo o espaço de memória espaço de memória usado por uma Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: void
void freeDList(DList *lst)
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

//2) Informações sobre Lista Dupla

// 2.a) Função que verifica se uma lista Dupla é vazia
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: bool (TRUE se a Lista Dupla é vazia, FALSE caso contrário

bool isEmptyDList(DList * lst)
{
    return (!lst || lst->size==0);
}

// 2.b) Função que Imprime o conteudo da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: void
void printDList(DList *lst) {

    Node *ptr;

    if(isEmptyDList(lst)) return;
    printf("\n[ ");
    ptr=lst->first;

    //inicia do primeiro elemento da Lista Dupla
    while(ptr != NULL)
    {
      printf("(%d) ",ptr->info->value);
      ptr = ptr->next;
    }
	printf(" ]");
}

// 2.c) Função que verifica o tamanho da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: inteiro >=0 representando o tamanho da Lista Dupla, -1 caso a Lista Dupla seja nula
int lengthDList(DList *lst)
{
	if (!lst) return -1;
	return lst->size;
}

// 2.d) Função que encontra um elemento na Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: ponteiro para Info com o elemento encontrado, NULL caso contrário
Info* findDList(DList *lst, Info *inf) {

	Node *ptr;
	//if list is empty
	if(isEmptyDList(lst)) return NULL;
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

// 2.e) Função que encontra a posição de um elemento na Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: 	-inteiro maior que 0 (Zero) que representa a posição do elemento na Lista Dupla.
//				-0 (Zero) caso o elemento não se encontre
int posDList(DList *lst, Info *inf)
{
	int pos;
	Node *ptr;
	if (isEmptyDList(lst)) return 0;
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

// 2.f) Função verifica se um elemento está presente na Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: 	- inteiro maior que 0 (Zero) caso o elemento esteja presente na Lista Dupla
//				-0 (Zero) caso contrário
int isInDList(DList *lst, Info *inf)
{
	return posDList(lst,inf);
}


//3) Operações sobre Lista Dupla

// 3.a) Função que insere um elemento na primeira posição da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla não nula
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário

bool insertFirstDList(DList *lst, Info *inf)
{
    Node *ptr;
    if(!lst || !(ptr=createNode())) return false;
    ptr->info=inf;
    ptr->next=lst->first;
    ptr->prev=NULL;
    if(!isEmptyDList(lst)) lst->first->prev=ptr;
    lst->first=ptr;
    lst->size++;
    return true;
}

// 3.b) Função que insere um elemento na última posição da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário

bool insertLastDList(DList *lst, Info *inf)
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
		ptr->prev=aux;
	}
	lst->size++;
    return true;
}

// 3.c) Função que insere um elemento de informação em uma posição da lista
//		Entrada: ponteiro para uma Lista Dupla (lst), elemento de informação (info) e a posição (pos)
//		na qual o elemento será inserido
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário)

bool insertPositionDList(DList *lst, Info *inf,int pos)
{
    Node *ptr, *aux;
    int i;
    if(!lst || !(aux=createNode())) return false;
    aux->info=inf;
    
    if(lst->first==NULL) lst->first=aux;
    else
	{
		ptr=lst->first;
		for(i=1; i<pos && ptr->next!=NULL; i++, ptr=ptr->next);
		if(i<pos){
			ptr->next=aux;
			aux->prev=ptr;
		}
		else
		{
			if(ptr->prev!=NULL)
			{
				ptr->prev->next=aux;
				aux->prev=ptr->prev;
			}
			else lst->first=aux;
			aux->next=ptr;
			ptr->prev=aux;
		}
	}
	lst->size++;
    return true;
}

// 3.d) Função que deleta o elemento da primeira posição da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: ponteiro para Info com o elemento deletado
Info *deleteFirstDList(DList *lst) {

  Node *ptr;
  Info *inf;
  if (isEmptyDList(lst)) return NULL;
  ptr=lst->first;
  lst->first=ptr->next;
  if(lst->first!=NULL) lst->first->prev=NULL;
  inf=ptr->info;
  free(ptr);
  lst->size--;
  return inf;
}

// 3.e) Função que deleta o elemento da última posição da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: ponteiro para Info com o elemento deletado
Info *deleteLastDList(DList *lst) {

  Node *ptr,*pptr;
  Info *inf;
  if (isEmptyDList(lst)) return NULL;
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

// 3.f) Função que deleta o elemento de uma posição específica da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla e um inteiro indicando a posição do elemento a ser deletado
//		Saída: ponteiro para Info com o elemento deletado

Info* deletePositionDList(DList *lst, int pos)
{
	Node *ptr;
	Info *inf;
	int i;

	if (isEmptyDList(lst) || pos>lst->size || pos<=0){
		printf("\nImpossivel retirar elemento!\n");
		return NULL;
	}
	ptr=lst->first;
	for(i=1; i<pos;i++, ptr=ptr->next);
	if(ptr->prev!=NULL) ptr->prev->next=ptr->next;
	else lst->first=ptr->next;
	if(ptr->next!=NULL) ptr->next->prev=ptr->prev;
	inf=ptr->info;
	free(ptr);
	lst->size--;
	return inf;
}


// 3.g) Função que deleta o elemento da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla e um ponteiro para Info representando o elemento a ser deletado
//		Saída: ponteiro para Info com o elemento deletado
Info* deleteInfoDList(DList *lst, Info *inf) {

	Node *ptr, *pptr;
	Info *auxInf;
	//if list is empty
	if (isEmptyDList(lst)) return NULL;

	ptr=lst->first;	
	//navigate through list
	while(ptr!=NULL && ptr->info->value != auxInf->value) ptr = ptr->next;
	if(ptr==NULL) return NULL;
	//found a match, update the link
	if(ptr->prev!=NULL){
		ptr->prev->next=ptr->next;
	}
	else
	{
		lst->first=ptr->next;
	}
	if(ptr->next!=NULL)ptr->next->prev=ptr->prev;
	auxInf=ptr->info;
	free(ptr);
	lst->size--;
	return auxInf;
}


// 3.h) Função que inverte uma Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: void.
void reverseDList(DList *lst) {

   Node *prev=NULL, *current, *next;
   
   if (isEmptyDList(lst)|| lst->size==1) return;
   current=lst->first;
   while (current != NULL) {
      next  = current->next;
      current->next = prev;
      current->prev=next;
      prev = current;
      current = next;
    }
	lst->first=prev;
}

// 3.i) Função que ordena crescente uma Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Saída: void.
void sortDList(DList *lst) {

   int i, j, k;
   Info *tempInfo;
   Node *current;
   Node *next;

	k = lst->size;
	if (isEmptyDList(lst)) return;

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


