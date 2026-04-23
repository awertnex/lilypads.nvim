#include "h/common.h"
#include "h/logger.h"

FILE *_file_out = NULL;

int main(void)
{
    str temp[STRING_MAX] = {0};

    if ((_file_out = fopen("FUCK", "w")) == NULL)
    {
        snprintf(temp, STRING_MAX, "Failed to Write File '%s'", "FUCK");
        _log_error(temp);
        goto cleanup;
    }

    if (_file_out != NULL)
        fclose(_file_out);

cleanup:
    if (_file_out != NULL)
        fclose(_file_out);
    return 0;
}
