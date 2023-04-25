#pragma once

#include <ccc/asserts.h>

typedef char      i8;
typedef short     i16;
typedef int       i32;
typedef long long i64;

typedef i8  v2i8 [2];
typedef i16 v2i16[2];
typedef i32 v2i32[2];
typedef i64 v2i64[2];

typedef i8  v3i8 [3];
typedef i16 v3i16[3];
typedef i32 v3i32[3];
typedef i64 v3i64[3];

ccc_static_assert(sizeof(i8)  == 1);
ccc_static_assert(sizeof(i16) == 2);
ccc_static_assert(sizeof(i32) == 4);
ccc_static_assert(sizeof(i64) == 8);

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef u8  v2u8 [2];
typedef u16 v2u16[2];
typedef u32 v2u32[2];
typedef u64 v2u64[2];

typedef u8  v3u8 [3];
typedef u16 v3u16[3];
typedef u32 v3u32[3];
typedef u64 v3u64[3];

ccc_static_assert(sizeof(u8)  == 1);
ccc_static_assert(sizeof(u16) == 2);
ccc_static_assert(sizeof(u32) == 4);
ccc_static_assert(sizeof(u64) == 8);

typedef u8  b8;
typedef u16 b16;
typedef u32 b32;
typedef u64 b64;

ccc_static_assert(sizeof(b8)  == 1);
ccc_static_assert(sizeof(b16) == 2);
ccc_static_assert(sizeof(b32) == 4);
ccc_static_assert(sizeof(b64) == 8);

typedef float  f32;
typedef double f64;

typedef f32 v2f32[2];
typedef f64 v2f64[2];

typedef f32 v3f32[3];
typedef f64 v3f64[3];

ccc_static_assert(sizeof(f32) == 4);
ccc_static_assert(sizeof(f64) == 8);

enum
{
	V_X = 0,
	V_Y = 1,
	V_Z = 2,

	V_R = 0,
	V_G = 1,
	V_B = 2,

	V_W = 0,
	V_H = 1,
	V_D = 2,
};
