#include "deps/buildtool/buildtool.h"

#define DIR_SRC "src/"

_buf cmd = {0};

str *cflags[] =
{
    "-Wall",
    "-Wextra",
    "-std=c89",
    "-Wpedantic",
    "-shared",
    "-fpic",
};

str *files_lua[] =
{
    DIR_SRC"logger.c",
    DIR_SRC"util.c",
};

int main(int argc, char **argv)
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
    cmd_push(&cmd, "lilypads");
    cmd_ready(&cmd);

    if (exec(&cmd, "main().cmd") != 0)
        cmd_fail(&cmd);

    return 0;
}
