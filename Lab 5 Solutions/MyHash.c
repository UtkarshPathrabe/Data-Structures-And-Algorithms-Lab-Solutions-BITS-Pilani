//MyHash.c

#include "OffenceOps.h"

table *build_table(FILE *input){
/* Function builds a hash table from file
* Accepts file pointer and returns pointer to hash table structure
* Function automatically resizes the table when it reaches certain ammount of items.
* This is controlled by typedef'ed constant "RATIO"
*/
	printf("Trying to build table...\n");
	table *hash_table = gcalloc(1, sizeof(table)); 	//allocating memory to the hash table
	int max_size; 	//maximum amount of items in a table to trigger the resizing
	int h; 		//hash variable
    
	hash_table -> size = INIT_SIZE; 					//initial size
	hash_table -> items = 0; 						//number of items
	hash_table -> data = gcalloc(hash_table->size, sizeof(drvr)); 	//allocating memory for data storage
	max_size = hash_table -> size * RATIO; 				//update maximum allowed size

    	int uid, license, penalty;
	char c;
	printf("Entering loop...\n");
    	while(fscanf(input, "%d%c%d\n", &uid,&c,&license)!=EOF){ //loop through the input file one word at a time
        	if( max_size < hash_table -> items){ 		//triggering the resize
            		hash_table = grow_table(hash_table);	
			printf("Grow table called.\n");
            		max_size = hash_table -> size * RATIO; 	//storing new size to trigger the resize
        	}
        	h = hash(license, hash_table -> size); 		//integer hashing
        	hash_table -> data[h] = insert_word(hash_table -> data[h], uid, license, penalty, &hash_table -> items); 
								//inserting word in a right place
    	}
    	return hash_table;
}

table1 *build_table1(FILE *input){
/* Function builds a hash table from file
* Accepts file pointer and returns pointer to hash table structure
* Function automatically resizes the table when it reaches certain ammount of items.
* This is controlled by typedef'ed constant "RATIO"
*/
	printf("Trying to build table...\n");
	table1 *hash_table = gcalloc(1, sizeof(table1)); 	//allocating memory to the hash table
	int max_size; 	//maximum amount of items in a table to trigger the resizing
	int h; 		//hash variable
    
	hash_table -> size = INIT_SIZE; 					//initial size
	hash_table -> items = 0; 						//number of items
	hash_table -> data = gcalloc(hash_table->size, sizeof(ownr)); 	//allocating memory for data storage
	max_size = hash_table -> size * RATIO; 				//update maximum allowed size

    	int uid, vno;
	char c;
	printf("Entering loop...\n");
    	while(fscanf(input, "%d%c%d\n", &uid,&c,&vno)!=EOF){ //loop through the input file one word at a time
        	if( max_size < hash_table -> items){ 		//triggering the resize
            		hash_table = grow_table1(hash_table);	
			printf("Grow table called.\n");
            		max_size = hash_table -> size * RATIO; 	//storing new size to trigger the resize
        	}
        	h = hash(uid, hash_table -> size); 		//integer hashing
        	hash_table -> data[h] = insert_word1(hash_table -> data[h], uid, vno, &hash_table -> items); 
								//inserting word in a right place
    	}
    	return hash_table;
}

unsigned int hash(int data, int tbl_size){
	return data % tbl_size;
}

driver insert_word(driver word_list, int uid, int license, int penalty, int *used){
/* Function for inserting word to a list
* Returns head of a list */
	int count; 						//dummy variable required by search_list()
	driver node = create_node(uid, license, penalty);
	node -> next = word_list;
	*used += 1;
    	return node;
}

owner insert_word1(owner word_list, int uid, int vno, int *used){
/* Function for inserting word to a list
* Returns head of a list */
	int count; 						//dummy variable required by search_list()
	owner node = create_node1(uid, vno);
	node -> next = word_list;
	*used += 1;
    	return node;
}

table *grow_table(table *hash_table){
/* Resizes hash table.
* Requires hash table as an argument and returns pointer to bigger hash table
*
* It first allocates memory to a table GROWTH times bigger and then rehashes all
* the previous values into a new one. Memory allocated for old table is freed
*/
	int h, i = 0;
	driver bucket; 							//for storing a list to be rehashed
    	driver node;
    	table *new_table = gcalloc(1, sizeof(table)); 			//memory allocated for table structure
    	new_table -> size = (int)(hash_table -> size * GROWTH) + 1; 	//Size is increased and 1 is added for the number to be odd
    	new_table -> items = hash_table -> items; 			//Number of elements is copied to the new table
    	new_table -> data = gcalloc(new_table -> size, sizeof(drvr)); 	//Memory allocated for data array
	for( ; i <= hash_table -> size ; i++){				//Loops through all hash table
        	if(hash_table -> data[i] != NULL){
            		bucket = hash_table -> data[i]; 		//Stores cell pointer for manipulation
            		while(bucket != NULL){
                		h = hash(bucket -> lic, new_table -> size); //Rehashing values for new table size
                		node = create_node(bucket -> uid, bucket -> lic, bucket -> penalty); 
									//Creating a list node from uid, license, and penalty
                		node -> next = new_table -> data[h]; 	//Connecting node with the list
                		new_table -> data[h] = node; 		//Replacing pointer to the list head
                		bucket = bucket -> next; 		//Advancing through the list
            		}
           	 	destroy(hash_table -> data[i]); 		//Freeing the memory allocated for the list in a cell
        	}
    	}
    	free(hash_table); 						//Freeing the memory allocated for old hash table
    	return new_table;
}

table1 *grow_table1(table1 *hash_table){
/* Resizes hash table.
* Requires hash table as an argument and returns pointer to bigger hash table
*
* It first allocates memory to a table GROWTH times bigger and then rehashes all
* the previous values into a new one. Memory allocated for old table is freed
*/
	int h, i = 0;
	owner bucket; 							//for storing a list to be rehashed
    	owner node;
    	table1 *new_table = gcalloc(1, sizeof(table1)); 			//memory allocated for table structure
    	new_table -> size = (int)(hash_table -> size * GROWTH) + 1; 	//Size is increased and 1 is added for the number to be odd
    	new_table -> items = hash_table -> items; 			//Number of elements is copied to the new table
    	new_table -> data = gcalloc(new_table -> size, sizeof(ownr)); 	//Memory allocated for data array
	for( ; i <= hash_table -> size ; i++){				//Loops through all hash table
        	if(hash_table -> data[i] != NULL){
            		bucket = hash_table -> data[i]; 		//Stores cell pointer for manipulation
            		while(bucket != NULL){
                		h = hash(bucket -> uid, new_table -> size); //Rehashing values for new table size
                		node = create_node1(bucket -> uid, bucket -> vno); 
									//Creating a list node from uid, license, and penalty
                		node -> next = new_table -> data[h]; 	//Connecting node with the list
                		new_table -> data[h] = node; 		//Replacing pointer to the list head
                		bucket = bucket -> next; 		//Advancing through the list
            		}
           	 	destroy(hash_table -> data[i]); 		//Freeing the memory allocated for the list in a cell
        	}
    	}
    	free(hash_table); 						//Freeing the memory allocated for old hash table
    	return new_table;
}


/* Searches hash table, Returns pointer to result list structure */
driver search_table(table *hash_table, int license, int *count){
	unsigned int h = hash(license, hash_table -> size); 		//hash value calculation
    	//printf("The hash value of %d for table size %d is %d\n", license, hash_table -> size, h);
    	return search_list(hash_table -> data[h], license, count); 	//list search function call with an array cell as an argument
}

owner search_table1(table1 *hash_table, int uid){
	unsigned int h = hash(uid, hash_table -> size); 		//hash value calculation
    	//printf("The hash value of %d for table size %d is %d\n", license, hash_table -> size, h);
    	return search_list1(hash_table -> data[h], uid); 	//list search function call with an array cell as an argument
}

driver search_list(driver word_list, int license, int *count){
/* List searching function, Funtion returns NULL if word is not found and a driver pointer if it's found.*/
	*count = 0;
	while(word_list != NULL){ 					//looping through a list
        	*count += 1; 						//increase number of comparisons made
        	if( word_list -> lic == license )
            		return word_list;
        	word_list = word_list -> next;
	}
    	return NULL;
}

owner search_list1(owner word_list, int uid){
/* List searching function, Funtion returns NULL if word is not found and a driver pointer if it's found.*/
	while(word_list != NULL){ 					//looping through a list
        	if(word_list -> uid == uid )
            		return word_list;
        	word_list = word_list -> next;
	}
    	return NULL;
}

double print_time(clock_t time){
/* Function calculates time elapsed after the "time" variable was set
* Accepts clock_t variable and returns time in seconds
*/
	return ((double)(clock() - time)/CLOCKS_PER_SEC);
}

void *gcalloc( int number, int size){
/* Graceful calloc function
* Checks if memory allocation using calloc() was successful
*/
	void *p = calloc(number, size);
	if(p == NULL){
		printf("Memory allocation error!\n");
		exit(1);
    	}
    	else return p;
}

void print_stats(table *hash_table){
/* Prints various hash table statistics.
* Accepts pointer to table structure
*
* The function prints table size, number of items stored,
* used and free cells in a hash table, number of cells with hash collisions,
* percentage of cells used and how much of them are collided,
* longest chain in a table, average length of all cells and
* average length of collided cells
*/
	int j, i = 0;
	int free, used, collision;
	int chain_max = 1;
	int chain_sum = 0;
	driver tmp;
	free = used = collision = 0;
    	for( ; i < hash_table -> size ; i++){ 				//loops through the hash table
        	j = 0;
        	if (hash_table -> data[i] == NULL)
			free++;
        	else if (hash_table -> data[i] -> next == NULL){
			chain_sum++;
			used++;
        	}
        	else{
            		tmp = hash_table -> data[i];
            		for( ; tmp != NULL ; tmp = tmp -> next){ 	//descends the list in a cell and counts for words stored
                		j++;
                		chain_sum++;
                		if(j > chain_max) 			//remembers the maximum list length
                			chain_max = j;
            		}
            		collision++;
        	}
    	}
	printf("---------------------------------------------------------STATS------------------------------------------------------------------\n");
    	printf("Table size: %d\n# of Items: %d\n", hash_table -> size, chain_sum);
    	printf("Cells used: %d\nCells free: %d\n", used + collision, free);
    	printf("Collisions: %d\n%% used: %5.3f\n", collision, ((double)(used + collision) / hash_table -> size) * 100);
    	printf("%% of them collided: %5.3f\nLongest chain: %d\n", ((double)(collision) / (double)(used + collision) * 100), chain_max);
    	printf("Average chain lenght: %5.2f\n", (double)chain_sum / (hash_table -> size - free));
    	printf("Average collided lenght: %5.2f\n", (double)(chain_sum - used) / (collision));
}

driver create_node(int uid, int license, int penalty){
// Function creates new instance of driver variable
	driver node = gcalloc(1, sizeof(drvr));
    	node -> uid = uid;
    	node -> lic= license;
    	node -> penalty = penalty;
    	node -> next = NULL;
    	return node;
}

owner create_node1(int uid, int vno){
// Function creates new instance of driver variable
	owner node = gcalloc(1, sizeof(ownr));
    	node -> uid = uid;
    	node -> vno = vno;
    	node -> next = NULL;
    	return node;
}

void destroy(driver word_list){
/* Frees memory allocated to a linked list
* Accepts pointer to a list
* Steps through whole list freeing every node separately
*/
	driver tmp;
	for( ; tmp != NULL; word_list = tmp){
		tmp = word_list->next;
        	free(word_list);
    	}
}

driver populateDrivers(FILE *source){
	driver head = (driver)malloc(sizeof(drvr));
	head->next = NULL;
	// Check if source exists
	if(source==NULL){
		printf("Input file not found. Exiting.");
		exit(1);
	}
	// Read file into a linked list
	int uid, license;
	char c;
	//fscanf(source, "%d%c%d\n", &uid,&c,&license);
	//head ->uid = uid;
	//head ->lic = license;
	while(fscanf(source, "%d%c%d\n", &uid,&c,&license)!=EOF){
		// Create a new node and store data in it
		driver newNode =(driver)malloc(sizeof(drvr));
		newNode -> uid = uid;
		newNode -> lic = license;
		// Find the first node larger than the newNode
		drvr *ptr = head;
		while(ptr -> next!=NULL && ptr -> next -> uid < uid){
			ptr = ptr -> next;
		}
		if (ptr -> next==NULL){
			newNode -> next = NULL;
			//printf("poop\n");
			ptr -> next = newNode;	
		}else{
			newNode -> next = ptr -> next;
			ptr -> next = newNode;
		}
	}
	return head;
}

void print_result(driver result, int count){
/* Prints search result and number of comparisons made.*/
    	if(result == NULL)
		printf("Not found, compared %d times", count );
	else
        	printf("License: %d \t UID: %d,\nCompared %d times", result -> lic, result -> uid, count);
}

driver makeRevokeList(FILE *source, table *hash_table, table1 *hash_table1, int* count){
	owner own;
	driver head = (driver)malloc(sizeof(drvr));
	head -> next = NULL;
	// Check if source exists
	if(source == NULL){
		fprintf(stderr, "Input file not found. Exiting.");
		exit(1);
	}
	// Read file into a linked list
	int uid, license, penalty;
	char c;
	// fscanf(source, "%d%c%d\n", &uid,&c,&license);
	// head -> uid = uid;
	// head -> lic = license;
	while(fscanf(source, "%d%c%d\n", &license,&c,&penalty) != EOF){
		// Create a new node and store data in it
		driver newNode = (driver)malloc(sizeof(drvr));
		driver result = search_table(hash_table, license, count);
		// printf("%d\n", result -> penalty);
		result -> penalty += penalty;
		if(result -> penalty >= 10){
			own = search_table1(hash_table1, result -> uid);
			newNode -> uid = result -> uid;
			newNode -> lic = license;
			if(own != NULL)
				newNode -> penalty = own -> vno;
			else
				newNode -> penalty = 0000;
			// Find the first node larger than the newNode
			drvr *ptr = head;
			while(ptr -> next!=NULL && ptr -> next -> uid < uid){
				ptr = ptr -> next;
			}
			// and then Insert correspondingly
			if (ptr -> next==NULL){
				newNode -> next = NULL;
				ptr -> next = newNode;	
			}
			else{
				newNode -> next = ptr -> next;
				ptr -> next = newNode;
			}
		}
	}
	return head;
}

void printDriversList(FILE * fp, driver node){
	fprintf(fp, "The Revoked Drivers are:\n\nUID\t\tLicense No.\tVehicle No.\n");
	if(node -> next!=NULL){
        	node = node -> next;
	}
  	while(node!=NULL){
    		fprintf(fp, "%d,\t%d,\t%d", node -> uid, node -> lic, node -> penalty);
    		fprintf(fp, "\n");
		node = node -> next;
	}
}

int ask_user(void){
/* Query handling function
* Returns 1 if user wants to continue, 0 for other cases.
*/
	char c;
    	while(getchar() != '\n'); 						//discard all newline characters from previous user input
    	printf("Do you wish to perform another query? [y/n]: ");
    	scanf("%c", &c);
    	if( c == 'y')
        	return 1;
    	else
        	return 0;
}
