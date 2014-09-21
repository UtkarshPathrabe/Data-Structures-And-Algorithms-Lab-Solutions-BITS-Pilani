#include <stdio.h>
#include <math.h>
#include "ListOps.h"

List makeArray(FILE *fp1, long long int size){
	List ptr, l = (List)malloc((size)*sizeof(Element));
	ptr = l;
	int a;
	a = fscanf(fp1, "%lld", &ptr -> number);
	while(feof(fp1) == 0){
		ptr++;
		a = fscanf(fp1, "%lld", &ptr -> number);		
	}
	return l;
}
