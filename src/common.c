#include "h/common.h"
#include "h/config.h"

/* ---- section: declarations ----------------------------------------------- */

static llp_col nocolor = {0};

llp_col_diag col_diag_dark =
{
    {204,  41,  53}, /* error */
    {204,  88,  41}, /* warn */
    {122, 202, 204}, /* info */
    {208, 230, 207}, /* hint */
    {162, 222, 137}, /* ok */
};

llp_col_diag col_diag_light =
{
    {204,  41,  53}, /* error */
    {204,  88,  41}, /* warn */
    {122, 202, 204}, /* info */ /* (TODO: adjust color for light mode) */
    {208, 230, 207}, /* hint */ /* (TODO: adjust color for light mode) */
    {162, 222, 137}, /* ok */   /* (TODO: adjust color for light mode) */
};

/* ---- section: implementation --------------------------------------------- */

void setup_hl_group(llp_hl_group *g, const str *name, u32 flags,
        llp_col fg, llp_col bg, enum hl_group_sp_index sp, llp_col sp_col)
{
    if (name)
        snprintf(g->name, HL_GROUP_NAME_MAX, "%s", name);

    g->flags = flags;
    g->fg = rgb_to_hex(fg);
    g->bg = rgb_to_hex(bg);
    g->sp = sp;
    g->sp_col = rgb_to_hex(sp_col);
}

void setup_hl_groups(llp_colorscheme *col)
{
    llp_hl_groups *g = &col->groups;

    setup_hl_group(&g->visual, "Visual", FLAG_LUA | FLAG_VIM | FLAG_FG | FLAG_BG, col->c_base.highly_radioactive, col->c_base.visual, 0, nocolor);
}

void setup_colors_nature_dark(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_NATURE_DARK];

    col->na_coef = INACTIVE_COEF;
    col->c_diag = (llp_col_diag)col_diag_dark;

    setup_hl_groups(col);
}

void setup_colors_nature_dark_dead(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_NATURE_DARK_DEAD];

    col->na_coef = INACTIVE_COEF;
    col->c_diag = (llp_col_diag)col_diag_light;

    setup_hl_groups(col);
}

void setup_colors_nature_light(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_NATURE_LIGHT];

    col->na_coef = INACTIVE_COEF;
    col->c_diag = (llp_col_diag)col_diag_dark;

    setup_hl_groups(col);
}

void setup_colors_nature_light_dead(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_NATURE_LIGHT_DEAD];

    col->na_coef = INACTIVE_COEF;
    col->c_diag = (llp_col_diag)col_diag_light;

    setup_hl_groups(col);
}

void setup_colors_cherry_dark(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_CHERRY_DARK];

    col->na_coef = INACTIVE_COEF;
    col->c_diag = (llp_col_diag)col_diag_dark;

    setup_hl_groups(col);
}

void setup_colors_cherry_dark_dead(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_CHERRY_DARK_DEAD];

    col->na_coef = INACTIVE_COEF;
    col->c_diag = (llp_col_diag)col_diag_light;

    setup_hl_groups(col);
}

void setup_colors_cherry_light(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_CHERRY_LIGHT];

    col->na_coef = INACTIVE_COEF;
    col->c_diag = (llp_col_diag)col_diag_dark;

    setup_hl_groups(col);
}

void setup_colors_cherry_light_dead(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_CHERRY_LIGHT_DEAD];

    col->na_coef = INACTIVE_COEF;
    col->c_diag = (llp_col_diag)col_diag_light;

    setup_hl_groups(col);
}

void setup_colors_oceans_dark(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_OCEANS_DARK];

    col->na_coef = INACTIVE_COEF;
    col->c_diag = (llp_col_diag)col_diag_dark;

    setup_hl_groups(col);
}

void setup_colors_oceans_dark_dead(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_OCEANS_DARK_DEAD];

    col->na_coef = INACTIVE_COEF;
    col->c_diag = (llp_col_diag)col_diag_light;

    setup_hl_groups(col);
}

void setup_colors_oceans_light(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_OCEANS_LIGHT];

    col->na_coef = INACTIVE_COEF;
    col->c_diag = (llp_col_diag)col_diag_dark;

    setup_hl_groups(col);
}

void setup_colors_oceans_light_dead(void)
{
    llp_colorscheme *col = &lilypads_colorscheme[LLP_COLOR_OCEANS_LIGHT_DEAD];

    col->na_coef = INACTIVE_COEF;
    col->c_diag = (llp_col_diag)col_diag_light;

    setup_hl_groups(col);
}
