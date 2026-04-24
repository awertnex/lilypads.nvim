#include "h/common.h"
#include "h/logger.h"

FILE *_file_out = NULL;
str lilypads_theme_name[LLP_COLOR_COUNT][NAME_MAX] = {0};
llp_theme_colors lilypads_theme_colors[LLP_COLOR_COUNT] = {0};
llp_theme_colors theme_colors_nature_dark = {0};
llp_theme_colors theme_colors_nature_dark_dead = {0};
llp_theme_colors theme_colors_nature_light = {0};
llp_theme_colors theme_colors_nature_light_dead = {0};
llp_theme_colors theme_colors_cherry_dark = {0};
llp_theme_colors theme_colors_cherry_dark_dead = {0};
llp_theme_colors theme_colors_cherry_light = {0};
llp_theme_colors theme_colors_cherry_light_dead = {0};
llp_theme_colors theme_colors_oceans_dark = {0};
llp_theme_colors theme_colors_oceans_dark_dead = {0};
llp_theme_colors theme_colors_oceans_light = {0};
llp_theme_colors theme_colors_oceans_light_dead = {0};

u32 write_file(const str *name, llp_theme_colors colors)
{
    str temp[STRING_MAX] = {0};
    str path[STRING_MAX] = {0};

    snprintf(path, STRING_MAX, "%s%s"LLP_EXT, LLP_DIR_DST, name);

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
            name);
    comment_block(temp);
    fputc('\n', _file_out);

    vim_cmd("hi clear");
    fputc('\n', _file_out);

    header_setup(name);
    write_colors(colors);
    footer_setup();

    if (_file_out != NULL)
        fclose(_file_out);

    return 0;

cleanup:

    if (_file_out != NULL)
        fclose(_file_out);

    return 1;
}

int main(void)
{
    i32 i = 0;

    snprintf(lilypads_theme_name[LLP_COLOR_NATURE_DARK],        NAME_MAX, "%s", "lilypads_nature_dark");
    snprintf(lilypads_theme_name[LLP_COLOR_NATURE_DARK_DEAD],   NAME_MAX, "%s", "lilypads_nature_dark_dead");
    snprintf(lilypads_theme_name[LLP_COLOR_NATURE_LIGHT],       NAME_MAX, "%s", "lilypads_nature_light");
    snprintf(lilypads_theme_name[LLP_COLOR_NATURE_LIGHT_DEAD],  NAME_MAX, "%s", "lilypads_nature_light_dead");
    snprintf(lilypads_theme_name[LLP_COLOR_CHERRY_DARK],        NAME_MAX, "%s", "lilypads_cherry_dark");
    snprintf(lilypads_theme_name[LLP_COLOR_CHERRY_DARK_DEAD],   NAME_MAX, "%s", "lilypads_cherry_dark_dead");
    snprintf(lilypads_theme_name[LLP_COLOR_CHERRY_LIGHT],       NAME_MAX, "%s", "lilypads_cherry_light");
    snprintf(lilypads_theme_name[LLP_COLOR_CHERRY_LIGHT_DEAD],  NAME_MAX, "%s", "lilypads_cherry_light_dead");
    snprintf(lilypads_theme_name[LLP_COLOR_OCEANS_DARK],        NAME_MAX, "%s", "lilypads_oceans_dark");
    snprintf(lilypads_theme_name[LLP_COLOR_OCEANS_DARK_DEAD],   NAME_MAX, "%s", "lilypads_oceans_dark_dead");
    snprintf(lilypads_theme_name[LLP_COLOR_OCEANS_LIGHT],       NAME_MAX, "%s", "lilypads_oceans_light");
    snprintf(lilypads_theme_name[LLP_COLOR_OCEANS_LIGHT_DEAD],  NAME_MAX, "%s", "lilypads_oceans_light_dead");

    lilypads_theme_colors[LLP_COLOR_NATURE_DARK] =          (llp_theme_colors)theme_colors_nature_dark;
    lilypads_theme_colors[LLP_COLOR_NATURE_DARK_DEAD] =     (llp_theme_colors)theme_colors_nature_dark_dead;
    lilypads_theme_colors[LLP_COLOR_NATURE_LIGHT] =         (llp_theme_colors)theme_colors_nature_light;
    lilypads_theme_colors[LLP_COLOR_NATURE_LIGHT_DEAD] =    (llp_theme_colors)theme_colors_nature_light_dead;
    lilypads_theme_colors[LLP_COLOR_CHERRY_DARK] =          (llp_theme_colors)theme_colors_cherry_dark;
    lilypads_theme_colors[LLP_COLOR_CHERRY_DARK_DEAD] =     (llp_theme_colors)theme_colors_cherry_dark_dead;
    lilypads_theme_colors[LLP_COLOR_CHERRY_LIGHT] =         (llp_theme_colors)theme_colors_cherry_light;
    lilypads_theme_colors[LLP_COLOR_CHERRY_LIGHT_DEAD] =    (llp_theme_colors)theme_colors_cherry_light_dead;
    lilypads_theme_colors[LLP_COLOR_OCEANS_DARK] =          (llp_theme_colors)theme_colors_oceans_dark;
    lilypads_theme_colors[LLP_COLOR_OCEANS_DARK_DEAD] =     (llp_theme_colors)theme_colors_oceans_dark_dead;
    lilypads_theme_colors[LLP_COLOR_OCEANS_LIGHT] =         (llp_theme_colors)theme_colors_oceans_light;
    lilypads_theme_colors[LLP_COLOR_OCEANS_LIGHT_DEAD] =    (llp_theme_colors)theme_colors_oceans_light_dead;

    for (i = 0; i < LLP_COLOR_COUNT; ++i)
        write_file(lilypads_theme_name[i], lilypads_theme_colors[i]);
    return 0;
}
