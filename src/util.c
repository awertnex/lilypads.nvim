#include "h/common.h"
#include "h/logger.h"

#include <stdio.h>
#include <string.h>

/* I like this function a lot, it's an adjustable-width title (a comment line) */
void title(u8 level, const str *text, const str *file_name)
{
    str temp[STRING_MAX] = {0};
    i32 cursor = 0;
    i32 strlen_cmt = strlen(LLP_CMT);
    FILE *_file = NULL;

    if ((_file = fopen(file_name, "w")) == NULL)
    {
        snprintf(temp, STRING_MAX, "Failed to Write File '%s'", file_name);
        _log_error(temp);
        return;
    }

    while (level)
    {
        cursor += snprintf(temp + cursor, STRING_MAX - cursor, "%s", "    ");
        --level;
    }

    if (!text[0])
    {
        cursor += snprintf(temp + cursor, STRING_MAX - cursor, "%s ", LLP_CMT);
        for (; cursor < TEXT_WIDTH - strlen_cmt - 1; ++cursor)
            temp[cursor] = '-';
        cursor += snprintf(temp + cursor, STRING_MAX - cursor, " %s", LLP_CMT);
        fprintf(_file, "%s\n", temp);
        return;
    }

    cursor += snprintf(temp + cursor, STRING_MAX - cursor, "%s ---- ", LLP_CMT);
    cursor += snprintf(temp + cursor, STRING_MAX - cursor, "%s", text);

    if (cursor < TEXT_WIDTH - strlen_cmt - 1)
        temp[cursor++] = ' ';

    for (; cursor < TEXT_WIDTH - strlen_cmt - 1; ++cursor)
        temp[cursor] = '-';

    if (cursor < TEXT_WIDTH - strlen_cmt)
        cursor += snprintf(temp + cursor, STRING_MAX - cursor, " %s", LLP_CMT);

    fprintf(_file, "%s\n", temp);

    if (_file != NULL)
        fclose(_file);
    return;
}
