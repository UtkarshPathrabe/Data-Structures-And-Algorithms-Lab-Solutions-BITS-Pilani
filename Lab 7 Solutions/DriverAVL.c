#include "AVLTreeIndex.h"

int main(int argc, char *argv[]){
	FILE * fp;
	struct AVLNode *avl = NULL, *result = NULL ;
	int h, count = 0;
	char name[15];
	if (argc != 3) {
        	fprintf(stderr, "Program requires two text files as arguments!\n");
		exit(1);
    	}
	if((fp = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "\nThe File could not be opened!\n");
		return 0;
	}
    	avl = buildindex(fp, &h, &count);
	fclose(fp);
	fp = fopen(argv[2], "w");
	fprintf (fp, "***************************************************************INDEX******************************************************\n" ) ;
    	display (fp, avl) ;
	fprintf(fp, "\n");
	fclose(fp);
	//do {
        //	printf("Enter a name to search: \t");
        //	scanf("%s", name);
        //	result = searchdata(avl, name);
	//	if(result == NULL)
        //		printf("%s not found.\n", name);
	//	else
	//		printf("%s found.\n", name);
	//} while(ask_user());
	deltree(avl) ;
	return 0;
}
