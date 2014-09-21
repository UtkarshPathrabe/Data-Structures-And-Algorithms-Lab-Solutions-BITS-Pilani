#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

struct AVLNode{
    	char data[15];
    	int balfact;
    	struct AVLNode *left;
    	struct AVLNode *right;
	struct List *link;
};

struct List{
	int num;
	struct List *next;
};

extern struct AVLNode * insertdata (struct AVLNode *, char data[], int * , int *);
extern struct AVLNode * deldata (struct AVLNode *, char data[], int * );
extern struct AVLNode * del (struct AVLNode *, struct AVLNode *, int * );
extern struct AVLNode * balright (struct AVLNode *, int * );
extern struct AVLNode * balleft (struct AVLNode *, int * );
extern void display (FILE *, struct AVLNode * );
extern void print (FILE *, struct List *);
extern void deltree (struct AVLNode * );
extern struct AVLNode * searchdata(struct AVLNode *, char data[]);
extern int ask_user(void);
extern struct AVLNode * buildindex (FILE *, int * , int *);
