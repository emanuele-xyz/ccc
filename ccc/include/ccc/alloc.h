#pragma once

#include <ccc/types.h>
#include <ccc/errors.h>

// allocate size bytes of memory and zero initialize it
ccc_err ccc_alloc(u64 size, void** out);
ccc_err ccc_free(void** in);

// display memory-leak report when the app exits
void ccc_check_for_leaks_on_exit(void);
