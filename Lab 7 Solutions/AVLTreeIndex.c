#include "AVLTreeIndex.h"

/* inserts an element into tree */
struct AVLNode * insertdata(struct AVLNode *root, char data[], int *h , int *count){
	struct AVLNode *node1, *node2 ;

	if (!root){
		*count += 1;
        	root = (struct AVLNode*)malloc(sizeof(struct AVLNode)) ;
        	strcpy(root -> data, data);
        	root -> left = NULL;
        	root -> right = NULL;
        	root -> balfact = 0;
		root -> link = (struct List*)malloc(sizeof(struct List));
		root -> link -> num = *count;
		root -> link -> next = NULL;
        	*h = TRUE;
		return (root);
	}

	if(strcmp(data, root -> data) < 0){
        	root -> left = insertdata ( root -> left, data, h, count);
        	/* If left subtree is higher */
		if(*h){
            		switch (root -> balfact){
                		case 1:
					node1 = root -> left ;
                    			if(node1 -> balfact == 1){
                        			//printf ( "\nRight rotation along %s.", root -> data ) ;
                        			root -> left = node1 -> right ;
                        			node1 -> right = root ;
                        			root -> balfact = 0 ;
                    				root = node1 ;
                    			}else{
                        			//printf ( "\nDouble rotation, left along %s", node1 -> data ) ;
                        			node2 = node1 -> right ;
                        			node1 -> right = node2 -> left ;
                        			//printf ( " then right along %s.\n", root -> data ) ;
                        			node2 -> left = node1 ;
                        			root -> left = node2 -> right ;
                        			node2 -> right = root ;
                        			if ( node2 -> balfact == 1 )
							root -> balfact = -1 ;
                        			else
                            				root -> balfact = 0;
                        			if ( node2 -> balfact == -1 )
							node1 -> balfact = 1 ;
                        			else
                            				node1 -> balfact = 0 ;
							root = node2 ;
                    			}
                    			root -> balfact = 0 ;
                    			*h = FALSE ;
                    			break ;

                		case 0:
					root -> balfact = 1 ;
                    			break ;

                		case -1:
                    			root -> balfact = 0 ;
                    			*h = FALSE ;
            		}
        	}
    	}

    	if(strcmp(data, root -> data) > 0){
        	root -> right = insertdata ( root -> right, data, h, count) ;
        	/* If the right subtree is higher */
		if ( *h ){
            		switch ( root -> balfact ){
                		case 1:
                    			root -> balfact = 0 ;
                    			*h = FALSE ;
                    			break ;

                		case 0:
                    			root -> balfact = -1 ;
                    			break;

                		case -1:
                    			node1 = root -> right ;
                    			if ( node1 -> balfact == -1 ){
                        			//printf ( "\nLeft rotation along %s.", root -> data ) ;
                        			root -> right = node1 -> left ;
                        			node1 -> left = root ;
                        			root -> balfact = 0 ;
                        			root = node1 ;
                    			}else{
                        			//printf ( "\nDouble rotation, right along %s", node1 -> data ) ;
                        			node2 = node1 -> left ;
                        			node1 -> left = node2 -> right ;
                        			node2 -> right = node1 ;
                        			//printf ( " then left along %s.\n", root -> data ) ;
                        			root -> right = node2 -> left ;
                        			node2 -> left = root ;
						if ( node2 -> balfact == -1 )
							root -> balfact = 1 ;
                        			else
                        				root -> balfact = 0 ;
                        			if ( node2 -> balfact == 1 )
                        				node1 -> balfact = -1 ;
                        			else
                        				node1 -> balfact = 0 ;
						root = node2 ;
                    			}
                    			root -> balfact = 0 ;
                    			*h = FALSE ;
			}
        	}
	}
	return ( root ) ;
}

/* deletes an item from the tree */
struct AVLNode * deldata ( struct AVLNode *root, char data[], int *h ){
	struct AVLNode *node ;

    	if (!root){
        	//printf ( "\nNo such data." ) ;
        	return (root) ;
    	}else{
        	if(strcmp(data, root -> data) < 0){
            		root -> left = deldata ( root -> left, data, h ) ;
            	if ( *h )
                	root = balright ( root, h ) ;
       		}else{
            		if (strcmp(data, root -> data) > 0){
                		root -> right = deldata ( root -> right, data, h ) ;
                		if ( *h )
					root = balleft ( root, h ) ;
			}else{
                		node = root ;
                		if ( node -> right == NULL ){
                    			root = node -> left ;
                    			*h = TRUE ;
					free ( node ) ;
                		}else{
                    			if ( node -> left == NULL ){
                        			root = node -> right ;
                        			*h = TRUE ;
                   	 			free ( node ) ;
                    			}else{
                        			node -> right = del ( node -> right, node, h ) ;
                        			if ( *h )
							root = balleft ( root, h ) ;
                    			}
                		}
            		}
        	}
    	}
    	return ( root ) ;
}

struct AVLNode * del(struct AVLNode *succ, struct AVLNode *node, int *h){
	struct AVLNode *temp = succ;
	if ( succ -> left != NULL ){
        	succ -> left = del ( succ -> left, node, h ) ;
        	if ( *h )
			succ = balright ( succ, h ) ;
    	}else{
        	temp = succ ;
        	strcpy(node -> data, succ -> data);
        	succ = succ -> right ;
        	free ( temp ) ;
		*h = TRUE ;
    	}
    	return ( succ ) ;
}

/* balances the tree, if right sub-tree is higher */
struct AVLNode * balright ( struct AVLNode *root, int *h ){
	struct AVLNode *node1, *node2 ;

	switch ( root -> balfact ){
        	case 1:
			root -> balfact = 0 ;
            		break;

        	case 0:
			root -> balfact = -1 ;
			*h  = FALSE ;
            		break;

        	case -1:
			node1 = root -> right ;
            		if ( node1 -> balfact <= 0 ){
                		//printf ( "\nLeft rotation along %s.", root -> data ) ;
                		root -> right = node1 -> left ;
                		node1 -> left = root ;
                		if ( node1 -> balfact == 0 ){
                    			root -> balfact = -1 ;
                    			node1 -> balfact = 1 ;
					*h = FALSE ;
                		}else{
					root -> balfact = node1 -> balfact = 0 ;
                		}
                		root = node1 ;
            		}else{
                		//printf ( "\nDouble rotation, right along %s", node1 -> data );
                		node2 = node1 -> left ;
                		node1 -> left = node2 -> right ;
                		node2 -> right = node1 ;
                		//printf ( " then left along %s.\n", root -> data );
                		root -> right = node2 -> left ;
                		node2 -> left = root ;

                		if ( node2 -> balfact == -1 )
                    			root -> balfact = 1 ;
                		else
     					root -> balfact = 0 ;
                		if ( node2 -> balfact == 1 )
       					node1 -> balfact = -1 ;
                		else
                    			node1 -> balfact = 0 ;
                		root = node2 ;
                		node2 -> balfact = 0 ;
            		}
    	}
    	return ( root ) ;
}

/* balances the tree, if left sub-tree is higher */
struct AVLNode * balleft ( struct AVLNode *root, int *h ){
    	struct AVLNode *node1, *node2 ;

    	switch ( root -> balfact ){
        	case -1:
            		root -> balfact = 0 ;
            		break ;

        	case 0:
            		root -> balfact = 1 ;
            		*h = FALSE ;
            		break ;

        	case 1:
			node1 = root -> left ;
            		if ( node1 -> balfact >= 0 ){
                		//printf ( "\nRight rotation along %s.", root -> data ) ;
                		root -> left = node1 -> right ;
                		node1 -> right = root ;
                		if ( node1 -> balfact == 0 ){
                    			root -> balfact = 1 ;
                    			node1 -> balfact = -1 ;
                    			*h = FALSE ;
                		}else{
                    			root -> balfact = node1 -> balfact = 0 ;
                		}
                		root = node1 ;
            		}else{
                		//printf ( "\nDouble rotation, left along %s", node1 -> data ) ;
                		node2 = node1 -> right ;
                		node1 -> right = node2 -> left ;
                		node2 -> left = node1 ;
                		//printf ( " then right along %s.\n", root -> data ) ;
                		root -> left = node2 -> right ;
                		node2 -> right = root ;

                		if ( node2 -> balfact == 1 )
                	    		root -> balfact = -1 ;
                		else
					root -> balfact = 0 ;
                		if ( node2-> balfact == -1 )
                    			node1 -> balfact = 1 ;
                		else
					node1 -> balfact = 0 ;
                		root = node2 ;
                		node2 -> balfact = 0 ;
            		}
    	}
    	return ( root ) ;
}

/* displays the tree in-order */
void display (FILE * fp, struct AVLNode *root ){
	if ( root != NULL ){
        	display (fp, root -> left ) ;
        	fprintf (fp, "%-15.15s:\t", root -> data) ;
		print (fp, root -> link ) ;
		fprintf(fp, ".\n");
        	display (fp, root -> right ) ;
    	}
}

/* prints the contents of the list */
void print (FILE * fp, struct List *list){
	fprintf(fp, "%d", list -> num);
	list = list -> next;
	while(list != NULL){
		fprintf(fp, ", %d", list -> num);
		list = list -> next;
	}
}

/* deletes the tree */
void deltree ( struct AVLNode *root ){
    	if(root != NULL){
        	deltree ( root -> left ) ;
        	deltree ( root -> right ) ;
    	}
    	free ( root ) ;
}

/* searches the tree for a specific data */
struct AVLNode * searchdata(struct AVLNode * root, char data[]){
	while((root != NULL) && ((strcmp(data, root -> data) != 0))){
		if(strcmp(data, root -> data) < 0){
			root = root -> left;
		}else{
			root = root -> right;
		}
	}
	return root;
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

struct AVLNode * buildindex (FILE *fp, int *h, int *count){
	struct AVLNode * root = NULL, *result = NULL;
	struct List * l = NULL, *m = NULL;
	char name[15];
	int j;
	while(feof(fp) == 0){
		j = fscanf(fp, "%s", name);
		result = searchdata(root, name);
		if(result == NULL){
			root = insertdata(root, name, h, count);
		}else{
			*count += 1;
			l = result -> link;
			while(l -> next != NULL){
				l = l -> next;
			}
			m = (struct List*)malloc(sizeof(struct List));
			m -> num = *count;
			m -> next = NULL;
			l -> next = m;
		}
	}
	return root;
}
