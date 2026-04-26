#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#define STRING_MAX 2048
#define TEXT_WIDTH 80
#define LLP_CMT "--"

enum hl_group_sp_index
{
    HL_GROUP_SP_NONE,
    HL_GROUP_SP_BOLD,
    HL_GROUP_SP_UNDERLINE,
    HL_GROUP_SP_UNDERCURL,
    HL_GROUP_SP_UNDERDOUBLE,
    HL_GROUP_SP_UNDERDOTTED,
    HL_GROUP_SP_UNDERDASHED,
    HL_GROUP_SP_STRIKETHROUGH,
    HL_GROUP_SP_REVERSE,
    HL_GROUP_SP_INVERSE,
    HL_GROUP_SP_ITALIC,
    HL_GROUP_SP_STANDOUT,
    HL_GROUP_SP_ALTFONT,
    HL_GROUP_SP_DIM,
    HL_GROUP_SP_BLINK,
    HL_GROUP_SP_CONCEAL,
    HL_GROUP_SP_OVERLINE,
    HL_GROUP_SP_NOCOMBINE,
    HL_GROUP_SP_COUNT
}; /* hl_group_sp_index */

void _log_error(const char *msg)
{
    fprintf(stderr, "\033[91m[ERROR]: %s\033[0m\n", msg);
}

/* I like this function a lot, it's an adjustable-width title (a comment line) */
void title(unsigned int level, const char *text, const char *file_name)
{
    char temp[STRING_MAX] = {0};
    int cursor = 0;
    int strlen_cmt = strlen(LLP_CMT);
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
