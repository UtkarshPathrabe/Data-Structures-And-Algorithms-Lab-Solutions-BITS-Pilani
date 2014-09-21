//phone_book_main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone_book.h"

int main(int argc, char *argv[]){
	FILE *fp;
	Head h = NULL, temp = NULL;
	int i=0, j=0;
	char name[30];
	h = uploadAddresses(h, argv[1]);
	fp = fopen(argv[3], "w");
	printAddressBook(h, fp);
	h = uploadAddresses(h, argv[2]);
	printAddressBook(h, fp);
	printf("\nEnter any name whose phone number you want to search:\t");
	i = scanf("%s", name);
	temp = searchByName(h, name);
	if(temp != NULL)
		printf("\n%-30.30s\t%12.0f\n",temp->name,temp->mnum);
	else
		printf("\nNo Such Name Exits In The Phone-Book!\n");
	fclose(fp);
	return 0;
}
