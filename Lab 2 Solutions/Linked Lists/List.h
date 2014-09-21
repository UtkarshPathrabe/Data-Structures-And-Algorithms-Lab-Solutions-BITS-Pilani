//List.h

#include <stdio.h>

struct node;
typedef struct node Node;
typedef Node *Link;
struct node{
	long long int data;
	Link next;
};
typedef Link List;
