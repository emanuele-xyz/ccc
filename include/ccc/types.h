#pragma once

#include <ccc/asserts.h>

typedef char      i8;
typedef short     i16;
typedef int       i32;
typedef long long i64;

typedef union v2i8 
{
    struct { i8 x, y; };
    i8 v[2];
} v2i8;

typedef union v2i16 
{
    struct { i16 x, y; };
    i16 v[2];
} v2i16;

typedef union v2i32 
{
    struct { i32 x, y; };
    i32 v[2];
} v2i32;

typedef union v2i64 
{
    struct { i64 x, y; };
    i64 v[2];
} v2i64;

ccc_static_assert(sizeof(i8)  == 1);
ccc_static_assert(sizeof(i16) == 2);
ccc_static_assert(sizeof(i32) == 4);
ccc_static_assert(sizeof(i64) == 8);

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef union v2u8 
{
    struct { u8 x, y; };
    u8 v[2];
} v2u8;

typedef union v2u16 
{
    struct { u16 x, y; };
    u16 v[2];
} v2u16;

typedef union v2u32 
{
    struct { u32 x, y; };
    u32 v[2];
} v2u32;

typedef union v2u64 
{
    struct { u64 x, y; };
    u64 v[2];
} v2u64;

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

typedef union v2f32 
{
    struct { f32 x, y; };
    f32 v[2];
} v2f32;

typedef union v2f64 
{
    struct { f64 x, y; };
    f64 v[2];
} v2f64;

ccc_static_assert(sizeof(f32) == 4);
ccc_static_assert(sizeof(f64) == 8);
