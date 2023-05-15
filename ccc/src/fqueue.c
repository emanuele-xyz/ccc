#include <ccc/fqueue.h>
#include <ccc/alloc.h>

ccc_err ccc_fqueue_init(u64 elem_size, u64 capacity, void** out)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	ccc_fqueue* tmp = 0;
	err = ccc_alloc(sizeof(ccc_fqueue) + elem_size * capacity, &tmp);
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
			((char*)q)[((start + length) % capacity) * elem_size + i] = ((char*)(v))[i];
		}
		ccc_fqueue_length(q)++;
	}

	return err;
}

ccc_err ccc_fqueue_dequeue(void* q, void* v)
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
