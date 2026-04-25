#include "h/common.h"

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
    { 74,  77,  77},    /* dead */
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
    { 74,  77,  77},    /* dead */
    {178, 181, 180},    /* radioactive */
    {207, 237, 187},    /* highly_radioactive */
    {124, 131, 127},    /* blooming_radioactive */
};

static llp_col_base col_base_nature_light =
{
    { 49, 122,  47},    /* base */
    { 56, 136,  34},    /* loud */
    { 44,  82,  28},    /* bright */
    {192, 215, 190},    /* visual */
    {111, 146,  99},    /* habitable */
    {100,  96,  30},    /* dry0 */
    {118, 127,  76},    /* dry1 */
    {100, 117, 101},    /* thirsty */
    { 90, 128,  44},    /* mossy */
    {151, 157, 157},    /* dead */
    {139, 182, 121},    /* radioactive */
    { 41, 104,   0},    /* highly_radioactive */
    { 32,  82,   0}     /* blooming_radioactive */
};

static llp_col_base col_base_nature_light_dead =
{
    { 83,  86,  83},    /* base */
    { 84,  87,  83},    /* loud */
    { 55,  56,  54},    /* bright */
    {202, 203, 202},    /* visual */
    {122, 123, 122},    /* habitable */
    { 66,  66,  64},    /* dry0 */
    {102, 102, 101},    /* dry1 */
    {108, 109, 108},    /* thirsty */
    { 86,  87,  85},    /* mossy */
    {151, 157, 157},    /* dead */
    {178, 181, 180},    /* radioactive */
    { 11,  29,   0},    /* highly_radioactive */
    { 15,  16,  16}     /* blooming_radioactive */
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
    {230, 230, 230},    /* base */
    {235, 235, 235},    /* line_nu */
    {250, 250, 250},    /* status_line */
};

static llp_col_text col_text_dark =
{
    {188, 188, 188},    /* base */
    {236, 236, 236},    /* base_alt */
    {188, 188, 188},    /* light */
    {236, 236, 236},    /* light_alt */
    {127, 136, 141},    /* line_nu */
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
    { 90,  90,  90},    /* base */
    {117, 117, 117},    /* base_alt */
    {188, 188, 188},    /* light */
    {236, 236, 236},    /* light_alt */
    {120, 128, 133},    /* line_nu */
    { 14, 144, 148},    /* link */

    {204,  41,  53},    /* error */
    {151,  73,  45},    /* error_alt */
    {204,  88,  41},    /* warn */
    { 61, 156, 159},    /* info */
    {153, 181, 152},    /* hint */
    { 82, 167,  47},    /* ok */

    { 79, 127,  63},    /* diff_add_fg */
    {127, 127, 127},    /* diff_change_fg */
    {127,  66,  63},    /* diff_delete_fg */
    { 63, 127, 123},    /* diff_text_fg */
    {174, 204, 164},    /* diff_add_bg */
    {204, 204, 204},    /* diff_change_bg */
    {204, 166, 164},    /* diff_delete_bg */
    {164, 204, 201}     /* diff_text_bg */
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

    setup_hl_group(&g->special_key, "SpecialKey", FLAG_ON | FLAG_FG, col->c_base.blooming_radioactive, nocolor, 0);
    setup_hl_group(&g->term_cursor, "TermCursor", FLAG_ON | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_REVERSE);
    setup_hl_group(&g->non_text, "NonText", FLAG_ON | FLAG_FG, col->c_base.radioactive, nocolor, 0);
    setup_hl_group(&g->directory, "Directory", FLAG_ON | FLAG_FG, col->c_base.highly_radioactive, nocolor, 0);
    setup_hl_group(&g->error_msg, "ErrorMsg", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.light_alt, col->c_text.error_alt, 0);
    setup_hl_group(&g->ignore, "Ignore", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->search, "Search", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.base, col->c_ui.status_line, 0);
    setup_hl_group(&g->cur_search, "CurSearch", FLAG_ON | FLAG_FG | FLAG_BG, col->c_base.highly_radioactive, col->c_ui.status_line, 0);
    setup_hl_group(&g->inc_search, "IncSearch", FLAG_ON | FLAG_FG | FLAG_BG, col->c_base.highly_radioactive, col->c_ui.status_line, 0);
    setup_hl_group(&g->more_msg, "MoreMsg", FLAG_ON | FLAG_FG | FLAG_SP, col->c_base.bright, nocolor, HL_GROUP_SP_BOLD);
    setup_hl_group(&g->mode_msg, "ModeMsg", FLAG_ON | FLAG_FG | FLAG_SP, col->c_base.highly_radioactive, nocolor, HL_GROUP_SP_BOLD);
    setup_hl_group(&g->line_nr, "LineNr", FLAG_ON | FLAG_FG | FLAG_BG | FLAG_SP, col->c_text.line_nu, col->c_ui.line_nu, 0);
    setup_hl_group(&g->line_nr_above, "LineNrAbove", FLAG_ON | FLAG_FG | FLAG_BG, col->c_base.dead, col->c_ui.line_nu, 0);
    setup_hl_group(&g->line_nr_below, "LineNrBelow", FLAG_ON | FLAG_FG | FLAG_BG, col->c_base.dead, col->c_ui.line_nu, 0);
    setup_hl_group(&g->cursor_line_nr, "CursorLineNr", FLAG_ON | FLAG_FG | FLAG_BG | FLAG_SP, col->c_text.line_nu, col->c_ui.line_nu, 0);
    setup_hl_group(&g->question, "Question", FLAG_ON | FLAG_FG, col->c_text.link, nocolor, 0);
    setup_hl_group(&g->status_line, "StatusLine", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.base, col->c_ui.status_line, 0);
    setup_hl_group(&g->status_line_nc, "StatusLineNC", FLAG_ON | FLAG_FG | FLAG_BG, txt_nc(col->c_text.base), col_nc(col->c_ui.status_line), 0);
    setup_hl_group(&g->status_line_term, "StatusLineTerm", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.base, col->c_ui.status_line, 0);
    setup_hl_group(&g->status_line_term_nc, "StatusLineTermNC", FLAG_ON | FLAG_FG | FLAG_BG, txt_nc(col->c_text.base), col_nc(col->c_ui.status_line), 0);

    setup_hl_group(&g->win_separator, "WinSeparator", FLAG_ON | FLAG_FG, col->c_ui.base, nocolor, 0);
    setup_hl_group(&g->vert_split, "VertSplit", FLAG_ON | FLAG_FG, col->c_ui.base, nocolor, 0);
    setup_hl_group(&g->title, "Title", FLAG_ON | FLAG_FG, col->c_base.highly_radioactive, nocolor, 0);
    setup_hl_group(&g->toolbar_button, "ToolbarButton", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.base, col_nc(col->c_ui.status_line), 0);
    setup_hl_group(&g->toolbar_line, "ToolbarLine", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.base_alt, col->c_ui.status_line, 0);
    setup_hl_group(&g->visual, "Visual", FLAG_ON | FLAG_FG | FLAG_BG, col->c_base.highly_radioactive, col->c_base.visual, 0);
    setup_hl_group(&g->visual_nos, "VisualNOS", FLAG_ON | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_BOLD);
    setup_hl_group(&g->warning_msg, "WarningMsg", FLAG_ON | FLAG_FG, col->c_text.warn, nocolor, 0);
    setup_hl_group(&g->wild_menu, "WildMenu", FLAG_ON | FLAG_FG, col->c_base.radioactive, col->c_ui.line_nu, 0);
    setup_hl_group(&g->fold_column, "FoldColumn", FLAG_ON | FLAG_FG, col->c_base.blooming_radioactive, nocolor, 0);
    setup_hl_group(&g->folded, "Folded", FLAG_ON | FLAG_FG, col->c_base.blooming_radioactive, nocolor, 0);
    setup_hl_group(&g->diff_add, "DiffAdd", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.diff_add_fg, col->c_text.diff_add_bg, 0);
    setup_hl_group(&g->diff_change, "DiffChange", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.diff_change_fg, col->c_text.diff_change_bg, 0);
    setup_hl_group(&g->diff_delete, "DiffDelete", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.diff_delete_fg, col->c_text.diff_delete_bg, 0);
    setup_hl_group(&g->diff_text, "DiffText", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.diff_text_fg, col->c_text.diff_text_bg, 0);
    setup_hl_group(&g->sign_column, "SignColumn", FLAG_ON | FLAG_FG | FLAG_BG | FLAG_SP, col->c_base.highly_radioactive, col->c_ui.line_nu, HL_GROUP_SP_BOLD);
    setup_hl_group(&g->conceal, "Conceal", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->spell_bad, "SpellBad", FLAG_ON | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERCURL);
    setup_hl_group(&g->spell_cap, "SpellCap", FLAG_ON | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERCURL);
    setup_hl_group(&g->spell_rare, "SpellRare", FLAG_ON | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERCURL);
    setup_hl_group(&g->spell_local, "SpellLocal", FLAG_ON | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERCURL);
    setup_hl_group(&g->pmenu, "Pmenu", FLAG_ON | FLAG_FG | FLAG_BG, txt_nc(col->c_text.base), col_nc(col->c_ui.status_line), 0);
    setup_hl_group(&g->pmenu_sel, "PmenuSel", FLAG_ON | FLAG_FG | FLAG_BG, txt_nc(col->c_text.base), col->c_ui.status_line, 0);
    setup_hl_group(&g->pmenu_match, "PmenuMatch", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->pmenu_match_sel, "PmenuMatchSel", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->pmenu_sbar, "PmenuSbar", FLAG_ON | FLAG_FG | FLAG_BG, txt_nc(col->c_text.base), col_nc(col->c_ui.status_line), 0);
    setup_hl_group(&g->pmenu_thumb, "PmenuThumb", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.base, col->c_ui.status_line, 0);
    setup_hl_group(&g->tab_line, "TabLine", FLAG_ON | FLAG_FG | FLAG_BG, txt_nc(col->c_text.base), col_nc(col->c_ui.base), 0);
    setup_hl_group(&g->tab_line_sel, "TabLineSel", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.base, col->c_ui.base, 0);
    setup_hl_group(&g->tab_line_fill, "TabLineFill", FLAG_ON | FLAG_BG, nocolor, col_nc(col->c_ui.base), 0);
    setup_hl_group(&g->cursor_column, "CursorColumn", FLAG_ON | FLAG_BG, nocolor, col->c_ui.line_nu, 0);
    setup_hl_group(&g->cursor_line, "CursorLine", FLAG_ON | FLAG_BG, nocolor, col->c_ui.line_nu, 0);
    setup_hl_group(&g->color_column, "ColorColumn", FLAG_ON | FLAG_BG, nocolor, col_nc(col->c_ui.base), 0);
    setup_hl_group(&g->quick_fix_line, "QuickFixLine", FLAG_ON | FLAG_FG, col->c_text.link, nocolor, 0);
    setup_hl_group(&g->normal_nc, "NormalNC", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.base, col_ncl(col->c_ui.base), 0);
    setup_hl_group(&g->normal_float, "NormalFloat", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->float_border, "FloatBorder", FLAG_ON | FLAG_FG, txt_nc(col->c_ui.base), nocolor, 0);
    setup_hl_group(&g->win_bar, "WinBar", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->win_bar_nc, "WinBarNC", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->cursor, "Cursor", FLAG_ON | FLAG_BG | FLAG_SP, nocolor, col_nc(col->c_ui.status_line), HL_GROUP_SP_REVERSE);
    setup_hl_group(&g->redraw_debug_normal, "RedrawDebugNormal", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->underlined, "Underlined", FLAG_ON | FLAG_FG | FLAG_SP, col->c_base.highly_radioactive, nocolor, HL_GROUP_SP_UNDERLINE);
    setup_hl_group(&g->l_cursor, "lCursor", 0, nocolor, nocolor, 0);

    setup_hl_group(&g->normal, "Normal", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.base, col->c_ui.base, 0);
    setup_hl_group(&g->character, "Character", FLAG_ON | FLAG_FG, col->c_base.habitable, nocolor, 0);
    setup_hl_group(&g->constant, "Constant", FLAG_ON | FLAG_FG, col->c_base.mossy, nocolor, 0);
    setup_hl_group(&g->number, "Number", FLAG_ON | FLAG_FG, col->c_base.highly_radioactive, nocolor, 0);
    setup_hl_group(&g->boolean, "Boolean", FLAG_ON | FLAG_FG, col->c_text.base, nocolor, 0);
    setup_hl_group(&g->conditional, "Conditional", FLAG_ON | FLAG_FG, col->c_base.dry1, nocolor, 0);
    setup_hl_group(&g->statement, "Statement", FLAG_ON | FLAG_FG, col->c_base.base, nocolor, 0);
    setup_hl_group(&g->include, "Include", FLAG_ON | FLAG_FG, col->c_base.loud, nocolor, 0);
    setup_hl_group(&g->pre_proc, "PreProc", FLAG_ON | FLAG_FG, col->c_base.loud, nocolor, 0);
    setup_hl_group(&g->define, "Define", FLAG_ON | FLAG_FG, col->c_base.bright, nocolor, 0);
    setup_hl_group(&g->macro, "Macro", FLAG_ON | FLAG_FG, col->c_base.bright, nocolor, 0);
    setup_hl_group(&g->type, "Type", FLAG_ON | FLAG_FG, txt_nc(col->c_text.base), nocolor, 0);
    setup_hl_group(&g->special, "Special", FLAG_ON | FLAG_FG, col->c_text.line_nu, nocolor, 0);
    setup_hl_group(&g->diagnostic_error, "DiagnosticError", FLAG_ON | FLAG_FG, col->c_text.error, nocolor, 0);
    setup_hl_group(&g->diagnostic_warn, "DiagnosticWarn", FLAG_ON | FLAG_FG, col->c_text.warn, nocolor, 0);
    setup_hl_group(&g->diagnostic_info, "DiagnosticInfo", FLAG_ON | FLAG_FG, col->c_text.info, nocolor, 0);
    setup_hl_group(&g->diagnostic_hint, "DiagnosticHint", FLAG_ON | FLAG_FG, col->c_text.hint, nocolor, 0);
    setup_hl_group(&g->diagnostic_ok, "DiagnosticOk", FLAG_ON | FLAG_FG, col->c_text.ok, nocolor, 0);
    setup_hl_group(&g->comment, "Comment", FLAG_ON | FLAG_FG, col->c_base.dead, nocolor, 0);
    setup_hl_group(&g->string, "String", FLAG_ON | FLAG_FG, col->c_base.habitable, nocolor, 0);
    setup_hl_group(&g->identifier, "Identifier", FLAG_ON | FLAG_FG, col->c_base.thirsty, nocolor, 0);
    setup_hl_group(&g->function, "Function", FLAG_ON | FLAG_FG, col->c_text.base, nocolor, 0);
    setup_hl_group(&g->operator, "Operator", FLAG_ON | FLAG_FG, col->c_text.base_alt, nocolor, 0);
    setup_hl_group(&g->delimiter, "Delimiter", FLAG_ON | FLAG_FG, txt_nc(col->c_text.base), nocolor, 0);
    setup_hl_group(&g->todo, "Todo", FLAG_ON | FLAG_FG | FLAG_BG, col->c_base.highly_radioactive, col->c_base.visual, 0);
    setup_hl_group(&g->added, "Added", FLAG_ON | FLAG_FG, col->c_text.diff_add_fg, col->c_base.visual, 0);
    setup_hl_group(&g->removed, "Removed", FLAG_ON | FLAG_FG, col->c_text.diff_delete_fg, nocolor, 0);
    setup_hl_group(&g->changed, "Changed", FLAG_ON | FLAG_FG, col->c_text.diff_text_fg, nocolor, 0);
    setup_hl_group(&g->diagnostic_deprecated, "DiagnosticDeprecated", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->float_shadow, "FloatShadow", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->float_shadow_through, "FloatShadowThrough", 0, nocolor, nocolor, 0);
    setup_hl_group(&g->match_paren, "MatchParen", FLAG_ON | FLAG_BG, nocolor, col->c_ui.status_line, 0);
    setup_hl_group(&g->redraw_debug_clear, "RedrawDebugClear", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.light, col->c_base.dry0, 0);
    setup_hl_group(&g->redraw_debug_composed, "RedrawDebugComposed", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.light, col->c_base.mossy, 0);
    setup_hl_group(&g->redraw_debug_recompose, "RedrawDebugRecompose", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.light, col->c_text.error_alt, 0);
    setup_hl_group(&g->error, "Error", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.light, col->c_text.error_alt, 0);
    setup_hl_group(&g->diagnostic_underline_error, "DiagnosticUnderlineError", FLAG_ON | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERLINE);
    setup_hl_group(&g->diagnostic_underline_warn, "DiagnosticUnderlineWarn", FLAG_ON | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERLINE);
    setup_hl_group(&g->diagnostic_underline_info, "DiagnosticUnderlineInfo", FLAG_ON | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERLINE);
    setup_hl_group(&g->diagnostic_underline_hint, "DiagnosticUnderlineHint", FLAG_ON | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERLINE);
    setup_hl_group(&g->diagnostic_underline_ok, "DiagnosticUnderlineOk", FLAG_ON | FLAG_SP, nocolor, nocolor, HL_GROUP_SP_UNDERLINE);
    setup_hl_group(&g->nvim_internal_error, "NvimInternalError", FLAG_ON | FLAG_FG | FLAG_BG, col->c_text.light, col->c_text.error_alt, 0);
    setup_hl_group(&g->nvim_spacing, "NvimSpacing", FLAG_ON | FLAG_FG, txt_nc(col->c_ui.base), nocolor, 0);
    setup_hl_group(&g->cmp_item_abbr_default, "CmpItemAbbrDefault", FLAG_ON | FLAG_FG, col->c_text.info, nocolor, 0);
    setup_hl_group(&g->vim_user_func, "VimUserFunc", FLAG_ON | FLAG_FG, col->c_text.base, nocolor, 0);
    setup_hl_group(&g->vim_embed_error, "VimEmbedError", FLAG_ON | FLAG_FG, col->c_text.base, nocolor, 0);
    setup_hl_group(&g->cmp_item_abbr_deprecated_default, "CmpItemAbbrDeprecatedDefault", FLAG_ON | FLAG_FG, col->c_text.info, nocolor, 0);
    setup_hl_group(&g->cmp_item_abbr_match_default, "CmpItemAbbrMatchDefault", FLAG_ON | FLAG_FG, col->c_text.info, nocolor, 0);
    setup_hl_group(&g->cmp_item_abbr_match_fuzzy_default, "CmpItemAbbrMatchFuzzyDefault", FLAG_ON | FLAG_FG, col->c_text.info, nocolor, 0);
    setup_hl_group(&g->cmp_item_kind_default, "CmpItemKindDefault", FLAG_ON | FLAG_FG, col->c_text.info, nocolor, 0);
    setup_hl_group(&g->cmp_item_menu_default, "CmpItemMenuDefault", FLAG_ON | FLAG_FG, col->c_text.info, nocolor, 0);
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
