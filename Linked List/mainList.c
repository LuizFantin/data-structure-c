#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.cpp"

void main() {

	List *lst=createList();
	Info *tempInfo;

	tempInfo=createInfo(5);
	insertFirstList(lst,tempInfo);

   	tempInfo=createInfo(125);
	insertFirstList(lst,tempInfo);

	tempInfo=createInfo(45);
	insertFirstList(lst,tempInfo);

   	tempInfo=createInfo(56);
	insertFirstList(lst,tempInfo);

   	tempInfo=createInfo(9);
	insertFirstList(lst,tempInfo);

   	tempInfo=createInfo(25);
	insertFirstList(lst,tempInfo);

   	tempInfo=createInfo(7);
	insertFirstList(lst,tempInfo);

	tempInfo=createInfo(1);
	insertFirstList(lst,tempInfo);

	tempInfo=createInfo(2);
	insertFirstList(lst,tempInfo);

	tempInfo=createInfo(3);
	insertFirstList(lst,tempInfo);

   printf("Original List: ");

   //print list
   printList(lst);

	printf("\nOrdered List: ");
   //ordena
   sortList(lst);
   //print sorted list
   printList(lst);

	printf("\nReversed List: ");
   //inverte
   reverseList(lst);
   //print reversed list
   printList(lst);

	printf("\nFirst Deleted List: ");
   //deleta primeiro
   deleteFirstList(lst);
   printList(lst);

	printf("\nFirst Deleted List: ");
   //deleta primeiro
   deleteFirstList(lst);
   printList(lst);

	printf("\nPosition 20 Deleted List: ");
   //deleta posicao 20
   deletePositionList(lst,20);
   printList(lst);

	printf("\nPosition 1 Deleted List: ");
   //deleta posicao 8
   deletePositionList(lst,1);
   printList(lst);

		printf("\nLast Deleted List: ");
	//deleta último
   deleteLastList(lst);
   printList(lst);

	printf("\n Find Info in List: "); 
   //Encontra elemento
   tempInfo=createInfo(1);
   printf("\n Find Info in List: %d ",tempInfo->value); 
   tempInfo=findList(lst,tempInfo);
   if(tempInfo) 
   {
   	printf("\nEncontrou=%d",tempInfo->value);
   	printf("\nPosicao=%d",posList(lst,tempInfo));
   } 
   else printf("\nNAO Encontrou!");

   //Encontra elemento
   tempInfo=createInfo(9);
   printf("\n Find Info in List: %d ",tempInfo->value);
   tempInfo=findList(lst,tempInfo);
   if(tempInfo){
   	printf("\nEncontrou=%d",tempInfo->value);
   	printf("\nPosicao=%d",posList(lst,tempInfo));
   } 
   else printf("\nNAO Encontrou!");

	printf("\n List: ");
   printList(lst);
   //inverte
	
	printf("\nReversed List: ");
   reverseList(lst);
   //print reversed list
   printList(lst);
   freeList(lst);
   printf("\n Free List!!!");
   getchar();
   return;
}

