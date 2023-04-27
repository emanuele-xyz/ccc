#include <ccc/alloc.h>
#include <ccc/compilers.h>
#include <ccc/asserts.h>

#if defined(CCC_MSVC)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#else
#include <stdlib.h>
#endif

ccc_err ccc_alloc(u64 size, void** out)
{
	*out = calloc(1, size);
	if (*out) return CCC_OK;
	else return CCC_ERR_ALLOC_FAIL;
}

ccc_err ccc_free(void** in)
{
	if (*in)
	{
		free(*in);
		return CCC_OK;
	}
	else
	{
		return CCC_ERR_CANT_FREE;
	}
}

void ccc_check_for_leaks_on_exit(void)
{
	#if defined(CCC_MSVC)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	#else
	#endif
}
