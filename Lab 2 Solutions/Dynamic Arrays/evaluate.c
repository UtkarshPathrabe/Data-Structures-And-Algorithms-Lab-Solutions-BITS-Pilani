#include <stdio.h>
#include <math.h>
#include "ListOps.h"

int main(int argc, char *argv[]){
	FILE *fp1;
	List list;
	long long int size = atoi(argv[2]);
	fp1 = fopen(argv[1], "w");
	fp1 = input1(fp1, size);
	fclose(fp1);
	fp1 = fopen(argv[1], "r");
	list = makeArray(fp1, size);
	fclose(fp1);
	fp1 = fopen(argv[3], "w");
	print(list, size, fp1);
	list = method6(list, size);
	print(list, size, fp1);
	if(fp1 != NULL){
		fclose(fp1);
	}
	return 0;
}
