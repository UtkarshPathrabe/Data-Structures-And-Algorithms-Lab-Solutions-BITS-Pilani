#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *fp1, *fp2;
	char c;
	int i = 0;
	if((fp1 = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "The First File could not be opened.");
		return 1;
	}
	if(argc > 2){
		fp2 = fopen(argv[2], "w");
		i = 1;
	}
	c = getc(fp1);
	while(c != EOF){
		if(i){
			putc(c, fp2);
			c = getc(fp1);
		}else{
			printf("%c", c);
			c = getc(fp1);
		}
	}
	fclose(fp1);
	if(i){
		fclose(fp2);
	}
	printf("\n\n");
	return 0;
}
