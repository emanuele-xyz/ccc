#pragma once

/*
    https://sourceforge.net/p/predef/wiki/Compilers
*/

#if defined(_MSC_VER)
#define CCC_MSVC 1
#else
#error compiler not supported
#endif
