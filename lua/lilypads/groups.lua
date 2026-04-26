local M = {}

local U = require("lilypads.util")

function M.set_groups(palette_base, palette_ui, palette_text)
    local b = palette_base
    local u = palette_ui
    local t = palette_text

    return {

        -- ---- ui highlight groups ----------------------------------------- --

        SpecialKey = {termfg = U.guitoterm(b.hi_radium), guifg = b.hi_radium};
        TermCursor = {sp = "reverse"};
        NonText = {termfg = U.guitoterm(b.lo_radium), guifg = b.lo_radium};
        Directory = {termfg = U.guitoterm(b.radium), guifg = b.radium};
        Search = {termfg = U.guitoterm(t.base), guifg = t.base, termbg = U.guitoterm(u.status_line), guibg = u.status_line};
        CurSearch = {termfg = U.guitoterm(b.radium), guifg = b.radium, termbg = U.guitoterm(u.status_line), guibg = u.status_line};
        MoreMsg = {termfg = U.guitoterm(b.radium), guifg = b.radium, sp = "bold"};
        ModeMsg = {link = "MoreMsg"};
        Question = {termfg = U.guitoterm(t.link), guifg = t.link};
        StatusLine = {termfg = U.guitoterm(t.base), guifg = t.base, termbg = U.guitoterm(u.status_line), guibg = u.status_line};
        StatusLineNC = {termfg = U.guitoterm(U.txt_nc(t.base)), guifg = U.txt_nc(t.base), termbg = U.guitoterm(U.col_nc(u.status_line)), guibg = U.col_nc(u.status_line)};
        WinSeparator = {termfg = U.guitoterm(u.base), guifg = u.base};
        VertSplit = {termfg = U.guitoterm(u.base), guifg = u.base};
        WinBar = {};
        WinBarNC = {};
        Conceal = {};
        LineNr = {termfg = U.guitoterm(t.line_nu), guifg = t.line_nu, termbg = U.guitoterm(u.line_nu), guibg = u.line_nu};
        CursorLineNr = {termfg = U.guitoterm(t.base), guifg = t.base, termbg = U.guitoterm(u.line_nu), guibg = u.line_nu};
        LineNrAbove = {termfg = U.guitoterm(b.dead), guifg = b.dead, termbg = U.guitoterm(u.line_nu), guibg = u.line_nu};
        LineNrBelow = {link = "LineNrAbove"};
        Cursor = {termbg = U.guitoterm(U.col_nc(u.status_line)), guibg = U.col_nc(u.status_line), sp = "reverse"};
        lCursor = {};
        CursorLine = {termbg = U.guitoterm(u.line_nu), guibg = u.line_nu};
        CursorColumn = {termbg = U.guitoterm(u.line_nu), guibg = u.line_nu};
        ColorColumn = {termbg = U.guitoterm(U.col_nc(u.base)), guibg = U.col_nc(u.base)};
        SignColumn = {termfg = U.guitoterm(b.radium), guifg = b.radium, termbg = U.guitoterm(u.line_nu), guibg = u.line_nu, sp = "bold"};
        Pmenu = {termfg = U.guitoterm(U.txt_nc(t.base)), guifg = U.txt_nc(t.base), termbg = U.guitoterm(U.col_nc(u.status_line)), guibg = U.col_nc(u.status_line)};
        PmenuSel = {termfg = U.guitoterm(U.txt_nc(t.base)), guifg = U.txt_nc(t.base), termbg = U.guitoterm(u.status_line), guibg = u.status_line};
        PmenuMatch = {};
        PmenuMatchSel = {};
        PmenuSbar = {termfg = U.guitoterm(U.txt_nc(t.base)), guifg = U.txt_nc(t.base), termbg = U.guitoterm(U.col_nc(u.status_line)), guibg = U.col_nc(u.status_line)};
        PmenuThumb = {termfg = U.guitoterm(t.base), guifg = t.base, termbg = U.guitoterm(u.status_line), guibg = u.status_line};
        TabLine = {termfg = U.guitoterm(U.txt_nc(t.base)), guifg = U.txt_nc(t.base), termbg = U.guitoterm(U.col_nc(u.base)), guibg = U.col_nc(u.base)};
        TabLineSel = {termfg = U.guitoterm(t.base), guifg = t.base, termbg = U.guitoterm(u.base), guibg = u.base};
        TabLineFill = {termbg = U.guitoterm(U.col_nc(u.base)), guibg = U.col_nc(u.base)};
        NormalNC = {termfg = U.guitoterm(t.base), guifg = t.base, termbg = U.guitoterm(U.col_ncl(u.base)), guibg = U.col_ncl(u.base)};
        NormalFloat = {};
        FloatBorder = {termfg = U.guitoterm(U.txt_nc(u.base)), guifg = U.txt_nc(u.base)};

        -- ---- syntax highlight groups ------------------------------------- --

        Title = {termfg = U.guitoterm(b.radium), guifg = b.radium};
        Visual = {termfg = U.guitoterm(b.radium), guifg = b.radium, termbg = U.guitoterm(b.visual), guibg = b.visual};
        Folded = {termfg = U.guitoterm(b.hi_radium), guifg = b.hi_radium};
        QuickFixLine = {link = "Question"};
        Underlined = {termfg = U.guitoterm(b.radium), guifg = b.radium, sp = "underline"};
        Todo = {termfg = U.guitoterm(b.radium), guifg = b.radium, termbg = U.guitoterm(b.visual), guibg = b.visual};

        -- ---- my favorite section ----------------------------------------- --

        Normal = {termfg = U.guitoterm(t.base), guifg = t.base, termbg = U.guitoterm(u.base), guibg = u.base};
        Number = {termfg = U.guitoterm(b.radium), guifg = b.radium};
        Character = {termfg = U.guitoterm(b.habitable), guifg = b.habitable};
        String = {link = "Character"};
        Statement = {termfg = U.guitoterm(b.base), guifg = b.base};
        PreProc = {link = "Statement"};
        Macro = {link = "Statement"};
        Include = {link = "Statement"};
        Define = {link = "Statement"};
        Type = {termfg = U.guitoterm(U.txt_nc(t.base)), guifg = U.txt_nc(t.base)};
        Operator = {link = "Type"};
        Delimiter = {link = "Type"};
        Special = {link = "Type"};
        Function = {termfg = U.guitoterm(t.base), guifg = t.base};
        Boolean = {link = "Function"};
        Constant = {termfg = U.guitoterm(b.mossy), guifg = b.mossy};
        Conditional = {termfg = U.guitoterm(b.dry1), guifg = b.dry1};
        Comment = {termfg = U.guitoterm(b.dead), guifg = b.dead};
        Identifier = {termfg = U.guitoterm(b.thirsty), guifg = b.thirsty};

        -- ---- diagnostic highlight groups --------------------------------- --

        Error = {termfg = U.guitoterm(t.light), guifg = t.light, termbg = U.guitoterm(t.error_alt), guibg = t.error_alt};
        ErrorMsg = {link = "Error"};
        WarningMsg = {termfg = U.guitoterm(t.warn), guifg = t.warn};
        NvimInternalError = {link = "Error"};
        DiagnosticDeprecated = {};
        DiagnosticError = {termfg = U.guitoterm(t.error), guifg = t.error};
        DiagnosticWarn = {termfg = U.guitoterm(t.warn), guifg = t.warn};
        DiagnosticInfo = {termfg = U.guitoterm(t.info), guifg = t.info};
        DiagnosticHint = {termfg = U.guitoterm(t.hint), guifg = t.hint};
        DiagnosticOk = {termfg = U.guitoterm(t.ok), guifg = t.ok};
        DiagnosticUnderlineError = {sp = "underline"};
        DiagnosticUnderlineWarn = {sp = "underline"};
        DiagnosticUnderlineInfo = {sp = "underline"};
        DiagnosticUnderlineHint = {sp = "underline"};
        DiagnosticUnderlineOk = {sp = "underline"};
        SpellBad = {sp = "undercurl"};
        SpellCap = {sp = "undercurl"};
        SpellRare = {sp = "undercurl"};
        SpellLocal = {sp = "undercurl"};

        DiffAdd = {termfg = U.guitoterm(t.diff_add_fg), guifg = t.diff_add_fg, termbg = U.guitoterm(t.diff_add_bg), guibg = t.diff_add_bg};
        DiffChange = {termfg = U.guitoterm(t.diff_change_fg), guifg = t.diff_change_fg, termbg = U.guitoterm(t.diff_change_bg), guibg = t.diff_change_bg};
        DiffDelete = {termfg = U.guitoterm(t.diff_delete_fg), guifg = t.diff_delete_fg, termbg = U.guitoterm(t.diff_delete_bg), guibg = t.diff_delete_bg};
        DiffText = {termfg = U.guitoterm(t.diff_text_fg), guifg = t.diff_text_fg, termbg = U.guitoterm(t.diff_text_bg), guibg = t.diff_text_bg};
        Added = {termfg = U.guitoterm(t.diff_add_fg), guifg = t.diff_add_fg};
        Removed = {termfg = U.guitoterm(t.diff_delete_fg), guifg = t.diff_delete_fg};
        Changed = {termfg = U.guitoterm(t.diff_text_fg), guifg = t.diff_text_fg};
        MatchParen = {termbg = U.guitoterm(u.status_line), guibg = u.status_line};
        RedrawDebugNormal = {};
        RedrawDebugClear = {termfg = U.guitoterm(t.light), guifg = t.light, termbg = U.guitoterm(b.dry0), guibg = b.dry0};
        RedrawDebugComposed = {termfg = U.guitoterm(t.light), guifg = t.light, termbg = U.guitoterm(b.mossy), guibg = b.mossy};
        RedrawDebugRecompose = {termfg = U.guitoterm(t.light), guifg = t.light, termbg = U.guitoterm(t.error_alt), guibg = t.error_alt};

        -- ---- other highlight groups -------------------------------------- --

        FloatShadow = {};
        FloatShadowThrough = {};
        NvimSpacing = {termfg = U.guitoterm(U.txt_nc(u.base)), guifg = U.txt_nc(u.base)};
        VimUserFunc = {link = "Function"};
        VimEmbedError = {termfg = U.guitoterm(t.base), guifg = t.base};
        CmpItemAbbrDefault = {termfg = U.guitoterm(t.info), guifg = t.info};
        CmpItemAbbrDeprecatedDefault = {termfg = U.guitoterm(t.info), guifg = t.info};
        CmpItemAbbrMatchDefault = {termfg = U.guitoterm(t.info), guifg = t.info};
        CmpItemAbbrMatchFuzzyDefault = {termfg = U.guitoterm(t.info), guifg = t.info};
        CmpItemKindDefault = {termfg = U.guitoterm(t.info), guifg = t.info};
        CmpItemMenuDefault = {termfg = U.guitoterm(t.info), guifg = t.info};

        -- ---- nvim-treesitter highlight groups ---------------------------- --

        ["@variable"] = {link = "Function"};
        ["@variable.builtin"] = {link = "Function"};
    }
end

return M
