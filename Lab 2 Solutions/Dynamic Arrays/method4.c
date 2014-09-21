#include <stdio.h>
#include <stdlib.h>
#include "ListOps.h"

List method4(List list, long long int list_size){
        long long int i, j;
        Element temp;
        for(i = 0; i < list_size - 1; i++){
                for(j = 0; j < list_size - 1; j++){
                        if(((list + j) -> number) > ((list + j + 1) -> number)){
                                temp.number = (list + j) -> number;
                                (list + j) -> number = (list + j + 1) -> number;
                                (list + j + 1) -> number = temp.number;
                        }else{
                                continue;
                        }
                }
        }
        return list;
}
/*
List sort(List list, long long int list_size){
	long long int i, j;
	Element temp;
	for(i = 0; i < list_size - 1; i++){
		for(j = 0; j < list_size - 1; j++){
			if(((list + j) -> number) > ((list + j + 1) -> number)){
				temp.number = (list + j) -> number;
				(list + j) -> number = (list + j + 1) -> number;
				(list + j + 1) -> number = temp.number;
			}else{
				continue;
			}
		}
	}
	return list;
}
*/
