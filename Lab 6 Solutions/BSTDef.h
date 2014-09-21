//Binary Search Tree Definitions

typedef struct{
	int key;
	char title[30];
	char author[30];
	double price;
}book;
typedef book *Book;

struct node;
typedef struct node book_node;
typedef book_node* BookLink;
struct node{
        BookLink p;
        book b;
        BookLink left;
        BookLink right;
};

typedef struct{
	BookLink root;
	int total;
	int height;
}bst;
typedef bst* BST;

enum boolean{False = 0, True = 1};
typedef enum boolean Boolean;
