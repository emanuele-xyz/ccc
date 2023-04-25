#include <ccc/log.h>
#include <ccc/win32.h>

// TODO: https://github.com/emanuele-xyz/Blaze/blob/master/Blaze/src/log.c

static const char* s_headers[CCC_LOG_MAX] =
{
	[CCC_LOG_ERROR] = "ERROR",
	[CCC_LOG_WARN] = "WARN",
	[CCC_LOG_INFO] = "INFO",
	[CCC_LOG_DBG] = "DEBUG",
};

void ccc_log_init(void)
{
}

void ccc_log_fini(void)
{
}

void ccc_log_no_head(ccc_log_level lvl, const char* msg)
{
}

void ccc_log(ccc_log_level lvl, const char* msg)
{
}

void ccc_logf_no_head(ccc_log_level lvl, const char* msg, ...)
{
}

void ccc_logf(ccc_log_level lvl, const char* msg, ...)
{
}
