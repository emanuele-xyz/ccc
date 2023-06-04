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
