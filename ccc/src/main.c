#include <stdio.h>

#include <ccc/compilers.h>
#include <ccc/asserts.h>
#include <ccc/types.h>
#include <ccc/alloc.h>
#include <ccc/fstack.h>
#include <ccc/fqueue.h>
#include <ccc/min_max.h>
#include <ccc/clamp.h>

void test_fqueue(void)
{
	ccc_err err = CCC_OK;

	i32* q = 0;
	u64 cap = 8;
	{
		err = ccc_fqueue_init(sizeof(*q), cap, &q);
		printf("queue initialized: %s\n", ccc_err_desc(err));
		u64 elem_size = ccc_fqueue_elem_size(q);
		u64 capacity = ccc_fqueue_capacity(q);
		u64 start = ccc_fqueue_start(q);
		u64 length = ccc_fqueue_length(q);
		printf("elem_size %llu - capacity %llu - start %llu - length %llu\n", elem_size, capacity, start, length);
	}

	{
		i32 v = 0;
		err = ccc_fqueue_dequeue(q, &v);
		printf("dequeuing ... %s\n", ccc_err_desc(err));
	}

	for (u64 i = 0; i < cap; i++)
	{
		i32 v = (i32)i;
		err = ccc_fqueue_enqueue(q, &i);
		printf("enqueuing %d ... %s\n", v, ccc_err_desc(err));

		u64 elem_size = ccc_fqueue_elem_size(q);
		u64 capacity = ccc_fqueue_capacity(q);
		u64 start = ccc_fqueue_start(q);
		u64 length = ccc_fqueue_length(q);
		printf("elem_size %llu - capacity %llu - start %llu - length %llu\n", elem_size, capacity, start, length);
	}

	{
		i32 v = (i32)(cap + 1);
		err = ccc_fqueue_enqueue(q, &v);
		printf("enqueuing %d ... %s\n", v, ccc_err_desc(err));
	}

	for (u64 i = 0; i < cap + 1; i++)
	{
		i32 v = 0;
		err = ccc_fqueue_dequeue(q, &v);
		printf("dequeuing %d ... %s\n", v, ccc_err_desc(err));

		u64 elem_size = ccc_fqueue_elem_size(q);
		u64 capacity = ccc_fqueue_capacity(q);
		u64 start = ccc_fqueue_start(q);
		u64 length = ccc_fqueue_length(q);
		printf("elem_size %llu - capacity %llu - start %llu - length %llu\n", elem_size, capacity, start, length);
	}

	{
		for (u64 i = 0; i < cap / 2; i++)
		{
			i32 v = (i32)i;
			err = ccc_fqueue_enqueue(q, &i);
			printf("enqueuing %d ... %s\n", v, ccc_err_desc(err));

			u64 elem_size = ccc_fqueue_elem_size(q);
			u64 capacity = ccc_fqueue_capacity(q);
			u64 start = ccc_fqueue_start(q);
			u64 length = ccc_fqueue_length(q);
			printf("elem_size %llu - capacity %llu - start %llu - length %llu\n", elem_size, capacity, start, length);
		}

		for (u64 i = 0; i < cap / 4; i++)
		{
			i32 v = 0;
			err = ccc_fqueue_dequeue(q, &v);
			printf("dequeuing %d ... %s\n", v, ccc_err_desc(err));

			u64 elem_size = ccc_fqueue_elem_size(q);
			u64 capacity = ccc_fqueue_capacity(q);
			u64 start = ccc_fqueue_start(q);
			u64 length = ccc_fqueue_length(q);
			printf("elem_size %llu - capacity %llu - start %llu - length %llu\n", elem_size, capacity, start, length);
		}

		for (u64 i = 0; i < cap / 4; i++)
		{
			i32 v = (i32)i;
			err = ccc_fqueue_enqueue(q, &i);
			printf("enqueuing %d ... %s\n", v, ccc_err_desc(err));

			u64 elem_size = ccc_fqueue_elem_size(q);
			u64 capacity = ccc_fqueue_capacity(q);
			u64 start = ccc_fqueue_start(q);
			u64 length = ccc_fqueue_length(q);
			printf("elem_size %llu - capacity %llu - start %llu - length %llu\n", elem_size, capacity, start, length);
		}

		for (u64 i = 0; i < cap / 2; i++)
		{
			i32 v = 0;
			err = ccc_fqueue_dequeue(q, &v);
			printf("dequeuing %d ... %s\n", v, ccc_err_desc(err));

			u64 elem_size = ccc_fqueue_elem_size(q);
			u64 capacity = ccc_fqueue_capacity(q);
			u64 start = ccc_fqueue_start(q);
			u64 length = ccc_fqueue_length(q);
			printf("elem_size %llu - capacity %llu - start %llu - length %llu\n", elem_size, capacity, start, length);
		}
	}

	{
		ccc_fqueue_fini(q);
		printf("queue finalized\n");
	}
}

int main(void)
{
	ccc_check_for_leaks_on_exit();
	{
		i32* ptr = 0;
		ccc_alloc(16, &ptr);
	}

	ccc_err err = CCC_OK;

	u64 cap = 8;
	i32* s = 0;
	err = ccc_fstack_init(sizeof(i32), cap, &s);
	for (i32 i = 0; i < (i32)cap + 1; i++)
	{
		err = ccc_fstack_push(s, &i);
		u64 size = ccc_fstack_elem_size(s);
		u64 capacity = ccc_fstack_capacity(s);
		u64 count = ccc_fstack_count(s);
		printf("trying to push %d onto stack ... %s ... ", i, ccc_err_desc(err));
		printf("size:%llu - capacity:%llu - count:%llu\n", size, capacity, count);
	}

	for (i32 i = 0; i < (i32)cap + 1; i++)
	{
		{
			i32 a = 0;
			err = ccc_fstack_peek(s, &a);
			printf("peeking onto the stack ... ");
			if (ccc_ok(err)) printf("%d ... ", a);
			else printf("%s ... ", ccc_err_desc(err));
			u64 size = ccc_fstack_elem_size(s);
			u64 capacity = ccc_fstack_capacity(s);
			u64 count = ccc_fstack_count(s);
			printf("size:%llu - capacity:%llu - count:%llu\n", size, capacity, count);

		}

		{
			i32 b = 0;
			err = ccc_fstack_pop(s, &b);
			u64 size = ccc_fstack_elem_size(s);
			u64 capacity = ccc_fstack_capacity(s);
			u64 count = ccc_fstack_count(s);
			printf("popping stack ... ");
			if (ccc_ok(err)) printf("got %d ... ", b);
			else printf("%s ... ", ccc_err_desc(err));
			printf("size:%llu - capacity:%llu - count:%llu\n", size, capacity, count);
		}
	}

	err = ccc_fstack_clear(s);
	printf("stack_cleared ... %s ... size:%llu - capacity:%llu - count:%llu\n", ccc_err_desc(err), ccc_fstack_elem_size(s), ccc_fstack_capacity(s), ccc_fstack_count(s));
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

	test_fqueue();

	return 0;
}
