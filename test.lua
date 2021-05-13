package.cpath = package.cpath .. ";./?.so"

local curses = require("curses")

--print(COLOR_MAGENTA, COLOR_RED, COLOR_BLACK, COLOR_YELLOW, COLOR_CYAN)

local screen = curses.initscr()
curses.move(2, 2)
curses.insch("A")
curses.addstr("hello this is a test string")
curses.mvaddstr(5, 40, "BONJOUR MADAME")
curses.box(screen, "|", "-")
curses.refresh()
curses.getch()
curses.clear()
curses.addstr(string.format("has colors? => %q\n", curses.has_colors()))
curses.refresh()
