#include <ccc/errors.h>

static const char* s_descs[] =
{
	[CCC_OK] = "CCC_OK",
	[CCC_ERR_ALLOC_FAIL] = "CCC_ERR_ALLOC_FAIL",
	[CCC_ERR_CANT_FREE] = "CCC_ERR_CANT_FREE",
	[CCC_ERR_INVARIANT] = "CCC_ERR_INVARIANT",
};

const char* ccc_err_desc(ccc_err err)
{
	return s_descs[err];
}
