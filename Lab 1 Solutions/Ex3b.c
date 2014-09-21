#include <stdio.h>
#include <stdlib.h>

struct linked_list{
	int number;
	struct linked_list *next;
};
typedef struct linked_list node;

void create(node *, FILE *);
void print(node *, FILE *);
node *sort(node *, node *);

int main(int argc, char *argv[]){
	node *head1, *head2, *head3;
	FILE *f1, *f2;
	
	if(((f1 = fopen(argv[1], "r")) == NULL) || ((f2 = fopen(argv[2], "r")) == NULL)){
		printf("The file could not be opened.\n");
		return 1;
	}
	
	head1 = (node *)malloc(sizeof(node));
	head2 = (node *)malloc(sizeof(node));
	create(head1, f1);
	create(head2, f2);
	
	fclose(f1);
	fclose(f2);
	
	f1 = fopen(argv[3], "w");
	head3 = sort(head1, head2);
	print(head3, f1);
	fclose(f1);
	free(head1);
	free(head2);
	free(head3);
	
	return 0;
	
}

void create(node *list, FILE *f){
	int p = fscanf(f, "%d", &list -> number);
	if(list -> number == -999){
		list -> next = NULL;
	}else{
		list -> next = (node *)malloc(sizeof(node));
		create(list -> next, f);
	}
}

void print(node *list, FILE *f){
	if(list -> next != NULL){
		fprintf(f, " %d -->", list -> number);
		if(list -> next -> next == NULL){
			fprintf(f, "%d\n", list -> next -> number);
		}
		print(list -> next, f);
	}
	return;
}

node *sort(node *a, node *b){
	node *head;
	head = (node *)malloc(sizeof(node));
	if((a -> number != -999) && (b -> number != -999)){
		if((a -> number) < (b -> number)){
			head -> number = a -> number;
			head -> next = sort(a -> next, b);
		}else{
			head -> number = b -> number;
			head -> next = sort(a, b -> next);
		}
	}else if((a -> number == -999) && (b -> number != -999)){
		head -> number = b -> number;
		head -> next = sort(a, b -> next);
	}else if((a -> number != -999) && (b -> number == -999)){
		head -> number = a -> number;
		head -> next = sort(a -> next, b);
	}else{
		head -> number = -999;
		head -> next = NULL;
	}
	return head;
}
