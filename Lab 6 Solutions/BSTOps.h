//Binary Search Tree Operation Definitions

#include <stdio.h>
#include "BSTDef.h"

extern BST createEmptyBST();
extern BST insert_BST(BST btree, book s);
extern Boolean find_BST(BST btree, book s);
extern BookLink find_BSTree(BST btree, book s);
extern BST delete_BST(BST btree, book s);
extern BST Transplant(BST btree, BookLink u, BookLink v);
extern book find_MaxPrice(BST btree);
extern book find_MinPrice(BST btree);
extern int getHeight(BST btree);
extern int Height(BookLink bl);
extern BookLink InOrder(BookLink bl);
extern BookLink PreOrder(BookLink bl);
extern book find_latestBook(BST btree);
extern book find_oldestBook(BST btree);
extern BST reOrderBST(BST btree);
extern BookLink Minimum(BookLink x);
extern BookLink Maximum(BookLink x);
extern BST reInOrder(BST btree, BookLink root);
extern BST reInsert_BST(BST btree, book s);
