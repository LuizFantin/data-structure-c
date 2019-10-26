#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.cpp"

void main() {

	Stack *stack=createStack();

	Info *tempInfo;
	
	tempInfo=createInfo(5);
	push(stack,tempInfo);

   	tempInfo=createInfo(125);
	push(stack,tempInfo);

	tempInfo=createInfo(45);
	push(stack,tempInfo);

   	tempInfo=createInfo(56);
	push(stack,tempInfo);

   	tempInfo=createInfo(9);
	push(stack,tempInfo);

   	tempInfo=createInfo(25);
	push(stack,tempInfo);

   	tempInfo=createInfo(7);
	push(stack,tempInfo);

	tempInfo=createInfo(1);
	push(stack,tempInfo);

	tempInfo=createInfo(2);
	push(stack,tempInfo);

	tempInfo=createInfo(3);
	push(stack,tempInfo);

   printf("Original Stack: ");

   //print Stack
   printStack(stack);

	printf("\n POP Stack: ");
    tempInfo=pop(stack);
   	printStack(stack);

	tempInfo=createInfo(100);
    printf("\n PUSH Stack: %d", tempInfo->value);
	push(stack,tempInfo);
   	printStack(stack);

	printf("\n POP Stack: ");
    tempInfo=pop(stack);
   	printStack(stack);
   	
    tempInfo=createInfo(3333);
    printf("\n PUSH Stack: %d", tempInfo->value);
	push(stack,tempInfo);
   	printStack(stack);
   	
   	printf("\n POP Stack: ");
    tempInfo=pop(stack);
   	printStack(stack);
   	
    tempInfo=createInfo(3122);
    printf("\n PUSH Stack: %d", tempInfo->value);
	push(stack,tempInfo);
	printStack(stack);
	
   	printf("\n Free Stack");
    freeStack(stack);
    getchar();
   return;
}

