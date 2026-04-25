#include "h/common.h"
#include "h/hl_group.h"
#include "h/logger.h"

#include <stdio.h>
#include <inttypes.h>

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

    code(0, "function! " FUNC_PAINT "(group, parameters)");
    code(1, "call " FUNC_CLEAR "(a:group)");
    code(1, "let cmd = 'hi ' . a:group");
    code(1, "for [key, value] in items(a:parameters)");
    code(2, "let cmd .= ' ' . key . '=' . value");
    code(1, "endfor");
    code(1, "execute cmd");
    code(0, "endfunction");
    fputc('\n', _file_out);

    code(0, "function! " FUNC_CLEAR "(group)");
    code(1, "execute 'hi clear ' . a:group");
    code(0, "endfunction");
}

void footer_setup(const llp_hl_groups groups) /* no code is required on the vim side */
{
    (void)groups;
}


void highlight_group(u8 level, const llp_hl_group group)
{
    str temp[STRING_MAX] = {0};
    str str_separator[4] = {0};

    /* 0: cterm, 1: gui, 2: term */
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
        snprintf(temp, STRING_MAX, "call " FUNC_PAINT "('%s', {})", group.name);
        comment(0, temp);
        return;
    }

    if (group.flags & FLAG_FG)
    {
        snprintf(str_fg, STRING_MAX, "'ctermfg': '%"PRIu32"', 'guifg': '#%06"PRIx32"'",
                gui_to_cterm(group.fg), group.fg);
        snprintf(str_separator, 4, "%s", ", ");
    }

    if (group.flags & FLAG_BG)
    {
        snprintf(str_bg, STRING_MAX, "%s'ctermbg': '%"PRIu32"', 'guibg': '#%06"PRIx32"'",
                str_separator, gui_to_cterm(group.bg), group.bg);
        snprintf(str_separator, 4, "%s", ", ");
    }

    if (group.flags & FLAG_SP)
    {
        snprintf(str_sp, STRING_MAX, "%s'term': '%s', 'cterm': '%s', 'gui': '%s', 'guisp': '#%06"PRIx32"'",
                str_separator,
                hl_group_sp_text[group.sp], hl_group_sp_text[group.sp],
                hl_group_sp_text[group.sp], group.fg);
    }

    fprintf(_file_out, "call " FUNC_PAINT "('%s', {%s%s%s})\n",
            group.name, str_fg, str_bg, str_sp);
}

void link_group(u8 level, const str *src, const llp_hl_group dst)
{
    (void)level;
    (void)src;
    (void)dst;
}

void write_colors(const llp_hl_groups groups)
{
    fputc('\n', _file_out);

    title(0, "general highlight groups");
    fputc('\n', _file_out);

    highlight_group(0, groups.color_column);
    highlight_group(0, groups.conceal);
    highlight_group(0, groups.cur_search);
    highlight_group(0, groups.cursor);
    highlight_group(0, groups.cursor_column);
    highlight_group(0, groups.cursor_line);
    highlight_group(0, groups.cursor_line_nr);
    highlight_group(0, groups.diff_add);
    highlight_group(0, groups.diff_change);
    highlight_group(0, groups.diff_delete);
    highlight_group(0, groups.diff_text);
    highlight_group(0, groups.directory);
    highlight_group(0, groups.error_msg);
    highlight_group(0, groups.fold_column);
    highlight_group(0, groups.folded);
    highlight_group(0, groups.ignore);
    highlight_group(0, groups.inc_search);
    highlight_group(0, groups.line_nr);
    highlight_group(0, groups.line_nr_above);
    highlight_group(0, groups.line_nr_below);
    highlight_group(0, groups.match_paren);
    highlight_group(0, groups.mode_msg);
    highlight_group(0, groups.more_msg);
    highlight_group(0, groups.non_text);
    highlight_group(0, groups.normal);
    highlight_group(0, groups.pmenu);
    highlight_group(0, groups.pmenu_sbar);
    highlight_group(0, groups.pmenu_sel);
    highlight_group(0, groups.pmenu_thumb);
    highlight_group(0, groups.question);
    highlight_group(0, groups.search);
    highlight_group(0, groups.sign_column);
    highlight_group(0, groups.special_key);
    highlight_group(0, groups.spell_bad);
    highlight_group(0, groups.spell_cap);
    highlight_group(0, groups.spell_rare);
    highlight_group(0, groups.spell_local);
    highlight_group(0, groups.status_line);
    highlight_group(0, groups.status_line_nc);
    highlight_group(0, groups.status_line_term);
    highlight_group(0, groups.status_line_term_nc);
    highlight_group(0, groups.tab_line);
    highlight_group(0, groups.tab_line_fill);
    highlight_group(0, groups.tab_line_sel);
    highlight_group(0, groups.title);
    highlight_group(0, groups.toolbar_button);
    highlight_group(0, groups.toolbar_line);
    highlight_group(0, groups.visual);
    highlight_group(0, groups.visual_nos);
    highlight_group(0, groups.warning_msg);
    highlight_group(0, groups.wild_menu);
    highlight_group(0, groups.l_cursor);

    fputc('\n', _file_out);
    title(0, "syntax highlight groups");
    fputc('\n', _file_out);

    highlight_group(0, groups.added);
    highlight_group(0, groups.boolean);
    highlight_group(0, groups.changed);
    highlight_group(0, groups.character);
    highlight_group(0, groups.cmp_item_abbr_default);
    highlight_group(0, groups.cmp_item_abbr_deprecated_default);
    highlight_group(0, groups.cmp_item_abbr_match_default);
    highlight_group(0, groups.cmp_item_abbr_match_fuzzy_default);
    highlight_group(0, groups.cmp_item_kind_default);
    highlight_group(0, groups.cmp_item_menu_default);
    highlight_group(0, groups.comment);
    highlight_group(0, groups.conditional);
    highlight_group(0, groups.constant);
    highlight_group(0, groups.define);
    highlight_group(0, groups.diagnostic_error);
    highlight_group(0, groups.diagnostic_warn);
    highlight_group(0, groups.diagnostic_info);
    highlight_group(0, groups.diagnostic_hint);
    highlight_group(0, groups.diagnostic_ok);
    highlight_group(0, groups.diagnostic_underline_error);
    highlight_group(0, groups.diagnostic_underline_warn);
    highlight_group(0, groups.diagnostic_underline_info);
    highlight_group(0, groups.diagnostic_underline_hint);
    highlight_group(0, groups.diagnostic_underline_ok);
    highlight_group(0, groups.error);
    highlight_group(0, groups.float_border);
    highlight_group(0, groups.function);
    highlight_group(0, groups.identifier);
    highlight_group(0, groups.include);
    highlight_group(0, groups.macro);
    highlight_group(0, groups.number);
    highlight_group(0, groups.nvim_internal_error);
    highlight_group(0, groups.nvim_spacing);
    highlight_group(0, groups.operator);
    highlight_group(0, groups.pre_proc);
    highlight_group(0, groups.redraw_debug_clear);
    highlight_group(0, groups.redraw_debug_composed);
    highlight_group(0, groups.redraw_debug_recompose);
    highlight_group(0, groups.removed);
    highlight_group(0, groups.special);
    highlight_group(0, groups.statement);
    highlight_group(0, groups.string);
    highlight_group(0, groups.todo);
    highlight_group(0, groups.type);
    highlight_group(0, groups.underlined);
    highlight_group(0, groups.vim_embed_error);
    highlight_group(0, groups.vim_user_func);
}
