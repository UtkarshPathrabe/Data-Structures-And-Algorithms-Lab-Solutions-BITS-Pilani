#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "ListOps.h"

List MergeSort(List, long long int, long long int);
List Merge(List, long long int, long long int, long long int);

List method2(List list, long long int list_size){
        MergeSort(list, 1, list_size);
        return list;
}
/*
List sort(List list, long long int list_size){
	MergeSort(list, 1, list_size);
	return list;
}
*/
List MergeSort(List list, long long int p, long long int r){
	long long int q;
	if (p < r){
		q = (long long int)floor((p + r)/2);
		MergeSort(list, p, q);
		MergeSort(list, q+1, r);
		Merge(list, p, q, r);
	}
	return list;
}

List Merge(List list, long long int p, long long int q, long long int r){
	long long int n1, n2;
	n1 = q - p + 1;
	n2 = r - q;
	long long int i, j, k;
	List l = (List)calloc(n1+1, sizeof(Element));
	List m = (List)calloc(n2+1, sizeof(Element));
	for(i = 0; i < n1; i++){
		(l + i) -> number = (list + p + i - 1) -> number;
	}
	for(j = 0; j < n2; j++){
		(m + j) -> number = (list + q + j) -> number;
	}
	(l + i) -> number = LLONG_MAX;
	(m + j) -> number = LLONG_MAX;
	i = 0, j = 0;
	for(k = p; k <= r; k++){
		if(((l + i) -> number) <= ((m + j) -> number)){
			(list + k - 1) -> number = (l + i) -> number;
			i++; 
		}else{
			(list + k - 1) -> number = (m + j) -> number;
			j++;
		}
	}
	return list;
}
