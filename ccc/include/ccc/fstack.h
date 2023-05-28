#pragma once

#include <ccc/types.h>
#include <ccc/errors.h>

/*
	fixed size stack

	u64 elem_size: element size
	u64 capacity:  maximum number of elements
	u64 count:     current number of elements
*/

typedef struct ccc_fstack
{
	u64 elem_size;
	u64 capacity;
	u64 count;
} ccc_fstack;

#define ccc_fstack_elem_size(s) (((ccc_fstack*)(s) - 1)->elem_size)
#define ccc_fstack_capacity(s)  (((ccc_fstack*)(s) - 1)->capacity)
#define ccc_fstack_count(s)     (((ccc_fstack*)(s) - 1)->count)

ccc_err ccc_fstack_init(u64 elem_size, u64 capacity, void** out);
void ccc_fstack_fini(void* s);
ccc_err ccc_fstack_push(void* s, void* in);
ccc_err ccc_fstack_peek(void* s, void* out);
ccc_err ccc_fstack_pop(void* s, void* out);
ccc_err ccc_fstack_clear(void* s);
