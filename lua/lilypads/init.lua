local M = {}

function M.setup(palette_base, palette_ui, palette_text)
    local U = require("lilypads.util")
    local G = require("lilypads.groups")
    local groups = G.set_groups(palette_base, palette_ui, palette_text)

    vim.cmd.highlight("clear")
    for group, params in pairs(groups) do
        U.set_paint(group, params)
    end
end

return M
