#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ListOps.h"

int main(){
	FILE *fp1;
	List head;
	fp1 = fopen("Input.txt", "w");
	fp1 = input(fp1, 100);
	fclose(fp1);
	fp1 = fopen("Input.txt", "r");
	head = makeList(fp1, 100);
	fclose(fp1);
	fp1 = fopen("Output.txt", "w");
	print(head, 100, fp1);
	fclose(fp1);
	return 0;	
}
