#include <stdio.h>

#include <ccc/compilers.h>
#include <ccc/asserts.h>
#include <ccc/types.h>
#include <ccc/alloc.h>
#include <ccc/fstack.h>
#include <ccc/min_max.h>
#include <ccc/clamp.h>

int main(void)
{
	ccc_check_for_leaks_on_exit();
	{
		i32* ptr = 0;
		ccc_alloc(16, &ptr);
	}

	ccc_err err = CCC_OK;

	u64 capacity = 8;
	i32* s = 0;
	err = ccc_fstack_init(sizeof(i32), capacity, &s);
	for (i32 i = 0; i < capacity + 1; i++)
	{
		err = ccc_fstack_push(s, &i);
		u64 size = ccc_fstack_size(s);
		u64 capacity = ccc_fstack_capacity(s);
		u64 count = ccc_fstack_count(s);
		printf("trying to push %d onto stack ... %s ... ", i, ccc_err_desc(err));
		printf("size:%llu - capacity:%llu - count:%llu\n", size, capacity, count);
	}

	for (i32 i = 0; i < capacity + 1; i++)
	{
		{
			i32 a = 0;
			err = ccc_fstack_peek(s, &a);
			printf("peeking onto the stack ... ");
			if (ccc_ok(err)) printf("%d ... ", a);
			else printf("%s ... ", ccc_err_desc(err));
			u64 size = ccc_fstack_size(s);
			u64 capacity = ccc_fstack_capacity(s);
			u64 count = ccc_fstack_count(s);
			printf("size:%llu - capacity:%llu - count:%llu\n", size, capacity, count);

		}

		{
			i32 b = 0;
			err = ccc_fstack_pop(s, &b);
			u64 size = ccc_fstack_size(s);
			u64 capacity = ccc_fstack_capacity(s);
			u64 count = ccc_fstack_count(s);
			printf("popping stack ... ");
			if (ccc_ok(err)) printf("got %d ... ", b);
			else printf("%s ... ", ccc_err_desc(err));
			printf("size:%llu - capacity:%llu - count:%llu\n", size, capacity, count);
		}
	}

	err = ccc_fstack_clear(s);
	printf("stack_cleared ... %s ... size:%llu - capacity:%llu - count:%llu\n", ccc_err_desc(err), ccc_fstack_size(s), ccc_fstack_capacity(s), ccc_fstack_count(s));
	ccc_fstack_fini(s);

	{
		i32 lo = 5;
		i32 hi = 8;
		printf("min(%d,%d)=%d\n", lo, hi, ccc_min(lo, hi));
		printf("max(%d,%d)=%d\n", lo, hi, ccc_max(lo, hi));
		i32 v0 = 1;
		printf("clamp(%d,%d,%d)=%d\n", v0, lo, hi, ccc_clamp(v0, lo, hi));
		i32 v1 = 9;
		printf("clamp(%d,%d,%d)=%d\n", v1, lo, hi, ccc_clamp(v1, lo, hi));
		i32 v2 = 7;
		printf("clamp(%d,%d,%d)=%d\n", v2, lo, hi, ccc_clamp(v2, lo, hi));
	}

	return 0;
}
