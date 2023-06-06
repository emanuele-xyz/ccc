#include <ccc/hash.h>

u64 ccc_hash_bytes(u64 length, char* str)
{
	u64 hash = 5381;
	for (u64 i = 0; i < length; i++)
	{
		hash = ((hash << 5) + hash) + str[i]; /* hash * 33 + c */
	}
	return hash;
}

u64 ccc_hash_i8(i8 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_i16(i16 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_i32(i32 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_i64(i64 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }

u64 ccc_hash_v2i8(v2i8 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v2i16(v2i16 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v2i32(v2i32 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v2i64(v2i64 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }

u64 ccc_hash_v3i8(v3i8 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v3i16(v3i16 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v3i32(v3i32 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v3i64(v3i64 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }

u64 ccc_hash_u8(u8 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_u16(u16 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_u32(u32 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_u64(u64 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }

u64 ccc_hash_v2u8(v2u8 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v2u16(v2u16 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v2u32(v2u32 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v2u64(v2u64 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }

u64 ccc_hash_v3u8(v3u8 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v3u16(v3u16 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v3u32(v3u32 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v3u64(v3u64 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }

u64 ccc_hash_b8(b8 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_b16(b16 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_b32(b32 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_b64(b64 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }

u64 ccc_hash_f32(f32 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_f64(f64 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }

u64 ccc_hash_v2f32(v2f32 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v2f64(v2f64 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }

u64 ccc_hash_v3f32(v3f32 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
u64 ccc_hash_v3f64(v3f64 x) { return ccc_hash_bytes(sizeof(x), (char*)(&x)); }
