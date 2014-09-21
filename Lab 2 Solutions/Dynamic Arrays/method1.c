#include <stdio.h>
#include "ListOps.h"

List method1(List list, long long int list_size){
        Element x;
        long long int i, j;
        for(j = 1; j < list_size; j++){
                x.number = (list + j) -> number;
                i = j - 1;
                while((i > -1) && (((list + i) -> number) > x.number)){
                        (list + i + 1) -> number = (list + i) -> number;
                        i = i - 1;
                }
                (list + i + 1) -> number = x.number;
        }
        return list;
}

//List sort(List list, long long int list_size){
//	Element x;
//	long long int i, j;
//	for(j = 1; j < list_size; j++){
//		x.number = (list + j) -> number;
//		i = j - 1;
//		while((i > -1) && (((list + i) -> number) > x.number)){
//			(list + i + 1) -> number = (list + i) -> number;
//			i = i - 1;
//		}
//		(list + i + 1) -> number = x.number;
//	}
//	return list;
//}

