#include "h/common.h"
#include "h/logger.h"

#include <stdio.h>
#include <string.h>

FILE *_file_out = NULL;
llp_colorscheme lilypads_colorscheme[LLP_COLOR_COUNT] = {0};
str hl_group_sp_text[HL_GROUP_SP_COUNT][HL_GROUP_PARAM_MAX] = {0};

static u32 generate_palettes(void);
static void generate_aux_pallettes(void);
static u32 generate_colorscheme_entries(const str *cmd_reload_lua, llp_colorscheme *c);

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

    write_colors(colors.groups);

    if (_file_out != NULL)
        fclose(_file_out);
    return 0;

cleanup:

    if (_file_out != NULL)
        fclose(_file_out);
    return 2;
}

static u32 generate_palettes(void)
{
    str temp[STRING_MAX] = {0};
    str path[STRING_MAX] = {0};
    u32 i = 0;

    snprintf(path, STRING_MAX, "%s", "lua/lilypads/palette.lua");
    if ((_file_out = fopen(path, "w")) == NULL)
    {
        snprintf(temp, STRING_MAX, "Failed to Write File '%s'", path);
        _log_error(temp);
        goto cleanup;
    }

    fprintf(_file_out, "%s", "local M = {}\n\n");

    generate_aux_pallettes();

    for (i = 0; i < LLP_COLOR_COUNT; ++i)
        fprintf(_file_out,
                "M.%s = {\n"
                "    base = \"#%06x\",\n"
                "    loud = \"#%06x\",\n"
                "    bright = \"#%06x\",\n"
                "    visual = \"#%06x\",\n"
                "    habitable = \"#%06x\",\n"
                "    dry0 = \"#%06x\",\n"
                "    dry1 = \"#%06x\",\n"
                "    thirsty = \"#%06x\",\n"
                "    mossy = \"#%06x\",\n"
                "    dead = \"#%06x\",\n"
                "    radioactive = \"#%06x\",\n"
                "    highly_radioactive = \"#%06x\",\n"
                "    blooming_radioactive = \"#%06x\"\n"
                "}\n\n",
                lilypads_colorscheme[i].name + 9,
                rgb_to_hex(lilypads_colorscheme[i].c_base.base),
                rgb_to_hex(lilypads_colorscheme[i].c_base.loud),
                rgb_to_hex(lilypads_colorscheme[i].c_base.bright),
                rgb_to_hex(lilypads_colorscheme[i].c_base.visual),
                rgb_to_hex(lilypads_colorscheme[i].c_base.habitable),
                rgb_to_hex(lilypads_colorscheme[i].c_base.dry0),
                rgb_to_hex(lilypads_colorscheme[i].c_base.dry1),
                rgb_to_hex(lilypads_colorscheme[i].c_base.thirsty),
                rgb_to_hex(lilypads_colorscheme[i].c_base.mossy),
                rgb_to_hex(lilypads_colorscheme[i].c_base.dead),
                rgb_to_hex(lilypads_colorscheme[i].c_base.radioactive),
                rgb_to_hex(lilypads_colorscheme[i].c_base.highly_radioactive),
                rgb_to_hex(lilypads_colorscheme[i].c_base.blooming_radioactive));

    fprintf(_file_out, "%s", "return M\n");

    if (_file_out != NULL)
        fclose(_file_out);
    return 0;

cleanup:

    if (_file_out != NULL)
        fclose(_file_out);
    return 1;
}

static void generate_aux_pallettes(void)
{
    fprintf(_file_out,
            "M.ui_dark = {\n"
            "    base = \"#%06x\",\n"
            "    line_nu = \"#%06x\",\n"
            "    status_line = \"#%06x\"\n"
            "}\n\n",
            rgb_to_hex(lilypads_colorscheme[0].c_ui.base),
            rgb_to_hex(lilypads_colorscheme[0].c_ui.line_nu),
            rgb_to_hex(lilypads_colorscheme[0].c_ui.status_line));

    fprintf(_file_out,
            "M.ui_light = {\n"
            "    base = \"#%06x\",\n"
            "    line_nu = \"#%06x\",\n"
            "    status_line = \"#%06x\"\n"
            "}\n\n",
            rgb_to_hex(lilypads_colorscheme[2].c_ui.base),
            rgb_to_hex(lilypads_colorscheme[2].c_ui.line_nu),
            rgb_to_hex(lilypads_colorscheme[2].c_ui.status_line));

    fprintf(_file_out,
            "M.text_dark = {\n"
            "    base = \"#%06x\",\n"
            "    line_nu = \"#%06x\",\n"
            "    status_line = \"#%06x\",\n"
            "    base = \"#%06x\",\n"
            "    base_alt = \"#%06x\",\n"
            "    light = \"#%06x\",\n"
            "    light_alt = \"#%06x\",\n"
            "    line_nu = \"#%06x\",\n"
            "    link = \"#%06x\",\n"

            "    error = \"#%06x\",\n"
            "    error_alt = \"#%06x\",\n"
            "    warn = \"#%06x\",\n"
            "    info = \"#%06x\",\n"
            "    hint = \"#%06x\",\n"
            "    ok = \"#%06x\",\n"

            "    diff_add_fg = \"#%06x\",\n"
            "    diff_change_fg = \"#%06x\",\n"
            "    diff_delete_fg = \"#%06x\",\n"
            "    diff_text_fg = \"#%06x\",\n"
            "    diff_add_bg = \"#%06x\",\n"
            "    diff_change_bg = \"#%06x\",\n"
            "    diff_delete_bg = \"#%06x\",\n"
            "    diff_text_bg = \"#%06x\"\n"
            "}\n\n",
        rgb_to_hex(lilypads_colorscheme[0].c_text.base),
        rgb_to_hex(lilypads_colorscheme[0].c_text.base_alt),
        rgb_to_hex(lilypads_colorscheme[0].c_text.light),
        rgb_to_hex(lilypads_colorscheme[0].c_text.light_alt),
        rgb_to_hex(lilypads_colorscheme[0].c_text.line_nu),
        rgb_to_hex(lilypads_colorscheme[0].c_text.link),

        rgb_to_hex(lilypads_colorscheme[0].c_text.error),
        rgb_to_hex(lilypads_colorscheme[0].c_text.error_alt),
        rgb_to_hex(lilypads_colorscheme[0].c_text.warn),
        rgb_to_hex(lilypads_colorscheme[0].c_text.info),
        rgb_to_hex(lilypads_colorscheme[0].c_text.hint),
        rgb_to_hex(lilypads_colorscheme[0].c_text.ok),

        rgb_to_hex(lilypads_colorscheme[0].c_text.diff_add_fg),
        rgb_to_hex(lilypads_colorscheme[0].c_text.diff_change_fg),
        rgb_to_hex(lilypads_colorscheme[0].c_text.diff_delete_fg),
        rgb_to_hex(lilypads_colorscheme[0].c_text.diff_text_fg),
        rgb_to_hex(lilypads_colorscheme[0].c_text.diff_add_bg),
        rgb_to_hex(lilypads_colorscheme[0].c_text.diff_change_bg),
        rgb_to_hex(lilypads_colorscheme[0].c_text.diff_delete_bg),
        rgb_to_hex(lilypads_colorscheme[0].c_text.diff_text_bg));

    fprintf(_file_out,
            "M.text_light = {\n"
            "    base = \"#%06x\",\n"
            "    line_nu = \"#%06x\",\n"
            "    status_line = \"#%06x\",\n"
            "    base = \"#%06x\",\n"
            "    base_alt = \"#%06x\",\n"
            "    light = \"#%06x\",\n"
            "    light_alt = \"#%06x\",\n"
            "    line_nu = \"#%06x\",\n"
            "    link = \"#%06x\",\n"

            "    error = \"#%06x\",\n"
            "    error_alt = \"#%06x\",\n"
            "    warn = \"#%06x\",\n"
            "    info = \"#%06x\",\n"
            "    hint = \"#%06x\",\n"
            "    ok = \"#%06x\",\n"

            "    diff_add_fg = \"#%06x\",\n"
            "    diff_change_fg = \"#%06x\",\n"
            "    diff_delete_fg = \"#%06x\",\n"
            "    diff_text_fg = \"#%06x\",\n"
            "    diff_add_bg = \"#%06x\",\n"
            "    diff_change_bg = \"#%06x\",\n"
            "    diff_delete_bg = \"#%06x\",\n"
            "    diff_text_bg = \"#%06x\"\n"
            "}\n\n",
        rgb_to_hex(lilypads_colorscheme[2].c_text.base),
        rgb_to_hex(lilypads_colorscheme[2].c_text.base_alt),
        rgb_to_hex(lilypads_colorscheme[2].c_text.light),
        rgb_to_hex(lilypads_colorscheme[2].c_text.light_alt),
        rgb_to_hex(lilypads_colorscheme[2].c_text.line_nu),
        rgb_to_hex(lilypads_colorscheme[2].c_text.link),

        rgb_to_hex(lilypads_colorscheme[2].c_text.error),
        rgb_to_hex(lilypads_colorscheme[2].c_text.error_alt),
        rgb_to_hex(lilypads_colorscheme[2].c_text.warn),
        rgb_to_hex(lilypads_colorscheme[2].c_text.info),
        rgb_to_hex(lilypads_colorscheme[2].c_text.hint),
        rgb_to_hex(lilypads_colorscheme[2].c_text.ok),

        rgb_to_hex(lilypads_colorscheme[2].c_text.diff_add_fg),
        rgb_to_hex(lilypads_colorscheme[2].c_text.diff_change_fg),
        rgb_to_hex(lilypads_colorscheme[2].c_text.diff_delete_fg),
        rgb_to_hex(lilypads_colorscheme[2].c_text.diff_text_fg),
        rgb_to_hex(lilypads_colorscheme[2].c_text.diff_add_bg),
        rgb_to_hex(lilypads_colorscheme[2].c_text.diff_change_bg),
        rgb_to_hex(lilypads_colorscheme[2].c_text.diff_delete_bg),
        rgb_to_hex(lilypads_colorscheme[2].c_text.diff_text_bg));
}

static u32 generate_colorscheme_entries(const str *cmd_reload_lua, llp_colorscheme *c)
{
    str temp[2][STRING_MAX] = {0};
    snprintf(temp[0], STRING_MAX, "colors/%s.lua", c->name);

    if ((_file_out = fopen(temp[0], "w")) == NULL)
    {
        snprintf(temp[1], STRING_MAX, "Failed to Write File '%s'", temp[0]);
        _log_error(temp[1]);
        goto cleanup;
    }

    snprintf(temp[0], STRING_MAX, "%s", cmd_reload_lua);
    fprintf(_file_out, "%s"
            "local P = require(\"lilypads.palette\").%s\n"
            "require(\"lilypads.init\").setup(P)\n",
            temp[0], c->name + 9);

    if (_file_out != NULL)
        fclose(_file_out);
    return 0;

cleanup:

    if (_file_out != NULL)
        fclose(_file_out);
    return 1;
}

int main(int argc, char **argv)
{
    i32 i = 0;
    u32 err = 0;
    str temp[STRING_MAX] = {0};

    if (argc < 2 || strncmp(argv[1], "release", 8))
    {
        _log_warning("Installing Development Build!");
        snprintf(temp, STRING_MAX, "%s",
                "package.loaded[\"lilypads.nvim\"] = nil\n\n");
    }

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
        /*
        err = write_file(lilypads_colorscheme[i]);
        */
        err = generate_colorscheme_entries(temp, &lilypads_colorscheme[i]);
        if (err != 0) goto cleanup;
    }

cleanup:

    return err;
}
