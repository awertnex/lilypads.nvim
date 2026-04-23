#include "h/common.h"

void vim_cmd(const str *cmd)
{
    fprintf(_file_out, "vim.cmd \"%s\"\n", cmd);
}
