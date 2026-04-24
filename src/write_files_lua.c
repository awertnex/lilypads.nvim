#include "h/common.h"
#include "h/logger.h"

#include "stdio.h"

void header_setup(const str *name) /* no code is required on the lua side */
{
    (void)name;

    fputc('\n', _file_out);
    code(0, "function " FUNC_PAINT "(group, table)");
    code(1, "local cterm = table.cterm and table.cterm or \"NONE\"");
    code(1, "local fg = table.fg and table.fg or \"NONE\"");
    code(1, "local bg = table.bg and table.bg or \"NONE\"");
    code(1, "local gui = table.gui and table.gui or \"NONE\"");
    code(1, "local guisp = table.guisp and table.guisp or \"NONE\"");
    code(1, "vim.cmd(\"highlight \" .. group .. \" cterm=\" .. cterm .. \" guifg=\" .. fg .. \" guibg=\" .. bg .. \" gui=\" .. gui .. \" guisp=\" .. guisp)");
    code(0, "end");
}

void footer_setup(void)
{
    fputc('\n', _file_out);
    code(0, "for key, value in pairs(paints) do");
    code(1, FUNC_PAINT"(key, value)");
    code(0, "end");
}

void write_colors(const llp_theme_colors c)
{
    str temp[STRING_MAX] = {0};

    fputc('\n', _file_out);
    code(0, "local paints = {");

    title(1, "general highlight groups");
    fputc('\n', _file_out);

    title(1, "syntax highlight groups");
    fputc('\n', _file_out);

    title(1, "my favorite section");
    fputc('\n', _file_out);

    code(0, "}");
}
