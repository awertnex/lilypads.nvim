local M = {}

M.ui_dark = {
    base = "#1f1f1f",
    line_nu = "#242424",
    status_line = "#404040",
}

M.ui_light = {
    base = "#e6e6e6",
    line_nu = "#ebebeb",
    status_line = "#fafafa",
}

M.text_dark = {
    base = "#bcbcbc",
    base_alt = "#ececec",
    light = "#bcbcbc",
    light_alt = "#ececec",
    line_nu = "#7f888d",
    link = "#88f2eb",

    error = "#cc2935",
    error_alt = "#803e26",
    warn = "#cc5829",
    info = "#7acacc",
    hint = "#d0e6cf",
    ok = "#a2de89",

    diff_add_fg = "#aecca4",
    diff_change_fg = "#cccccc",
    diff_delete_fg = "#cca6a4",
    diff_text_fg = "#a4ccc9",
    diff_add_bg = "#4f7f3f",
    diff_change_bg = "#7f7f7f",
    diff_delete_bg = "#7f423f",
    diff_text_bg = "#3f7f7b",
}

M.text_light = {
    base = "#5a5a5a",
    base_alt = "#757575",
    light = "#bcbcbc",
    light_alt = "#ececec",
    line_nu = "#788085",
    link = "#0e9094",

    error = "#cc2935",
    error_alt = "#97492d",
    warn = "#cc5829",
    info = "#3d9c9f",
    hint = "#99b598",
    ok = "#52a72f",

    diff_add_fg = "#4f7f3f",
    diff_change_fg = "#7f7f7f",
    diff_delete_fg = "#7f423f",
    diff_text_fg = "#3f7f7b",
    diff_add_bg = "#aecca4",
    diff_change_bg = "#cccccc",
    diff_delete_bg = "#cca6a4",
    diff_text_bg = "#a4ccc9",
}

M.nature_dark = {
    base = "#348031",
    visual = "#2c521c",
    habitable = "#97b994",
    dry0 = "#807a26",
    dry1 = "#8e995c",
    thirsty = "#afccb1",
    mossy = "#5a802c",
    dead = "#4a4d4d",
    lo_radium = "#a2de89",
    radium = "#a4ed74",
    hi_radium = "#65ff00",
}

M.nature_dark_dead = {
    base = "#575a59",
    visual = "#363837",
    habitable = "#a6a7a7",
    dry0 = "#525452",
    dry1 = "#7a7b7a",
    thirsty = "#bdbebe",
    mossy = "#555756",
    dead = "#4a4d4d",
    lo_radium = "#b2b5b4",
    radium = "#cfedbb",
    hi_radium = "#7c837f"
}

M.nature_light = {
    base = "#317a2f",
    visual = "#c0d7be",
    habitable = "#6f9263",
    dry0 = "#64601e",
    dry1 = "#767f4c",
    thirsty = "#647565",
    mossy = "#5a802c",
    dead = "#979d9d",
    lo_radium = "#8bb679",
    radium = "#296800",
    hi_radium = "#0b1d00"
}

M.nature_light_dead = {
    base = "#535653",
    visual = "#cacbca",
    habitable = "#7a7b7a",
    dry0 = "#424240",
    dry1 = "#666665",
    thirsty = "#6c6d6c",
    mossy = "#565755",
    dead = "#979d9d",
    lo_radium = "#b2b5b4",
    radium = "#3a7100",
    hi_radium = "#0f1010"
}

M.cherry_dark = {
    base = "#b3533c",
    visual = "#76342c",
    habitable = "#d5a595",
    dry0 = "#7672b2",
    dry1 = "#9f8cb7",
    thirsty = "#d1c0cb",
    mossy = "#ba5456",
    dead = "#4d4c4a",
    lo_radium = "#ffb19e",
    radium = "#ffa295",
    hi_radium = "#ff4960"
}

M.cherry_dark_dead = {
    base = "#5b5957",
    visual = "#393736",
    habitable = "#a7a7a6",
    dry0 = "#565352",
    dry1 = "#7c7a7a",
    thirsty = "#bebebd",
    mossy = "#585655",
    dead = "#4d4c4a",
    lo_radium = "#b6b4b2",
    radium = "#ffd4ca",
    hi_radium = "#86807c"
}

M.cherry_light = {
    base = "#aa4f38",
    visual = "#ebc9be",
    habitable = "#b5796c",
    dry0 = "#94435f",
    dry1 = "#a96870",
    thirsty = "#816c63",
    mossy = "#ba5456",
    dead = "#9c9c98",
    lo_radium = "#e39687",
    radium = "#a1322f",
    hi_radium = "#2c1006"
}

M.cherry_light_dead = {
    base = "#585453",
    visual = "#cccaca",
    habitable = "#7c7a7a",
    dry0 = "#444142",
    dry1 = "#676666",
    thirsty = "#6e6c6c",
    mossy = "#595656",
    dead = "#9c9c98",
    lo_radium = "#b6b4b2",
    radium = "#b44744",
    hi_radium = "#10100f"
}

M.oceans_dark = {
    base = "#008594",
    visual = "#00565a",
    habitable = "#7abbc3",
    dry0 = "#008b63",
    dry1 = "#44a492",
    thirsty = "#9ecdd5",
    mossy = "#008982",
    dead = "#4c4c4e",
    lo_radium = "#20e6ec",
    radium = "#00f9fa",
    hi_radium = "#00ffff"
}

M.oceans_dark_dead = {
    base = "#575a5b",
    visual = "#363839",
    habitable = "#a7a7a7",
    dry0 = "#515455",
    dry1 = "#797b7b",
    thirsty = "#bebebe",
    mossy = "#555758",
    dead = "#4c4c4e",
    lo_radium = "#b2b5b6",
    radium = "#a2f3f2",
    hi_radium = "#7b8386"
}

M.oceans_light = {
    base = "#007e8e",
    visual = "#afd9de",
    habitable = "#3c969a",
    dry0 = "#006d4f",
    dry1 = "#398879",
    thirsty = "#5a767a",
    mossy = "#008982",
    dead = "#9a9ca0",
    lo_radium = "#46bcc0",
    radium = "#006f73",
    hi_radium = "#001f21"
}

M.oceans_light_dead = {
    base = "#515657",
    visual = "#c9cbcb",
    habitable = "#797b7b",
    dry0 = "#404242",
    dry1 = "#656666",
    thirsty = "#6b6d6d",
    mossy = "#545757",
    dead = "#9a9ca0",
    lo_radium = "#b2b5b6",
    radium = "#147b7f",
    hi_radium = "#101010"
}

return M
