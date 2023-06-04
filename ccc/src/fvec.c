#include <ccc/fvec.h>
#include <ccc/alloc.h>

ccc_err ccc_fvec_init(u64 elem_size, u64 capacity, void** out)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	ccc_fvec* v = 0;
	err = ccc_alloc(elem_size * capacity + sizeof(*v), &v);
	res = res && ccc_ok(err);
	if (res)
	{
		v->elem_size = elem_size;
		v->capacity = capacity;
		v->length = 0;
		*out = v + 1;
	}

	return err;
}

void ccc_fvec_fini(void* v)
{
	ccc_free((ccc_fvec*)(v)-1);
}

ccc_err ccc_fvec_add(void* v, void* x)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	u64 elem_size = ccc_fvec_elem_size(v);
	u64 capacity = ccc_fvec_capacity(v);
	u64 length = ccc_fvec_length(v);
	err = ccc_invariant(length < capacity);
	res = res && ccc_ok(err);
	if (res)
	{
		for (u64 i = 0; i < elem_size; i++)
		{
			((char*)(v))[length + i] = ((char*)(x))[i];
		}
		ccc_fvec_length(v)++;
	}

	return err;
}

ccc_err ccc_fvec_remove(void* v, void* x)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	u64 elem_size = ccc_fvec_elem_size(v);
	u64 capacity = ccc_fvec_capacity(v);
	u64 length = ccc_fvec_length(v);
	err = ccc_invariant(length > 0);
	res = res && ccc_ok(err);
	if (res)
	{
		for (u64 i = 0; i < elem_size; i++)
		{
			((char*)(x))[i] = ((char*)(v))[(length - 1) + i];
		}
		ccc_fvec_length(v)--;
	}

	return err;
}
