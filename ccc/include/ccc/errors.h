#pragma once

typedef enum ccc_err
{
	CCC_OK,
	CCC_ERR_ALLOC_FAIL,
	CCC_ERR_CANT_FREE,
	CCC_ERR_INVARIANT,
} ccc_err;

#define ccc_ok(e) ((e) == CCC_OK)
#define ccc_err(e) (!ccc_ok(e))
#define ccc_invariant(p) ((p) ? CCC_OK : CCC_ERR_INVARIANT)

const char* ccc_err_desc(ccc_err err);
