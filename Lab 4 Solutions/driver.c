#include <stdio.h>
#include <stdlib.h>
#include "MyFuns.h"

int main(int argc, char *argv[]){
	FILE *fp, *fp1, *fp2;
	int flag = 1, size = atoi(argv[4]), i, a, sum = atoi(argv[5]);
	int array1[size], array2[size];
	Boolean x;
	//-------------------------------------------------------------------------------------------------------------
	if((fp = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "\nThe Input file could not be opened.\n");
		flag = 0;
		return -1;
	}
	for(i = 0; i < size; i++){
                a = fscanf(fp, "%d", &array1[i]);
        }
	fclose(fp);
	//-------------------------------------------------------------------------------------------------------------
	if((fp = fopen(argv[1], "r")) == NULL){
                fprintf(stderr, "\nThe Input file could not be opened.\n");
                flag = 0;
                return -1;
        }
        for(i = 0; i < size; i++){
                a = fscanf(fp, "%d", &array2[i]);
        }
        fclose(fp);
	//-------------------------------------------------------------------------------------------------------------
	fp1 = fopen(argv[2], "w");
	print(fp1, array1, size);
	insertionSort_R(array1, 0, size - 1);
	print(fp1, array1, size);
	x = subsetSum_R(array1, size, sum);
	if(x){
		fprintf(fp1, "\nFound a Sub-Set with the sum %d.(Using Recursive Method)\n\n", sum);
	}else{
		fprintf(fp1, "\nNo Sub-Set was found with sum %d.(Using Recursive Method)\n\n", sum);
	}
	fclose(fp1);
	//-------------------------------------------------------------------------------------------------------------
	fp2 = fopen(argv[3], "w");
        print(fp2, array2, size);
        insertionSort_R(array2, 0, size - 1);
        print(fp2, array2, size);
        x = subsetSum_R(array2, size, sum);
        if(x){
                fprintf(fp2, "\nFound a Sub-Set with the sum %d.(Using Iterative Method)\n\n", sum);
        }else{
                fprintf(fp2, "\nNo Sub-Set was found with sum %d.(Using Iterative Method)\n\n", sum);
        }
        fclose(fp2);
	//-------------------------------------------------------------------------------------------------------------
	return 0;
}
