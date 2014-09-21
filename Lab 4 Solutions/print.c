#include <stdio.h>
#include <stdlib.h>

void print(FILE *fp, int arr[], int size){
	int i;
	for(i = 0; i < size; i++){
		fprintf(fp, "%d\n", arr[i]);
	}
	fprintf(fp, "\n\n");
}
