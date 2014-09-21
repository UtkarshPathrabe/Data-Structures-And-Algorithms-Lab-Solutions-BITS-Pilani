//phone_book_driver.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone_book.h"

Head uploadAddresses(Head h, char n[30]){
	FILE *fp;
	char m[30];
	int i, j;
	double mob;
	if((fp = fopen(n, "r")) == NULL){
		fprintf(stderr, "\nThe File could not be opened!\n");
		return NULL;
	}
	if(h == NULL){
		h = createAddressBook();
	}
	i = fscanf(fp, "%s %lf", m, &mob);
	while((feof(fp) == 0)){
		h = insertAddress(h, m, mob);
		i = fscanf(fp, "%s %lf", m, &mob);
	}
	fclose(fp);
	return h;
}
