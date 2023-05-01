#include <ccc/fqueue.h>
#include <ccc/alloc.h>

/*
	TODO: move in .h file 
 
	fixed size queue

	u64 elem_size: element size
	u64 capacity:  maximum number of elements
	u64 start:     queue's starting index
	u64 length:    queue's length
*/

ccc_err ccc_fqueue_init(u64 elem_size, u64 capacity, void** out)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	ccc_fqueue* tmp = 0;
	err = ccc_alloc(elem_size * capacity, &tmp);
	res = res && ccc_ok(err);
	if (res)
	{
		tmp->elem_size = elem_size;
		tmp->capacity = capacity;
		tmp->start = 0;
		tmp->length = 0;
		*out = tmp + 1;
	}

	return err;
}

void ccc_fqueue_fini(void* q)
{
	ccc_free(((ccc_fqueue*)(q)-1));
}

/*
	TODO: move in .h file

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

ccc_err ccc_fqueue_enqueue(void* q, void* v)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	u64 elem_size = ccc_fqueue_elem_size(q);
	u64 capacity = ccc_fqueue_capacity(q);
	u64 start = ccc_fqueue_start(q);
	u64 length = ccc_fqueue_length(q);
	err = ccc_invariant(length < capacity);
	res = res && ccc_ok(err);

	if (res)
	{
		for (u64 i = 0; i < elem_size; i++)
		{
			((char*)(q))[((start + length) % capacity) * elem_size + i] = ((char*)(v))[i];
		}
		ccc_fqueue_length(q)++;
	}

	return err;
}

/*
	TODO: move in .h file
 
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

void ccc_fqueue_dequeue(void* q, void* v)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	u64 elem_size = ccc_fqueue_elem_size(q);
	u64 capacity = ccc_fqueue_capacity(q);
	u64 start = ccc_fqueue_start(q);
	u64 length = ccc_fqueue_length(q);
	err = ccc_invariant(length > 0);
	res = res && ccc_ok(err);

	if (res)
	{
		for (u64 i = 0; i < elem_size; i++)
		{
			((char*)(v))[i] = ((char*)(q))[start * elem_size + i];
		}
		ccc_fqueue_start(q) = (start + 1) % capacity;
		ccc_fqueue_length(q)--;
	}

	return err;
}
