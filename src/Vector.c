/*
 *  Copyright (c) 2015 Ryan McCullagh <me@ryanmccullagh.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Vector.h"

vector_t* vector_init()
{
	vector_t* v = malloc(sizeof(vector_t));
	
	if(v == NULL) {
		fprintf(stdout, "%s\n", "vector_init: vector_t init memory allocation failure");
		exit(EXIT_FAILURE);
	}

	v->size = 0;
	v->capacity = VECTOR_DEFAULT_CAPACITY;
	v->data = malloc(v->capacity * sizeof(Var*));
	
	if(v->data == NULL) {
		fprintf(stdout, "%s\n", "vector_init: v->data memory allocation error");
		exit(EXIT_FAILURE);
	}
	return v;		
}

/*
 * vector_push_back
 * Resize the array if needed, else increase the size
 * and push the element onto the back of the stack
 */
void vector_push_back(vector_t* v, Var* element)
{	
	if(v->size == v->capacity) {
	
		fprintf(stderr, "%s %d\n", "[DEBUG]: resizing at size", v->size);

		v->capacity *= 2;
		v->data = realloc(v->data, v->capacity * sizeof(Var*));
			
		if(v->data == NULL) {
			fprintf(stdout, "%s \n", "vector_push_back: failed to resize array");
			exit(EXIT_FAILURE);
		}
		
		v->data[v->size] = element;
		v->size++;	
	
	} else {
		v->data[v->size] = element;
		v->size++;
	}
}

/*
 * vector_size
 * Utility function to return the vector size
 */
size_t vector_size(vector_t* v)
{
	return v->size;
}

/* 
 * vector_get
 * get an element at the index, but also check that it is possible
 * to retrieve by making sure the index is less than the size
 * the max index value is v->size - 1
 */
Var* vector_get(vector_t* v, size_t index)
{
	if(index < v->size) {
		return v->data[index];
	} else {
		fprintf(stdout, "vector_get: fatal error: undefined offset %zu\n", index);
		exit(EXIT_FAILURE);
	}
}

/*
 * vector_free
 * free all elements in the dynamic array of strings
 * and the struct itself
 */
void vector_free(vector_t* v)
{
	size_t i;
	
	for(i = 0; i < v->size; i++) {
		var_destroy(v->data[i]);
	}

	free(v->data);
	free(v);
}
