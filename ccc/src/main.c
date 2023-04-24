#include <stdio.h>

#include <ccc/compilers.h>
#include <ccc/asserts.h>
#include <ccc/types.h>
#include <ccc/alloc.h>
#include <ccc/fstack.h>

int main(void)
{
    puts("Hello!");

    i32* s = ccc_fstack_init(sizeof(i32), 8);
    for (i32 i = 0; i < 8; i++)
    {
    	ccc_fstack_push(s, &i);
    	u64 size = ccc_fstack_size(s);
    	u64 capacity = ccc_fstack_capacity(s);
    	u64 count = ccc_fstack_count(s);
    	printf("pushed %d onto stack - size:%zu - capacity:%zu - count:%zu\n", i, size, capacity, count);
    }
    //i32 v = 8;
    //ccc_fstack_push(s, &v);

    for (i32 i = 0; i < 8; i++)
    {
        i32 a = 0;
        ccc_fstack_peek(s, &a);
        printf("peeking onto the stack ... found %d\n", a);
        i32 b = 0;
        ccc_fstack_pop(s, &b);
        u64 size = ccc_fstack_size(s);
        u64 capacity = ccc_fstack_capacity(s);
        u64 count = ccc_fstack_count(s);
        printf("popping stack ... got %d - size:%zu - capacity:%zu - count:%zu\n", b, size, capacity, count);
    }
    //i32 w = 0;
    //ccc_fstack_pop(s, &w);

    ccc_fstack_clear(s);
    printf("stack_cleared - size:%zu - capacity:%zu - count:%zu\n", ccc_fstack_size(s), ccc_fstack_capacity(s), ccc_fstack_count(s));
    ccc_fstack_fini(s);

    return 0;
}
