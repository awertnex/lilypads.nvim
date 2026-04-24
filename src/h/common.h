#ifndef LILYPADS_COMMON_H
#define LILYPADS_COMMON_H

#include "types.h"

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

struct col
{
    u8 r, g, b;
};
typedef struct col llp_col;

struct theme_colors
{
    str name[NAME_MAX];
    void (*setup_func)(void);

    struct
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
    } lilypads;

    struct
    {
        llp_col bg_base;
        llp_col bg_base_na;
        llp_col bg_base_na_light;
        llp_col bg_linenu;
        llp_col bg_statusline;
        llp_col bg_statusline_na;
    } ui;

    struct
    {
        llp_col base_white;
        llp_col base_white_na;
        llp_col bright_white;
        llp_col linenu;
        llp_col comment;
        llp_col cmp;
        llp_col bg_debugerror;
    } syntax;

    struct
    {
        llp_col error;
        llp_col warn;
        llp_col info;
        llp_col hint;
        llp_col ok;
    } diagnostic;
};
typedef struct theme_colors llp_theme_colors;

enum llp_color
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
    LLP_COLOR_COUNT,
}; /* llp_color */

/* ---- section: declarations ----------------------------------------------- */

/*! declared in `main.c`.
 */
extern FILE *_file_out;

/*! declared and initialized in `main.c`.
 */
extern llp_theme_colors lilypads_theme_colors[LLP_COLOR_COUNT];

/* ---- section: signatures ------------------------------------------------- */

void vim_cmd(const str *cmd);
void code(u8 level, const str *text);
void comment(u8 level, const str *text);
void comment_block(const str *text);
void license(void);
void title(u8 level, const str *text);

void header_setup(const str *name);
void footer_setup(void);
void write_colors(const llp_theme_colors c);

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

u32 write_file(llp_theme_colors colors);

#endif /* LILYPADS_COMMON_H */
