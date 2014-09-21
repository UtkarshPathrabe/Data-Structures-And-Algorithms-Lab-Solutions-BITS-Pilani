#include "tree.h"

int main(int argc, char *argv[]){
	FILE *fp;
	Node root = NULL, result = NULL;
	clock_t time;
	int i, count;
	if (argc != 3) {
        	fprintf(stderr, "Program requires two text files as arguments!\n");
		exit(1);
    	}
	if((fp = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "\nThe File could not be opened!\n");
		return 0;
	}
	time = clock(); 
	root = MakeBST(fp);
	printf("Storing numbers in a BST took %6.10fs.\n", print_time(time));
	fclose(fp);
	printf("Before Balancing, Height: %d.\n", Height(root));
	printf("Before Balancing, Sum of the Absolute difference in height of every node: %d.\n", SumAbsDiff(root));
	DSWBalancingAlgo(root);
	fp = fopen(argv[2], "w");
	fprintf(fp, "The Inorder-Tree-Walk gives:\n\n");
	PrintTree(fp, root);
	fclose(fp);
	printf("After Balancing, Height: %d.\n", Height(root));
	printf("After Balancing, Sum of the Absolute difference in height of every node: %d.\n", SumAbsDiff(root));
	//loop for searching in BST
	do {
		count = 0;
        	printf("Enter a number to search: ");
        	scanf("%d", &i);
        	printf("BST:\n");
        	time = clock();
        	result = FindNode(root, i, &count);
        	print_result(result, count);
        	printf(", took %6.10fs.\n", print_time(time));
	} while(ask_user());
	return 0;
	DeleteTree(root);
	return 0;
}
