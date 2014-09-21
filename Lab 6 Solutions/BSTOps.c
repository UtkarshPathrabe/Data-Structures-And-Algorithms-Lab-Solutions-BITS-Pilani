#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "BSTOps.h"

BST createEmptyBST(){
	BST tree = (BST)malloc(sizeof(bst));
	tree -> total = 0;
	tree -> height = 0;
	tree -> root = NULL;
	return tree;
}

BST insert_BST(BST btree, book s){
	BookLink z = (BookLink)malloc(sizeof(book_node));
	BookLink y = NULL;
	BookLink x = btree -> root;
	z -> p = NULL;
	z -> b.key = s.key;
	strcpy(z -> b.title, s.title);
	strcpy(z -> b.author, s.author);
	z -> b.price = s.price;
	z -> left = NULL;
	z -> right = NULL;
	btree -> total += 1;
	while(x != NULL){
		y = x;
		if((z -> b.key) < (x -> b.key)){
			x = x -> left;
		}else{
			x = x -> right;
		}
	}
	z -> p = y;
	if(y == NULL){
		btree -> root = z;
	}else if((z -> b.key) < (y -> b.key)){
		y -> left = z;
	}else{
		y -> right = z;
	}
	btree -> height = getHeight(btree);
	return btree;
}

Boolean find_BST(BST btree, book s){
	BookLink x = btree -> root;
	while((x != NULL) && (s.key != x -> b.key)){
		if((s.key) < (x -> b.key)){
			x = x -> left;
		}else{
			x = x -> right;
		}
	}
	if(x == NULL){
		return False;
	}else if((strcmp(x -> b.title, s.title) == 0) && (strcmp(x -> b.author, s.author) == 0) && (x -> b.price == s.price)){
		return True;
	}else{
		return False;
	}
}

BookLink find_BSTree(BST btree, book s){
        BookLink x = btree -> root;
        while((x != NULL) && (s.key != x -> b.key)){
                if((s.key) < (x -> b.key)){
                        x = x -> left;
                }else{
                        x = x -> right;
                }
        }
        if(x == NULL){
                return NULL;
        }else if((strcmp(x -> b.title, s.title) == 0) && (strcmp(x -> b.author, s.author) == 0) && (x -> b.price == s.price)){
                return x;
        }else{
                return NULL;
   	}
}

BookLink Minimum(BookLink x){
	while(x -> left != NULL){
		x = x -> left;
	}
	return x;
}

BookLink Maximum(BookLink x){
        while(x -> right != NULL){
                x = x -> right;
        }
        return x;
}

BST delete_BST(BST btree, book s){
	BookLink z = find_BSTree(btree, s), y;
	if(z == NULL){
		return btree;
	}
	if(z -> left == NULL){
		btree = Transplant(btree, z, z -> right);
	}else if(z -> right == NULL){
		btree = Transplant(btree, z, z -> left);
	}else{
		y = Minimum(z -> right);
		if(y -> p != z){
			btree = Transplant(btree, y, y -> right);
			y -> right = z -> right;
			y -> right -> p = y;
		}
		btree = Transplant(btree, z, y);
		y -> left = z -> left;
		y -> left -> p = y;
	}
	btree -> total -= 1;
	btree -> height = getHeight(btree);
	return btree;
}

BST Transplant(BST btree, BookLink u, BookLink v){
	if(u -> p == NULL){
		btree -> root = v;
	}else if(u == (u -> p -> left)){
		u -> p -> left = v;
	}else{
		u -> p -> right = v;
	}
	if(v != NULL){
		v -> p = u -> p;
	}
	return btree;
}

int getHeight(BST btree){
	int x;
	if(btree -> root == NULL){
		x = 0;
	}else{
		x = Height(btree -> root) - 1;
	}
	return x;
}

int Height(BookLink bl){
	if((bl == NULL)){
		return 0;
	}else{
		return (1 + fmax(Height(bl -> left), Height(bl -> right)));
	}
}

book find_latestBook(BST btree){
	book t;
	BookLink x = btree -> root;
	while(x -> right != NULL){
		x = x -> right;
	}
	t = x -> b;
	return t;
}

book find_oldestBook(BST btree){
	book t;
        BookLink x = btree -> root;
        while(x -> left != NULL){
                x = x -> left;
        }
        t = x -> b;
        return t;
}

book find_MaxPrice(BST btree){
	book t;
	BookLink x = btree -> root, y;
	y = InOrder(x);
	t = y -> b;
	return t;
}

BookLink InOrder(BookLink root){
	BookLink y, current, pre;
	if(root == NULL){
		return NULL;
	}
	y = root;
	current = root;
	while(current != NULL){
		if(current -> left == NULL){
			if((current -> b.price) > (y -> b.price)){
				y = current;
			}
			current = current -> right;
		}else{
			pre = current -> left;
			while((pre -> right != NULL) && (pre -> right != current)){
        			pre = pre -> right;
			}
			if(pre -> right == NULL){
				pre -> right = current;
				current = current -> left;
			}else{
				pre -> right = NULL;
				if((current -> b.price) > (y -> b.price)){
                                	y = current;
                        	}
				current = current -> right;
			}
		}
	}
	return y;
}

book find_MinPrice(BST btree){
	book t;
        BookLink x = btree -> root, y;
        y = PreOrder(x);
        t = y -> b;
	return t;
}

BookLink PreOrder(BookLink root){
	BookLink y = root, current;
	while(root != NULL){
		if(root -> left == NULL){
			if((root -> b.price) < (y -> b.price)){
				y = current;
			}
			root = root -> right;
		}else{
			current = root -> left;
			while ((current -> right != NULL) && (current -> right != root)){
				current = current -> right;
			}
			if(current -> right == root){
				current -> right = NULL;
				root = root -> right;
			}else{
				if((current -> b.price) < (y -> b.price)){
					y = current;
				}
				current->right = root;
				root = root->left;
			}
		}
	}
	return y;
}

BST reOrderBST(BST btree){
	BST tree = createEmptyBST();
	tree = reInOrder(tree, btree -> root);
	return tree;
}

BST reInOrder(BST btree, BookLink root){
        BookLink y, current, pre;
        if(root == NULL){
                return NULL;
        }
        y = root;
        current = root;
        while(current != NULL){
                if(current -> left == NULL){
                        btree = reInsert_BST(btree, current -> b);
                        current = current -> right;
                }else{
                        pre = current -> left;
                        while((pre -> right != NULL) && (pre -> right != current)){
                                pre = pre -> right;
                        }
                        if(pre -> right == NULL){
                                pre -> right = current;
                                current = current -> left;
                        }else{
                                pre -> right = NULL;
                                btree = reInsert_BST(btree, current -> b);
                                current = current -> right;
                        }
                }
        }
        return btree;
}

BST reInsert_BST(BST btree, book s){
        BookLink z = (BookLink)malloc(sizeof(book_node));
        BookLink y = NULL;
        BookLink x = btree -> root;
        z -> p = NULL;
        z -> b.key = s.key;
        strcpy(z -> b.title, s.title);
        strcpy(z -> b.author, s.author);
        z -> b.price = s.price;
        z -> left = NULL;
        z -> right = NULL;
        btree -> total += 1;
        while(x != NULL){
                y = x;
                if((z -> b.price) <= (x -> b.price)){
                        x = x -> left;
                }else{
                        x = x -> right;
                }
        }
        z -> p = y;
        if(y == NULL){
                btree -> root = z;
        }else if((z -> b.price) <= (y -> b.price)){
                y -> left = z;
        }else{
                y -> right = z;
        }
        btree -> height = getHeight(btree);
        return btree;
}
