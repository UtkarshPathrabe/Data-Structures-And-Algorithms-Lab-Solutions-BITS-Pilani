//To make an input file

#include <stdio.h>
#include <math.h>

FILE *input(FILE *fp1, long long int size){
	srand(time(NULL));
	long long int i;
	for(i = 0; i < size; i++){
		fprintf(fp1, "%08lld\n", (1+(rand()%(size*2))));
	}
	return fp1;
}

FILE *input1(FILE *fp1, long long int size){
        srand(time(NULL));
        long long int i;
        for(i = 0; i < size; i++){
                fprintf(fp1, "%d\n", (rand()%10));
        }
        return fp1;
}
