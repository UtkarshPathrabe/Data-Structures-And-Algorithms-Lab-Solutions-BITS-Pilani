#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BSTInOut.h"

Book input(FILE *fp, int *size){
	Book b;
	int i = 0, k, j;
	char t[30], a[30];
	double p;
	if(*size == 0){
		*size = 10;
	}
	b = (Book)malloc((*size) * sizeof(book));
	while((feof(fp) == 0) && (i < (*size))){
		j = fscanf(fp, "%d %s %s %lf", &k, t, a, &p);
		(b + i) -> key = k;
		strcpy((b + i) -> title, t);
		strcpy((b + i) -> author, a);
		(b + i) -> price = p;
		i++;
	}
	return b;
}

void InPrint(BST btree, FILE *fp){
	BookLink bl = btree -> root;
	fprintf(fp, "\nThe InOrder Tree Walk Gives:\n");
	InOrderPrint(bl, fp);
}

void InOrderPrint(BookLink x, FILE *fp){
	if(x != NULL){
		InOrderPrint(x -> left, fp);
		fprintf(fp, "%07d %30s %30s %8.2lf\n", x -> b.key, x -> b.title, x -> b.author, x -> b.price);
		InOrderPrint(x -> right, fp);
	}
}

void printBook(book s, FILE *fp){
	fprintf(fp, "\n The Book is: %07d %30s %30s %8.2lf\n", s.key, s.title, s.author, s.price);
}
