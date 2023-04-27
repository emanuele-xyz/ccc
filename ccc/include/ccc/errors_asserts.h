#pragma once

#include <ccc/errors.h>
#include <ccc/asserts.h>

#define ccc_assert_success(e) ccc_assert(ccc_ok(e))
