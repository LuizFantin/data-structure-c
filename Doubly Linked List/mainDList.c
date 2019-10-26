#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DList.cpp"

void main() {

	DList *lst=createDList();

	Info *tempInfo;

	tempInfo=createInfo(5);
	insertFirstDList(lst,tempInfo);
	
   	tempInfo=createInfo(125);
	insertFirstDList(lst,tempInfo);

	tempInfo=createInfo(45);
	insertFirstDList(lst,tempInfo);

   	tempInfo=createInfo(56);
	insertFirstDList(lst,tempInfo);

   	tempInfo=createInfo(9);
	insertFirstDList(lst,tempInfo);

   	tempInfo=createInfo(25);
	insertFirstDList(lst,tempInfo);

   	tempInfo=createInfo(7);
	insertFirstDList(lst,tempInfo);

	tempInfo=createInfo(1);
	insertFirstDList(lst,tempInfo);

	tempInfo=createInfo(2);
	insertFirstDList(lst,tempInfo);

	tempInfo=createInfo(3);
	insertFirstDList(lst,tempInfo);
	
   printf("Original List: ");

   //print list
	printDList(lst);
	getchar();

	printf("\nOrdered List: ");
   //ordena
	sortDList(lst);
   //print sorted list
	printDList(lst);

	printf("\nReversed List: ");
   //inverte
   reverseDList(lst);
    //print reversed list
   printDList(lst);
  
	printf("\nFirst Deleted List: ");
   //deleta primeiro
   deleteFirstDList(lst);
   printDList(lst);

	printf("\nFirst Deleted List: ");
   //deleta primeiro
   deleteFirstDList(lst);
   printDList(lst);

	printf("\nPosition 20 Deleted List: ");
   //deleta posicao 20
   deletePositionDList(lst,20);
   printDList(lst);

printf("\n****Last Position Deleted List: ");
   //deleta posicao 8
   deletePositionDList(lst,lst->size);
   printDList(lst);

printf("\nLast Deleted List: ");
	//deleta último
   deleteLastDList(lst);
   printDList(lst);

printf("\n Find Info in List: "); 
   //Encontra elemento
   tempInfo=createInfo(1);
   printf("\n Find Info in List: %d ",tempInfo->value); 
   tempInfo=findDList(lst,tempInfo);
   if(tempInfo) 
   {
   	printf("\nEncontrou=%d",tempInfo->value);
   	printf("\nPosicao=%d",posDList(lst,tempInfo));
   } 
   else printf("\nNAO Encontrou!");

   //Encontra elemento
   tempInfo=createInfo(9);
   printf("\n Find Info in List: %d ",tempInfo->value);
   tempInfo=findDList(lst,tempInfo);
   if(tempInfo){
   	printf("\nEncontrou=%d",tempInfo->value);
   	printf("\nPosicao=%d",posDList(lst,tempInfo));
   } 
   else printf("\nNAO Encontrou!");

	printf("\n List: ");
   printDList(lst);
   //inverte
	
	printf("\nReversed List: ");
   reverseDList(lst);
   //print reversed list
   printDList(lst);
   freeDList(lst);
   printf("\n Free List!!!");
   getchar();
   return;
}

