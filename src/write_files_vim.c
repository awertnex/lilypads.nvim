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

    if (!(group.flags & FLAG_VIM))
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

void write_colors(const llp_hl_groups groups)
{
    fputc('\n', _file_out);

    title(0, "general highlight groups");
    fputc('\n', _file_out);

    fputc('\n', _file_out);
    title(0, "syntax highlight groups");
    fputc('\n', _file_out);

    highlight_group(0, groups.visual);

    fputc('\n', _file_out);
    title(0, "my favorite section");
    fputc('\n', _file_out);
}
