#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.cpp"

void main() {

	Queue *queue=createQueue();

	Info *tempInfo;
	
	tempInfo=createInfo(5);
	insertQueue(queue,tempInfo);
	
   	tempInfo=createInfo(125);
	insertQueue(queue,tempInfo);

	tempInfo=createInfo(45);
	insertQueue(queue,tempInfo);

   	tempInfo=createInfo(56);
	insertQueue(queue,tempInfo);

   	tempInfo=createInfo(9);
	insertQueue(queue,tempInfo);

   	tempInfo=createInfo(25);
	insertQueue(queue,tempInfo);

   	tempInfo=createInfo(7);
	insertQueue(queue,tempInfo);

	tempInfo=createInfo(1);
	insertQueue(queue,tempInfo);

	tempInfo=createInfo(2);
	insertQueue(queue,tempInfo);

	tempInfo=createInfo(3);
	insertQueue(queue,tempInfo);

   printf("Original Queue: ");

   //print Queue
   printQueue(queue);

	printf("\nremove Queue: ");
    tempInfo=removeQueue(queue);
   	printQueue(queue);

	tempInfo=createInfo(100);
    printf("\n insert Queue: %d", tempInfo->value);
	insertQueue(queue,tempInfo);
   	printQueue(queue);

	printf("\nremove Queue: ");
    tempInfo=removeQueue(queue);
   	printQueue(queue);
   	
    tempInfo=createInfo(3333);
    printf("\n insert Queue: %d", tempInfo->value);
	insertQueue(queue,tempInfo);
   	printQueue(queue);
   	
   	printf("\nremove Queue: ");
    tempInfo=removeQueue(queue);
   	printQueue(queue);
   	
    tempInfo=createInfo(3122);
    printf("\n insert Queue: %d", tempInfo->value);
	insertQueue(queue,tempInfo);
	printQueue(queue);
   	printf("\n Free Queue");
    freeQueue(queue);
    getchar();
   return;
}

