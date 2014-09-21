//Driver.c

#include "OffenceOps.h"

int main(int argc, const char *argv[]){
    	FILE *input; 				//File pointer
    	driver word_list;			//Linked list initialization
    	driver result; 				//node pointer to store result
    	table *hash_table;
    	table1 *hash_table1; 			//Hash table initialization
    	clock_t time; 				//Variable for program running time calculations
    	int count, license; 			//Number of comparisons made
	/* Checking for correct command-line arguments */
    	if (argc != 5) {
        	printf("Program requires four text files as arguments!\n");
		exit(1);
    	}
    	if ( (input = fopen(argv[1], "r")) == NULL){
        	printf("Unable to open %s\n", argv[1]);
		exit(1);
    	}
    
	// Build Linked List and measure Time
    	time = clock(); 			//initializing zero time value
    	word_list = populateDrivers(input); 	//parsing input file into a linked list
    	printf("Storing text in a list took %6.10f s\n", print_time(time));
    	fclose(input); 				//closing and reopening the

    	// Build Hash Table and measure Time
    	input = fopen(argv[1], "r"); 		//text file for reading into a hash table
		time = clock(); 			//initializing zero time value
    	hash_table = build_table(input); 	//parsing input file into a hash table
    	printf("Storing text in a hash table took %6.10f s\n", print_time(time));
    	print_stats(hash_table); 		//printing all the hash table statistics
    	printf("\n");
    	fclose(input);

	if ((input = fopen(argv[2], "r")) == NULL){
        	fprintf(stderr, "Unable to open %s\n", argv[2]);
        	exit(1);
    	}
	hash_table1 = build_table1(input);
	fclose(input);

    	// Prepare revokeList
    	if ((input = fopen(argv[3], "r")) == NULL){
        	fprintf(stderr, "Unable to open %s\n", argv[3]);
        	exit(1);
    	}
    	driver revokeList = makeRevokeList(input, hash_table, hash_table1, &count);
	fclose(input);
	input = fopen(argv[4], "w");
    	printDriversList(input, revokeList);
    	fclose(input);

    	//loop for searching in list and hash table
	do {
        	printf("Enter a license to search: ");
        	scanf("%d", &license);
        	printf("list:\n");
        	time = clock();
        	result = search_list(word_list, license, &count);
        	print_result(result, count);
        	printf(", took %6.10f s\n", print_time(time));
        	printf("hash table:\n");
        	time = clock();
        	result = search_table(hash_table, license, &count);
        	print_result(result, count);
        	printf(", took %6.10f s\n", print_time(time));
	} while(ask_user());
	return 0;
}


