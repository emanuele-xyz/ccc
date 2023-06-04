#pragma once

#include <ccc/types.h>
#include <ccc/errors.h>

/*
	Fixed size vector
*/

typedef struct ccc_fvec
{
	u64 elem_size;
	u64 capacity;
	u64 length;
} ccc_fvec;

#define ccc_fvec_elem_size(v) (((ccc_fvec*)(v) - 1)->elem_size)
#define ccc_fvec_capacity(v)  (((ccc_fvec*)(v) - 1)->capacity)
#define ccc_fvec_length(v)	  (((ccc_fvec*)(v) - 1)->length)

ccc_err ccc_fvec_init(u64 elem_size, u64 capacity, void** out);
void ccc_fvec_fini(void* v);
ccc_err ccc_fvec_append(void* v, void* elem);
