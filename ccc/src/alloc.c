#include <ccc/alloc.h>
#include <ccc/asserts.h>

#include <stdlib.h>

void* ccc_alloc(u64 size)
{
    void* ptr = calloc(1, size);
    ccc_assert(ptr);
    return ptr;
}

void  ccc_free(void* ptr)
{
    free(ptr);
}
