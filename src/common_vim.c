#include "h/common.h"

void vim_cmd(const str *cmd)
{
    fprintf(_file_out, "%s\n", cmd);
}

void comment(const str *text)
{
    fprintf(_file_out, LLP_CMT"%s\n", text);
}
