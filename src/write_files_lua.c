#include "h/common.h"
#include "h/logger.h"

#include "stdio.h"

void header_setup(const str *name) /* no code is required on the lua side */
{
    (void)name;
}

void footer_setup(void)
{
    fputs("\n\n", _file_out);
    code(0, "function set_paint(group, table)");
    code(1, "local cterm = table.cterm and table.cterm or \"NONE\"");
    code(1, "local fg = table.fg and table.fg or \"NONE\"");
    code(1, "local bg = table.bg and table.bg or \"NONE\"");
    code(1, "local gui = table.gui and table.gui or \"NONE\"");
    code(1, "local guisp = table.guisp and table.guisp or \"NONE\"");
    code(1, "vim.cmd(\"highlight \" .. group .. \" cterm=\" .. cterm .. \" guifg=\" .. fg .. \" guibg=\" .. bg .. \" gui=\" .. gui .. \" guisp=\" .. guisp)");
    code(0, "end");
    fputc('\n', _file_out);
    code(0, "for key, value in pairs(paints) do");
    code(1, "set_paint(key, value)");
    code(0, "end");
}

void write_colors(llp_theme_colors colors)
{
    str temp[STRING_MAX] = {0};

    code(0, "local paints = {");
    code(0, "}");
}
