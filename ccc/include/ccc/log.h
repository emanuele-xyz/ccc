#pragma once

typedef enum ccc_log_level
{
	CCC_LOG_ERROR,
	CCC_LOG_WARN,
	CCC_LOG_INFO,
	CCC_LOG_DBG,
	CCC_LOG_MAX,
} ccc_log_level;

void ccc_log_init(void);
void ccc_log_fini(void);
void ccc_log_no_head(ccc_log_level lvl, const char* msg);
void ccc_log(ccc_log_level lvl, const char* msg);
void ccc_logf_no_head(ccc_log_level lvl, const char* msg, ...);
void ccc_logf(ccc_log_level lvl, const char* msg, ...);
