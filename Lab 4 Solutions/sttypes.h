#ifndef _BOOLEAN
#define _BOOLEAN
typedef enum {FALSE=0, TRUE=1} Boolean;
#endif

struct snapShotStruct;
typedef struct snapShotStruct snap;
typedef snap *Elem;

struct snapShotStruct{
      	int siz;
	int sum;
	int stage;
        Boolean flag;
	Elem next;
};

typedef struct stack *Stack; 

struct stack{
	Elem top;
	int size; 
};
