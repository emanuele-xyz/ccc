#include <ccc/fvec.h>
#include <ccc/alloc.h>
#include <ccc/memory.h>

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
			((char*)(v))[length * elem_size + i] = ((char*)(x))[i];
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
	u64 length = ccc_fvec_length(v);
	err = ccc_invariant(length > 0);
	res = res && ccc_ok(err);
	if (res)
	{
		for (u64 i = 0; i < elem_size; i++)
		{
			((char*)(x))[i] = ((char*)(v))[(length - 1) * elem_size + i];
		}
		ccc_fvec_length(v)--;
	}

	return err;
}

ccc_err ccc_fvec_insert(void* v, u64 at, void* x)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	u64 elem_size = ccc_fvec_elem_size(v);
	u64 capacity = ccc_fvec_capacity(v);
	u64 length = ccc_fvec_length(v);
	{
		ccc_err err1 = ccc_invariant(length < capacity);
		ccc_err err2 = ccc_invariant(at < length);
		res = res && ccc_ok(err) && ccc_ok(err1) && ccc_ok(err2);
	}
	if (res)
	{
		// shift
		for (u64 i = 0; i < (length - at) * elem_size; i++)
		{
			((char*)(v))[(length + 1) * elem_size - 1 - i] = ((char*)(v))[length * elem_size - 1 - i];
		}
		// copy
		for (u64 i = 0; i < elem_size; i++)
		{
			((char*)(v))[at * elem_size + i] = ((char*)(x))[i];
		}
		ccc_fvec_length(v)++;
	}

	return err;
}

void ccc_fvec_clear(void* v)
{
	#ifdef CCC_FVEC_ZERO_CLEAR
	u64 elem_size = ccc_fvec_elem_size(v);
	u64 capacity = ccc_fvec_capacity(v);
	ccc_memzero(v, elem_size * capacity);
	#else
	ccc_fvec_length(v) = 0;
	#endif // CCC_FVEC_ZERO_CLEAR
}
