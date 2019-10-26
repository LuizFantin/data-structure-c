#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

//1) Inicializa��o e Libera��o de uma lista

// 1.a) fun��o que aloca mem�ria para uma lista, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma lista
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

//1.d) fun��o que libera todo o espa�o de mem�ria espa�o de mem�ria usado por uma lista
//		Entrada: ponteiro para uma lista
//		Sa�da: void

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




//2) Informa��es sobre lista

// 2.a) Fun��o que verifica se uma list � vazia
//		Entrada: ponteiro para uma lista
//		Sa�da: bool (TRUE se a lista � vazia, FALSE caso contr�rio

bool isEmptyList(List * lst)
{
    return (!lst || lst->size==0);
}

// 2.b) Fun��o que Imprime o conteudo da lista
//		Entrada: ponteiro para uma lista
//		Sa�da: bool (TRUE se a lista � vazia, FALSE caso contr�rio
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

// 2.c) Fun��o que verifica o tamanho da lista
//		Entrada: ponteiro para uma lista
//		Sa�da: inteiro >=0 representando o tamanho da lista, -1 caso a lista seja nula
int lengthList(List *lst)
{
	if (!lst) return -1;
	return lst->size;
}

// 2.d) Fun��o que encontra um elemento na lista
//		Entrada: ponteiro para uma lista
//		Sa�da: ponteiro para Info com o elemento encontrado, NULL caso contr�rio
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

// 2.e) Fun��o que encontra a posi��o de um elemento na lista
//		Entrada: ponteiro para uma lista
//		Sa�da: 	-inteiro maior que 0 (Zero) que representa a posi��o do elemento na lista.
//				-0 (Zero) caso o elemento n�o se encontre
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

// 2.f) Fun��o verifica se um elemento est� presente na lista
//		Entrada: ponteiro para uma lista
//		Sa�da: 	- inteiro maior que 0 (Zero) caso o elemento esteja presente na lista
//				-0 (Zero) caso contr�rio
int isInList(List *lst, Info *inf)
{
	return posList(lst,inf);
}


//3) Opera��es sobre lista

// 3.a) Fun��o que insere um elemento na primeira posi��o da lista
//		Entrada: ponteiro para uma lista n�o nula
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio

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

// 3.b) Fun��o que insere um elemento na �ltima posi��o da lista
//		Entrada: ponteiro para uma lista
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio

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


// 3.c) Fun��o que deleta o elemento da primeira posi��o da lista
//		Entrada: ponteiro para uma lista
//		Sa�da: ponteiro para Info com o elemento deletado
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

// 3.d) Fun��o que deleta o elemento da lista
//		Entrada: ponteiro para uma lista e um ponteiro para Info representando o elemento a ser deletado
//		Sa�da: ponteiro para Info com o elemento deletado
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

// 3.e) Fun��o que deleta o elemento de uma posi��o espec�fica da lista
//		Entrada: ponteiro para uma lista e um inteiro indicando a posi��o do elemento a ser deletado
//		Sa�da: ponteiro para Info com o elemento deletado
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

// 3.f) Fun��o que inverte uma lista
//		Entrada: ponteiro para uma lista
//		Sa�da: void.
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

// 3.g) Fun��o que ordena crescente uma lista
//		Entrada: ponteiro para uma lista
//		Sa�da: void.
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
// 3.h) Fun��o que deleta o elemento da �ltima posi��o da lista
//		Entrada: ponteiro para uma lista
//		Sa�da: ponteiro para Info com o elemento deletado
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

