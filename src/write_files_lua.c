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
    code(1, "local guisp = table.guifg and table.guifg or \"NONE\"");
    fputc('\n', _file_out);

    code(1, "vim.cmd(\"highlight \" .. group .. \" ctermfg=\" .. termfg .. \" guifg=\" .. guifg .. \" ctermbg=\" .. termbg .. \" guibg=\" .. guibg .. \" cterm=\" .. sp .. \" gui=\" .. sp .. \" guisp=\" .. guisp)");
    code(0, "end");
    fputc('\n', _file_out);

    code(0, "function " FUNC_LINK "(src, dst)");
    code(1, "vim.cmd(\"hi clear \" .. src)");
    code(1, "vim.cmd(\"hi link \" .. src .. \" \" .. dst)");
    code(0, "end");
}

void footer_setup(const llp_hl_groups groups)
{
    fputc('\n', _file_out);
    code(0, "for key, value in pairs(paints) do");
    code(1, FUNC_PAINT"(key, value)");
    code(0, "end");

    link_group(0, "@variable", groups.function);
    link_group(0, "@variable.builtin", groups.function);
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

    if (!(group.flags & FLAG_ON))
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

void link_group(u8 level, const str *src, const llp_hl_group dst)
{
    while (level)
    {
        fprintf(_file_out, "%s", "    ");
        --level;
    }

    fprintf(_file_out, FUNC_LINK "('%s', '%s')\n", src, dst.name);
}

void write_colors(const llp_hl_groups groups)
{
    fputc('\n', _file_out);
    code(0, "local paints = {");

    fputc('\n', _file_out);
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
    highlight_group(1, groups.spell_bad);
    highlight_group(1, groups.spell_cap);
    highlight_group(1, groups.spell_rare);
    highlight_group(1, groups.spell_local);
    highlight_group(1, groups.pmenu);
    highlight_group(1, groups.pmenu_sel);
    highlight_group(1, groups.pmenu_match);
    highlight_group(1, groups.pmenu_match_sel);
    highlight_group(1, groups.pmenu_sbar);
    highlight_group(1, groups.pmenu_thumb);
    highlight_group(1, groups.tab_line);
    highlight_group(1, groups.tab_line_sel);
    highlight_group(1, groups.tab_line_fill);
    highlight_group(1, groups.cursor_column);
    highlight_group(1, groups.cursor_line);
    highlight_group(1, groups.color_column);
    highlight_group(1, groups.quick_fix_line);
    highlight_group(1, groups.normal_nc);
    highlight_group(1, groups.normal_float);
    highlight_group(1, groups.float_border);
    highlight_group(1, groups.win_bar);
    highlight_group(1, groups.win_bar_nc);
    highlight_group(1, groups.cursor);
    highlight_group(1, groups.redraw_debug_normal);
    highlight_group(1, groups.underlined);
    highlight_group(1, groups.l_cursor);

    fputc('\n', _file_out);
    title(1, "my favorite section");
    fputc('\n', _file_out);

    highlight_group(1, groups.normal);
    highlight_group(1, groups.character);
    highlight_group(1, groups.constant);
    highlight_group(1, groups.number);
    highlight_group(1, groups.boolean);
    highlight_group(1, groups.conditional);
    highlight_group(1, groups.statement);
    highlight_group(1, groups.include);
    highlight_group(1, groups.pre_proc);
    highlight_group(1, groups.define);
    highlight_group(1, groups.macro);
    highlight_group(1, groups.type);
    highlight_group(1, groups.special);
    highlight_group(1, groups.diagnostic_error);
    highlight_group(1, groups.diagnostic_warn);
    highlight_group(1, groups.diagnostic_info);
    highlight_group(1, groups.diagnostic_hint);
    highlight_group(1, groups.diagnostic_ok);
    highlight_group(1, groups.comment);
    highlight_group(1, groups.string);
    highlight_group(1, groups.identifier);
    highlight_group(1, groups.function);
    highlight_group(1, groups.operator);
    highlight_group(1, groups.delimiter);
    highlight_group(1, groups.todo);
    highlight_group(1, groups.added);
    highlight_group(1, groups.removed);
    highlight_group(1, groups.changed);
    highlight_group(1, groups.diagnostic_deprecated);
    highlight_group(1, groups.float_shadow);
    highlight_group(1, groups.float_shadow_through);
    highlight_group(1, groups.match_paren);
    highlight_group(1, groups.redraw_debug_clear);
    highlight_group(1, groups.redraw_debug_composed);
    highlight_group(1, groups.redraw_debug_recompose);
    highlight_group(1, groups.error);
    highlight_group(1, groups.diagnostic_underline_error);
    highlight_group(1, groups.diagnostic_underline_warn);
    highlight_group(1, groups.diagnostic_underline_info);
    highlight_group(1, groups.diagnostic_underline_hint);
    highlight_group(1, groups.diagnostic_underline_ok);

    fputc('\n', _file_out);
    title(1, "other highlight groups");
    fputc('\n', _file_out);

    highlight_group(1, groups.nvim_internal_error);
    highlight_group(1, groups.nvim_spacing);
    highlight_group(1, groups.cmp_item_abbr_default);
    highlight_group(1, groups.vim_user_func);
    highlight_group(1, groups.vim_embed_error);
    highlight_group(1, groups.cmp_item_abbr_deprecated_default);
    highlight_group(1, groups.cmp_item_abbr_match_default);
    highlight_group(1, groups.cmp_item_abbr_match_fuzzy_default);
    highlight_group(1, groups.cmp_item_kind_default);
    highlight_group(1, groups.cmp_item_menu_default);

    code(0, "}");
}
