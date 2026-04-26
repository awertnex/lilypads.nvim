#include "deps/buildtool/buildtool.h"

#define DIR_SRC "src/"

_buf cmd = {0};

str *cflags[] =
{
    "-Wall",
    "-Wextra",
    "-std=c89",
    "-Wpedantic",
};

str *files_lua[] =
{
    DIR_SRC"main.c",
    DIR_SRC"common.c",
    DIR_SRC"logger.c",
    DIR_SRC"util.c",
    DIR_SRC"write_files_lua.c",
};

str *files_vim[] =
{
    DIR_SRC"main.c",
    DIR_SRC"common.c",
    DIR_SRC"logger.c",
    DIR_SRC"util.c",
    DIR_SRC"write_files_vim.c",
};

void build_lua(int argc, char **argv);
void build_vim(int argc, char **argv);

int main(int argc, char **argv)
{
    build_lua(argc, argv);
    cmd_free(&cmd);
    build_vim(argc, argv);
    return 0;
}

void build_lua(int argc, char **argv)
{
    i64 i = 0;

    if (build_init(argc, argv, "build.c", "build") != 0)
        cmd_fail(&cmd);

    cmd_push(&cmd, COMPILER);
    cmd_push(&cmd, "-DLLP_LUA");

    for (i = 0; i < arr_len(cflags); ++i)
        cmd_push(&cmd, cflags[i]);

    for (i = 0; i < arr_len(files_lua); ++i)
        cmd_push(&cmd, files_lua[i]);

    cmd_push(&cmd, "-o");
    cmd_push(&cmd, "lilypads_lua");
    cmd_ready(&cmd);

    if (exec(&cmd, "main().cmd") != 0)
        cmd_fail(&cmd);
}

void build_vim(int argc, char **argv)
{
    i64 i = 0;

    if (build_init(argc, argv, "build.c", "build") != 0)
        cmd_fail(&cmd);

    cmd_push(&cmd, COMPILER);
    cmd_push(&cmd, "-DLLP_VIM");

    for (i = 0; i < arr_len(cflags); ++i)
        cmd_push(&cmd, cflags[i]);

    for (i = 0; i < arr_len(files_vim); ++i)
        cmd_push(&cmd, files_vim[i]);

    cmd_push(&cmd, "-o");
    cmd_push(&cmd, "lilypads_vim");
    cmd_ready(&cmd);

    if (exec(&cmd, "main().cmd") != 0)
        cmd_fail(&cmd);
}
