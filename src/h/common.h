#ifndef LILYPADS_COMMON_H
#define LILYPADS_COMMON_H

#define _GNU_SOURCE

#if defined(LLP_LUA)

#   define LLP_DIR_DST "lilypads/lua/colors/"
#   define LLP_EXT ".lua"
#   define LLP_VIM_CMD_OPEN "vim.cmd \""
#   define LLP_VIM_CMD_CLOSE "\""
#   define LLP_CMT "--"
#   define LLP_CMT_TAB1 "  "
#   define LLP_CMT_TAB2 "      "
#   define LLP_CODE_SETUP ""

#elif defined(LLP_VIM)

#   define LLP_DIR_DST "lilypads/vim/colors/"
#   define LLP_EXT ".vim"
#   define LLP_VIM_CMD_OPEN ""
#   define LLP_VIM_CMD_CLOSE ""
#   define LLP_CMT "\""
#   define LLP_CMT_TAB1 "   "
#   define LLP_CMT_TAB2 "       "

#endif /* LLP_SYNTAX */

#include "types.h"
#include "hl_group.h"

#include <stdio.h>

/* ---- section: definitions ------------------------------------------------ */

#define NAME_MAX 256

#ifdef STRING_MAX
#   undef STRING_MAX
#   define STRING_MAX 2048
#else
#   define STRING_MAX 2048
#endif /* STRING_MAX */

#define TEXT_WIDTH 80

#define LLP_PROJECT_REPOSITORY "https://github.com/awertnex/lilypads.git"
#define LLP_LICENSE_OWNER "Lily Awertnex"
#define LLP_LICENSE_YEAR 2026
#define LLP_NOTES \
    LLP_CMT_TAB1"NOTES:\n" \
    LLP_CMT_TAB2"hitest command: `source $VIMRUNTIME/syntax/hitest.vim`"

#define FUNC_PAINT "SetPaint"
#define FUNC_LINK "SetLink"
#define FUNC_CLEAR "SetClear"

enum llp_flag
{
    FLAG_ON = 0x01,
    FLAG_FG = 0x02,
    FLAG_BG = 0x04,
    FLAG_SP = 0x08
}; /* llp_flag */

struct col
{
    u8 r, g, b;
};
typedef struct col llp_col;

struct col_base
{
    llp_col base;
    llp_col loud;
    llp_col bright;
    llp_col visual;
    llp_col habitable;
    llp_col dry0;
    llp_col dry1;
    llp_col thirsty;
    llp_col mossy;
    llp_col dead;
    llp_col radioactive;
    llp_col highly_radioactive;
    llp_col blooming_radioactive;
};
typedef struct col_base llp_col_base;

struct col_ui
{
    llp_col base;
    llp_col line_nu;
    llp_col status_line;
};
typedef struct col_ui llp_col_ui;

struct col_text
{
    /* base syntax colors */
    llp_col base;
    llp_col base_alt;
    llp_col light;
    llp_col light_alt;
    llp_col line_nu;
    llp_col link;

    /* diagnostic colors */
    llp_col error;
    llp_col error_alt;
    llp_col warn;
    llp_col info;
    llp_col hint;
    llp_col ok;

    /* diff colors */
    llp_col diff_add_fg, diff_change_fg, diff_delete_fg, diff_text_fg;
    llp_col diff_add_bg, diff_change_bg, diff_delete_bg, diff_text_bg;
};
typedef struct col_text llp_col_text;

struct colorscheme
{
    /*! @brief colorscheme name, no file extension.
     */
    str name[NAME_MAX];

    /*! @brief function to fill in colors (functions found in 'common.c').
     */
    void (*setup_func)(void);

    llp_col_base c_base;
    llp_col_ui c_ui;
    llp_col_text c_text;
    llp_hl_groups groups;
};
typedef struct colorscheme llp_colorscheme;

enum llp_color_index
{
    LLP_COLOR_NATURE_DARK,
    LLP_COLOR_NATURE_DARK_DEAD,
    LLP_COLOR_NATURE_LIGHT,
    LLP_COLOR_NATURE_LIGHT_DEAD,
    LLP_COLOR_CHERRY_DARK,
    LLP_COLOR_CHERRY_DARK_DEAD,
    LLP_COLOR_CHERRY_LIGHT,
    LLP_COLOR_CHERRY_LIGHT_DEAD,
    LLP_COLOR_OCEANS_DARK,
    LLP_COLOR_OCEANS_DARK_DEAD,
    LLP_COLOR_OCEANS_LIGHT,
    LLP_COLOR_OCEANS_LIGHT_DEAD,
    LLP_COLOR_COUNT
}; /* llp_color_index */

/* ---- section: declarations ----------------------------------------------- */

/*! @brief global file descriptor used to write each file.
 *
 *  declared and initialized in `main.c`.
 */
extern FILE *_file_out;

/*! declared and initialized in `main.c`.
 */
extern llp_colorscheme lilypads_colorscheme[LLP_COLOR_COUNT];

/* ---- section: signatures ------------------------------------------------- */

void vim_cmd(const str *cmd);
void code(u8 level, const str *text);
void comment(u8 level, const str *text);
void comment_block(const str *text);
void license(void);
void title(u8 level, const str *text);
void highlight_group(u8 level, const llp_hl_group group);
void link_group(u8 level, const str *src, const llp_hl_group dst);
void pretty_print_hex_to_rgb(const str *name, u32 hex);
u32 rgb_to_hex(llp_col col);
u32 gui_to_cterm(u32 hex);

/*! @brief multiply color with @ref COL_NC_COEF.
 */
llp_col col_nc(llp_col col);

/*! @brief multiply color with @ref COL_NCL_COEF.
 */
llp_col col_ncl(llp_col col);

/*! @brief multiply color with @ref TXT_NC_COEF.
 */
llp_col txt_nc(llp_col col);

/*! @brief multiply color with @ref TXT_NCL_COEF.
 */
llp_col txt_ncl(llp_col col);

/*! @brief write the header components of the colorscheme file.
 *
 *  @remark called automatically inside @ref write_file().
 */
void header_setup(const str *name);

/*! @brief write the footer components of the colorscheme file.
 *
 *  @remark called automatically inside @ref write_file().
 */
void footer_setup(const llp_hl_groups groups);

/*! @brief write the body of the colorscheme file.
 *
 *  @remark called automatically inside @ref write_file().
 */
void write_colors(const llp_hl_groups groups);

void setup_hl_group(llp_hl_group *g, const str *name, u32 flags,
        llp_col fg, llp_col bg, enum hl_group_sp_index sp);

void setup_hl_groups(llp_colorscheme *col);
void setup_colors_nature_dark(void);
void setup_colors_nature_dark_dead(void);
void setup_colors_nature_light(void);
void setup_colors_nature_light_dead(void);
void setup_colors_cherry_dark(void);
void setup_colors_cherry_dark_dead(void);
void setup_colors_cherry_light(void);
void setup_colors_cherry_light_dead(void);
void setup_colors_oceans_dark(void);
void setup_colors_oceans_dark_dead(void);
void setup_colors_oceans_light(void);
void setup_colors_oceans_light_dead(void);

/*! @brief generate the colorscheme file.
 */
u32 write_file(llp_colorscheme colors);

#endif /* LILYPADS_COMMON_H */
