#include <stdio.h>
#include <stdlib.h>
#include "ListOps.h"

List radixSort(List list, int d, long long int size);

List method7(List list, long long int size){
	List head = radixSort(list, 8, size);
	return head;
}

List radixSort(List list, int d, long long int size){
	
}
