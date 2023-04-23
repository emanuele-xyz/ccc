#include <stdio.h>

#include <ccc/compilers.h>
#include <ccc/asserts.h>
#include <ccc/types.h>
#include <ccc/alloc.h>

int main(void)
{
    puts("Hello!");

    u64* p = ccc_alloc(sizeof(u64));
    ccc_free(p);
    ccc_crash();

    return 0;
}
