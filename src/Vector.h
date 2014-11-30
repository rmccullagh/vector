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

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Var.h"

#define VECTOR_DEFAULT_CAPACITY (100)

typedef struct vector {
	size_t size;
	size_t capacity;
	Var** data;
} vector_t;

vector_t* vector_init();

void vector_push_back(vector_t*, Var*);

size_t vector_size(vector_t*);

Var* vector_get(vector_t*, size_t);

void vector_free(vector_t*);

#endif /* __VECTOR_H__ */
