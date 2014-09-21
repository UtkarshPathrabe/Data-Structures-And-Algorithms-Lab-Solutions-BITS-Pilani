#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linked_list{
	char id[12];
	char name[30];
	float marks;
	struct linked_list *next;
};
typedef struct linked_list node;

void print(node *, FILE *);
node *insert_Sort(node *, char[12], char[30], float);

int main(int argc, char *argv[]){
	FILE *f1;
	char a[12];
	char n[30];
	float m;
	node *head = NULL;
	
	if((f1 = fopen(argv[1], "r")) == NULL){
		printf("The file could not be opened!");
		return 0;
	}
	fscanf(f1, "%s %s %f", a, n, &m);
	
	while(!feof(f1)){
		if(head == NULL){		/* create base node */
			head = (node *)malloc(sizeof(node));
			strcpy(head -> id, a);
			strcpy(head -> name, n);
			head -> marks = m;
			head -> next = NULL;
		}else{					/* insert next item */
			head = insert_Sort(head, a, n, m);
		}
		int p = fscanf(f1, "%s %s %f", a, n, &m);
	}
	fclose(f1);
	f1 = fopen(argv[2], "w");
	print(head, f1);
	fclose(f1);
	free(head);
}

node *insert_Sort(node *list, char a[12], char n[30], float m){
	node *p1, *p2, *p;
	p1 = NULL;
	p2 = list;
	int flag = 0, store;
	
	for( ;p2 -> marks > m; p2 = p2 -> next){
		p1 = p2;
		if(p2 -> next == NULL){
			p2 = p2 -> next;
			break;
		}
	}
	p = (node *)malloc(sizeof(node));
	strcpy(p -> id, a);					
	strcpy(p -> name, n);				   
	p -> marks = m;
	p -> next = p2;
	if(p1 == NULL){
		list = p;
		flag = 1;						
	}else{
		p1 -> next = p;
	}
	if(p -> next != NULL){
		p2 = p -> next;
		while((p2 -> marks) == m){
			store = strcmp(p -> id, p2 -> id);
			if(store > 0){
				if(flag){
					p -> next = p2 -> next;
					p2 -> next = p;
					list = p2;
				}else{
					p -> next = p2 -> next;
					p1 -> next = p2;
					p2 -> next = p;
					p1 = p1 -> next; 
				}
			}
			if(p2 -> next != NULL){
				p2 = p2 -> next;
			}else{
				break;
			}
		}
	}
	return (list);
}

void print(node *list, FILE *f){
	int rank = 1;
	fprintf(f, "**************************************************\n");
	fprintf(f, "\n\t\tBITS-PILANI 'DSA COURSE' 2013-14\n\n");
	fprintf(f, "\tRANK\t\tNAME OF STUDENT\n\n");
	while(list != NULL){
		fprintf(f, "\t%3d\t\t%s\n", rank, list -> name);
		list = list -> next;
		rank += 1;
	}
	fprintf(f, "\n**************************************************\n");
}
