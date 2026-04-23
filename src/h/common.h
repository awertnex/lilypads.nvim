#ifndef LILYPADS_COMMON_H
#define LILYPADS_COMMON_H

#include "types.h"

#if defined(LLP_LUA)

#   define LLP_CMT "-- "
#   define LLP_DIR_DST "lilypads/lua/colors/"

#elif defined(LLP_VIM)

#   define LLP_CMT "\" "
#   define LLP_DIR_DST "lilypads/vim/colors/"

#endif /* LLP_SYNTAX */

#include "stdio.h"

/* ---- section: definitions ------------------------------------------------ */

#define STRING_MAX 2048

struct col
{
    u8 r, g, b, a;
};
typedef struct col llp_col;

struct theme_colors
{
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
} /* llp_color */;

/* ---- section: declarations ----------------------------------------------- */

extern FILE *_file_out;
extern llp_theme_colors colors[LLP_COLOR_COUNT];

/* ---- section: signatures ------------------------------------------------- */

void vim_cmd(const str *cmd);
void comment(const str *text);

#endif /* LILYPADS_COMMON_H */
