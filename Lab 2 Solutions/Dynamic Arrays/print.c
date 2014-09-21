#include <stdio.h>
#include <math.h>
#include "ListOps.h"

void print(List list, long long int list_size, FILE *fp){
	long long int i;
	if(fp == NULL){
		for(i = 0; i<list_size; i++, list++){
                	fprintf(stdout, "%08lld\n", list->number);
        	}
        	fprintf(stdout, "\n");
	}else{
		for(i = 0; i<list_size; i++, list++){
			fprintf(fp, "%08lld\n", list->number);
		}
		fprintf(fp, "\n");
	}
}

void print_time(FILE *fp, double t0, double t1, double t2, double t3, double t4, double t5, long long int size){
	if(fp == NULL){
		fprintf(stdout, "%8lld, %8.3lf, %8.3lf, %8.3lf, %8.3lf, %8.3lf\n", size, ((t1 - t0)/1000.0), ((t2 - t1)/1000.0), ((t3 - t2)/1000.0), ((t4 - t3)/1000.0), ((t5 - t4)/1000.0));
	}else{
		fprintf(fp, "%8lld, %8.3lf, %8.3lf, %8.3lf, %8.3lf, %8.3lf\n", size, ((t1 - t0)/1000.0), ((t2 - t1)/1000.0), ((t3 - t2)/1000.0), ((t4 - t3)/1000.0), ((t5 - t4)/1000.0));
	}
}
