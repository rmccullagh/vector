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

#include <stdio.h>
#include <config.h>

#include "Var.h"
#include "Vector.h"

int main()
{
	vector_t* v = vector_init();
		
	vector_push_back(v, var_string("Ryan"));
	vector_push_back(v, var_string("McCullagh"));
	vector_push_back(v, var_string("Lawrence"));

	vector_push_back(v, var_string("Pam"));
	vector_push_back(v, var_string("Larry"));
	vector_push_back(v, var_string("Emily"));


	vector_push_back(v, var_string("Dillon"));
	vector_push_back(v, var_string("James"));
	vector_push_back(v, var_string("Pat"));

	vector_push_back(v, var_string("Time"));
	vector_push_back(v, var_string("Length"));
	vector_push_back(v, var_string("C++"));

	size_t i;
	for(i = 0; i < vector_size(v); i++) {
		var_print(vector_get(v, i));
		printf("\n");
	}

	vector_free(v);

	return 0;	
}
