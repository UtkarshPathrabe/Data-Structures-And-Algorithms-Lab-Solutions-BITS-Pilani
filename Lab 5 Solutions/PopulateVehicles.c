//PopulateVehicles.c

#include "OffenceOps.h"

owner populateVehicles(FILE *source){
// Check if source exists
	if(source == NULL){
		fprintf(stderr, "Input file not found. Exiting.");
		exit(1);
	}
	owner head = (owner)malloc(sizeof(ownr));
	head -> next = NULL;
	// int used = 0 ; //number of tuples read
	// Read file into a linked list
	int uid, vehno;
	char c;
	while(fscanf(source, "%d%c%d\n", &uid,&c,&vehno) != EOF){
	// Create a new node and store data in it
		owner newNode = (owner)malloc(sizeof(ownr));
		newNode -> uid = uid;
		newNode -> vno = vehno;
		// Find the first node larger than the newNode
		owner ptr = head;
		while(ptr -> next != NULL && ptr -> next -> uid < uid){
			ptr = ptr -> next;
		}
		if (ptr -> next == NULL){
			newNode -> next = NULL;
			// printf("poop\n");
			ptr -> next = newNode;	
		}else{
			newNode -> next = ptr -> next;
			ptr -> next = newNode;
		}
	}
	return head;
}

void printVehicleListP(FILE * fp, owner node){
	fprintf(fp, "The Vehicles List in sorted order is:\n\nUID\t\tVehicle No.\n");
	if(node -> next!=NULL){
        	node = node -> next;
	}
  	while(node != NULL){
    		fprintf(fp, "%d,\t%d", node -> uid, node -> vno);
    		fprintf(fp, "\n");
		node = node -> next;
	}
}

