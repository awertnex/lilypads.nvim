#include "h/common.h"
#include "h/config.h"

#include <stdio.h>

/* ---- section: declarations ----------------------------------------------- */

static llp_col nocolor = {0};

static llp_col_base col_base_nature_dark =
{
    { 52, 128,  49},    /* base */
    { 61, 143,  36},    /* loud */
    { 98, 179,  72},    /* bright */
    { 44,  82,  28},    /* visual */
    {151, 185, 148},    /* habitable */
    {128, 122,  38},    /* dry0 */
    {142, 153,  92},    /* dry1 */
    {175, 204, 177},    /* thirsty */
    { 90, 128,  44},    /* mossy */
    {162, 222, 137},    /* radioactive */
    {164, 237, 116},    /* highly_radioactive */
    {101, 255,   0}     /* blooming_radioactive */
};

static llp_col_base col_base_nature_dark_dead =
{
    { 87,  90,  89},    /* base */
    { 88,  91,  90},    /* loud */
    {124, 127, 126},    /* bright */
    { 54,  56,  55},    /* visual */
    {166, 167, 167},    /* habitable */
    { 82,  84,  82},    /* dry0 */
    {122, 123, 122},    /* dry1 */
    {189, 190, 190},    /* thirsty */
    { 85,  87,  86},    /* mossy */
    {178, 181, 180},    /* radioactive */
    {207, 237, 187},    /* highly_radioactive */
    {124, 131, 127},    /* blooming_radioactive */
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
    { 36,  36,  36},    /* line_nu */
    { 64,  64,  64},    /* status_line */
};

static llp_col_ui col_ui_light =
{
    {224, 224, 224},    /* base */
    {219, 219, 219},    /* line_nu */
    {191, 191, 191},    /* status_line */
};

static llp_col_text col_text_dark =
{
    {188, 188, 188},    /* base */
    {236, 236, 236},    /* base_alt */
    {127, 136, 141},    /* line_nu */
    { 74,  77,  77},    /* comment */
    {136, 242, 235},    /* link */

    {204,  41,  53},    /* error */
    {128,  62,  38},    /* error_alt */
    {204,  88,  41},    /* warn */
    {122, 202, 204},    /* info */
    {208, 230, 207},    /* hint */
    {162, 222, 137},    /* ok */

    {174, 204, 164},    /* diff_add_fg */
    {204, 204, 204},    /* diff_change_fg */
    {204, 166, 164},    /* diff_delete_fg */
    {164, 204, 201},    /* diff_text_fg */
    { 79, 127,  63},    /* diff_add_bg */
    {127, 127, 127},    /* diff_change_bg */
    {127,  66,  63},    /* diff_delete_bg */
    { 63, 127, 123}     /* diff_text_bg */
};

static llp_col_text col_text_light =
{
    {188, 188, 188},    /* base */      /* (TODO: adjust color for light mode) */
    {236, 236, 236},    /* base_alt */  /* (TODO: adjust color for light mode) */
    {127, 136, 141},    /* line_nu */   /* (TODO: adjust color for light mode) */
    { 74,  77,  77},    /* comment */   /* (TODO: adjust color for light mode) */
    {136, 242, 235},    /* link */      /* (TODO: adjust color for light mode) */

    {204,  41,  53},    /* error */
    {128,  62,  38},    /* error_alt */
    {204,  88,  41},    /* warn */
    {122, 202, 204},    /* info */      /* (TODO: adjust color for light mode) */
    {208, 230, 207},    /* hint */      /* (TODO: adjust color for light mode) */
    {162, 222, 137},    /* ok */        /* (TODO: adjust color for light mode) */

    {174, 204, 164},    /* diff_add_fg */
    {204, 204, 204},    /* diff_change_fg */
    {204, 166, 164},    /* diff_delete_fg */
    {164, 204, 201},    /* diff_text_fg */
    { 79, 127,  63},    /* diff_add_bg */
    {127, 127, 127},    /* diff_change_bg */
    {127,  66,  63},    /* diff_delete_bg */
    { 63, 127, 123}     /* diff_text_bg */
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
    setup_hl_group(&g->error_msg, "ErrorMsg", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.base_alt, col->c_text.error_alt, 0);
    setup_hl_group(&g->search, "Search", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.base, col->c_ui.status_line, 0);
    setup_hl_group(&g->cur_search, "CurSearch", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_base.highly_radioactive, col->c_ui.status_line, 0);
    setup_hl_group(&g->more_msg, "MoreMsg", FLAG_LUA | FLAG_FG | FLAG_SP, col->c_base.bright, nocolor, HL_GROUP_SP_BOLD);
    setup_hl_group(&g->mode_msg, "ModeMsg", FLAG_LUA | FLAG_FG | FLAG_SP, col->c_base.highly_radioactive, nocolor, HL_GROUP_SP_BOLD);
    setup_hl_group(&g->line_nr, "LineNr", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.line_nu, col->c_ui.line_nu, 0);
    setup_hl_group(&g->line_nr_above, "LineNrAbove", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.comment, col->c_ui.line_nu, 0);
    setup_hl_group(&g->line_nr_below, "LineNrBelow", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.comment, col->c_ui.line_nu, 0);
    setup_hl_group(&g->cursor_line_nr, "CursorLineNr", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.line_nu, col->c_ui.line_nu, 0);
    setup_hl_group(&g->question, "Question", FLAG_LUA | FLAG_FG, col->c_text.link, nocolor, 0);
    setup_hl_group(&g->status_line, "StatusLine", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.base, col->c_ui.status_line, 0);
    setup_hl_group(&g->status_line_nc, "StatusLineNC", FLAG_LUA | FLAG_FG | FLAG_BG, txt_nc(col->c_text.base), col_nc(col->c_ui.status_line), 0);

    setup_hl_group(&g->win_separator, "WinSeparator", FLAG_LUA | FLAG_FG, col->c_ui.base, nocolor, 0);
    setup_hl_group(&g->vert_split, "VertSplit", FLAG_LUA | FLAG_FG, col->c_ui.base, nocolor, 0);
    setup_hl_group(&g->title, "Title", FLAG_LUA | FLAG_FG, col->c_base.highly_radioactive, nocolor, 0);
    setup_hl_group(&g->visual, "Visual", FLAG_LUA | FLAG_VIM | FLAG_FG | FLAG_BG, col->c_base.highly_radioactive, col->c_base.visual, 0);
    setup_hl_group(&g->warning_msg, "WarningMsg", FLAG_LUA | FLAG_FG, col->c_text.warn, nocolor, 0);
    setup_hl_group(&g->folded, "Folded", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->diff_add, "DiffAdd", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.diff_add_fg, col->c_text.diff_add_bg, 0);
    setup_hl_group(&g->diff_change, "DiffChange", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.diff_change_fg, col->c_text.diff_change_bg, 0);
    setup_hl_group(&g->diff_delete, "DiffDelete", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.diff_delete_fg, col->c_text.diff_delete_bg, 0);
    setup_hl_group(&g->diff_text, "DiffText", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.diff_text_fg, col->c_text.diff_text_bg, 0);
    setup_hl_group(&g->sign_column, "SignColumn", FLAG_LUA | FLAG_FG | FLAG_BG | FLAG_SP, col->c_base.highly_radioactive, col->c_ui.line_nu, HL_GROUP_SP_BOLD);
    setup_hl_group(&g->conceal, "Conceal", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->spell_bad, "SpellBad", FLAG_LUA | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERCURL);
    setup_hl_group(&g->spell_cap, "SpellCap", FLAG_LUA | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERCURL);
    setup_hl_group(&g->spell_rare, "SpellRare", FLAG_LUA | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERCURL);
    setup_hl_group(&g->spell_local, "SpellLocal", FLAG_LUA | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERCURL);
    setup_hl_group(&g->pmenu, "Pmenu", FLAG_LUA | FLAG_FG | FLAG_BG, txt_nc(col->c_text.base), col_nc(col->c_ui.status_line), 0);
    setup_hl_group(&g->pmenu_sel, "PmenuSel", FLAG_LUA | FLAG_FG | FLAG_BG, txt_nc(col->c_text.base), col->c_ui.status_line, 0);
    setup_hl_group(&g->pmenu_match, "PmenuMatch", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->pmenu_match_sel, "PmenuMatchSel", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->pmenu_sbar, "PmenuSbar", FLAG_LUA | FLAG_FG | FLAG_BG, txt_nc(col->c_text.base), col_nc(col->c_ui.status_line), 0);
    setup_hl_group(&g->pmenu_thumb, "PmenuThumb", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.base, col->c_ui.status_line, 0);
    setup_hl_group(&g->tab_line, "TabLine", FLAG_LUA | FLAG_FG | FLAG_BG, txt_nc(col->c_text.base), col_nc(col->c_ui.base), 0);
    setup_hl_group(&g->tab_line_sel, "TabLineSel", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.base, col->c_ui.base, 0);
    setup_hl_group(&g->tab_line_fill, "TabLineFill", FLAG_LUA | FLAG_BG, nocolor, col_nc(col->c_ui.base), 0);
    setup_hl_group(&g->cursor_column, "CursorColumn", FLAG_LUA | FLAG_BG, nocolor, col->c_ui.line_nu, 0);
    setup_hl_group(&g->cursor_line, "CursorLine", FLAG_LUA | FLAG_BG, nocolor, col->c_ui.line_nu, 0);
    setup_hl_group(&g->color_column, "ColorColumn", FLAG_LUA | FLAG_BG, nocolor, col_nc(col->c_ui.base), 0);
    setup_hl_group(&g->quick_fix_line, "QuickFixLine", FLAG_LUA | FLAG_FG, col->c_text.link, nocolor, 0);
    setup_hl_group(&g->normal_nc, "NormalNC", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.base, col_ncl(col->c_ui.base), 0);
    setup_hl_group(&g->normal_float, "NormalFloat", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->float_border, "FloatBorder", FLAG_LUA | FLAG_FG, txt_nc(col->c_ui.base), nocolor, 0);
    setup_hl_group(&g->win_bar, "WinBar", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->win_bar_nc, "WinBarNC", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->cursor, "Cursor", FLAG_LUA | FLAG_BG, nocolor, col_nc(col->c_ui.status_line), 0);
    setup_hl_group(&g->redraw_debug_normal, "RedrawDebugNormal", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->underlined, "Underlined", FLAG_LUA | FLAG_FG | FLAG_SP, col->c_base.highly_radioactive, nocolor, HL_GROUP_SP_UNDERLINE);
    setup_hl_group(&g->l_cursor, "lCursor", 0, nocolor, nocolor, 0);

    setup_hl_group(&g->normal, "Normal", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.base, col->c_ui.base, 0);
    setup_hl_group(&g->character, "Character", FLAG_LUA | FLAG_FG, col->c_base.habitable, nocolor, 0);
    setup_hl_group(&g->constant, "Constant", FLAG_LUA | FLAG_FG, col->c_base.mossy, nocolor, 0);
    setup_hl_group(&g->number, "Number", FLAG_LUA | FLAG_FG, col->c_base.highly_radioactive, nocolor, 0);
    setup_hl_group(&g->boolean, "Boolean", FLAG_LUA | FLAG_FG, col->c_text.base, nocolor, 0);
    setup_hl_group(&g->conditional, "Conditional", FLAG_LUA | FLAG_FG, col->c_base.dry1, nocolor, 0);
    setup_hl_group(&g->statement, "Statement", FLAG_LUA | FLAG_FG, col->c_base.base, nocolor, 0);
    setup_hl_group(&g->include, "Include", FLAG_LUA | FLAG_FG, col->c_base.loud, nocolor, 0);
    setup_hl_group(&g->pre_proc, "PreProc", FLAG_LUA | FLAG_FG, col->c_base.loud, nocolor, 0);
    setup_hl_group(&g->define, "Define", FLAG_LUA | FLAG_FG, col->c_base.bright, nocolor, 0);
    setup_hl_group(&g->macro, "Macro", FLAG_LUA | FLAG_FG, col->c_base.bright, nocolor, 0);
    setup_hl_group(&g->type, "Type", FLAG_LUA | FLAG_FG, txt_nc(col->c_text.base), nocolor, 0);
    setup_hl_group(&g->special, "Special", FLAG_LUA | FLAG_FG, col->c_text.line_nu, nocolor, 0);
    setup_hl_group(&g->diagnostic_error, "DiagnosticError", FLAG_LUA | FLAG_FG, col->c_text.error, nocolor, 0);
    setup_hl_group(&g->diagnostic_warn, "DiagnosticWarn", FLAG_LUA | FLAG_FG, col->c_text.warn, nocolor, 0);
    setup_hl_group(&g->diagnostic_info, "DiagnosticInfo", FLAG_LUA | FLAG_FG, col->c_text.info, nocolor, 0);
    setup_hl_group(&g->diagnostic_hint, "DiagnosticHint", FLAG_LUA | FLAG_FG, col->c_text.hint, nocolor, 0);
    setup_hl_group(&g->diagnostic_ok, "DiagnosticOk", FLAG_LUA | FLAG_FG, col->c_text.ok, nocolor, 0);
    setup_hl_group(&g->comment, "Comment", FLAG_LUA | FLAG_FG, col->c_text.comment, nocolor, 0);
    setup_hl_group(&g->string, "String", FLAG_LUA | FLAG_FG, col->c_base.habitable, nocolor, 0);
    setup_hl_group(&g->identifier, "Identifier", FLAG_LUA | FLAG_FG, col->c_base.thirsty, nocolor, 0);
    setup_hl_group(&g->function, "Function", FLAG_LUA | FLAG_FG, col->c_text.base, nocolor, 0);
    setup_hl_group(&g->operator, "Operator", FLAG_LUA | FLAG_FG, col->c_text.base_alt, nocolor, 0);
    setup_hl_group(&g->delimiter, "Delimiter", FLAG_LUA | FLAG_FG, txt_nc(col->c_text.base), nocolor, 0);
    setup_hl_group(&g->todo, "Todo", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_base.highly_radioactive, col->c_base.visual, 0);
    setup_hl_group(&g->added, "Added", FLAG_LUA | FLAG_FG, col->c_text.diff_add_fg, col->c_base.visual, 0);
    setup_hl_group(&g->removed, "Removed", FLAG_LUA | FLAG_FG, col->c_text.diff_delete_fg, nocolor, 0);
    setup_hl_group(&g->changed, "Changed", FLAG_LUA | FLAG_FG, col->c_text.diff_text_fg, nocolor, 0);
    setup_hl_group(&g->diagnostic_deprecated, "DiagnosticDeprecated", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->float_shadow, "FloatShadow", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->float_shadow_through, "FloatShadowThrough", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->match_paren, "MatchParen", FLAG_LUA | FLAG_BG, nocolor, col->c_ui.status_line, 0);
    setup_hl_group(&g->redraw_debug_clear, "RedrawDebugClear", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.base, col->c_base.dry0, 0);
    setup_hl_group(&g->redraw_debug_composed, "RedrawDebugComposed", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.base, col->c_base.mossy, 0);
    setup_hl_group(&g->redraw_debug_recompose, "RedrawDebugRecompose", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.base, col->c_text.error_alt, 0);
    setup_hl_group(&g->error, "Error", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.base, col->c_text.error_alt, 0);
    setup_hl_group(&g->diagnostic_underline_error, "DiagnosticUnderlineError", FLAG_LUA | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERLINE);
    setup_hl_group(&g->diagnostic_underline_warn, "DiagnosticUnderlineWarn", FLAG_LUA | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERLINE);
    setup_hl_group(&g->diagnostic_underline_info, "DiagnosticUnderlineInfo", FLAG_LUA | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERLINE);
    setup_hl_group(&g->diagnostic_underline_hint, "DiagnosticUnderlineHint", FLAG_LUA | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERLINE);
    setup_hl_group(&g->diagnostic_underline_ok, "DiagnosticUnderlineOk", FLAG_LUA | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERLINE);
    setup_hl_group(&g->nvim_internal_error, "NvimInternalError", FLAG_LUA | FLAG_FG | FLAG_BG, col->c_text.base, col->c_text.error_alt, 0);
    setup_hl_group(&g->nvim_spacing, "NvimSpacing", FLAG_LUA | FLAG_FG, txt_nc(col->c_ui.base), nocolor, 0);
    setup_hl_group(&g->cmp_item_abbr_default, "CmpItemAbbrDefault", FLAG_LUA | FLAG_FG, col->c_text.info, nocolor, 0);
    setup_hl_group(&g->vim_user_func, "VimUserFunc", FLAG_LUA | FLAG_FG, txt_nc(col->c_ui.base), nocolor, 0);
    setup_hl_group(&g->vim_embed_error, "VimEmbedError", FLAG_LUA | FLAG_FG, txt_nc(col->c_ui.base), nocolor, 0);
    setup_hl_group(&g->cmp_item_abbr_deprecated_default, "CmpItemAbbrDeprecatedDefault", FLAG_LUA | FLAG_FG, col->c_text.info, nocolor, 0);
    setup_hl_group(&g->cmp_item_abbr_match_default, "CmpItemAbbrMatchDefault", FLAG_LUA | FLAG_FG, col->c_text.info, nocolor, 0);
    setup_hl_group(&g->cmp_item_abbr_match_fuzzy_default, "CmpItemAbbrMatchFuzzyDefault", FLAG_LUA | FLAG_FG, col->c_text.info, nocolor, 0);
    setup_hl_group(&g->cmp_item_kind_default, "CmpItemKindDefault", FLAG_LUA | FLAG_FG, col->c_text.info, nocolor, 0);
    setup_hl_group(&g->cmp_item_menu_default, "CmpItemMenuDefault", FLAG_LUA | FLAG_FG, col->c_text.info, nocolor, 0);
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
    col->c_ui = col_ui_dark;
    col->c_text = col_text_dark;

    setup_hl_groups(col);
}

void setup_colors_nature_light(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_NATURE_LIGHT];

    col->c_base = col_base_nature_light;
    col->c_ui = col_ui_light;
    col->c_text = col_text_light;

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
    col->c_ui = col_ui_dark;
    col->c_text = col_text_dark;

    setup_hl_groups(col);
}

void setup_colors_cherry_light(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_CHERRY_LIGHT];

    col->c_base = col_base_cherry_light;
    col->c_ui = col_ui_light;
    col->c_text = col_text_light;

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
    col->c_ui = col_ui_dark;
    col->c_text = col_text_dark;

    setup_hl_groups(col);
}

void setup_colors_oceans_light(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_OCEANS_LIGHT];

    col->c_base = col_base_oceans_light;
    col->c_ui = col_ui_light;
    col->c_text = col_text_light;

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
