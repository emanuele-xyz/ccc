#include <ccc/memory.h>

#include <string.h>

void ccc_memset(void* dst, u64 size, u8 val)
{
	memset(dst, val, size);
}

void ccc_memzero(void* dst, u64 size)
{
	ccc_memset(dst, size, 0);
}
