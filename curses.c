/* $NetBSD$ */

#include <stdbool.h>

#include <curses.h>

#include <lua.h>
#include <lauxlib.h>

int luaopen_curses(lua_State *L);

#define DECLARE(x) static int curses_##x(lua_State *L)
#define WINDOW_LTYPE "WINDOW"

DECLARE(addch);
DECLARE(addstr);
DECLARE(attroff);
DECLARE(attron);
DECLARE(baudrate);
DECLARE(beep);
DECLARE(box);
DECLARE(cbreak);
DECLARE(clear);
DECLARE(curs_set);
DECLARE(delch);
DECLARE(deleteln);
DECLARE(echo);
DECLARE(endwin);
DECLARE(erase);
DECLARE(filter);
DECLARE(flash);
DECLARE(getbegx);
DECLARE(getbegy);
DECLARE(getch);
DECLARE(getcurx);
DECLARE(getcury);
DECLARE(getmaxx);
DECLARE(getmaxy);
DECLARE(getparx);
DECLARE(getpary);
DECLARE(getsyx);
DECLARE(halfdelay);
DECLARE(has_colors);
DECLARE(has_ic);
DECLARE(hline);
DECLARE(idlok);
DECLARE(initscr);
DECLARE(insch);
DECLARE(isendwin);
DECLARE(keypad);
DECLARE(meta);
DECLARE(move);
DECLARE(mvaddstr);
DECLARE(mvcur);
DECLARE(nl);
DECLARE(nocbreak);
DECLARE(noecho);
DECLARE(nonl);
DECLARE(noraw);
DECLARE(raw);
DECLARE(refresh);
DECLARE(resize_term);
DECLARE(resizeterm);
DECLARE(scrl);
DECLARE(scroll);
DECLARE(scrollok);
DECLARE(setsyx);
DECLARE(standend);
DECLARE(standout);
DECLARE(underend);
DECLARE(underscore);
DECLARE(vline);
DECLARE(wstandend);
DECLARE(wstandout);

/* ********** */

/*
 * result = addch(ch)
 */
DECLARE(addch)
{
	const char *ch = luaL_checkstring(L, 1);
	lua_pushinteger(L, addch(ch[0]));
	return 1;
}


/*
 * result = addstr(string)
 */
DECLARE(addstr)
{
	const char *string = luaL_checkstring(L, 1);
	lua_pushinteger(L, addstr(string));
	return 1;
}


/*
 * result = attroff(attr)
 */
DECLARE(attroff)
{
	int attr = luaL_checkinteger(L, 1);
	lua_pushinteger(L, attroff(attr));
	return 1;
}


/*
 * result = attron(attr)
 */
DECLARE(attron)
{
	int attr = luaL_checkinteger(L, 1);
	lua_pushinteger(L, attron(attr));
	return 1;
}


/*
 * bits_per_second = baudrate()
 */
DECLARE(baudrate)
{
	lua_pushinteger(L, baudrate());
	return 1;
}


/*
 * result = beep()
 */
DECLARE(beep)
{
	lua_pushinteger(L, beep());
	return 1;
}


/*
 * result = box(window, vertical, horizontal)
 */
DECLARE(box)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	const char *vert = luaL_checkstring(L, 2);
	const char *horiz = luaL_checkstring(L, 3);
	lua_pushinteger(L, box(*window, vert[0], horiz[0]));
	return 1;
}


/*
 * result = cbreak()
 */
DECLARE(cbreak)
{
	lua_pushinteger(L, cbreak());
	return 1;
}


/*
 * result = clear()
 */
DECLARE(clear)
{
	lua_pushinteger(L, clear());
	return 1;
}


/*
 * result = curs_set(visibility)
 */
DECLARE(curs_set)
{
	int visibility = luaL_checkinteger(L, 1);
	lua_pushinteger(L, curs_set(visibility));
	return 1;
}


/*
 * result = delch()
 */
DECLARE(delch)
{
	lua_pushinteger(L, delch());
	return 1;
}


/*
 * result = deleteln
 */
DECLARE(deleteln)
{
	lua_pushinteger(L, deleteln());
	return 1;
}


/*
 * result = echo()
 */
DECLARE(echo)
{
	lua_pushinteger(L, echo());
	return 1;
}


/*
 * result = endwin()
 */
DECLARE(endwin)
{
	lua_pushinteger(L, endwin());
	return 1;
}


/*
 * result = erase()
 */
DECLARE(erase)
{
	lua_pushinteger(L, erase());
	return 1;
}


/*
 * filter()
 */
DECLARE(filter)
{
	filter();
	return 0;
}


/*
 * result = flash()
 */
DECLARE(flash)
{
	lua_pushinteger(L, flash());
	return 1;
}


/*
 * x = getbegx(window)
 */
DECLARE(getbegx)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	lua_pushinteger(L, getbegx(*window));
	return 1;
}


/*
 * y = getbegy(window)
 */
DECLARE(getbegy)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	lua_pushinteger(L, getbegy(*window));
	return 1;
}
 

/*
 * result = getch()
 */
DECLARE(getch)
{
	lua_pushinteger(L, getch());
	return 1;
}


/*
 * x = getcurx(window)
 */
DECLARE(getcurx)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	lua_pushinteger(L, getcurx(*window));
	return 1;
}


/*
 * y = getcury(window)
 */
DECLARE(getcury)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	lua_pushinteger(L, getcury(*window));
	return 1;
}


/*
 * x = getmaxx(window)
 */
DECLARE(getmaxx)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	lua_pushinteger(L, getmaxx(*window));
	return 1;
}


/*
 * y = getmaxy(window)
 */
DECLARE(getmaxy)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	lua_pushinteger(L, getmaxy(*window));
	return 1;
}


/*
 * x = getparx(window)
 */
DECLARE(getparx)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	lua_pushinteger(L, getparx(*window));
	return 1;
}


/*
 * y = getpary(window)
 */
DECLARE(getpary)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	lua_pushinteger(L, getpary(*window));
	return 1;
}


/*
 * y, x = getsyx()
 */
DECLARE(getsyx)
{
	int y;
	int x;
	getsyx(y, x);
	lua_pushinteger(L, y);
	lua_pushinteger(L, x);
	return 2;
}


/*
 * result = halfdelay(count)
 */
DECLARE(halfdelay)
{
	int count = luaL_checkinteger(L, 1);
	lua_pushinteger(L, halfdelay(count));
	return 1;
}


/*
 * result = has_colors()
 */
DECLARE(has_colors)
{
	lua_pushboolean(L, has_colors());
	return 1;
}


/*
 * bool = has_ic()
 */
DECLARE(has_ic)
{
	lua_pushboolean(L, has_ic());
	return 1;
}


/*
 * result = hline(char, n)
 */
DECLARE(hline)
{
	const char *ch = luaL_checkstring(L, 1);
	int n = luaL_checkinteger(L, 2);
	lua_pushinteger(L, hline(ch[0], n));
	return 1;
}


/*
 * result = idlok(window, bool)
 */
DECLARE(idlok)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	luaL_checktype(L, 2, LUA_TBOOLEAN);
	bool flag = lua_toboolean(L, 2);
	lua_pushinteger(L, idlok(*window, flag));
	return 1;
}


/*
 * window = initscr()
 */
DECLARE(initscr)
{
	WINDOW **window = lua_newuserdata(L, sizeof(WINDOW*));
	luaL_setmetatable(L, WINDOW_LTYPE);
	*window = initscr();
	return 1;
}


/*
 * result = insch(char)
 */
DECLARE(insch)
{
	const char *str = luaL_checkstring(L, 1);
	lua_pushinteger(L, insch(str[0]));
	return 1;
}


/*
 * bool = isendwin()
 */
DECLARE(isendwin)
{
	lua_pushboolean(L, isendwin());
	return 1;
}


/*
 * bool = keypad(window, bool)
 */
DECLARE(keypad)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	luaL_checktype(L, 2, LUA_TBOOLEAN);
	bool flag = lua_toboolean(L, 2);
	lua_pushinteger(L, keypad(*window, flag));
	return 1;
}



/*
 * result = meta(window, bool)
 */
DECLARE(meta)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	luaL_checktype(L, 2, LUA_TBOOLEAN);
	bool flag = lua_toboolean(L, 2);
	lua_pushinteger(L, meta(*window, flag));
	return 1;
}


/*
 * result = move(y, x)
 */
DECLARE(move)
{
	int y = luaL_checkinteger(L, 1);
	int x = luaL_checkinteger(L, 2);
	lua_pushinteger(L, move(y, x));
	return 1;
}


/*
 * result = mvaddstr(y, x, string)
 */
DECLARE(mvaddstr)
{
	int y = luaL_checkinteger(L, 1);
	int x = luaL_checkinteger(L, 2);
	const char *string = luaL_checkstring(L, 3);
	lua_pushinteger(L, mvaddstr(y, x, string));
	return 1;
}


/*
 * result = mvcur(oldy, oldx, y, x)
 */
DECLARE(mvcur)
{
	int oldy = luaL_checkinteger(L, 1);
	int oldx = luaL_checkinteger(L, 2);
	int y = luaL_checkinteger(L, 3);
	int x = luaL_checkinteger(L, 4);
	lua_pushinteger(L, mvcur(oldy, oldx, y, x));
	return 1;
}


/*
 * result = nl()
 */
DECLARE(nl)
{
	lua_pushinteger(L, nl());
	return 1;
}


/*
 * result = nocbreak()
 */
DECLARE(nocbreak)
{
	lua_pushinteger(L, nocbreak());
	return 1;
}


/*
 * result = noecho()
 */
DECLARE(noecho)
{
	lua_pushinteger(L, noecho());
	return 1;
}


/*
 * result = nonl()
 */
DECLARE(nonl)
{
	lua_pushinteger(L, nonl());
	return 1;
}


/*
 * result = noraw()
 */
DECLARE(noraw)
{
	lua_pushinteger(L, noraw());
	return 1;
}


/*
 * result = raw()
 */
DECLARE(raw)
{
	lua_pushinteger(L, raw());
	return 1;
}


/*
 * result = refresh()
 */
DECLARE(refresh)
{
	lua_pushinteger(L, refresh());
	return 1;
}


/*
 * result = resize_term(lines, cols)
 */
DECLARE(resize_term)
{
	int lines = luaL_checkinteger(L, 1);
	int cols = luaL_checkinteger(L, 2);
	lua_pushinteger(L, resize_term(lines, cols));
	return 1;
}


/*
 * resizeterm(lines, cols)
 */
DECLARE(resizeterm)
{
	int lines = luaL_checkinteger(L, 1);
	int cols = luaL_checkinteger(L, 2);
	lua_pushinteger(L, resizeterm(lines, cols));
	return 1;
}


/*
 * result = scrl(n)
 */
DECLARE(scrl)
{
	int n = luaL_checkinteger(L, 1);
	lua_pushinteger(L, scrl(n));
	return 1;
}


/*
 * result = scroll(window)
 */
DECLARE(scroll)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	lua_pushinteger(L, scroll(*window));
	return 1;
}


/*
 * result = scrollok(window, bool)
 */
DECLARE(scrollok)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	luaL_checktype(L, 2, LUA_TBOOLEAN);
	bool flag = lua_toboolean(L, 2); 
	lua_pushinteger(L, scrollok(*window, flag));
	return 1;
}


/*
 * setsyx(y, x)
 */
DECLARE(setsyx)
{
	int y = luaL_checkinteger(L, 1);
	int x = luaL_checkinteger(L, 2);
	setsyx(y, x);
	return 0;
}


/*
 * result = standend()
 */
DECLARE(standend)
{
	lua_pushinteger(L, standend());
	return 1;
}


/*
 * result = standout()
 */
DECLARE(standout)
{
	lua_pushinteger(L, standout());
	return 1;
}


/*
 * result = underend()
 */
DECLARE(underend)
{
	lua_pushinteger(L, underend());
	return 1;
}


/*
 * result = underscore()
 */
DECLARE(underscore)
{
	lua_pushinteger(L, underscore());
	return 1;
}


/*
 * result = vline(char, n)
 */
DECLARE(vline)
{
	const char *ch = luaL_checkstring(L, 1);
	int n = luaL_checkinteger(L, 2);
	lua_pushinteger(L, vline(ch[0], n));
	return 1;
}


/*
 * result = wstandend(window)
 */
DECLARE(wstandend)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	lua_pushinteger(L, wstandend(*window));
	return 1;
}


/*
 * result = wstandout(window)
 */
DECLARE(wstandout)
{
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);
	lua_pushinteger(L, wstandout(*window));
	return 1;
}

#undef DECLARE

/* ********** */

int
luaopen_curses(lua_State *L)
{
	luaL_newmetatable(L, WINDOW_LTYPE);

#define CONSTANT(x) {#x, x}

	struct {
		const char *name;
		int value;
	} constants[] = {
		CONSTANT(A_ALTCHARSET),
		CONSTANT(A_ATTRIBUTES),
		CONSTANT(A_BLANK),
		CONSTANT(A_BLINK),
		CONSTANT(A_BOLD),
		CONSTANT(A_CHARTEXT),
		CONSTANT(A_COLOR),
		CONSTANT(A_DIM),
		CONSTANT(A_INVIS),
		CONSTANT(A_NORMAL),
		CONSTANT(A_PROTECT),
		CONSTANT(A_REVERSE),
		CONSTANT(A_STANDOUT),
		CONSTANT(A_UNDERLINE),
		CONSTANT(COLOR_BLACK),
		CONSTANT(COLOR_BLUE),
		CONSTANT(COLOR_CYAN),
		CONSTANT(COLOR_GREEN),
		CONSTANT(COLOR_MAGENTA),
		CONSTANT(COLOR_RED),
		CONSTANT(COLOR_WHITE),
		CONSTANT(COLOR_YELLOW),
		CONSTANT(ERR),
		CONSTANT(KEY_A1),
		CONSTANT(KEY_A3),
		CONSTANT(KEY_B2),
		CONSTANT(KEY_BACKSPACE),
		CONSTANT(KEY_BEG),
		CONSTANT(KEY_BREAK),
		CONSTANT(KEY_BTAB),
		CONSTANT(KEY_C1),
		CONSTANT(KEY_C3),
		CONSTANT(KEY_CANCEL),
		CONSTANT(KEY_CATAB),
		CONSTANT(KEY_CLEAR),
		CONSTANT(KEY_CLOSE),
		CONSTANT(KEY_CODE_YES),
		CONSTANT(KEY_COMMAND),
		CONSTANT(KEY_COPY),
		CONSTANT(KEY_CREATE),
		CONSTANT(KEY_CTAB),
		CONSTANT(KEY_DC),
		CONSTANT(KEY_DL),
		CONSTANT(KEY_DOWN),
		CONSTANT(KEY_EIC),
		CONSTANT(KEY_END),
		CONSTANT(KEY_ENTER),
		CONSTANT(KEY_EOL),
		CONSTANT(KEY_EOS),
		CONSTANT(KEY_EXIT),
		CONSTANT(KEY_FIND),
		CONSTANT(KEY_HELP),
		CONSTANT(KEY_HOME),
		CONSTANT(KEY_IC),
		CONSTANT(KEY_IL),
		CONSTANT(KEY_LEFT),
		CONSTANT(KEY_LL),
		CONSTANT(KEY_MARK),
		CONSTANT(KEY_MAX),
		CONSTANT(KEY_MESSAGE),
		CONSTANT(KEY_MIN),
		CONSTANT(KEY_MOUSE),
		CONSTANT(KEY_MOVE),
		CONSTANT(KEY_NEXT),
		CONSTANT(KEY_NPAGE),
		CONSTANT(KEY_OPEN),
		CONSTANT(KEY_OPTIONS),
		CONSTANT(KEY_PPAGE),
		CONSTANT(KEY_PREVIOUS),
		CONSTANT(KEY_PRINT),
		CONSTANT(KEY_REDO),
		CONSTANT(KEY_REFERENCE),
		CONSTANT(KEY_REFRESH),
		CONSTANT(KEY_REPLACE),
		CONSTANT(KEY_RESET),
		CONSTANT(KEY_RESIZE),
		CONSTANT(KEY_RESTART),
		CONSTANT(KEY_RESUME),
		CONSTANT(KEY_RIGHT),
		CONSTANT(KEY_SAVE),
		CONSTANT(KEY_SBEG),
		CONSTANT(KEY_SCANCEL),
		CONSTANT(KEY_SCOMMAND),
		CONSTANT(KEY_SCOPY),
		CONSTANT(KEY_SCREATE),
		CONSTANT(KEY_SDC),
		CONSTANT(KEY_SDL),
		CONSTANT(KEY_SELECT),
		CONSTANT(KEY_SEND),
		CONSTANT(KEY_SEOL),
		CONSTANT(KEY_SEXIT),
		CONSTANT(KEY_SF),
		CONSTANT(KEY_SFIND),
		CONSTANT(KEY_SHELP),
		CONSTANT(KEY_SHOME),
		CONSTANT(KEY_SIC),
		CONSTANT(KEY_SLEFT),
		CONSTANT(KEY_SMESSAGE),
		CONSTANT(KEY_SMOVE),
		CONSTANT(KEY_SNEXT),
		CONSTANT(KEY_SOPTIONS),
		CONSTANT(KEY_SPREVIOUS),
		CONSTANT(KEY_SPRINT),
		CONSTANT(KEY_SR),
		CONSTANT(KEY_SREDO),
		CONSTANT(KEY_SREPLACE),
		CONSTANT(KEY_SRESET),
		CONSTANT(KEY_SRIGHT),
		CONSTANT(KEY_SRSUME),
		CONSTANT(KEY_SSAVE),
		CONSTANT(KEY_SSUSPEND),
		CONSTANT(KEY_STAB),
		CONSTANT(KEY_SUNDO),
		CONSTANT(KEY_SUSPEND),
		CONSTANT(KEY_UNDO),
		CONSTANT(KEY_UP),
		CONSTANT(OK),
		{NULL, 0},
	};

#undef CONSTANT

	for (int i = 0; constants[i].name; i++) {
		lua_pushinteger(L, constants[i].value);
		lua_setglobal(L, constants[i].name);
	}


#define BINDING(x) {#x, curses_##x}

	struct luaL_Reg functions[] = {
		BINDING(addch),
		BINDING(addstr),
		BINDING(attroff),
		BINDING(attron),
		BINDING(baudrate),
		BINDING(beep),
		BINDING(box),
		BINDING(cbreak),
		BINDING(clear),
		BINDING(curs_set),
		BINDING(delch),
		BINDING(deleteln),
		BINDING(echo),
		BINDING(endwin),
		BINDING(erase),
		BINDING(filter),
		BINDING(flash),
		BINDING(getbegx),
		BINDING(getbegy),
		BINDING(getch),
		BINDING(getcurx),
		BINDING(getcury),
		BINDING(getmaxx),
		BINDING(getmaxy),
		BINDING(getparx),
		BINDING(getpary),
		BINDING(getsyx),
		BINDING(halfdelay),
		BINDING(has_colors),
		BINDING(has_ic),
		BINDING(hline),
		BINDING(idlok),
		BINDING(initscr),
		BINDING(insch),
		BINDING(isendwin),
		BINDING(keypad),
		BINDING(meta),
		BINDING(move),
		BINDING(mvaddstr),
		BINDING(mvcur),
		BINDING(nl),
		BINDING(nocbreak),
		BINDING(noecho),
		BINDING(nonl),
		BINDING(noraw),
		BINDING(raw),
		BINDING(refresh),
		BINDING(resize_term),
		BINDING(resizeterm),
		BINDING(scrl),
		BINDING(scroll),
		BINDING(scrollok),
		BINDING(setsyx),
		BINDING(standend),
		BINDING(standout),
		BINDING(underend),
		BINDING(underscore),
		BINDING(vline),
		BINDING(wstandend),
		BINDING(wstandout),
		{NULL, NULL},
	};

#undef BINDING

#if LUA_VERSION_NUM >= 502
	luaL_newlib(L, functions);
#else
	luaL_register(L, "curses", functions);
#endif

	return 1;
}
