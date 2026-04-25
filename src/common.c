#include "h/common.h"
#include "h/config.h"

#include <stdio.h>

/* ---- section: declarations ----------------------------------------------- */

static llp_col nocolor = {0};

static llp_col_base col_base_nature_dark =
{
    { 52, 128,  49}, /* base */
    { 61, 143,  36}, /* loud */
    { 98, 179,  72}, /* bright */
    { 44,  82,  28}, /* visual */
    {151, 185, 148}, /* habitable */
    {128, 122,  38}, /* dry0 */
    {142, 153,  92}, /* dry1 */
    {175, 204, 177}, /* thirsty */
    { 90, 128,  44}, /* mossy */
    {162, 222, 137}, /* radioactive */
    {164, 237, 116}, /* highly_radioactive */
    {101, 255,   0}  /* blooming_radioactive */
};

static llp_col_base col_base_nature_dark_dead =
{0
};

static llp_col_base col_base_nature_light =
{0
};

static llp_col_base col_base_nature_light_dead =
{0
};

static llp_col_base col_base_cherry_dark =
{0
};

static llp_col_base col_base_cherry_dark_dead =
{0
};

static llp_col_base col_base_cherry_light =
{0
};

static llp_col_base col_base_cherry_light_dead =
{0
};

static llp_col_base col_base_oceans_dark =
{0
};

static llp_col_base col_base_oceans_dark_dead =
{0
};

static llp_col_base col_base_oceans_light =
{0
};

static llp_col_base col_base_oceans_light_dead =
{0
};

static llp_col_ui col_ui_dark =
{
    { 31,  31,  31},    /* base */
    { 24,  24,  24},    /* base_nc */
    { 27,  27,  27},    /* base_nc_light */
    { 36,  36,  36},    /* line_nu */
    { 64,  64,  64},    /* status_line */
    { 48,  48,  48}     /* status_line_nc */
};

static llp_col_ui col_ui_light =
{0
};

static llp_col_text col_text_dark =
{
    {188, 188, 188},    /* text */
    {236, 236, 236},    /* text_alt */
    {127, 136, 141},    /* line_nu */
    { 74,  77,  77},    /* comment */
    {136, 242, 235},    /* link */

    {204,  41,  53},    /* error */
    {128,  62,  38},    /* error_alt */
    {204,  88,  41},    /* warn */
    {122, 202, 204},    /* info */
    {208, 230, 207},    /* hint */
    {162, 222, 137}     /* ok */
};

static llp_col_text col_text_light =
{
    {188, 188, 188},    /* text */      /* (TODO: adjust color for light mode) */
    {236, 236, 236},    /* text_alt */  /* (TODO: adjust color for light mode) */
    {127, 136, 141},    /* line_nu */   /* (TODO: adjust color for light mode) */
    { 74,  77,  77},    /* comment */   /* (TODO: adjust color for light mode) */
    {136, 242, 235},    /* link */      /* (TODO: adjust color for light mode) */

    {204,  41,  53},    /* error */
    {128,  62,  38},    /* error_alt */
    {204,  88,  41},    /* warn */
    {122, 202, 204},    /* info */      /* (TODO: adjust color for light mode) */
    {208, 230, 207},    /* hint */      /* (TODO: adjust color for light mode) */
    {162, 222, 137}     /* ok */        /* (TODO: adjust color for light mode) */
};

/* ---- section: implementation --------------------------------------------- */

void setup_hl_group(llp_hl_group *g, const str *name, u32 flags,
        llp_col fg, llp_col bg, enum hl_group_sp_index sp)
{
    if (name)
        snprintf(g->name, HL_GROUP_NAME_MAX, "%s", name);

    g->flags = flags;
    g->fg = rgb_to_hex(fg);
    g->bg = rgb_to_hex(bg);
    g->sp = sp;
}

void setup_hl_groups(llp_colorscheme *col)
{
    llp_hl_groups *g = &col->groups;

    setup_hl_group(&g->special_key, "SpecialKey", FLAG_LUA | FLAG_FG, col->c_base.blooming_radioactive, nocolor, 0);
    setup_hl_group(&g->term_cursor, "TermCursor", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->non_text, "NonText", FLAG_LUA | FLAG_FG, col->c_base.radioactive, nocolor, 0);
    setup_hl_group(&g->directory, "Directory", FLAG_LUA | FLAG_FG, col->c_base.highly_radioactive, nocolor, 0);
    setup_hl_group(&g->error_msg, "ErrorMsg", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.text_alt, col->c_text.error_alt, 0);
    setup_hl_group(&g->search, "Search", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.text, col->c_ui.status_line, 0);
    setup_hl_group(&g->cur_search, "CurSearch", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_base.highly_radioactive, col->c_ui.status_line, 0);
    setup_hl_group(&g->more_msg, "MoreMsg", FLAG_LUA | FLAG_FG | FLAG_SP, col->c_base.bright, nocolor, HL_GROUP_SP_BOLD);
    setup_hl_group(&g->mode_msg, "ModeMsg", FLAG_LUA | FLAG_FG | FLAG_SP, col->c_base.highly_radioactive, nocolor, HL_GROUP_SP_BOLD);
    setup_hl_group(&g->line_nr, "LineNr", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.line_nu, col->c_ui.line_nu, 0);
    setup_hl_group(&g->line_nr_above, "LineNrAbove", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.comment, col->c_ui.line_nu, 0);
    setup_hl_group(&g->line_nr_below, "LineNrBelow", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.comment, col->c_ui.line_nu, 0);
    setup_hl_group(&g->cursor_line_nr, "CursorLineNr", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.line_nu, col->c_ui.line_nu, 0);
    setup_hl_group(&g->question, "Question", FLAG_LUA | FLAG_FG, col->c_text.link, nocolor, 0);
    setup_hl_group(&g->status_line, "StatusLine", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.text, col->c_ui.status_line, 0);
    setup_hl_group(&g->status_line_nc, "StatusLineNC", FLAG_LUA | FLAG_FG | FLAG_BG, col_nc(col->c_text.text), col_nc(col->c_ui.status_line), 0);

    setup_hl_group(&g->win_separator, "WinSeparator", FLAG_LUA | FLAG_FG, col->c_ui.base, nocolor, 0);
    setup_hl_group(&g->vert_split, "VertSplit", FLAG_LUA | FLAG_FG, col->c_ui.base, nocolor, 0);
    setup_hl_group(&g->title, "Title", FLAG_LUA | FLAG_FG, col->c_base.highly_radioactive, nocolor, 0);
    setup_hl_group(&g->visual, "Visual", FLAG_LUA | FLAG_VIM | FLAG_FG | FLAG_BG, col->c_base.highly_radioactive, col->c_base.visual, 0);
    setup_hl_group(&g->warning_msg, "WarningMsg", FLAG_LUA | FLAG_FG, col->c_text.warn, nocolor, 0);
    setup_hl_group(&g->folded, "Folded", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->diff_add, "DiffAdd", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->diff_change, "DiffChange", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->diff_delete, "DiffDelete", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->diff_text, "DiffText", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->sign_column, "SignColumn", FLAG_LUA | FLAG_FG | FLAG_BG | FLAG_SP, col->c_base.highly_radioactive, col->c_ui.line_nu, HL_GROUP_SP_BOLD);
    setup_hl_group(&g->conceal, "Conceal", 0, nocolor, nocolor, 0);
#if 0
    setup_hl_group(&g->spell_bad, "SpellBad", FLAG_LUA,
    setup_hl_group(&g->spell_cap, "SpellCap", FLAG_LUA,
    setup_hl_group(&g->spell_rare, "SpellRare", FLAG_LUA,
    setup_hl_group(&g->spell_local, "SpellLocal", FLAG_LUA,
    setup_hl_group(&g->pmenu, "Pmenu", FLAG_LUA,
    setup_hl_group(&g->pmenu_sel, "PmenuSel", FLAG_LUA,
    setup_hl_group(&g->pmenu_match, "PmenuMatch", FLAG_LUA,
    setup_hl_group(&g->pmenu_match_sel, "PmenuMatchSel", FLAG_LUA,
    setup_hl_group(&g->pmenu_sbar, "PmenuSbar", FLAG_LUA,
    setup_hl_group(&g->pmenu_thumb, "PmenuThumb", FLAG_LUA,
    setup_hl_group(&g->tab_line, "TabLine", FLAG_LUA,
    setup_hl_group(&g->tab_line_sel, "TabLineSel", FLAG_LUA,
    setup_hl_group(&g->tab_line_fill, "TabLineFill", FLAG_LUA,
    setup_hl_group(&g->cursor_column, "CursorColumn", FLAG_LUA,
    setup_hl_group(&g->cursor_line, "CursorLine", FLAG_LUA,
    setup_hl_group(&g->color_column, "ColorColumn", FLAG_LUA,
    setup_hl_group(&g->quick_fix_line, "QuickFixLine", FLAG_LUA,
    setup_hl_group(&g->normal_nc, "NormalNC", FLAG_LUA,
    setup_hl_group(&g->normal_float, "NormalFloat", FLAG_LUA,
    setup_hl_group(&g->float_border, "FloatBorder", FLAG_LUA,
    setup_hl_group(&g->win_bar, "WinBar", FLAG_LUA,
    setup_hl_group(&g->win_bar_nc, "WinBarNC", FLAG_LUA,
    setup_hl_group(&g->cursor, "Cursor", FLAG_LUA,
    setup_hl_group(&g->redraw_debug_normal, "RedrawDebugNormal", FLAG_LUA,
    setup_hl_group(&g->underlined, "Underlined", FLAG_LUA,
    setup_hl_group(&g->l_cursor, "lCursor", FLAG_LUA,
#endif

    setup_hl_group(&g->diagnostic_error, "DiagnosticError", FLAG_LUA | FLAG_FG, col->c_text.error, nocolor, 0);
    setup_hl_group(&g->diagnostic_warn, "DiagnosticWarn", FLAG_LUA | FLAG_FG, col->c_text.warn, nocolor, 0);
    setup_hl_group(&g->diagnostic_info, "DiagnosticInfo", FLAG_LUA | FLAG_FG, col->c_text.info, nocolor, 0);
    setup_hl_group(&g->diagnostic_hint, "DiagnosticHint", FLAG_LUA | FLAG_FG, col->c_text.hint, nocolor, 0);
    setup_hl_group(&g->diagnostic_ok, "DiagnosticOk", FLAG_LUA | FLAG_FG, col->c_text.ok, nocolor, 0);
}

void setup_colors_nature_dark(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_NATURE_DARK];

    col->c_base = col_base_nature_dark;
    col->c_ui = col_ui_dark;
    col->c_text = col_text_dark;

    setup_hl_groups(col);
}

void setup_colors_nature_dark_dead(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_NATURE_DARK_DEAD];

    col->c_base = col_base_nature_dark_dead;
    col->c_ui = col_ui_light;
    col->c_text = col_text_light;

    setup_hl_groups(col);
}

void setup_colors_nature_light(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_NATURE_LIGHT];

    col->c_base = col_base_nature_light;
    col->c_ui = col_ui_dark;
    col->c_text = col_text_dark;

    setup_hl_groups(col);
}

void setup_colors_nature_light_dead(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_NATURE_LIGHT_DEAD];

    col->c_base = col_base_nature_light_dead;
    col->c_ui = col_ui_light;
    col->c_text = col_text_light;

    setup_hl_groups(col);
}

void setup_colors_cherry_dark(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_CHERRY_DARK];

    col->c_base = col_base_cherry_dark;
    col->c_ui = col_ui_dark;
    col->c_text = col_text_dark;

    setup_hl_groups(col);
}

void setup_colors_cherry_dark_dead(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_CHERRY_DARK_DEAD];

    col->c_base = col_base_cherry_dark_dead;
    col->c_ui = col_ui_light;
    col->c_text = col_text_light;

    setup_hl_groups(col);
}

void setup_colors_cherry_light(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_CHERRY_LIGHT];

    col->c_base = col_base_cherry_light;
    col->c_ui = col_ui_dark;
    col->c_text = col_text_dark;

    setup_hl_groups(col);
}

void setup_colors_cherry_light_dead(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_CHERRY_LIGHT_DEAD];

    col->c_base = col_base_cherry_light_dead;
    col->c_ui = col_ui_light;
    col->c_text = col_text_light;

    setup_hl_groups(col);
}

void setup_colors_oceans_dark(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_OCEANS_DARK];

    col->c_base = col_base_oceans_dark;
    col->c_ui = col_ui_dark;
    col->c_text = col_text_dark;

    setup_hl_groups(col);
}

void setup_colors_oceans_dark_dead(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_OCEANS_DARK_DEAD];

    col->c_base = col_base_oceans_dark_dead;
    col->c_ui = col_ui_light;
    col->c_text = col_text_light;

    setup_hl_groups(col);
}

void setup_colors_oceans_light(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_OCEANS_LIGHT];

    col->c_base = col_base_oceans_light;
    col->c_ui = col_ui_dark;
    col->c_text = col_text_dark;

    setup_hl_groups(col);
}

void setup_colors_oceans_light_dead(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_OCEANS_LIGHT_DEAD];

    col->c_base = col_base_oceans_light_dead;
    col->c_ui = col_ui_light;
    col->c_text = col_text_light;

    setup_hl_groups(col);
}
