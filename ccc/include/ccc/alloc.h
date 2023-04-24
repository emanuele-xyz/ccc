#pragma once

#include <ccc/types.h>

/*
    Memory allocation and deallocation functions
    Crash on memory allocation failure
    All memory allocated is zero initialized
*/

void* ccc_alloc(u64 size);
void  ccc_free(void* ptr);
