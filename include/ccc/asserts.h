#pragma once

#include <ccc/compilers.h>

#if defined(CCC_MSVC)
#define ccc_static_assert(p) static_assert(p, #p)
#endif
