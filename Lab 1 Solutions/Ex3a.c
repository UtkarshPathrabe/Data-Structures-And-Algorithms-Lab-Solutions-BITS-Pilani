#include <stdio.h>
#include <stdlib.h>

struct linked_list{
	char c;
	struct linked_list *next;
	struct linked_list *previous;
};
typedef struct linked_list node;

int find_Palindrome(node *, node *);

int main(int argc, char *argv[]){
	FILE *fp1;
	node *head, *tail, *ptr;
	char a;
	int result;
	
	if((fp1 = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "The First File could not be opened.");
		return 1;
	}
	
	head = NULL;
	tail = head;
	ptr = tail;
	
	a = getc(fp1);
	while(a != EOF){
		if(head == NULL){
			head = (node *)malloc(sizeof(node));
			head -> c = a;
			head -> next = NULL;
			head -> previous = NULL;
		}else{
			tail = (node *)malloc(sizeof(node));
			tail -> c = a;
			tail -> next = NULL;
			if(head -> next == NULL){
				tail -> previous = head;
				head -> next = tail;
				ptr = tail;
			}else{
				tail -> previous = ptr;
				ptr -> next = tail;
				ptr = tail; 
			}
		}
		a = getc(fp1);
	}
	fclose(fp1);
	result = find_Palindrome(head, tail -> previous);
	free(head);
	if(result){
		printf("The String is NOT Paindrome.\n\n");
	}else{
		printf("The String is Palindrome.\n\n");
	}
	return 0;
}

int find_Palindrome(node *a, node *b){
	int i = 0;
	while((a != b)){
		if(a -> next == b){
			if((a -> c) != (b -> c)){
				i = 1;
			}
			break;
		}
		if((a -> c) != (b -> c)){
			i = 1;
			break;
		}
		a = a -> next;
		b = b -> previous;
	}
	return i;
}
