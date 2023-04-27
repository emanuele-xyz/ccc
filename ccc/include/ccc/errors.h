#pragma once

typedef enum ccc_err
{
	CCC_OK,
	CCC_ERR_ALLOC_FAIL,
	CCC_ERR_CANT_FREE,
} ccc_err;

#define ccc_ok(e) ((e) == CCC_OK)
#define ccc_err(e) (!ccc_ok(e))
