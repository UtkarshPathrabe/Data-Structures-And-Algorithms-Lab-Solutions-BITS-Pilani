#include <stdio.h>
#include <stdlib.h>
#include "ListOps.h"

List countingSort(List list, long long int k, long long int size);

List method6(List list, long long int size){
	List head = countingSort(list, 10, size);
	return head;
}

List countingSort(List list, long long int k, long long int size){
	List head = (List)malloc(size*sizeof(Element));
	long long int i, array[k];
	for(i = 0; i < k; i++){
		array[i] = 0;
	}
	for(i = 0; i < size; i++){
		array[(list + i) -> number] = array[(list + i) -> number] + 1;
	}
	for(i = 1; i < k; i++){
		array[i] = array[i] + array[i-1];
	}
	for(i = size-1; i > -1; i--){
		(head + array[(list + i) -> number] - 1) -> number = (list + i) -> number;
		array[(list + i) -> number] = array[(list + i) -> number] - 1;
	}
	free(list);
	return head;
}
