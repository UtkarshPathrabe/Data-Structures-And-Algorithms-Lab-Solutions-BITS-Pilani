#include <stdio.h>
#include <stdlib.h>
#include "methoddef.h"

Stack1 newStack1(){
	Stack1 st = (Stack1) malloc (sizeof (struct stack1)); 
	st -> top = NULL;
	st -> size = 0; 
	return st; 
}

Boolean push1(Stack1 st, Elem1 data){
	if (st == NULL){
		printf("\n Error-Push: Stack Non Existent. \n");
		return FALSE;
	}
	Elem1 el = (Elem1) malloc (sizeof (struct node)); 
	if(el == NULL){
		printf("\nError-Push: The Element cannot be pushed into the Stack.\n");
		return FALSE;
	}
	el -> next = NULL;
	el -> last = data -> last;
	el -> first = data -> first;
	el -> stage = data -> stage;
	if(st -> top == NULL){
		st -> top = el;
		st -> size = 1;
	}else {
		el -> next = st -> top;
		st -> top = el;
		st -> size++;
	}
	return TRUE; 
}

void pop1(Stack1 st){
	Elem1 el = NULL;
	if (st == NULL){
		printf("\n Error-Pop: Stack Non Existent.\n");
		return;
	}
	if (st -> top == NULL){
		printf("\n Error-Pop: Empty Stack.\n");
		return;
	}
	el = st -> top;
	st -> top = el -> next;
	return; 	
}

Elem1 top1(Stack1 st){
	Elem1 el = NULL;
	if (st == NULL){
		printf("\n Error-Top: Stack Non Existent.\n");
		return NULL;
	}
	if (st -> top == NULL){
		printf("\n Error-Top: Empty Stack.\n");
		return NULL;
	}
	el = st -> top;
	return el;
}

int size1(Stack1 st){
	if (st == NULL){
		printf("\n Error-Pop: Stack Non Existent.\n");
		return -1;
	}
	return st -> size; 
}

void display1(Stack1 st){
	if (st == NULL){
		printf("\n Error-Display: Stack Non Existent.\n");
	}else{
		printf("\n Stack-Display : ");
		Elem1 curr = st -> top;
		while(curr != NULL){
			printf("\n %d\t%d\t%d\n", curr -> first, curr -> last, curr -> stage);
			curr = curr -> next;
		}
		printf("\n Stack-Display ends.\n");
	}
}

Boolean isEmpty1(Stack1 st){
	if(st == NULL || st -> top == NULL)
		return TRUE;
	else
		return FALSE;
}
