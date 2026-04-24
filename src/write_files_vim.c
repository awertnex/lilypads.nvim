#include "h/common.h"
#include "h/logger.h"

#include "stdio.h"

void header_setup(const str *name)
{
    str temp[STRING_MAX] = {0};

    fputc('\n', _file_out);
    code(0, "if exists(\"syntax_on\")");
    code(1, "syntax reset");
    code(0, "endif");
    snprintf(temp, STRING_MAX, "let g:colors_name = \"%s\"", name);
    code(0, temp);
    code(0, "set termguicolors");
    fputc('\n', _file_out);

    code(0, "function! " FUNC_PAINT "(group, setting)");
    code(1, "let cmd = 'hi ' . a:group");
    code(1, "for [key, value] in items(a:setting)");
    code(2, "let cmd .= ' ' . key . '=' . value");
    code(1, "endfor");
    code(1, "execute cmd");
    code(0, "endfunction");
    fputc('\n', _file_out);

    code(0, "function! " FUNC_CLEAR "(group)");
    code(1, "execute 'hi clear ' . a:group");
    code(0, "endfunction");
}

void footer_setup(void) {} /* no code is required on the vim side */

void write_colors(const llp_theme_colors c)
{
    fputc('\n', _file_out);

    title(0, "general highlight groups");
    fputc('\n', _file_out);

    title(0, "syntax highlight groups");
    fputc('\n', _file_out);

    title(0, "my favorite section");
    fputc('\n', _file_out);
}
