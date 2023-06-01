#pragma once

#include <ccc/types.h>
#include <ccc/errors.h>

/*
	Linked list
*/

typedef struct ccc_list
{
	struct ccc_list* next;
	void* ptr;
} ccc_list;

ccc_err ccc_list_init(u64 elem_size, ccc_list** out);
void ccc_list_fini(ccc_list* l);
