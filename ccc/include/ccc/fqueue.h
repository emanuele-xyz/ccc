#pragma once

#include <ccc/types.h>
#include <ccc/errors.h>

/*
	Suppose we have the following fqueue
		elem_size: 8
		capacity:  4
		start:     0
		length:    3

		+---+---+---+---+
		| a | b | c | . |
		+---+---+---+---+

	After enqueuing element d we have that
		elem_size: 8
		capacity:  4
		start:     0
		length:    4 <-- update

		+---+---+---+---+
		| a | b | c | d |
		+---+---+---+---+

	Suppose we have the following fqueue
		elem_size: 8
		capacity:  4
		start:     1
		length:    3

		+---+---+---+---+
		| . | a | b | c |
		+---+---+---+---+

	After enqueuing element d we have that
		elem_size: 8
		capacity:  4
		start:     1
		length:    4 <-- update

		+---+---+---+---+
		| d | a | b | c |
		+---+---+---+---+
*/

/*
	Suppose we have the following fqueue
		elem_size: 8
		capacity:  4
		start:     0
		length:    3

		+---+---+---+---+
		| a | b | c | . |
		+---+---+---+---+

	After dequeuing (element a) we have that
		elem_size: 8
		capacity:  4
		start:     1 <-- update
		length:    2 <-- update

		+---+---+---+---+
		| . | b | c | . |
		+---+---+---+---+

	Suppose we have the following fqueue
		elem_size: 8
		capacity:  4
		start:     1
		length:    3

		+---+---+---+---+
		| . | a | b | c |
		+---+---+---+---+

	After dequeuing (element a) we have that
		elem_size: 8
		capacity:  4
		start:     2 <-- update
		length:    2 <-- update

		+---+---+---+---+
		| . | . | b | c |
		+---+---+---+---+

	Suppose we have the following fqueue
		elem_size: 8
		capacity:  4
		start:     3
		length:    2

		+---+---+---+---+
		| b | . | . | a |
		+---+---+---+---+

	After dequeuing (element a) we have that
		elem_size: 8
		capacity:  4
		start:     0 <-- update
		length:    1 <-- update

		+---+---+---+---+
		| b | . | . | . |
		+---+---+---+---+
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
ccc_err ccc_fqueue_enqueue(void* q, void* v);
ccc_err ccc_fqueue_dequeue(void* q, void* v);
