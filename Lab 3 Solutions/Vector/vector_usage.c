//vector_usage.c

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main() {

	Vector vector;							// declare and initialize a new vector
	vector_init(&vector);
	
	int i;								// fill it up with 150 arbitrary values
	for (i = 200; i > -50; i--) {					// this should expand capacity up to 200
		vector_append(&vector, i); 
	}
	
	vector_set(&vector, 4452, 21312984);				// set a value at an arbitrary index
									// this will expand and zero-fill the vector to fit
	printf("Heres the value at 27: %d\n", vector_get(&vector, 27));	// print out an arbitrary value in the vector
									// we're all done playing with our vector,
	vector_free(&vector);						// so free its underlying data array
	return 0;
}
