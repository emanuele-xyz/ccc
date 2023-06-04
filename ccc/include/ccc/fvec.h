#pragma once

#include <ccc/types.h>
#include <ccc/errors.h>

/*
	Fixed size vector

	Compile using
	
		#define CCC_FVEC_ZERO_CLEAR
	
	to set all data to zero when calling ccc_fvec_clean
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
ccc_err ccc_fvec_add(void* v, void* x);
ccc_err ccc_fvec_remove(void* v, void* x);
ccc_err ccc_fvec_insert(void* v, u64 at, void* x);
void ccc_fvec_clear(void* v);
