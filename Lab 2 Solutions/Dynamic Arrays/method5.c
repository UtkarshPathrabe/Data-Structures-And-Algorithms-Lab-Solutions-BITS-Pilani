#include <stdio.h>
#include <stdlib.h>
#include "ListOps.h"

Location get_min(List, long long int, long long int);

List method5(List list, long long int list_size){
        Element temp;
        long long int i, index_of_min;
        for(i = 0; i < list_size - 1; i++){
                index_of_min = get_min(list, i, list_size - 1);
                if(i != index_of_min){
                        temp.number = (list + index_of_min) -> number;
                        (list + index_of_min) -> number = (list + i) -> number;
                        (list + i) -> number = temp.number;
                }
        }
        return list;
}
/*
List sort(List list, long long int list_size){
	Element temp;
	long long int i, index_of_min;
	for(i = 0; i < list_size - 1; i++){
		index_of_min = get_min(list, i, list_size - 1);
		if(i != index_of_min){
			temp.number = (list + index_of_min) -> number;
			(list + index_of_min) -> number = (list + i) -> number;
			(list + i) -> number = temp.number;
		}
	}
	return list;
}
*/
Location get_min(List list, long long int p, long long int r){
	long long int min, i;
	min = p;
	for(i = p; i <= r; i++){
		if(((list + min) -> number) > ((list + i) -> number)){
			min = i;
		}
	}
	return min;
}
