#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DList.h"

//1) Inicializa��o e Libera��o de uma Lista Dupla Dupla

// 1.a) fun��o que aloca mem�ria para uma Lista Dupla Dupla, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma Lista Dupla Dupla
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

// 1.b) fun��o que aloca mem�ria para um no, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma Node
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

//1.d) fun��o que libera todo o espa�o de mem�ria espa�o de mem�ria usado por uma Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: void
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

//2) Informa��es sobre Lista Dupla

// 2.a) Fun��o que verifica se uma lista Dupla � vazia
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: bool (TRUE se a Lista Dupla � vazia, FALSE caso contr�rio

bool isEmptyDList(DList * lst)
{
    return (!lst || lst->size==0);
}

// 2.b) Fun��o que Imprime o conteudo da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: void
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

// 2.c) Fun��o que verifica o tamanho da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: inteiro >=0 representando o tamanho da Lista Dupla, -1 caso a Lista Dupla seja nula
int lengthDList(DList *lst)
{
	if (!lst) return -1;
	return lst->size;
}

// 2.d) Fun��o que encontra um elemento na Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: ponteiro para Info com o elemento encontrado, NULL caso contr�rio
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

// 2.e) Fun��o que encontra a posi��o de um elemento na Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: 	-inteiro maior que 0 (Zero) que representa a posi��o do elemento na Lista Dupla.
//				-0 (Zero) caso o elemento n�o se encontre
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

// 2.f) Fun��o verifica se um elemento est� presente na Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: 	- inteiro maior que 0 (Zero) caso o elemento esteja presente na Lista Dupla
//				-0 (Zero) caso contr�rio
int isInDList(DList *lst, Info *inf)
{
	return posDList(lst,inf);
}


//3) Opera��es sobre Lista Dupla

// 3.a) Fun��o que insere um elemento na primeira posi��o da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla n�o nula
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio

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

// 3.b) Fun��o que insere um elemento na �ltima posi��o da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio

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

// 3.c) Fun��o que insere um elemento de informa��o em uma posi��o da lista
//		Entrada: ponteiro para uma Lista Dupla (lst), elemento de informa��o (info) e a posi��o (pos)
//		na qual o elemento ser� inserido
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio)

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

// 3.d) Fun��o que deleta o elemento da primeira posi��o da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: ponteiro para Info com o elemento deletado
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

// 3.e) Fun��o que deleta o elemento da �ltima posi��o da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: ponteiro para Info com o elemento deletado
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

// 3.f) Fun��o que deleta o elemento de uma posi��o espec�fica da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla e um inteiro indicando a posi��o do elemento a ser deletado
//		Sa�da: ponteiro para Info com o elemento deletado

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


// 3.g) Fun��o que deleta o elemento da Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla e um ponteiro para Info representando o elemento a ser deletado
//		Sa�da: ponteiro para Info com o elemento deletado
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


// 3.h) Fun��o que inverte uma Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: void.
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

// 3.i) Fun��o que ordena crescente uma Lista Dupla
//		Entrada: ponteiro para uma Lista Dupla
//		Sa�da: void.
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


