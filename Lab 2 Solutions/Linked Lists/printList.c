#include <stdio.h>
#include <stdlib.h>
#include "ListOps.h"

void print(List list, long long int size, FILE *fp){
	long long int i;
        if(fp == NULL){
                for(i = 0; i < size; i++, list = list -> next){
                        fprintf(stdout, "%8lld\n", list -> data);
                }
                fprintf(stdout, "\n");
        }else{
                for(i = 0; i < size; i++, list = list -> next){
                        fprintf(fp, "%8lld\n", list -> data);
                }
                fprintf(fp, "\n");
        }
}
