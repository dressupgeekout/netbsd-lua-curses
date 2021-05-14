/* $NetBSD$ */

#include <stdbool.h>

#include <curses.h>

#include <lua.h>
#include <lauxlib.h>

int luaopen_curses(lua_State *L);

static int curses_addch(lua_State *L);
static int curses_addstr(lua_State *L);
static int curses_baudrate(lua_State *L);
static int curses_beep(lua_State *L);
static int curses_box(lua_State *L);
static int curses_cbreak(lua_State *L);
static int curses_clear(lua_State *L);
static int curses_curs_set(lua_State *L);
static int curses_echo(lua_State *L);
static int curses_endwin(lua_State *L);
static int curses_filter(lua_State *L);
static int curses_flash(lua_State *L);
static int curses_getbegx(lua_State *L);
static int curses_getbegy(lua_State *L);
static int curses_getch(lua_State *L);
static int curses_getcurx(lua_State *L);
static int curses_getcury(lua_State *L);
static int curses_getmaxx(lua_State *L);
static int curses_getmaxy(lua_State *L);
static int curses_getparx(lua_State *L);
static int curses_getpary(lua_State *L);
static int curses_getsyx(lua_State *L);
static int curses_halfdelay(lua_State *L);
static int curses_has_colors(lua_State *L);
static int curses_has_ic(lua_State *L);
static int curses_hline(lua_State *L);
static int curses_initscr(lua_State *L);
static int curses_insch(lua_State *L);
static int curses_isendwin(lua_State *L);
static int curses_meta(lua_State *L);
static int curses_move(lua_State *L);
static int curses_mvaddstr(lua_State *L);
static int curses_mvcur(lua_State *L);
static int curses_nl(lua_State *L);
static int curses_nocbreak(lua_State *L);
static int curses_noecho(lua_State *L);
static int curses_nonl(lua_State *L);
static int curses_noraw(lua_State *L);
static int curses_raw(lua_State *L);
static int curses_refresh(lua_State *L);
static int curses_resize_term(lua_State *L);
static int curses_resizeterm(lua_State *L);
static int curses_scroll(lua_State *L);
static int curses_scrollok(lua_State *L);
static int curses_setsyx(lua_State *L);
static int curses_standend(lua_State *L);
static int curses_standout(lua_State *L);
static int curses_vline(lua_State *L);
static int curses_wstandend(lua_State *L);
static int curses_wstandout(lua_State *L);

/* ********** */

/*
 * result = addch(ch)
 */
static int
curses_addch(lua_State *L)
{
	const char *ch = luaL_checkstring(L, 1);
	lua_pushinteger(L, addch(ch[0]));
	return 1;
}


/*
 * result = addstr(string)
 */
static int
curses_addstr(lua_State *L)
{
	const char *string = luaL_checkstring(L, 1);
	lua_pushinteger(L, addstr(string));
	return 1;
}


/*
 * bits_per_second = baudrate()
 */
static int
curses_baudrate(lua_State *L)
{
	lua_pushinteger(L, baudrate());
	return 1;
}


/*
 * result = beep()
 */
static int curses_beep(lua_State *L)
{
	lua_pushinteger(L, beep());
	return 1;
}


/*
 * result = box(window, vertical, horizontal)
 */
static int
curses_box(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	const char *vert = luaL_checkstring(L, 2);
	const char *horiz = luaL_checkstring(L, 3);
	lua_pushinteger(L, box(*window, vert[0], horiz[0]));
	return 1;
}


/*
 * result = cbreak()
 */
static int
curses_cbreak(lua_State *L)
{
	lua_pushinteger(L, cbreak());
	return 1;
}


/*
 * result = clear()
 */
static int
curses_clear(lua_State *L)
{
	lua_pushinteger(L, clear());
	return 1;
}


/*
 * result = curs_set(visibility)
 */
static int
curses_curs_set(lua_State *L)
{
	int visibility = luaL_checkinteger(L, 1);
	lua_pushinteger(L, curs_set(visibility));
	return 1;
}


/*
 * result = echo()
 */
static int
curses_echo(lua_State *L)
{
	lua_pushinteger(L, echo());
	return 1;
}


/*
 * result = endwin()
 */
static int
curses_endwin(lua_State *L)
{
	lua_pushinteger(L, endwin());
	return 1;
}


/*
 * filter()
 */
static int
curses_filter(lua_State *L)
{
	filter();
	return 0;
}


/*
 * result = flash()
 */
static int
curses_flash(lua_State *L)
{
	lua_pushinteger(L, flash());
	return 1;
}


/*
 * x = getbegx(window)
 */
static int
curses_getbegx(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	lua_pushinteger(L, getbegx(*window));
	return 1;
}


/*
 * y = getbegy(window)
 */
static int
curses_getbegy(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	lua_pushinteger(L, getbegy(*window));
	return 1;
}
 

/*
 * result = getch()
 */
static int
curses_getch(lua_State *L)
{
	lua_pushinteger(L, getch());
	return 1;
}


/*
 * x = getcurx(window)
 */
static int
curses_getcurx(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	lua_pushinteger(L, getcurx(*window));
	return 1;
}


/*
 * y = getcury(window)
 */
static int
curses_getcury(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	lua_pushinteger(L, getcury(*window));
	return 1;
}


/*
 * x = getmaxx(window)
 */
static int
curses_getmaxx(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	lua_pushinteger(L, getmaxx(*window));
	return 1;
}


/*
 * y = getmaxy(window)
 */
static int
curses_getmaxy(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	lua_pushinteger(L, getmaxy(*window));
	return 1;
}


/*
 * x = getparx(window)
 */
static int
curses_getparx(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	lua_pushinteger(L, getparx(*window));
	return 1;
}


/*
 * y = getpary(window)
 */
static int
curses_getpary(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	lua_pushinteger(L, getpary(*window));
	return 1;
}


/*
 * y, x = getsyx()
 */
static int
curses_getsyx(lua_State *L)
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
static int
curses_halfdelay(lua_State *L)
{
	int count = luaL_checkinteger(L, 1);
	lua_pushinteger(L, halfdelay(count));
	return 1;
}


/*
 * result = has_colors()
 */
static int
curses_has_colors(lua_State *L)
{
	lua_pushboolean(L, has_colors());
	return 1;
}


/*
 * bool = has_ic()
 */
static int
curses_has_ic(lua_State *L)
{
	lua_pushboolean(L, has_ic());
	return 1;
}


/*
 * result = hline(char, n)
 */
static int
curses_hline(lua_State *L)
{
	const char *ch = luaL_checkstring(L, 1);
	int n = luaL_checkinteger(L, 2);
	lua_pushinteger(L, hline(ch[0], n));
	return 1;
}


/*
 * window = initscr()
 */
static int
curses_initscr(lua_State *L)
{
	WINDOW **window = lua_newuserdata(L, sizeof(WINDOW*));
	luaL_setmetatable(L, "WINDOW");
	*window = initscr();
	return 1;
}


/*
 * result = insch(char)
 */
static int
curses_insch(lua_State *L)
{
	const char *str = luaL_checkstring(L, 1);
	lua_pushinteger(L, insch(str[0]));
	return 1;
}


/*
 * bool = isendwin()
 */
static int
curses_isendwin(lua_State *L)
{
	lua_pushboolean(L, isendwin());
	return 1;
}


/*
 * result = meta(window, bool)
 */
static int
curses_meta(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	luaL_checktype(L, 2, LUA_TBOOLEAN);
	bool flag = lua_toboolean(L, 2);
	lua_pushinteger(L, meta(*window, flag));
	return 1;
}


/*
 * result = move(y, x)
 */
static int
curses_move(lua_State *L)
{
	int y = luaL_checkinteger(L, 1);
	int x = luaL_checkinteger(L, 2);
	lua_pushinteger(L, move(y, x));
	return 1;
}


/*
 * result = mvaddstr(y, x, string)
 */
static int
curses_mvaddstr(lua_State *L)
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
static int
curses_mvcur(lua_State *L)
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
static int
curses_nl(lua_State *L)
{
	lua_pushinteger(L, nl());
	return 1;
}


/*
 * result = nocbreak()
 */
static int
curses_nocbreak(lua_State *L)
{
	lua_pushinteger(L, nocbreak());
	return 1;
}


/*
 * result = noecho()
 */
static int
curses_noecho(lua_State *L)
{
	lua_pushinteger(L, noecho());
	return 1;
}


/*
 * result = nonl()
 */
static int
curses_nonl(lua_State *L)
{
	lua_pushinteger(L, nonl());
	return 1;
}


/*
 * result = noraw()
 */
static int
curses_noraw(lua_State *L)
{
	lua_pushinteger(L, noraw());
	return 1;
}


/*
 * result = raw()
 */
static int
curses_raw(lua_State *L)
{
	lua_pushinteger(L, raw());
	return 1;
}


/*
 * result = refresh()
 */
static int
curses_refresh(lua_State *L)
{
	lua_pushinteger(L, refresh());
	return 1;
}


/*
 * result = resize_term(lines, cols)
 */
static int curses_resize_term(lua_State *L)
{
	int lines = luaL_checkinteger(L, 1);
	int cols = luaL_checkinteger(L, 2);
	lua_pushinteger(L, resize_term(lines, cols));
	return 1;
}


/*
 * resizeterm(lines, cols)
 */
static int
curses_resizeterm(lua_State *L)
{
	int lines = luaL_checkinteger(L, 1);
	int cols = luaL_checkinteger(L, 2);
	lua_pushinteger(L, resizeterm(lines, cols));
	return 1;
}


/*
 * result = scroll(window)
 */
static int
curses_scroll(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	lua_pushinteger(L, scroll(*window));
	return 1;
}


/*
 * result = scrollok(window, bool)
 */
static int
curses_scrollok(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	luaL_checktype(L, 2, LUA_TBOOLEAN);
	bool flag = lua_toboolean(L, 2); 
	lua_pushinteger(L, scrollok(*window, flag));
	return 1;
}


/*
 * setsyx(y, x)
 */
static int
curses_setsyx(lua_State *L)
{
	int y = luaL_checkinteger(L, 1);
	int x = luaL_checkinteger(L, 2);
	setsyx(y, x);
	return 0;
}


/*
 * result = standend()
 */
static int
curses_standend(lua_State *L)
{
	lua_pushinteger(L, standend());
	return 1;
}


/*
 * result = standout()
 */
static int
curses_standout(lua_State *L)
{
	lua_pushinteger(L, standout());
	return 1;
}


/*
 * result = vline(char, n)
 */
static int
curses_vline(lua_State *L)
{
	const char *ch = luaL_checkstring(L, 1);
	int n = luaL_checkinteger(L, 2);
	lua_pushinteger(L, vline(ch[0], n));
	return 1;
}


/*
 * result = wstandend(window)
 */
static int
curses_wstandend(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	lua_pushinteger(L, wstandend(*window));
	return 1;
}


/*
 * result = wstandout(window)
 */
static int
curses_wstandout(lua_State *L)
{
	WINDOW **window = luaL_checkudata(L, 1, "WINDOW");
	lua_pushinteger(L, wstandout(*window));
	return 1;
}

/* ********** */

int
luaopen_curses(lua_State *L)
{
	luaL_newmetatable(L, "WINDOW");

	struct {
		const char *name;
		int value;
	} constants[] = {
		{"COLOR_BLACK", COLOR_BLACK},
		{"COLOR_RED", COLOR_RED},
		{"COLOR_GREEN", COLOR_GREEN},
		{"COLOR_YELLOW", COLOR_YELLOW},
		{"COLOR_BLUE", COLOR_BLUE},
		{"COLOR_MAGENTA", COLOR_MAGENTA},
		{"COLOR_CYAN", COLOR_CYAN},
		{"COLOR_WHITE", COLOR_WHITE},
		{NULL, 0},
	};

	for (int i = 0; constants[i].name; i++) {
		lua_pushinteger(L, constants[i].value);
		lua_setglobal(L, constants[i].name);
	}

	struct luaL_Reg functions[] = {
		{"addch", curses_addch},
		{"addstr", curses_addstr},
		{"baudrate", curses_baudrate},
		{"beep", curses_beep},
		{"box", curses_box},
		{"cbreak", curses_cbreak},
		{"clear", curses_clear},
		{"curs_set", curses_curs_set},
		{"echo", curses_echo},
		{"endwin", curses_endwin},
		{"filter", curses_filter},
		{"flash", curses_flash},
		{"getbegx", curses_getbegx},
		{"getbegy", curses_getbegy},
		{"getch", curses_getch},
		{"getcurx", curses_getcurx},
		{"getcury", curses_getcury},
		{"getmaxx", curses_getmaxx},
		{"getmaxy", curses_getmaxy},
		{"getparx", curses_getparx},
		{"getpary", curses_getpary},
		{"getsyx", curses_getsyx},
		{"halfdelay", curses_halfdelay},
		{"has_colors", curses_has_colors},
		{"has_ic", curses_has_ic},
		{"hline", curses_hline},
		{"initscr", curses_initscr},
		{"insch", curses_insch},
		{"isendwin", curses_isendwin},
		{"meta", curses_meta},
		{"move", curses_move},
		{"mvaddstr", curses_mvaddstr},
		{"mvcur", curses_mvcur},
		{"nl", curses_nl},
		{"nocbreak", curses_nocbreak},
		{"noecho", curses_noecho},
		{"nonl", curses_nonl},
		{"noraw", curses_noraw},
		{"raw", curses_raw},
		{"refresh", curses_refresh},
		{"resize_term", curses_resize_term},
		{"resizeterm", curses_resizeterm},
		{"scroll", curses_scroll},
		{"scrollok", curses_scrollok},
		{"setsyx", curses_setsyx},
		{"standend", curses_standend},
		{"standout", curses_standout},
		{"vline", curses_vline},
		{"wstandend", curses_wstandend},
		{"wstandout", curses_wstandout},
		{NULL, NULL},
	};

#if LUA_VERSION_NUM >= 502
	luaL_newlib(L, functions);
#else
	luaL_register(L, "curses", functions);
#endif

	return 1;
}
