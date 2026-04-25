#include "h/common.h"
#include "h/hl_group.h"
#include "h/logger.h"

#include <stdio.h>
#include <inttypes.h>

void header_setup(const str *name) /* no code is required on the lua side */
{
    (void)name;

    fputc('\n', _file_out);
    code(0, "function " FUNC_PAINT "(group, table)");
    code(1, "local termfg = table.termfg and table.termfg or \"NONE\"");
    code(1, "local termbg = table.termbg and table.termbg or \"NONE\"");
    code(1, "local guifg = table.guifg and table.guifg or \"NONE\"");
    code(1, "local guibg = table.guibg and table.guibg or \"NONE\"");
    code(1, "local sp = table.sp and table.sp or \"NONE\"");
    code(1, "vim.cmd(\"highlight \" .. group .. \" ctermfg=\" .. termfg .. \" guifg=\" .. guifg .. \" ctermbg=\" .. termbg .. \" guibg=\" .. guibg .. \" cterm=\" .. sp .. \" gui=\" .. sp .. \" guisp=\" .. guifg)");
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
        comment(0, temp);
        return;
    }

    if (group.flags & FLAG_FG)
    {
        snprintf(str_fg, STRING_MAX, "termfg = '%"PRIu32"', guifg = '#%06"PRIx32"'",
                gui_to_cterm(group.fg), group.fg);
        snprintf(str_separator, 4, "%s", ", ");
    }

    if (group.flags & FLAG_BG)
    {
        snprintf(str_bg, STRING_MAX, "%stermbg = '%"PRIu32"', guibg = '#%06"PRIx32"'",
                str_separator, gui_to_cterm(group.bg), group.bg);
        snprintf(str_separator, 4, "%s", ", ");
    }

    if (group.flags & FLAG_SP)
        snprintf(str_sp, STRING_MAX, "%ssp = '%s'", str_separator, hl_group_sp_text[group.sp]);

    fprintf(_file_out, "%s = {%s%s%s};\n",
            group.name, str_fg, str_bg, str_sp);
}

void write_colors(const llp_hl_groups groups)
{
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

    highlight_group(1, groups.win_separator);
    highlight_group(1, groups.vert_split);
    highlight_group(1, groups.title);
    highlight_group(1, groups.visual);
    highlight_group(1, groups.warning_msg);
    highlight_group(1, groups.folded);
    highlight_group(1, groups.diff_add);
    highlight_group(1, groups.diff_change);
    highlight_group(1, groups.diff_delete);
    highlight_group(1, groups.diff_text);
    highlight_group(1, groups.sign_column);
    highlight_group(1, groups.conceal);

    fputc('\n', _file_out);
    title(1, "my favorite section");
    fputc('\n', _file_out);

    highlight_group(1, groups.diagnostic_error);
    highlight_group(1, groups.diagnostic_warn);
    highlight_group(1, groups.diagnostic_info);
    highlight_group(1, groups.diagnostic_hint);
    highlight_group(1, groups.diagnostic_ok);

    code(0, "}");
}
