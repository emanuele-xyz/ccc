#include <ccc/list.h>
#include <ccc/alloc.h>

ccc_err ccc_list_init(u64 elem_size, ccc_list** out)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	ccc_list* l = 0;
	err = ccc_alloc(sizeof(*l), &l);
	res = res && ccc_ok(err);
	if (res)
	{
		*out = l;
	}

	return res;
}

void ccc_list_fini(ccc_list* l)
{
	ccc_free(l);
}
