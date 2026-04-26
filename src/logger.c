#include "h/common.h"
#include "h/logger.h"

#include <stdio.h>

void _log_error(const str *msg)
{
    fprintf(stderr, "\033[91m[ERROR]: %s\033[0m\n", msg);
}

void _log_warning(const str *msg)
{
    fprintf(stderr, "\033[95m[ERROR]: %s\033[0m\n", msg);
}
