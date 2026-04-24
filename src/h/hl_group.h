#ifndef LILYPADS_HL_GROUP_H
#define LILYPADS_HL_GROUP_H

#include "types.h"

#define HL_GROUP_NAME_MAX 64
#define HL_GROUP_PARAM_MAX 64

struct hl_group
{
    str name[HL_GROUP_NAME_MAX];
    u32 flags;  /* enum: llp_flag */
    u32 fg;     /* hex: foreground color */
    u32 bg;     /* hex: background color */
    u32 sp;     /* sp: special elements (e.g. underline) */
    u32 sp_col; /* hex: color of `sp` */
};
typedef struct hl_group llp_hl_group;

struct hl_groups
{
    llp_hl_group special_key;
    llp_hl_group term_cursor;
    llp_hl_group non_text;
    llp_hl_group directory;
    llp_hl_group error_msg;
    llp_hl_group search;
    llp_hl_group cur_search;
    llp_hl_group more_msg;
    llp_hl_group mode_msg;
    llp_hl_group line_nr;
    llp_hl_group line_nr_above;
    llp_hl_group line_nr_below;
    llp_hl_group cursor_line_nr;
    llp_hl_group question;
    llp_hl_group status_line;
    llp_hl_group status_line_nc;
    llp_hl_group win_separator;
    llp_hl_group vert_split;
    llp_hl_group title;
    llp_hl_group visual;
    llp_hl_group warning_msg;
    llp_hl_group folded;
    llp_hl_group diff_add;
    llp_hl_group diff_change;
    llp_hl_group diff_delete;
    llp_hl_group diff_text;
    llp_hl_group sign_column;
    llp_hl_group conceal;
    llp_hl_group spell_bad;
    llp_hl_group spell_cap;
    llp_hl_group spell_rare;
    llp_hl_group spell_local;
    llp_hl_group pmenu;
    llp_hl_group pmenu_sel;
    llp_hl_group pmenu_match;
    llp_hl_group pmenu_match_sel;
    llp_hl_group pmenu_sbar;
    llp_hl_group pmenu_thumb;
    llp_hl_group tab_line;
    llp_hl_group tab_line_sel;
    llp_hl_group tab_line_fill;
    llp_hl_group cursor_column;
    llp_hl_group cursor_line;
    llp_hl_group color_column;
    llp_hl_group quick_fix_line;
    llp_hl_group normal_nc;
    llp_hl_group normal_float;
    llp_hl_group float_border;
    llp_hl_group win_bar;
    llp_hl_group win_bar_nc;
    llp_hl_group cursor;
    llp_hl_group redraw_debug_normal;
    llp_hl_group underlined;
    llp_hl_group l_cursor;
    llp_hl_group normal;
    llp_hl_group character;
    llp_hl_group constant;
    llp_hl_group number;
    llp_hl_group boolean;
    llp_hl_group conditional;
    llp_hl_group statement;
    llp_hl_group include;
    llp_hl_group pre_proc;
    llp_hl_group define;
    llp_hl_group macro;
    llp_hl_group type;
    llp_hl_group special;
    llp_hl_group diagnostic_error;
    llp_hl_group diagnostic_warn;
    llp_hl_group diagnostic_info;
    llp_hl_group diagnostic_hint;
    llp_hl_group diagnostic_ok;
    llp_hl_group comment;
    llp_hl_group _variable;
    llp_hl_group string;
    llp_hl_group identifier;
    llp_hl_group function;
    llp_hl_group operator;
    llp_hl_group delimiter;
    llp_hl_group todo;
    llp_hl_group _markup_strong;
    llp_hl_group _markup_italic;
    llp_hl_group _markup_strikethrough;
    llp_hl_group _markup_underline;
    llp_hl_group added;
    llp_hl_group removed;
    llp_hl_group changed;
    llp_hl_group _markup_heading_1_delimiter_vimdoc;
    llp_hl_group _markup_heading_2_delimiter_vimdoc;
    llp_hl_group diagnostic_deprecated;
    llp_hl_group float_shadow;
    llp_hl_group float_shadow_through;
    llp_hl_group match_paren;
    llp_hl_group redraw_debug_clear;
    llp_hl_group redraw_debug_composed;
    llp_hl_group redraw_debug_recompose;
    llp_hl_group error;
    llp_hl_group diagnostic_underline_error;
    llp_hl_group diagnostic_underline_warn;
    llp_hl_group diagnostic_underline_info;
    llp_hl_group diagnostic_underline_hint;
    llp_hl_group diagnostic_underline_ok;
    llp_hl_group nvim_internal_error;
    llp_hl_group nvim_spacing;
    llp_hl_group cmp_item_abbr_default;
    llp_hl_group vim_user_func;
    llp_hl_group vim_embed_error;
    llp_hl_group cmp_item_abbr_deprecated_default;
    llp_hl_group cmp_item_abbr_match_default;
    llp_hl_group cmp_item_abbr_match_fuzzy_default;
    llp_hl_group cmp_item_kind_default;
    llp_hl_group cmp_item_menu_default;
};
typedef struct hl_groups llp_hl_groups;

enum hl_group_sp_index
{
    HL_GROUP_SP_NONE,
    HL_GROUP_SP_BOLD,
    HL_GROUP_SP_UNDERLINE,
    HL_GROUP_SP_UNDERCURL,
    HL_GROUP_SP_UNDERDOUBLE,
    HL_GROUP_SP_UNDERDOTTED,
    HL_GROUP_SP_UNDERDASHED,
    HL_GROUP_SP_STRIKETHROUGH,
    HL_GROUP_SP_REVERSE,
    HL_GROUP_SP_INVERSE,
    HL_GROUP_SP_ITALIC,
    HL_GROUP_SP_STANDOUT,
    HL_GROUP_SP_ALTFONT,
    HL_GROUP_SP_DIM,
    HL_GROUP_SP_BLINK,
    HL_GROUP_SP_CONCEAL,
    HL_GROUP_SP_OVERLINE,
    HL_GROUP_SP_NOCOMBINE,
    HL_GROUP_SP_COUNT
}; /* hl_group_sp_index */

/*! @remark declared and initialized in 'main.c'.
 */
extern str hl_group_sp_text[HL_GROUP_SP_COUNT][HL_GROUP_PARAM_MAX];

#endif /* LILYPADS_HL_GROUP_H */
