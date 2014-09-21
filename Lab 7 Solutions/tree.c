//tree.c

#include "tree.h"

void PrintTree(FILE * fp, Node root){
	if(root != NULL){
		PrintTree(fp, root -> left);
		fprintf(fp, "%d\n", root -> data);
		PrintTree(fp, root -> right);
	}
}

Node FindNode(Node root, int value, int *count){
	while((root != NULL) && (value != root -> data)){
                if(value < root -> data){
                        root = root -> left;
			*count += 1;
                }else{
                        root = root -> right;
			*count += 1;
                }
        }
	return root;
}

Node MinValue(Node root){
	while(root -> left != NULL){
		root = root -> left;
	}
	return root;
}

Node MaxValue(Node root){
	while(root -> right != NULL){
		root = root -> right;
	}
	return root;
}

Node SuccessorValue(Node x){
	Node y;
	if(x -> right != NULL){
		return MinValue(x -> right);
	}
	y = x -> parent;
	while((y != NULL) && (x == y -> right)){
		x = y;
		y = y -> parent;
	}
	return y;
}

Node PredecessorValue(Node x){
	Node y;
	if(x -> left != NULL){
		return MaxValue(x -> left);
	}
	y = x -> parent;
	while((y != NULL) && (x == y -> left)){
		x = y;
		y = y -> parent;
	}
	return y;
}

Node InsertValue(Node root,int value){
	Node y = NULL, x = root, z = NULL;
	while(x != NULL){
		y = x;
		if(value < x -> data){
			x = x -> left;
		}else{
			x = x -> right;
		}
	}
	z = (Node)malloc(sizeof(nod));
	z -> data = value;
	z -> parent = y;
	if(y == NULL){
		root = z;
	}else if(value < y -> data){
		y -> left = z;
	}else{
		y -> right = z;
	}
	return root;
}

void Transplant(Node root, Node u, Node v){
	if(u -> parent == NULL)
		root = v;
	else if(u == u -> parent -> left)
		u -> parent -> left = v;
	else
		u -> parent -> right = v;
	if(v != NULL)
		v -> parent = u -> parent;
}

Node DeleteValue(Node root, int value){
	int count = 0;
	Node y = NULL, z = FindNode(root, value, &count);
	if(z -> left == NULL)
		Transplant(root, z, z -> right);
	else if(z -> right == NULL)
		Transplant(root, z, z -> left);
	else{
		y = MinValue(z -> right);
		if(y -> parent != z){
			Transplant(root, y, y -> right);
			y -> right = z -> right;
			y -> right -> parent = y;
		}
		Transplant(root, z, y);
		y -> left = z -> left;
		y -> left -> parent = y;
	}
	return root;
}

int SumAbsDiff(Node root){ 						// =0 Means a perfect balanced tree
	if(root == NULL){
		return 0;
	}
	return abs(Height(root -> left) - Height(root -> right)) + SumAbsDiff(root -> right) + SumAbsDiff(root -> left);
}

int Height(Node root){
	if(root == NULL){
		return 0;
	}
	return 1 + fmax(Height(root -> left), Height(root -> right));
}

// Rotates around the current node 
Boolean LeftRotate(Node node){  					// =True if rotate works, =False otherwise 
	Node nd;
	int data;
	if(node == NULL || node -> right == NULL){
		return False;
	}								// No Right Node!!
	nd = node -> right;
	node -> right = nd -> right;					// Move Node
	nd -> right = nd -> left;
	nd -> left = node -> left;
	node -> left = nd;
	data = node -> data;
	node -> data = nd -> data;
	nd -> data = data;
	return True;
}

// Rotate around current node
Boolean RightRotate(Node node){ 					// =True if rotate works, =False otherwise
	Node nd;
	int data;
	if(node == NULL || node -> left == NULL){
		return False;
	}	
	nd = node -> left;
	node -> left = nd -> left;
	nd -> left = nd -> right;
	nd -> right = node -> right;
	node -> right = nd;
	data = node -> data;
	node -> data = nd -> data;
	nd -> data = data;
	return True;
}

void DSWBalancingAlgo(Node root){
	Node p;
	int nodecount, i;
	///////////// Create Linear Back Bone ///////////////////
	for(p = root, nodecount = 0; p != NULL; p = p -> right, ++nodecount){
		while(RightRotate(p) == True) { }
	}
	////////////  Perform Balancing ///////////////////////
	for(i = nodecount / 2; i > 0; i /= 2){
		int k;
		for(p = root, k = 0; k < i; ++k, p = p -> right){
			LeftRotate(p);
		}
	}
}

void DeleteTree(Node root){
	if(root == NULL){
		return;
	}
	DeleteTree(root -> left);
	DeleteTree(root -> right);
	free(root);
}

Node MakeBST(FILE *fp){
	Node root = NULL;
	int k, j;
	while(feof(fp) == 0){
		j = fscanf(fp, "%d", &k);
		root = InsertValue(root, k);
	}
	return root;
}

double print_time(clock_t time){
	return ((double)(clock() - time)/CLOCKS_PER_SEC);
}

int ask_user(void){
	char c;
    	while(getchar() != '\n');
    	printf("Do you wish to perform another query? [y/n]: ");
    	scanf("%c", &c);
    	if(c == 'y')
        	return 1;
    	else
        	return 0;
}

void print_result(Node result, int count){
    	if(result == NULL)
		printf("Not found, compared %d times", count);
	else
        	printf("Number:\t%d,\nCompared %d times", result -> data, count);
}
