#include "h/common.h"
#include "h/logger.h"

#include "stdio.h"

void header_setup(const str *name)
{
    str temp[STRING_MAX] = {0};

    code(0, "if exists(\"syntax_on\")");
    code(1, "syntax reset");
    code(0, "endif");
    snprintf(temp, STRING_MAX, "let g:colors_name = \"%s\"", name);
    code(0, temp);
    code(0, "set termguicolors");
    fputc('\n', _file_out);
}

void footer_setup(void) {} /* no code is required on the vim side */

void write_colors(llp_theme_colors colors)
{
}
