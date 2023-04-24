#pragma once

#include <ccc/compilers.h>

#if defined(CCC_MSVC)
#define ccc_static_assert(p) static_assert(p, #p)
#define ccc_dbg_break() __debugbreak()
#endif

#if defined(CCC_DBG_BREAK_ON_CRASH)
#define ccc_crash() ccc_dbg_break()
#else
#define ccc_crash() ((*((int*)(0))) = 0)
#endif

#define ccc_statement(s) do { s } while (0)
#define ccc_assert(p) ccc_statement( if(!(p)) ccc_crash(); )
