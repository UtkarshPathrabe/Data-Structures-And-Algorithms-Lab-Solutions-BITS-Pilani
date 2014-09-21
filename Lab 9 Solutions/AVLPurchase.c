#include "AVLPurchase.h"

/* inserts an element into AVL Tree */
PurchaseData insert(PurchaseData root, int cust_id, int item_id, int *h){
	PurchaseData node1, node2 ;

	if (!root){
        	root = (PurchaseData)malloc(sizeof(pinfo)) ;
        	root -> cust_id = cust_id;
		root -> item_id = item_id;
        	root -> left = NULL;
        	root -> right = NULL;
        	root -> balfact = 0;
		root -> link = NULL;
        	*h = TRUE;
		return (root);
	}

	if(cust_id < root -> cust_id){
        	root -> left = insert ( root -> left, cust_id, item_id, h);
        	/* If left subtree is higher */
		if(*h){
            		switch (root -> balfact){
                		case 1:
					node1 = root -> left ;
                    			if(node1 -> balfact == 1){
                        			//printf ( "\nRight rotation along %s.", root -> cust_id ) ;
                        			root -> left = node1 -> right ;
                        			node1 -> right = root ;
                        			root -> balfact = 0 ;
                    				root = node1 ;
                    			}else{
                        			//printf ( "\nDouble rotation, left along %s", node1 -> cust_id ) ;
                        			node2 = node1 -> right ;
                        			node1 -> right = node2 -> left ;
                        			//printf ( " then right along %s.\n", root -> cust_id ) ;
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

    	if(cust_id > root -> cust_id){
        	root -> right = insert ( root -> right, cust_id, item_id, h) ;
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
                        			//printf ( "\nLeft rotation along %s.", root -> cust_id ) ;
                        			root -> right = node1 -> left ;
                        			node1 -> left = root ;
                        			root -> balfact = 0 ;
                        			root = node1 ;
                    			}else{
                        			//printf ( "\nDouble rotation, right along %s", node1 -> cust_id ) ;
                        			node2 = node1 -> left ;
                        			node1 -> left = node2 -> right ;
                        			node2 -> right = node1 ;
                        			//printf ( " then left along %s.\n", root -> cust_id ) ;
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

/* searches the tree for a specific cust_id */
PurchaseData find(PurchaseData root, int cust_id){
	while((root != NULL) && (cust_id != root -> cust_id)){
		if(cust_id < root -> cust_id){
			root = root -> left;
		}else{
			root = root -> right;
		}
	}
	return root;
}

/* searches the tree for all item_id's purchased by cust_id */
PurchaseData findall(PurchaseData root, int cust_id){
	while((root != NULL) && (cust_id != root -> cust_id)){
		if(cust_id < root -> cust_id){
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

PurchaseData buildTree (FILE *fp){
	PurchaseData root = NULL, result = NULL;
	List l = NULL, m = NULL;
	int cust_id = 0, item_id = 0;
	int j = 0, h = 0;
	while(feof(fp) == 0){
		j = fscanf(fp, "%d\t%d", &cust_id, &item_id);
		result = find(root, cust_id);
		if(result == NULL){
			root = insert(root, cust_id, item_id, &h);
		}else{
			l = result -> link;
			if(l == NULL){
				m = (List)malloc(sizeof(list));
				m -> item_id = item_id;
				m -> next = NULL;
				result -> link = m;
			}else{
				while(l != NULL){
					l = l -> next;
				}
				m = (List)malloc(sizeof(list));
				m -> item_id = item_id;
				m -> next = NULL;
				l -> next = m;
			}
		}
	}
	return root;
}

/* displays the tree in-order */
void display (FILE * fp, PurchaseData root ){
	if ( root != NULL ){
        	display (fp, root -> left ) ;
        	fprintf (fp, "%-8d\t%-8d", root -> cust_id, root -> item_id) ;
		if(root -> link != NULL){
			print (fp, root -> link ) ;
		}
		fprintf(fp, ".\n");
        	display (fp, root -> right ) ;
    	}
}

/* prints the contents of the list */
void print (FILE * fp, List list){
	while(list != NULL){
		fprintf(fp, ", %-8d", list -> item_id);
		list = list -> next;
	}
}

/* prints the contents of a single node */
void printElement(FILE * fp, PurchaseData root){
	fprintf (fp, "%-8d has purchased items %-8d", root -> cust_id, root -> item_id) ;
	if(root -> link != NULL){
		print (fp, root -> link ) ;
	}
	fprintf(fp, ".\n");
}

/* deletes the tree */
void deltree ( PurchaseData root ){
    	if(root != NULL){
        	deltree ( root -> left ) ;
        	deltree ( root -> right ) ;
    	}
    	free ( root ) ;
}
