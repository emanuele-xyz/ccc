#pragma once

#define WIN32_LEAN_AND_MEAN
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#pragma warning ( suppress : 5105 )
#include <Windows.h>

#define ccc_is_valid_handle(h) (((h) != INVALID_HANDLE_VALUE) && ((h) != 0))
