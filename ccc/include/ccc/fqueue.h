#pragma once

#include <ccc/fqueue.h>
#include <ccc/types.h>
#include <ccc/errors.h>

/*
	fixed size queue

	u64 elem_size: element size
	u64 capacity:  maximum number of elements
	u64 start:     queue's starting index
	u64 length:    queue's length
*/

typedef struct ccc_fqueue
{
	u64 elem_size;
	u64 capacity;
	u64 start;
	u64 length;
} ccc_fqueue;

#define ccc_fqueue_elem_size(q) (((ccc_fqueue*)(q) - 1)->elem_size)
#define ccc_fqueue_capacity(q)  (((ccc_fqueue*)(q) - 1)->capacity)
#define ccc_fqueue_length(q)    (((ccc_fqueue*)(q) - 1)->length)
#define ccc_fqueue_start(q)     (((ccc_fqueue*)(q) - 1)->start)

ccc_err ccc_fqueue_init(u64 elem_size, u64 capacity, void** out);
void ccc_fqueue_fini(void* q);

