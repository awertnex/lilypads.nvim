#include "h/common.h"
#include "h/hl_group.h"
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

void highlight_group(u8 level, const llp_hl_group group)
{
    str temp[STRING_MAX] = {0};
    str str_separator[4] = {0};

    /* 0: cterm, 1: gui */
    str str_fg[STRING_MAX] = {0};
    str str_bg[STRING_MAX] = {0};
    str str_sp[STRING_MAX] = {0};
    str str_sp_col[STRING_MAX] = {0};

    if (!group.name[0])
    {
        _log_error("Failed to Write Highlight Group, Name NULL");
        return;
    }

    while (level)
    {
        fprintf(_file_out, "%s", "    ");
        --level;
    }

    if (!(group.flags & FLAG_LUA))
    {
        snprintf(temp, STRING_MAX, "%s {};", group.name);
        comment(1, temp);
        return;
    }

    if (group.flags & FLAG_FG)
    {
        snprintf(str_fg, STRING_MAX, "ctermfg = '#%06x', guifg = '#%06x'",
                group.fg, gui_to_cterm(group.fg));
        snprintf(str_separator, 4, "%s", ", ");
    }

    if (group.flags & FLAG_BG)
    {
        snprintf(str_bg, STRING_MAX, "%sctermbg = '#%06x', guibg = '#%06x'",
                str_separator, group.bg, gui_to_cterm(group.bg));
        snprintf(str_separator, 4, "%s", ", ");
    }

    if (group.flags & FLAG_SP)
    {
        snprintf(str_sp, STRING_MAX, "%scterm = '%s', gui = '%s', guisp = '#%06x'",
                str_separator, hl_group_sp_text[group.sp], hl_group_sp_text[group.sp], group.sp_col);
    }

    fprintf(_file_out, "%s = {%s%s%s};\n",
            group.name, str_fg, str_bg, str_sp);
}

void write_colors(const llp_hl_groups groups)
{
    str temp[STRING_MAX] = {0};
    u32 i = 0;

    fputc('\n', _file_out);
    code(0, "local paints = {");

    title(1, "general highlight groups");
    fputc('\n', _file_out);

    highlight_group(1, groups.special_key);
    highlight_group(1, groups.term_cursor);
    highlight_group(1, groups.non_text);
    highlight_group(1, groups.directory);
    highlight_group(1, groups.error_msg);
    highlight_group(1, groups.search);
    highlight_group(1, groups.cur_search);
    highlight_group(1, groups.more_msg);
    highlight_group(1, groups.mode_msg);
    highlight_group(1, groups.line_nr);
    highlight_group(1, groups.line_nr_above);
    highlight_group(1, groups.line_nr_below);
    highlight_group(1, groups.cursor_line_nr);
    highlight_group(1, groups.question);
    highlight_group(1, groups.status_line);
    highlight_group(1, groups.status_line_nc);

    fputc('\n', _file_out);
    title(1, "syntax highlight groups");
    fputc('\n', _file_out);

    highlight_group(1, groups.visual);

    fputc('\n', _file_out);
    title(1, "my favorite section");
    fputc('\n', _file_out);

    code(0, "}");
}
