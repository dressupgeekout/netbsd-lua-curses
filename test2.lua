package.cpath = package.cpath .. ";./?.so"

local curses = require("curses")

local screen = curses.initscr()

curses.border("A", "B", "C", "D", "E", "F", "G", "H")

--curses.border(
	--curses.ACS_DIAMOND, curses.ACS_LANTERN,
	--curses.ACS_DIAMOND, curses.ACS_LANTERN,
	--curses.ACS_DIAMOND, curses.ACS_LANTERN,
	--curses.ACS_DIAMOND, curses.ACS_LANTERN
--)

curses.getch()

curses.refresh()
curses.endwin()
