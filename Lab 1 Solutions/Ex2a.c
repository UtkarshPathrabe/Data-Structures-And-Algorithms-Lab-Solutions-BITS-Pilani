#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *fp1, *fp2;
	char c;
	if((fp1 = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "The First File could not be opened.");
		return 1;
	}
	fp2 = fopen(argv[2], "w");
	c = getc(fp1);
	while(c != EOF){
		putc(c, fp2);
		c = getc(fp1);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
