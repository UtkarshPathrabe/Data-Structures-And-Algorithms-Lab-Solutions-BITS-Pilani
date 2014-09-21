typedef struct node* Elem1; 

struct node
{
	int stage;
	int last;
	int first;
	Elem1 next;
};

typedef struct stack1 *Stack1; 

struct stack1
{
	Elem1 top;
	int size; 
};

#ifndef _BOOLEAN
#define _BOOLEAN
typedef enum {FALSE=0, TRUE=1} Boolean; 
#endif


