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

ccc_err ccc_alloc_info(u64 size, void** out, const char* file, int line)
{
	#if defined(CCC_MSVC)
	*out = _calloc_dbg(1, size, _NORMAL_BLOCK, file, line);
	#else
	*out = calloc(1, size);
	#endif
	if (*out) return CCC_OK;
	else return CCC_ERR_ALLOC_FAIL;
}

void ccc_free(void* in)
{
	free(in);
}

void ccc_check_for_leaks_on_exit(void)
{
	#if defined(CCC_MSVC)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	#endif
}
