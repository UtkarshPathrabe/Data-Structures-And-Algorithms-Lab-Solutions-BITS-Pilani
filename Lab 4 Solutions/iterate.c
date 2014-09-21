#include <stdio.h>
#include <stdlib.h>
#include "methoddef.h"
#include "MyFuns.h"
#include "stops.h"

void insert_L(int arr[], int x, int size);
Boolean issubsetSum_L(int arr[], int size, int sum);

void insertionSort_L(int arr[], int first, int last){
	Stack1 stack = newStack1();
	Boolean x;
	Elem1 Node, newNode;
	struct node ele, ele2;
	ele2.first = first;
	ele2.last = last;
	ele2.stage = 0;
	Node = &ele2;
	x = push1(stack, Node);
	while(isEmpty1(stack) == FALSE){
		Node = top1(stack);
		pop1(stack);
		switch(Node -> stage){
			case 0:	if(((Node -> last) - (Node -> first)) > 1){
					Node -> stage = 1;
					x = push1(stack, Node);
					ele.first = first;
					ele.last = (Node -> last) - 1;
					ele.stage = 0;
					newNode = &ele;
					x = push1(stack, newNode);
					continue;
				}
				break;
			case 1:	insert_L(arr, arr[Node -> last], ((Node -> last) - (Node -> first)));
				break;
		}
	}
}

void insert_L(int arr[], int x, int size){
	int i, j, temp;
	for (j = 0; j < size; j++){
          	if (arr[j] > x)
              		break;
          	if (arr[j] == x)
              		return;
     	}
    	for (i = size - 1; i >= j; i--)
      	{
         	 arr[i + 1] = arr[i];
      	}
    	arr[j] = x;
}

Boolean subsetSum_L(int arr[], int size, int sum){
//	int size;
	Boolean x;
	if(arr != NULL){
//		size = (sizeof(arr))/(sizeof(arr[0]));
		x = issubsetSum_R(arr, size, sum);
	}else{
		x = FALSE;
	}
	return x;
}

Boolean issubsetSum_L(int arr[], int size, int sum){
	Stack stack = newStack();
	snap Node1, Node2;
	Elem elem1, elem2;
	Boolean x, y;
	Node1.siz = size;
	Node1.sum = sum;
	Node1.stage = 0;
	Node1.flag = FALSE;
	elem1 = &Node1;
	x = push(stack, elem1);
	while(isEmpty(stack) == FALSE){
		elem1 = top(stack);
		pop(stack);
		switch(elem1 -> stage){
			case 0:	if((elem1 -> siz) == 0){
					y = TRUE;
					continue;
				}
				if(((elem1 -> siz) == 0) && ((elem1 -> sum) != 0)){
					y = FALSE;
					continue;
				}else{
					elem1 -> stage = 1;
					Node2.siz = (elem1 -> siz) - 1;
					Node2.sum = elem1 -> sum;
					Node2.stage = 0;
					elem2 = &Node2;
					x = push(stack, elem2);
					continue;
				}
				break;
			case 1:	elem1 -> flag = y;
				elem1 -> stage = 2;
				Node2.siz = (elem1 -> siz) - 1;
				Node2.sum = (elem1 -> sum) - arr[(elem1 -> siz) - 1];
				Node2.stage = 0;
				elem2 = &Node2;
				x = push(stack, elem2);
				continue;
				break;
			case 2:	y = ((elem1 -> flag) || y);
				continue;
				break;
		}
	}
	return y;
}
