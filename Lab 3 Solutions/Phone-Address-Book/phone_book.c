//phone_book.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone_book.h"

int length(Head h){
	Head temp = h -> next;
	int count = 0;
	while(temp != h){
		temp = temp -> next;
		count++;
	}
	return count;
}

Head createAddressBook(){
	Head N = (Head)malloc(sizeof(Contact));			//allocating memory to first element
	strcpy(N -> name, "");
	N -> mnum = 0;
	N -> next = N;						//circular linked-list
	return N;
}

int isNotFull(Head h){
	int i = length(h);
	if(i >= MAX_SIZE){
		return -1;
	}else{
		return i;
	}
}

int isEmpty(Head h){
	int i = length(h);
	if(i == 0){
		return -1;
	}else{
		return i;
	}
}

void printAddressBook(Head N, FILE *fp){
	Head temp = N -> next;
	fprintf(fp, "\n*************************************************************************************************************************\n\n");
	fprintf(fp, "\t\t** MY PHONE BOOK **\n\n");
	fprintf(fp, "\tNAME\t\t\t\tMOBILE NUMBER\n");
	for(temp = N -> next; temp != N; temp = temp -> next){
		fprintf(fp, "\t%-30.30s\t%10.0f\n", temp -> name, temp -> mnum);
	}
	fprintf(fp, "\nThese are the contents of your address book.\n");
	fprintf(fp, "*************************************************************************************************************************\n\n");
}

Head searchByName(Head h, char n[30]){
	Head temp = h -> next;
	int i = strcmp(temp -> name, n);
	while((temp != h) && (i != 0)){
		temp = temp -> next;
		i = strcmp(temp -> name, n);
	}
	if(!i){
		return temp;
	}else{
		return NULL;
	}
}

Head searchByName2(Head h, char n[30]){
        Head temp = h;
        int i = strcmp(temp -> next -> name, n);
        while((temp -> next != h) && (i != 0)){
                temp = temp -> next;
                i = strcmp(temp -> next -> name, n);
        }
        if(!i){
                return temp;
        }else{
                return NULL;
        }
}

Head deleteAddress(Head h, char n[30]){
	Head temp, p;
	int i;
	i = strcmp(n,"");
	if(!i)
		return h;
	temp = searchByName2(h, n);
	if(temp == NULL){
		fprintf(stderr, "\nThe Contact %s Doesn't Exist!!!\n", n);
	}else{
		p = temp -> next -> next;			/*Pointer to the node following the key node*/
		free(temp -> next);				//free key node
		temp -> next = p;				//establish link
	}
	return h;
}

Head insertAddress(Head h, char n[30], double num){
	Head p1, p2, p, temp;
	int i, j;
	p1 = h;
	p2 = h -> next;
	i = strcmp(p2 -> name, n);
	for(; i < 0; p2 = p2 -> next,i = strcmp(p2 -> name, n)){
		p1 = p2;
		if(p2 -> next == h){
			p2 = p2 -> next;
			break;
		}
	}
	if(i != 0){
		j = isNotFull(h);
		if(j == -1){
			temp = p2 -> next;
			h = deleteAddress(h, p2 -> name);
			p2 = temp;
			p2 -> next = temp -> next;
		}
		p = (Head)malloc(sizeof(Contact));
		strcpy(p -> name, n);
		p -> mnum = num;
		p -> next = p2;
		if(p1 == h){
			h -> next = p;
		}else{
			p1 -> next = p;
		}
	}
	return h;
}

Head deleteAllAddresses(Head h){
	free(h);
	Head d = createAddressBook();
	return d;
}
