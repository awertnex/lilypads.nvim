#include "h/common.h"
#include "h/logger.h"

#include <stdio.h>

FILE *_file_out = NULL;
llp_colorscheme lilypads_colorscheme[LLP_COLOR_COUNT] = {0};
str hl_group_sp_text[HL_GROUP_SP_COUNT][HL_GROUP_PARAM_MAX] = {0};

u32 write_file(llp_colorscheme colors)
{
    str temp[STRING_MAX] = {0};
    str path[STRING_MAX] = {0};

    snprintf(path, STRING_MAX, "%s%s"LLP_EXT, LLP_DIR_DST, colors.name);

    if (!colors.setup_func)
    {
        snprintf(temp, STRING_MAX, "Failed to Write File '%s', `colors.setup_func` NULL", path);
        _log_error(temp);
        return 1;
    }

    if ((_file_out = fopen(path, "w")) == NULL)
    {
        snprintf(temp, STRING_MAX, "Failed to Write File '%s'", path);
        _log_error(temp);
        goto cleanup;
    }

    license();
    fputc('\n', _file_out);

    snprintf(temp, STRING_MAX,
            LLP_CMT_TAB1"file: %s"LLP_EXT"\n"
            LLP_CMT_TAB1"generated using tool: "LLP_PROJECT_REPOSITORY"\n"
            "\n"
            LLP_NOTES,
            colors.name);
    comment_block(temp);
    fputc('\n', _file_out);

    vim_cmd("hi clear");
    header_setup(colors.name);
    write_colors(colors.groups);
    footer_setup();

    if (_file_out != NULL)
        fclose(_file_out);

    return 0;

cleanup:

    if (_file_out != NULL)
        fclose(_file_out);

    return 2;
}

int main(void)
{
    i32 i = 0;
    u32 err = 0;

    snprintf(hl_group_sp_text[HL_GROUP_SP_NONE], HL_GROUP_PARAM_MAX, "%s", "NONE");
    snprintf(hl_group_sp_text[HL_GROUP_SP_BOLD], HL_GROUP_PARAM_MAX, "%s", "bold");
    snprintf(hl_group_sp_text[HL_GROUP_SP_UNDERLINE], HL_GROUP_PARAM_MAX, "%s", "underline");
    snprintf(hl_group_sp_text[HL_GROUP_SP_UNDERCURL], HL_GROUP_PARAM_MAX, "%s", "undercurl");
    snprintf(hl_group_sp_text[HL_GROUP_SP_UNDERDOUBLE], HL_GROUP_PARAM_MAX, "%s", "underdouble");
    snprintf(hl_group_sp_text[HL_GROUP_SP_UNDERDOTTED], HL_GROUP_PARAM_MAX, "%s", "underdotted");
    snprintf(hl_group_sp_text[HL_GROUP_SP_UNDERDASHED], HL_GROUP_PARAM_MAX, "%s", "underdashed");
    snprintf(hl_group_sp_text[HL_GROUP_SP_STRIKETHROUGH], HL_GROUP_PARAM_MAX, "%s", "strikethrough");
    snprintf(hl_group_sp_text[HL_GROUP_SP_REVERSE], HL_GROUP_PARAM_MAX, "%s", "reverse");
    snprintf(hl_group_sp_text[HL_GROUP_SP_INVERSE], HL_GROUP_PARAM_MAX, "%s", "inverse");
    snprintf(hl_group_sp_text[HL_GROUP_SP_ITALIC], HL_GROUP_PARAM_MAX, "%s", "italic");
    snprintf(hl_group_sp_text[HL_GROUP_SP_STANDOUT], HL_GROUP_PARAM_MAX, "%s", "standout");
    snprintf(hl_group_sp_text[HL_GROUP_SP_ALTFONT], HL_GROUP_PARAM_MAX, "%s", "altfont");
    snprintf(hl_group_sp_text[HL_GROUP_SP_DIM], HL_GROUP_PARAM_MAX, "%s", "dim");
    snprintf(hl_group_sp_text[HL_GROUP_SP_BLINK], HL_GROUP_PARAM_MAX, "%s", "blink");
    snprintf(hl_group_sp_text[HL_GROUP_SP_CONCEAL], HL_GROUP_PARAM_MAX, "%s", "conceal");
    snprintf(hl_group_sp_text[HL_GROUP_SP_OVERLINE], HL_GROUP_PARAM_MAX, "%s", "overline");
    snprintf(hl_group_sp_text[HL_GROUP_SP_NOCOMBINE], HL_GROUP_PARAM_MAX, "%s", "nocombine");

    snprintf(lilypads_colorscheme[LLP_COLOR_NATURE_DARK].name,         NAME_MAX, "%s", "lilypads_nature_dark");
    snprintf(lilypads_colorscheme[LLP_COLOR_NATURE_DARK_DEAD].name,    NAME_MAX, "%s", "lilypads_nature_dark_dead");
    snprintf(lilypads_colorscheme[LLP_COLOR_NATURE_LIGHT].name,        NAME_MAX, "%s", "lilypads_nature_light");
    snprintf(lilypads_colorscheme[LLP_COLOR_NATURE_LIGHT_DEAD].name,   NAME_MAX, "%s", "lilypads_nature_light_dead");
    snprintf(lilypads_colorscheme[LLP_COLOR_CHERRY_DARK].name,         NAME_MAX, "%s", "lilypads_cherry_dark");
    snprintf(lilypads_colorscheme[LLP_COLOR_CHERRY_DARK_DEAD].name,    NAME_MAX, "%s", "lilypads_cherry_dark_dead");
    snprintf(lilypads_colorscheme[LLP_COLOR_CHERRY_LIGHT].name,        NAME_MAX, "%s", "lilypads_cherry_light");
    snprintf(lilypads_colorscheme[LLP_COLOR_CHERRY_LIGHT_DEAD].name,   NAME_MAX, "%s", "lilypads_cherry_light_dead");
    snprintf(lilypads_colorscheme[LLP_COLOR_OCEANS_DARK].name,         NAME_MAX, "%s", "lilypads_oceans_dark");
    snprintf(lilypads_colorscheme[LLP_COLOR_OCEANS_DARK_DEAD].name,    NAME_MAX, "%s", "lilypads_oceans_dark_dead");
    snprintf(lilypads_colorscheme[LLP_COLOR_OCEANS_LIGHT].name,        NAME_MAX, "%s", "lilypads_oceans_light");
    snprintf(lilypads_colorscheme[LLP_COLOR_OCEANS_LIGHT_DEAD].name,   NAME_MAX, "%s", "lilypads_oceans_light_dead");

    lilypads_colorscheme[LLP_COLOR_NATURE_DARK].setup_func =       &setup_colors_nature_dark;
    lilypads_colorscheme[LLP_COLOR_NATURE_DARK_DEAD].setup_func =  &setup_colors_nature_dark_dead;
    lilypads_colorscheme[LLP_COLOR_NATURE_LIGHT].setup_func =      &setup_colors_nature_light;
    lilypads_colorscheme[LLP_COLOR_NATURE_LIGHT_DEAD].setup_func = &setup_colors_nature_light_dead;
    lilypads_colorscheme[LLP_COLOR_CHERRY_DARK].setup_func =       &setup_colors_cherry_dark;
    lilypads_colorscheme[LLP_COLOR_CHERRY_DARK_DEAD].setup_func =  &setup_colors_cherry_dark_dead;
    lilypads_colorscheme[LLP_COLOR_CHERRY_LIGHT].setup_func =      &setup_colors_cherry_light;
    lilypads_colorscheme[LLP_COLOR_CHERRY_LIGHT_DEAD].setup_func = &setup_colors_cherry_light_dead;
    lilypads_colorscheme[LLP_COLOR_OCEANS_DARK].setup_func =       &setup_colors_oceans_dark;
    lilypads_colorscheme[LLP_COLOR_OCEANS_DARK_DEAD].setup_func =  &setup_colors_oceans_dark_dead;
    lilypads_colorscheme[LLP_COLOR_OCEANS_LIGHT].setup_func =      &setup_colors_oceans_light;
    lilypads_colorscheme[LLP_COLOR_OCEANS_LIGHT_DEAD].setup_func = &setup_colors_oceans_light_dead;

    for (i = 0; i < LLP_COLOR_COUNT; ++i)
    {
        lilypads_colorscheme[i].setup_func();
        err = write_file(lilypads_colorscheme[i]);
        if (err != 0)
            return err;
    }

    return 0;
}
