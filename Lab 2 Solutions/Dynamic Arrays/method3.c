#include <stdio.h>
#include <stdlib.h>
#include "ListOps.h"

List QuickSort(List, long long int, long long int);
Location Partition(List, long long int, long long int);

List method3(List list, long long int list_size){
        QuickSort(list, 1, list_size);
        return list;
}
/*
List sort(List list, long long int list_size){
	QuickSort(list, 1, list_size);
	return list;
}
*/
List QuickSort(List list, long long int p, long long int r){
	long long int q;
	if(p < r){
		q = doPartition(list, p, r);
		QuickSort(list, p, q - 1);
		QuickSort(list, q + 1, r);
	}
	return list;
}

Location Partition(List list, long long int p, long long int r){
	Element x, temp;
	long long int i, j;
	x.number = (list + r - 1) -> number;
	i = p - 1;
	for(j = p; j < r; j++){
		if(((list + j - 1) -> number) <= (x.number)){
			i = i + 1;
			temp.number = (list + i - 1) -> number;
			(list + i - 1) -> number = (list + j - 1) -> number;
			(list + j - 1) -> number = temp.number;
		}
	}
	temp.number = (list + i) -> number;
	(list + i) -> number = x.number;
	(list + r - 1) -> number = temp.number;
	return (i+1);
}

Location doPartition(List list, long long int p, long long int r){
	srand(time(NULL));
	Location i;
	Element temp;
	i = p + (rand()%(r - p + 1));
	temp.number = (list + r - 1) -> number;
	(list + r - 1) -> number = (list + i - 1) -> number;
	(list + i - 1) -> number = temp.number;
	return Partition(list, p, r);
}
