#include <ccc/fstack.h>
#include <ccc/asserts.h>
#include <ccc/alloc.h>

void* ccc_fstack_init(u64 size, u64 capacity)
{
    u64 fields_size = FSTACK_DATA_OFFSET * sizeof(u64);
    u64* data = ccc_alloc(fields_size + size * capacity);
    data[FSTACK_SIZE_OFFSET] = size;
    data[FSTACK_CAPACITY_OFFSET] = capacity;
    data[FSTACK_COUNT_OFFSET] = 0;
    return data + FSTACK_DATA_OFFSET;
}

void ccc_fstack_fini(void* s)
{
    ccc_free(s);
}

void ccc_fstack_push(void* s, void* in)
{
    ccc_assert(s);
    ccc_assert(in);

    u64 size = ccc_fstack_size(s);
    u64 capacity = ccc_fstack_capacity(s);
    u64 count = ccc_fstack_count(s);
    ccc_assert(count < capacity);

    for (u64 i = 0; i < size; i++)
    {
        ((char*)(s))[size * count + i] = ((char*)(in))[i];
    }
    ccc_fstack_count(s) = count + 1;
}

void ccc_fstack_peek(void* s, void* out)
{
    ccc_assert(s);
    ccc_assert(out);

    u64 size = ccc_fstack_size(s);
    u64 count = ccc_fstack_count(s);
    ccc_assert(count > 0);

    for (u64 i = 0; i < size; i++)
    {
        ((char*)(out))[i] = ((char*)(s))[(count - 1) * size + i];
    }
}

void ccc_fstack_pop(void* s, void* out)
{
    ccc_assert(s);
    ccc_assert(out);

    u64 size = ccc_fstack_size(s);
    u64 count = ccc_fstack_count(s);
    ccc_assert(count > 0);

    for (u64 i = 0; i < size; i++)
    {
        ((char*)(out))[i] = ((char*)(s))[(count - 1) * size + i];
    }
    ccc_fstack_count(s) = count - 1;
}

void ccc_fstack_clear(void* s)
{
    ccc_assert(s);
    ccc_fstack_count(s) = 0;
}
