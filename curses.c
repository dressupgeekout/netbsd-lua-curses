/* $NetBSD$ */

#include <stdbool.h>

#include <curses.h>

#include <lua.h>
#include <lauxlib.h>

int luaopen_curses(lua_State *L);

static int curses_addch(lua_State *L);
static int curses_addstr(lua_State *L);
static int curses_box(lua_State *L);
static int curses_clear(lua_State *L);
static int curses_echo(lua_State *L);
static int curses_flash(lua_State *L);
static int curses_getch(lua_State *L);
static int curses_getcurx(lua_State *L);
static int curses_getcury(lua_State *L);
static int curses_has_colors(lua_State *L);
static int curses_hline(lua_State *L);
static int curses_initscr(lua_State *L);
static int curses_insch(lua_State *L);
static int curses_move(lua_State *L);
static int curses_mvaddstr(lua_State *L);
static int curses_nl(lua_State *L);
static int curses_noecho(lua_State *L);
static int curses_nonl(lua_State *L);
static int curses_refresh(lua_State *L);
static int curses_scroll(lua_State *L);
static int curses_scrollok(lua_State *L);
static int curses_vline(lua_State *L);

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
 * result = clear()
 */
static int
curses_clear(lua_State *L)
{
	lua_pushinteger(L, clear());
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
 * result = flash()
 */
static int
curses_flash(lua_State *L)
{
	lua_pushinteger(L, flash());
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
 * result = has_colors()
 */
static int
curses_has_colors(lua_State *L)
{
	lua_pushboolean(L, has_colors());
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
 * result = nl()
 */
static int
curses_nl(lua_State *L)
{
	lua_pushinteger(L, nl());
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
 * result = refresh()
 */
static int
curses_refresh(lua_State *L)
{
	lua_pushinteger(L, refresh());
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
		{"box", curses_box},
		{"clear", curses_clear},
		{"echo", curses_echo},
		{"flash", curses_flash},
		{"getch", curses_getch},
		{"getcurx", curses_getcurx},
		{"getcury", curses_getcury},
		{"has_colors", curses_has_colors},
		{"hline", curses_hline},
		{"initscr", curses_initscr},
		{"insch", curses_insch},
		{"move", curses_move},
		{"mvaddstr", curses_mvaddstr},
		{"nl", curses_nl},
		{"noecho", curses_noecho},
		{"nonl", curses_nonl},
		{"refresh", curses_refresh},
		{"scroll", curses_scroll},
		{"scrollok", curses_scrollok},
		{"vline", curses_vline},
		{NULL, NULL},
	};

#if LUA_VERSION_NUM >= 502
	luaL_newlib(L, functions);
#else
	luaL_register(L, "curses", functions);
#endif

	return 1;
}
