#include "AVLPurchase.h"

int main(int argc, char *argv[]){
	FILE * fp;
	PurchaseData pd = NULL, result = NULL ;
	int cust = 0, item = 0;
	if (argc != 3) {
        	fprintf(stderr, "Program requires two text files as arguments!\n");
		exit(1);
    	}
	if((fp = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "\nThe File could not be opened!\n");
		return 0;
	}
    	pd = buildTree(fp);
	fclose(fp);
	fp = fopen(argv[2], "w");
	fprintf (fp, "Customer ID\tItem ID's Purchased\n" ) ;
    	display (fp, pd) ;
	fprintf(fp, "\n");
	fclose(fp);
	do {
        	printf("Enter a Customer ID to find his purchases: \t");
        	scanf("%d", &cust);
        	result = find(pd, cust);
		if(result == NULL)
        		printf("%d has not purchased anything.\n", cust);
		else
			printElement(stdout, result);
	} while(ask_user());
	deltree(pd) ;
	return 0;
}
