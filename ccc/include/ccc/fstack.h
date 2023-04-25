#pragma once

#include <ccc/types.h>

/*
    fixed size stack

    u64 size:     element size
    u64 capacity: maximum number of elements
    u64 count:    current number of elements

            returned pointer -+
                              |
                              V
    +------+----------+-------+-----+
    | size | capacity | count | ... |
    +------+----------+-------+-----+
*/

typedef enum fstack_field
{
    CCC_FSTACK_SIZE,
    CCC_FSTACK_CAPACITY,
    CCC_FSTACK_COUNT,
    CCC_FSTACK_DATA,
} fstack_field;

#define ccc_fstack_size(s)     (((u64*)(s) - CCC_FSTACK_DATA)[CCC_FSTACK_SIZE])
#define ccc_fstack_capacity(s) (((u64*)(s) - CCC_FSTACK_DATA)[CCC_FSTACK_CAPACITY])
#define ccc_fstack_count(s)    (((u64*)(s) - CCC_FSTACK_DATA)[CCC_FSTACK_COUNT])

void* ccc_fstack_init(u64 size, u64 capacity);
void ccc_fstack_fini(void* s);
void ccc_fstack_push(void* s, void* in);
void ccc_fstack_peek(void* s, void* out);
void ccc_fstack_pop(void* s, void* out);
void ccc_fstack_clear(void* s);
