//tree.h

#include <stdio.h>	//File and termininal input/output
#include <string.h>	//String handling functions
#include <stdlib.h>	//General utilities
#include <ctype.h>	//Character handling functions
#include <time.h>	//Time related functions
#include <math.h>	//Mathematical functions

typedef struct node * Node;
typedef struct node{
	int data;
	Node left;
	Node right;
	Node parent;
}nod;

enum boolean{False = 0, True = 1};
typedef enum boolean Boolean;

extern Boolean LeftRotate(Node node);
extern Boolean RightRotate(Node node);
extern void DSWBalancingAlgo(Node root);
extern int Height(Node root);
extern int SumAbsDiff(Node root);
extern Node InsertValue(Node root,int value);
extern void PrintTree(FILE * fp, Node root);
extern void DeleteTree(Node root);
extern Node FindNode(Node root, int value, int *count);
extern void Transplant(Node root, Node u, Node v);
extern Node DeleteValue(Node root, int value);
extern Node MinValue(Node root);
extern Node MaxValue(Node root);
extern Node SuccessorValue(Node x);
extern Node PredecessorValue(Node x);
extern Node MakeBST(FILE *fp);
extern double print_time(clock_t time);
extern void print_result(Node result, int count);
extern int ask_user(void);
