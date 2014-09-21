#include <stdio.h>
#include <stdlib.h>
#include "ListOps.h"

void create(List list, FILE *fp);

List makeList(FILE *fp, long long int size){
        List head = NULL, ptr = NULL;
        int a;
	head = (List)malloc(sizeof(Node));
        a = fscanf(fp, "%lld", &head -> data);
	head -> next = NULL;
	ptr = head;
        while(feof(fp) == 0){
		ptr -> next = (List)malloc(sizeof(Node));
                a = fscanf(fp, "%lld", &ptr -> next -> data);
		ptr = ptr -> next;
		ptr -> next = NULL;
        }
        return head;
}
