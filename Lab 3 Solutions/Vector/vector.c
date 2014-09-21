//vector.c

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_init(Vector *vector) {		
	vector->size = 0;					// initialize size and capacity
	vector->capacity = VECTOR_INITIAL_CAPACITY;
	vector->data = malloc(sizeof(int) * vector->capacity);	// allocate memory for vector->data
}

void vector_append(Vector *vector, int value) {
	vector_double_capacity_if_full(vector);			// make sure there's room to expand into
	vector->data[vector->size++] = value;			// append the value and increment vector->size
}

int vector_get(Vector *vector, int index) {
	if (index >= vector->size || index < 0) {
		printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
		exit(1);
	}
	return vector->data[index];
}

void vector_set(Vector *vector, int index, int value) {
	while (index >= vector->size) {				// zero fill the vector up to the desired index
		vector_append(vector, 0);			// set the value at the desired index
	}
	vector->data[index] = value;
}

void vector_double_capacity_if_full(Vector *vector) {
if (vector->size >= vector->capacity) {
	vector->capacity *= 2;					// double vector->capacity and resize the
	vector->data = realloc(vector->data, sizeof(int) * vector->capacity);	// allocated memory accordingly
	}
}

void vector_free(Vector *vector) {
	free(vector->data);
}
