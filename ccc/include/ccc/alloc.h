#pragma once

#include <ccc/types.h>
#include <ccc/errors.h>

// allocate size bytes of memory and zero initialize it
ccc_err ccc_alloc_info(u64 size, void** out, const char* file, int line);
#define ccc_alloc(size, out) ccc_alloc_info((size), (out), __FILE__, __LINE__)
void ccc_free(void* in);

// display memory-leak report when the app exits
void ccc_check_for_leaks_on_exit(void);
