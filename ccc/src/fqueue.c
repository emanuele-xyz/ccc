#include <ccc/fqueue.h>
#include <ccc/alloc.h>

/*
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
