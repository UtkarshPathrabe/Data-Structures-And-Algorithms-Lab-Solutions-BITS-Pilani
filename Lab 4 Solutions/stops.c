#include <stdio.h>
#include <stdlib.h>
#include "stops.h"

Stack newStack(){
	Stack st = (Stack) malloc (sizeof (struct stack)); 
	st -> top = NULL;
	st -> size = 0; 
	return st; 
}

Boolean push (Stack st, Elem data){
	if (st == NULL){
		printf("\n Error-Push: Stack Non Existent. \n");
		return FALSE;
	}
	Elem el = (Elem) malloc (sizeof (snap)); 
	if(el == NULL){
		printf("\nError-Push: The Element cannot be pushed into the Stack.\n");
		return FALSE;
	}
	el -> next = NULL;
	el -> sum = data -> sum;
	el -> siz = data -> siz;
	el -> stage = data -> stage;
	if(st->top==NULL){
		st -> top = el;
		st -> size = 1;
	}else {
		el -> next = st -> top;
		st -> top = el;
		st -> size += 1;
	}
	return TRUE; 
}

void pop(Stack st){
	Elem el = NULL;
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

Elem top(Stack st){
	Elem el = NULL;
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

int size(Stack st){
	if (st == NULL){
		printf("\n Error-Pop: Stack Non Existent.\n");
		return -1;
	}
	return st -> size; 
}

void display(Stack st){
	if (st == NULL){
		printf("\n Error-Display: Stack Non Existent.\n");
	}else{
		printf("\n Stack-Display : ");
		Elem curr = st -> top;
		while(curr != NULL){
			printf("\n %d\t%d\t%d\n", curr -> siz, curr -> sum, curr -> stage);
			curr = curr -> next;
		}
		printf("\n Stack-Display ends.\n");
	}
}

Boolean isEmpty(Stack st){
	if(st == NULL || st -> top == NULL)
		return TRUE;
	else
		return FALSE;
}
