//phone_book.h

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

struct node;
typedef struct node Contact;
typedef Contact *Head;
struct node{
	char name[30];
	double mnum;
	Head next;
};
