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
DECLARE(baudrate);
DECLARE(beep);
DECLARE(box);
DECLARE(cbreak);
DECLARE(clear);
DECLARE(curs_set);
DECLARE(echo);
DECLARE(endwin);
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
DECLARE(initscr);
DECLARE(insch);
DECLARE(isendwin);
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
DECLARE(scroll);
DECLARE(scrollok);
DECLARE(setsyx);
DECLARE(standend);
DECLARE(standout);
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
		BINDING(baudrate),
		BINDING(beep),
		BINDING(box),
		BINDING(cbreak),
		BINDING(clear),
		BINDING(curs_set),
		BINDING(echo),
		BINDING(endwin),
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
		BINDING(initscr),
		BINDING(insch),
		BINDING(isendwin),
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
		BINDING(scroll),
		BINDING(scrollok),
		BINDING(setsyx),
		BINDING(standend),
		BINDING(standout),
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
