local M = {}

local COL_NC_COEF = 0.8
local COL_NCL_COEF = 0.9
local TXT_NC_COEF = 0.6
local TXT_NCL_COEF = 0.7

function M.set_paint(group, table)
    local termfg = table.termfg and table.termfg or "NONE"
    local termbg = table.termbg and table.termbg or "NONE"
    local guifg = table.guifg and table.guifg or "NONE"
    local guibg = table.guibg and table.guibg or "NONE"
    local sp = table.sp and table.sp or "NONE"
    local guisp = table.guifg and table.guifg or "NONE"

    vim.cmd.highlight("clear " .. group)

    if table.link then
        vim.cmd.highlight("link " .. group .. " " .. table.link)
    else
        vim.cmd.highlight(group .. " ctermfg=" .. termfg .. " guifg=" .. guifg .. " ctermbg=" .. termbg .. " guibg=" .. guibg .. " cterm=" .. sp .. " gui=" .. sp .. " guisp=" .. guisp)
    end
end

-- credit: hsluv (http://www.hsluv.org/).
-- slightly modified to change color range: [0.0, 1.0] -> [0, 255].
function hextorgb(hex)
    local hex_chars = "0123456789abcdef"
    local ret = {}
    c = string.lower(hex)
    for i = 0, 2 do
        local char_1 = string.sub(c, i * 2 + 2, i * 2 + 2)
        local char_2 = string.sub(c, i * 2 + 3, i * 2 + 3)
        local digit_1 = string.find(hex_chars, char_1) - 1
        local digit_2 = string.find(hex_chars, char_2) - 1
        ret[i + 1] = (digit_1 * 16 + digit_2)
    end
    return ret
end

-- credit: hsluv (http://www.hsluv.org/).
-- slightly modified to change color range: [0.0, 1.0] -> [0, 255].
function rgbtohex(rgb)
    local hex_chars = "0123456789abcdef"
    local ret = "#"
    for i = 1, 3 do
        local digit_2 = math.fmod(rgb[i], 16)
        local x = (rgb[i] - digit_2) / 16
        local digit_1 = math.floor(x)
        ret = ret .. string.sub(hex_chars, digit_1 + 1, digit_1 + 1)
        ret = ret .. string.sub(hex_chars, digit_2 + 1, digit_2 + 1)
    end
    return ret
end

-- turn a hex gui color into a term color value.
function M.guitoterm(col) -- TODO: make function `guitoterm()`
    return 0
end

-- darken color
function M.col_nc(col)
    local result = hextorgb(col)
    result[1] = result[1] * COL_NC_COEF
    result[2] = result[2] * COL_NC_COEF
    result[3] = result[3] * COL_NC_COEF
    return rgbtohex(result)
end

-- darken color (light mode)
function M.col_ncl(col)
    local result = hextorgb(col)
    result[1] = result[1] * COL_NCL_COEF
    result[2] = result[2] * COL_NCL_COEF
    result[3] = result[3] * COL_NCL_COEF
    return rgbtohex(result)
end

-- darken text color
function M.txt_nc(col)
    local result = hextorgb(col)
    result[1] = result[1] * TXT_NC_COEF
    result[2] = result[2] * TXT_NC_COEF
    result[3] = result[3] * TXT_NC_COEF
    return rgbtohex(result)
end

-- darken text color (light mode)
function M.txt_ncl(col)
    local result = hextorgb(col)
    result[1] = result[1] * TXT_NCL_COEF
    result[2] = result[2] * TXT_NCL_COEF
    result[3] = result[3] * TXT_NCL_COEF
    return rgbtohex(result)
end

return M
