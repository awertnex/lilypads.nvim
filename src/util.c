#include "h/common.h"

#include "string.h"

void vim_cmd(const str *cmd)
{
    fprintf(_file_out, LLP_VIM_CMD_OPEN "%s" LLP_VIM_CMD_CLOSE "\n", cmd);
}

void code(u8 level, const str *text)
{
    while (level)
    {
        fprintf(_file_out, "%s", "    ");
        --level;
    }
    fprintf(_file_out, "%s\n", text);
}

void comment(const str *text)
{
    fprintf(_file_out, LLP_CMT" %s\n", text);
}

void comment_block(const str *text)
{
    i64 i = 0;

    fprintf(_file_out, "%s", LLP_CMT);

    while (text[i])
    {
        fputc(text[i], _file_out);
        if (text[i] == '\n')
            fprintf(_file_out, "%s", LLP_CMT);
        ++i;
    }
    fputc('\n', _file_out);
}

void license(void)
{
    str temp[STRING_MAX * 4] = {0};
    snprintf(temp, STRING_MAX * 4,
            LLP_CMT_TAB1"MIT License\n"
            "\n"
            LLP_CMT_TAB1"Copyright (c) %s %s\n"
            "\n"
            LLP_CMT_TAB1"Permission is hereby granted, free of charge, to any person obtaining a copy\n"
            LLP_CMT_TAB1"of this software and associated documentation files (the \"Software\"), to deal\n"
            LLP_CMT_TAB1"in the Software without restriction, including without limitation the rights\n"
            LLP_CMT_TAB1"to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n"
            LLP_CMT_TAB1"copies of the Software, and to permit persons to whom the Software is\n"
            LLP_CMT_TAB1"furnished to do so, subject to the following conditions:\n"
            "\n"
            LLP_CMT_TAB1"The above copyright notice and this permission notice shall be included in all\n"
            LLP_CMT_TAB1"copies or substantial portions of the Software.\n"
            "\n"
            LLP_CMT_TAB1"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
            LLP_CMT_TAB1"IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
            LLP_CMT_TAB1"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n"
            LLP_CMT_TAB1"AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n"
            LLP_CMT_TAB1"LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
            LLP_CMT_TAB1"OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n"
            LLP_CMT_TAB1"SOFTWARE.\n",
        LLP_LICENSE_YEAR, LLP_LICENSE_OWNER);

    comment_block(temp);
}

void title(const str *text)
{
    str temp[STRING_MAX] = {0};
    i32 cursor = 0;
    i32 strlen_cmt = strlen(LLP_CMT);

    if (!text[0])
    {
        cursor += snprintf(temp, STRING_MAX, "%s ", LLP_CMT);
        for (; cursor < TEXT_WIDTH - strlen_cmt - 1; ++cursor)
            temp[cursor] = '-';
        cursor += snprintf(temp + cursor, STRING_MAX - cursor, " %s", LLP_CMT);
        fprintf(_file_out, "%s\n", temp);
        return;
    }

    cursor += snprintf(temp, STRING_MAX, "%s ---- ", LLP_CMT);
    cursor += snprintf(temp + cursor, STRING_MAX - cursor, "%s", text);

    if (cursor < TEXT_WIDTH - strlen_cmt - 1)
        temp[cursor++] = ' ';

    for (; cursor < TEXT_WIDTH - strlen_cmt - 1; ++cursor)
        temp[cursor] = '-';

    if (cursor < TEXT_WIDTH - strlen_cmt)
        cursor += snprintf(temp + cursor, STRING_MAX - cursor, " %s", LLP_CMT);

    fprintf(_file_out, "%s\n", temp);
}
