#include <ccc/fstack.h>
#include <ccc/alloc.h>
#include <ccc/errors_asserts.h>

ccc_err ccc_fstack_init(u64 size, u64 capacity, void** out)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	u64 fields_size = CCC_FSTACK_DATA * sizeof(u64);
	u64* data = 0;
	err = ccc_alloc(fields_size + size * capacity, &data);
	res = res && ccc_ok(err);

	if (res)
	{
		data[CCC_FSTACK_SIZE] = size;
		data[CCC_FSTACK_CAPACITY] = capacity;
		data[CCC_FSTACK_COUNT] = 0;
		*((u64**)(out)) = data + CCC_FSTACK_DATA;
	}

	return err;
}

void ccc_fstack_fini(void* in)
{
	u64* ptr = ((u64*)(in)) - CCC_FSTACK_DATA;
	ccc_free(ptr);
}

ccc_err ccc_fstack_push(void* s, void* in)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	u64 size = ccc_fstack_size(s);
	u64 capacity = ccc_fstack_capacity(s);
	u64 count = ccc_fstack_count(s);
	err = ccc_invariant(count < capacity);
	res = res && ccc_ok(err);

	if (res)
	{
		for (u64 i = 0; i < size; i++)
		{
			((char*)(s))[size * count + i] = ((char*)(in))[i];
		}
		ccc_fstack_count(s) = count + 1;
	}

	return err;
}

ccc_err ccc_fstack_peek(void* s, void* out)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	u64 size = ccc_fstack_size(s);
	u64 count = ccc_fstack_count(s);
	err = ccc_invariant(count > 0);
	res = res && ccc_ok(err);

	if (res)
	{
		for (u64 i = 0; i < size; i++)
		{
			((char*)(out))[i] = ((char*)(s))[(count - 1) * size + i];
		}
	}

	return err;
}

ccc_err ccc_fstack_pop(void* s, void* out)
{
	ccc_err err = CCC_OK;
	b8 res = CCC_T;

	u64 size = ccc_fstack_size(s);
	u64 count = ccc_fstack_count(s);
	err = ccc_invariant(count > 0);
	res = res && ccc_ok(err);

	if (res)
	{
		for (u64 i = 0; i < size; i++)
		{
			((char*)(out))[i] = ((char*)(s))[(count - 1) * size + i];
		}
		ccc_fstack_count(s) = count - 1;
	}

	return err;
}

ccc_err ccc_fstack_clear(void* s)
{
	ccc_fstack_count(s) = 0;
	return CCC_OK;
}
