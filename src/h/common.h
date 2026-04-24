#ifndef LILYPADS_COMMON_H
#define LILYPADS_COMMON_H

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

#include "stdio.h"

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

#define FUNC_PAINT "llp_paint"
#define FUNC_CLEAR "llp_clear"

enum llp_flag
{
    FLAG_LUA = 0x01,
    FLAG_VIM = 0x02,
    FLAG_FG = 0x04,
    FLAG_BG = 0x08,
    FLAG_SP = 0x10
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
    llp_col radioactive;
    llp_col highly_radioactive;
    llp_col blooming_radioactive;
};
typedef struct col_base llp_col_base;

struct col_ui
{
    llp_col bg_base;
    llp_col bg_base_na; /* TODO: deprecate, use `theme_colors.na_coef` */
    llp_col bg_base_na_light; /* TODO: deprecate, use `theme_colors.na_coef` */
    llp_col bg_linenu;
    llp_col bg_statusline;
    llp_col bg_statusline_na; /* TODO: deprecate, use `theme_colors.na_coef` */
    u8 na_coef;
};
typedef struct col_ui llp_col_ui;

struct col_syntax
{
    llp_col base_white;
    llp_col base_white_na; /* TODO: deprecate, use `theme_colors.na_coef` */
    llp_col bright_white;
    llp_col linenu;
    llp_col comment;
    llp_col cmp;
    llp_col bg_debugerror;
};
typedef struct col_syntax llp_col_syntax;

struct col_diag
{
    llp_col error;
    llp_col warn;
    llp_col info;
    llp_col hint;
    llp_col ok;
};
typedef struct col_diag llp_col_diag;

struct colorscheme
{
    /*! @brief colorscheme name, no file extension.
     */
    str name[NAME_MAX];

    /*! @brief function to fill in colors (functions found in 'common.c').
     */
    void (*setup_func)(void);

    /*! @brief inactive elements darkness coefficient.
     */
    u8 na_coef;

    llp_col_base c_base;
    llp_col_ui c_ui;
    llp_col_syntax c_syntax;
    llp_col_diag c_diag;
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
void pretty_print_hex_to_rgb(const str *name, u32 hex);
u32 rgb_to_hex(llp_col col);
u32 gui_to_cterm(u32 hex);

/*! @brief write the header components of the colorscheme file.
 *
 *  @remark called automatically inside @ref write_file().
 */
void header_setup(const str *name);

/*! @brief write the footer components of the colorscheme file.
 *
 *  @remark called automatically inside @ref write_file().
 */
void footer_setup(void);

/*! @brief write the body of the colorscheme file.
 *
 *  @remark called automatically inside @ref write_file().
 */
void write_colors(const llp_hl_groups groups);

void setup_hl_group(llp_hl_group *g, const str *name, u32 flags,
        llp_col fg, llp_col bg, enum hl_group_sp_index sp, llp_col sp_col);

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
