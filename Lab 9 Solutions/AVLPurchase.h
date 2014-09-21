#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct _purchaseInfo * PurchaseData;
typedef struct _list * List;

typedef struct _purchaseInfo{
    	int cust_id;
	int item_id;
    	int balfact;
    	PurchaseData left;
    	PurchaseData right;
	List link;
}pinfo;

typedef struct _list{
	int item_id;
	List next;
}list;

extern PurchaseData insert(PurchaseData , int , int , int *);
extern PurchaseData find(PurchaseData , int );
extern PurchaseData findall(PurchaseData , int );
extern int ask_user(void);
extern PurchaseData buildTree (FILE *);
extern void display (FILE * , PurchaseData );
extern void print (FILE * , List );
extern void printElement(FILE * , PurchaseData );
extern void deltree ( PurchaseData );
