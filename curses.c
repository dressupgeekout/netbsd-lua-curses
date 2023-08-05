/* $NetBSD$ */

#include <stdbool.h>

#include <curses.h>

#include <lua.h>
#include <lauxlib.h>

/* *********** */

#define WINDOW_LTYPE "WINDOW"

#define DECLARE(x) static int curses_##x(lua_State *L)

#define DEFINE_RVOID(x)			\
DECLARE(x)				\
{					\
	x();				\
	return 0;			\
}

#define DEFINE_RBOOL(x)			\
DECLARE(x)				\
{					\
	lua_pushboolean(L, x());	\
	return 1;			\
}

#define DEFINE_RINT(x)			\
DECLARE(x)				\
{					\
	lua_pushinteger(L, x());	\
	return 1;			\
}

#define DEFINE_RINT_INT(x)			\
DECLARE(x)					\
{						\
	int arg = luaL_checkinteger(L, 1);	\
	lua_pushinteger(L, x(arg));		\
	return 1;				\
}

#define DEFINE_RINT_STRING(x)				\
DECLARE(x)						\
{							\
	const char *string = luaL_checkstring(L, 1);	\
	lua_pushinteger(L, x(string));			\
	return 1;					\
}

#define DEFINE_RINT_WINDOW(x)					\
DECLARE(x)							\
{								\
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);	\
	lua_pushinteger(L, x(*window));				\
	return 1;						\
}

/* ********** */

int luaopen_curses(lua_State *L);

DECLARE(addch);
DECLARE(addstr);
DECLARE(attroff);
DECLARE(attron);
DECLARE(attrset);
DECLARE(baudrate);
DECLARE(beep);
DECLARE(box);
DECLARE(cbreak);
DECLARE(clear);
DECLARE(clrtobot);
DECLARE(clrtoeol);
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
DECLARE(inch);
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
DECLARE(setscrreg);
DECLARE(setsyx);
DECLARE(standend);
DECLARE(standout);
DECLARE(timeout);
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


DEFINE_RINT_STRING(addstr)
DEFINE_RINT_INT(attroff)
DEFINE_RINT_INT(attron)
DEFINE_RINT_INT(attrset)
DEFINE_RINT(baudrate)
DEFINE_RINT(beep)


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


DEFINE_RINT(cbreak)
DEFINE_RINT(clear)
DEFINE_RINT(clrtobot)
DEFINE_RINT(clrtoeol)
DEFINE_RINT_INT(curs_set)
DEFINE_RINT(delch)
DEFINE_RINT(deleteln)
DEFINE_RINT(echo)
DEFINE_RINT(endwin)
DEFINE_RINT(erase)
DEFINE_RVOID(filter)
DEFINE_RINT(flash)
DEFINE_RINT_WINDOW(getbegx)
DEFINE_RINT_WINDOW(getbegy)
DEFINE_RINT(getch)
DEFINE_RINT_WINDOW(getcurx)
DEFINE_RINT_WINDOW(getcury)
DEFINE_RINT_WINDOW(getmaxx)
DEFINE_RINT_WINDOW(getmaxy)
DEFINE_RINT_WINDOW(getparx)
DEFINE_RINT_WINDOW(getpary)


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


DEFINE_RINT_INT(halfdelay)
DEFINE_RBOOL(has_colors)
DEFINE_RBOOL(has_ic)


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
 * inch()
 */
DECLARE(inch)
{
	lua_pushinteger(L, inch());
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


DEFINE_RBOOL(isendwin)


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


DEFINE_RINT(nl)
DEFINE_RINT(nocbreak)
DEFINE_RINT(noecho)
DEFINE_RINT(nonl)
DEFINE_RINT(noraw)
DEFINE_RINT(raw)
DEFINE_RINT(refresh)


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


DEFINE_RINT_INT(scrl)
DEFINE_RINT_WINDOW(scroll)


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
 * result = setscrreg(top, bottom)
 */
DECLARE(setscrreg)
{
	int top = luaL_checkinteger(L, 1);
	int bottom = luaL_checkinteger(L, 2);
	lua_pushinteger(L, setscrreg(top, bottom));
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


DEFINE_RINT(standend)
DEFINE_RINT(standout)


/*
 * timeout(delay)
 */
DECLARE(timeout)
{
	int delay = luaL_checkinteger(L, 1);
	timeout(delay);
	return 0;
}


DEFINE_RINT(underend)
DEFINE_RINT(underscore)


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


DEFINE_RINT_WINDOW(wstandend)
DEFINE_RINT_WINDOW(wstandout)

#undef DECLARE
#undef DEFINE_RVOID
#undef DEFINE_RBOOL
#undef DEFINE_RINT
#undef DEFINE_RINT_INT
#undef DEFINE_RINT_STRING
#undef DEFINE_RINT_WINDOW

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
		BINDING(attrset),
		BINDING(baudrate),
		BINDING(beep),
		BINDING(box),
		BINDING(cbreak),
		BINDING(clear),
		BINDING(clrtobot),
		BINDING(clrtoeol),
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
		BINDING(inch),
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
		BINDING(setscrreg),
		BINDING(setsyx),
		BINDING(standend),
		BINDING(standout),
		BINDING(timeout),
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
