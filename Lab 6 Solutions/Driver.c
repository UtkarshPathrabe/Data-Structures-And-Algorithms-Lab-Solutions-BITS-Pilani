#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "BSTInOut.h"

int main(int argc, char *argv[]){
	FILE *fp;
	Book list;
	book b1, b2, b3, b4, b5;
	int size, i = 0, height = 0;
	BST tree, newTree;
	Boolean t;
	book boo;
	boo.key = 53;
	strcpy(boo.title,"Winning_Formulas");
	strcpy(boo.author, "A.R.K.Sarma");
	boo.price = 120.00;
	if(argv[3] != NULL){
		size = atoi(argv[3]);
	}else{
		size = 0;
	}
	if((fp = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "\nThe File could not be opened!\n");
		return 0;
	}
	list = input(fp, &size);
	fclose(fp);
	tree = createEmptyBST();
	for(i = 0; i < size; i++){
		tree = insert_BST(tree, *(list + i));
	}
	fp = fopen(argv[2], "w");
	InPrint(tree, fp);
	height = getHeight(tree);
	fprintf(fp, "\nThe height of the tree is %d.\n", height);
	b1 = *(list + 5);
	t = find_BST(tree, boo);
	if(t){
		fprintf(fp, "\nSearch:\tThe book is present.\n");
	}else{
		fprintf(fp, "\nSearch:\tThe book is absent.\n");
	}
	b2 = find_latestBook(tree);
	fprintf(fp, "\nLatest Book:");
	printBook(b2, fp);
	b3 = find_oldestBook(tree);
        fprintf(fp, "\nOldest Book:");
	printBook(b3, fp);
	b4 = find_MaxPrice(tree);
	fprintf(fp, "\nMaximum Price Book:");
        printBook(b4, fp);
	b5 = find_MinPrice(tree);
        fprintf(fp, "\nMinimum Price Book:");
        printBook(b5, fp);
	newTree = reOrderBST(tree);
	fprintf(fp, "\nRe-Ordered Binary Tree According to Price of Books.");
	InPrint(newTree, fp);
	height = getHeight(newTree);
        fprintf(fp, "\nThe height of the tree is %d.\n", height);
	i = size - 4;
	tree = delete_BST(tree, *(list + i));
	fprintf(fp, "\nThe Original Binary Tree after deleting the book:");
	printBook(*(list + i), fp);
	InPrint(tree, fp);
	height = getHeight(tree);
	fprintf(fp, "\nThe height of the tree is %d.\n", height);
	fclose(fp);
	free(list);
	free(tree);
	free(newTree);
	return 0;
}
