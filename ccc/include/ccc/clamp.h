#pragma once

#include <ccc/min_max.h>

#define ccc_clamp(v, lo, hi) ccc_min(ccc_max(v, lo), hi)
