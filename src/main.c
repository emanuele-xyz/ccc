#include <stdio.h>

#include <ccc/compilers.h>
#include <ccc/asserts.h>
#include <ccc/types.h>

int main(void)
{
    puts("Hello!");

    ccc_crash();

    return 0;
}
