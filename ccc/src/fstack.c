#include <ccc/fstack.h>
#include <ccc/alloc.h>

ccc_err ccc_fstack_init(u64 elem_size, u64 capacity, void** out)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	ccc_fstack* tmp = 0;
	err = ccc_alloc(sizeof(ccc_fstack) + elem_size * capacity, &tmp);
	res = res && ccc_ok(err);
	if (res)
	{
		tmp->elem_size = elem_size;
		tmp->capacity = capacity;
		tmp->count = 0;
		*out = tmp + 1;
	}

	return err;
}

void ccc_fstack_fini(void* s)
{
	ccc_free((ccc_fstack*)(s)-1);
}

ccc_err ccc_fstack_push(void* s, void* in)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	u64 elem_size = ccc_fstack_elem_size(s);
	u64 capacity = ccc_fstack_capacity(s);
	u64 count = ccc_fstack_count(s);
	err = ccc_invariant(count < capacity);
	res = res && ccc_ok(err);

	if (res)
	{
		for (u64 i = 0; i < elem_size; i++)
		{
			((char*)(s))[count * elem_size + i] = ((char*)(in))[i];
		}
		ccc_fstack_count(s)++;
	}

	return err;
}

ccc_err ccc_fstack_peek(void* s, void* out)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	u64 elem_size = ccc_fstack_elem_size(s);
	u64 capacity = ccc_fstack_capacity(s);
	u64 count = ccc_fstack_count(s);
	err = ccc_invariant(count > 0);
	res = res && ccc_ok(err);

	if (res)
	{
		for (u64 i = 0; i < elem_size; i++)
		{
			((char*)(out))[i] = ((char*)(s))[(count - 1) * elem_size + i];
		}
	}

	return err;
}

ccc_err ccc_fstack_pop(void* s, void* out)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	u64 elem_size = ccc_fstack_elem_size(s);
	u64 capacity = ccc_fstack_capacity(s);
	u64 count = ccc_fstack_count(s);
	err = ccc_invariant(count > 0);
	res = res && ccc_ok(err);

	if (res)
	{
		for (u64 i = 0; i < elem_size; i++)
		{
			((char*)(out))[i] = ((char*)(s))[(count - 1) * elem_size + i];
		}
		ccc_fstack_count(s)--;
	}

	return err;
}

ccc_err ccc_fstack_clear(void* s)
{
	ccc_fstack_count(s) = 0;
	return CCC_OK;
}
