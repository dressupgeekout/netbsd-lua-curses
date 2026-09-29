/* $NetBSD$ */

/*
 * Copyright (c) 2026 Charlotte Koch.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

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

#define DEFINE_RVOID_WINDOW(x)					\
DECLARE(x)							\
{								\
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);	\
	x(*window);						\
	return 0;						\
}


#define DEFINE_RINT_WINDOW(x)					\
DECLARE(x)							\
{								\
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);	\
	lua_pushinteger(L, x(*window));				\
	return 1;						\
}

#define DEFINE_RINT_INT_INT(x)			\
DECLARE(x)					\
{						\
	int arg1 = luaL_checkinteger(L, 1);	\
	int arg2 = luaL_checkinteger(L, 2);	\
	lua_pushinteger(L, x(arg1, arg2));	\
	return 1;				\
}

#define DEFINE_RINT_WINDOW_BOOL(x)				\
DECLARE(x)							\
{								\
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);	\
	luaL_checktype(L, 2, LUA_TBOOLEAN);			\
	bool arg2 = lua_toboolean(L, 2);			\
	lua_pushinteger(L, x(*window, arg2));			\
	return 1;						\
}

#define DEFINE_RINT_WINDOW_INT_INT(x)				\
DECLARE(x)							\
{								\
	WINDOW **window = luaL_checkudata(L, 1, WINDOW_LTYPE);	\
	int arg2 = luaL_checkinteger(L, 2);			\
	int arg3 = luaL_checkinteger(L, 3);			\
	lua_pushinteger(L, x(*window, arg2, arg3));		\
	return 1;						\
}


/*
 * There are several functions in libcurses which actually return an int,
 * but their purpose is to get a string and "return" it via one of the
 * parameters. In these cases, our Lua binding will return 2 values: first
 * is the actual return value (the int), and the second is the string which
 * was just "gotten."
 */
#define DEFINE_RINT_RSTRING_STRING(x)	\
DECLARE(x)				\
{					\
	static char result[LINE_MAX];	\
	lua_pushinteger(L, x(result));	\
	lua_pushstring(L, result);	\
	return 2;			\
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
DECLARE(border);
DECLARE(box);
DECLARE(can_change_color);
DECLARE(cbreak);
DECLARE(clear);
DECLARE(clearok);
DECLARE(clrtobot);
DECLARE(clrtoeol);
DECLARE(curs_set);
DECLARE(delwin);
DECLARE(doupdate);
DECLARE(delch);
DECLARE(deleteln);
DECLARE(echo);
DECLARE(endwin);
DECLARE(erase);
DECLARE(filter);
DECLARE(flash);
DECLARE(flushinp);
DECLARE(flushok);
DECLARE(getbegx);
DECLARE(getbegy);
DECLARE(getch);
DECLARE(getcurx);
DECLARE(getcury);
DECLARE(getmaxx);
DECLARE(getmaxy);
DECLARE(getnstr);
DECLARE(getparx);
DECLARE(getpary);
DECLARE(getsyx);
DECLARE(halfdelay);
DECLARE(has_colors);
DECLARE(has_ic);
DECLARE(hline);
DECLARE(idcok);
DECLARE(idlok);
DECLARE(immedok);
DECLARE(inch);
DECLARE(initscr);
DECLARE(insch);
DECLARE(insdelln);
DECLARE(insertln);
DECLARE(intrflush);
DECLARE(isendwin);
DECLARE(keypad);
DECLARE(leaveok);
DECLARE(meta);
DECLARE(move);
DECLARE(mvaddstr);
DECLARE(mvcur);
DECLARE(mvdelch);
DECLARE(mvgetch);
DECLARE(mvinch);
DECLARE(mvwin);
DECLARE(napms);
DECLARE(nl);
DECLARE(nocbreak);
DECLARE(nodelay);
DECLARE(noecho);
DECLARE(nonl);
DECLARE(noqiflush);
DECLARE(noraw);
DECLARE(notimeout);
DECLARE(qiflush);
DECLARE(raw);
DECLARE(refresh);
DECLARE(resetty);
DECLARE(resize_term);
DECLARE(resizeterm);
DECLARE(savetty);
DECLARE(scrl);
DECLARE(scroll);
DECLARE(scrollok);
DECLARE(setscrreg);
DECLARE(setsyx);
DECLARE(standend);
DECLARE(standout);
DECLARE(syncok);
DECLARE(timeout);
DECLARE(underend);
DECLARE(underscore);
DECLARE(ungetch);
DECLARE(vline);
DECLARE(wclear);
DECLARE(wclrtobot);
DECLARE(wclrtoeol);
DECLARE(wmove);
DECLARE(wstandend);
DECLARE(wstandout);
DECLARE(wsyncdown);
DECLARE(wsyncup);
DECLARE(insstr);

#ifdef LUA_CURSES_UNSAFE
DECLARE(getstr);
#endif /* LUA_CURSES_UNSAFE */

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
 * result = border(ls, rs, ts, bs, tl, tr, bl, br)
 */
DECLARE(border)
{
	const char *ls = luaL_checkstring(L, 1);
	const char *rs = luaL_checkstring(L, 2);
	const char *ts = luaL_checkstring(L, 3);
	const char *bs = luaL_checkstring(L, 4);
	const char *tl = luaL_checkstring(L, 5);
	const char *tr = luaL_checkstring(L, 6);
	const char *bl = luaL_checkstring(L, 7);
	const char *br = luaL_checkstring(L, 8);
	lua_pushinteger(L,
		border(ls[0], rs[0], ts[0], bs[0], tl[0], tr[0], bl[0], br[0]));
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


DEFINE_RBOOL(can_change_color)
DEFINE_RINT(cbreak)
DEFINE_RINT(clear)
DEFINE_RINT_WINDOW_BOOL(clearok)
DEFINE_RINT(clrtobot)
DEFINE_RINT(clrtoeol)
DEFINE_RINT_INT(curs_set)
DEFINE_RINT_WINDOW(delwin)
DEFINE_RINT(doupdate)
DEFINE_RINT(delch)
DEFINE_RINT(deleteln)
DEFINE_RINT(echo)
DEFINE_RINT(endwin)
DEFINE_RINT(erase)
DEFINE_RVOID(filter)
DEFINE_RINT(flash)
DEFINE_RINT(flushinp)
DEFINE_RINT_WINDOW_BOOL(flushok)
DEFINE_RINT_WINDOW(getbegx)
DEFINE_RINT_WINDOW(getbegy)
DEFINE_RINT(getch)
DEFINE_RINT_WINDOW(getcurx)
DEFINE_RINT_WINDOW(getcury)
DEFINE_RINT_WINDOW(getmaxx)
DEFINE_RINT_WINDOW(getmaxy)


/*
 * int, result = getnstr(limit)
 */
DECLARE(getnstr)
{
	int limit = luaL_checkinteger(L, 1);
	char *result = malloc(limit);
	lua_pushinteger(L, getnstr(result, limit));
	lua_pushstring(L, (const char *)result);
	free(result);
	return 2;
}


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


DEFINE_RINT_WINDOW_BOOL(idcok)
DEFINE_RINT_WINDOW_BOOL(idlok)
DEFINE_RINT_WINDOW_BOOL(immedok)


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


DEFINE_RINT(inch)


/*
 * result = insch(char)
 */
DECLARE(insch)
{
	const char *str = luaL_checkstring(L, 1);
	lua_pushinteger(L, insch(str[0]));
	return 1;
}

DEFINE_RINT_INT(insdelln);
DEFINE_RINT(insertln)
DEFINE_RINT_WINDOW_BOOL(intrflush)
DEFINE_RBOOL(isendwin)
DEFINE_RINT_WINDOW_BOOL(keypad)
DEFINE_RINT_WINDOW_BOOL(leaveok)
DEFINE_RINT_WINDOW_BOOL(meta)
DEFINE_RINT_INT_INT(move)


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


DEFINE_RINT_INT_INT(mvdelch)
DEFINE_RINT_INT_INT(mvgetch)
DEFINE_RINT_INT_INT(mvinch)
DEFINE_RINT_WINDOW_INT_INT(mvwin)
DEFINE_RINT_INT(napms)
DEFINE_RINT(nl)
DEFINE_RINT(nocbreak)
DEFINE_RINT_WINDOW_BOOL(nodelay)
DEFINE_RINT(noecho)
DEFINE_RINT(nonl)
DEFINE_RVOID(noqiflush)
DEFINE_RINT(noraw)
DEFINE_RINT_WINDOW_BOOL(notimeout)
DEFINE_RVOID(qiflush)
DEFINE_RINT(raw)
DEFINE_RINT(refresh)
DEFINE_RINT(resetty)
DEFINE_RINT_INT_INT(resize_term)
DEFINE_RINT_INT_INT(resizeterm)
DEFINE_RINT(savetty)
DEFINE_RINT_INT(scrl)
DEFINE_RINT_WINDOW(scroll)
DEFINE_RINT_WINDOW_BOOL(scrollok)
DEFINE_RINT_INT_INT(setscrreg)


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
DEFINE_RINT_WINDOW_BOOL(syncok)


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
DEFINE_RINT_INT(ungetch)


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


DEFINE_RINT_WINDOW(wclear)
DEFINE_RINT_WINDOW(wclrtobot)
DEFINE_RINT_WINDOW(wclrtoeol)
DEFINE_RINT_WINDOW_INT_INT(wmove)
DEFINE_RINT_WINDOW(wstandend)
DEFINE_RINT_WINDOW(wstandout)
DEFINE_RVOID_WINDOW(wsyncdown)
DEFINE_RVOID_WINDOW(wsyncup)
DEFINE_RINT_STRING(insstr)

#ifdef LUA_CURSES_UNSAFE
DEFINE_RINT_RSTRING_STRING(getstr)
#endif /* LUA_CURSES_UNSAFE */

#undef DECLARE
#undef DEFINE_RVOID
#undef DEFINE_RBOOL
#undef DEFINE_RINT
#undef DEFINE_RINT_INT
#undef DEFINE_RINT_STRING
#undef DEFINE_RVOID_WINDOW
#undef DEFINE_RINT_WINDOW
#undef DEFINE_RINT_INT_INT
#undef DEFINE_RINT_WINDOW_BOOL
#undef DEFINE_RINT_RSTRING_STRING

/* ********** */

int
luaopen_curses(lua_State *L)
{
	luaL_newmetatable(L, WINDOW_LTYPE);

#define INT_CONSTANT(x) {#x, x}

	struct {
		const char *name;
		int value;
	} int_constants[] = {
		INT_CONSTANT(A_ALTCHARSET),
		INT_CONSTANT(A_ATTRIBUTES),
		INT_CONSTANT(A_BLANK),
		INT_CONSTANT(A_BLINK),
		INT_CONSTANT(A_BOLD),
		INT_CONSTANT(A_CHARTEXT),
		INT_CONSTANT(A_COLOR),
		INT_CONSTANT(A_DIM),
		INT_CONSTANT(A_INVIS),
		INT_CONSTANT(A_NORMAL),
		INT_CONSTANT(A_PROTECT),
		INT_CONSTANT(A_REVERSE),
		INT_CONSTANT(A_STANDOUT),
		INT_CONSTANT(A_UNDERLINE),
		INT_CONSTANT(COLOR_BLACK),
		INT_CONSTANT(COLOR_BLUE),
		INT_CONSTANT(COLOR_CYAN),
		INT_CONSTANT(COLOR_GREEN),
		INT_CONSTANT(COLOR_MAGENTA),
		INT_CONSTANT(COLOR_RED),
		INT_CONSTANT(COLOR_WHITE),
		INT_CONSTANT(COLOR_YELLOW),
		INT_CONSTANT(ERR),
		INT_CONSTANT(KEY_A1),
		INT_CONSTANT(KEY_A3),
		INT_CONSTANT(KEY_B2),
		INT_CONSTANT(KEY_BACKSPACE),
		INT_CONSTANT(KEY_BEG),
		INT_CONSTANT(KEY_BREAK),
		INT_CONSTANT(KEY_BTAB),
		INT_CONSTANT(KEY_C1),
		INT_CONSTANT(KEY_C3),
		INT_CONSTANT(KEY_CANCEL),
		INT_CONSTANT(KEY_CATAB),
		INT_CONSTANT(KEY_CLEAR),
		INT_CONSTANT(KEY_CLOSE),
		INT_CONSTANT(KEY_CODE_YES),
		INT_CONSTANT(KEY_COMMAND),
		INT_CONSTANT(KEY_COPY),
		INT_CONSTANT(KEY_CREATE),
		INT_CONSTANT(KEY_CTAB),
		INT_CONSTANT(KEY_DC),
		INT_CONSTANT(KEY_DL),
		INT_CONSTANT(KEY_DOWN),
		INT_CONSTANT(KEY_EIC),
		INT_CONSTANT(KEY_END),
		INT_CONSTANT(KEY_ENTER),
		INT_CONSTANT(KEY_EOL),
		INT_CONSTANT(KEY_EOS),
		INT_CONSTANT(KEY_EXIT),
		INT_CONSTANT(KEY_FIND),
		INT_CONSTANT(KEY_HELP),
		INT_CONSTANT(KEY_HOME),
		INT_CONSTANT(KEY_IC),
		INT_CONSTANT(KEY_IL),
		INT_CONSTANT(KEY_LEFT),
		INT_CONSTANT(KEY_LL),
		INT_CONSTANT(KEY_MARK),
		INT_CONSTANT(KEY_MAX),
		INT_CONSTANT(KEY_MESSAGE),
		INT_CONSTANT(KEY_MIN),
		INT_CONSTANT(KEY_MOUSE),
		INT_CONSTANT(KEY_MOVE),
		INT_CONSTANT(KEY_NEXT),
		INT_CONSTANT(KEY_NPAGE),
		INT_CONSTANT(KEY_OPEN),
		INT_CONSTANT(KEY_OPTIONS),
		INT_CONSTANT(KEY_PPAGE),
		INT_CONSTANT(KEY_PREVIOUS),
		INT_CONSTANT(KEY_PRINT),
		INT_CONSTANT(KEY_REDO),
		INT_CONSTANT(KEY_REFERENCE),
		INT_CONSTANT(KEY_REFRESH),
		INT_CONSTANT(KEY_REPLACE),
		INT_CONSTANT(KEY_RESET),
		INT_CONSTANT(KEY_RESIZE),
		INT_CONSTANT(KEY_RESTART),
		INT_CONSTANT(KEY_RESUME),
		INT_CONSTANT(KEY_RIGHT),
		INT_CONSTANT(KEY_SAVE),
		INT_CONSTANT(KEY_SBEG),
		INT_CONSTANT(KEY_SCANCEL),
		INT_CONSTANT(KEY_SCOMMAND),
		INT_CONSTANT(KEY_SCOPY),
		INT_CONSTANT(KEY_SCREATE),
		INT_CONSTANT(KEY_SDC),
		INT_CONSTANT(KEY_SDL),
		INT_CONSTANT(KEY_SELECT),
		INT_CONSTANT(KEY_SEND),
		INT_CONSTANT(KEY_SEOL),
		INT_CONSTANT(KEY_SEXIT),
		INT_CONSTANT(KEY_SF),
		INT_CONSTANT(KEY_SFIND),
		INT_CONSTANT(KEY_SHELP),
		INT_CONSTANT(KEY_SHOME),
		INT_CONSTANT(KEY_SIC),
		INT_CONSTANT(KEY_SLEFT),
		INT_CONSTANT(KEY_SMESSAGE),
		INT_CONSTANT(KEY_SMOVE),
		INT_CONSTANT(KEY_SNEXT),
		INT_CONSTANT(KEY_SOPTIONS),
		INT_CONSTANT(KEY_SPREVIOUS),
		INT_CONSTANT(KEY_SPRINT),
		INT_CONSTANT(KEY_SR),
		INT_CONSTANT(KEY_SREDO),
		INT_CONSTANT(KEY_SREPLACE),
		INT_CONSTANT(KEY_SRESET),
		INT_CONSTANT(KEY_SRIGHT),
		INT_CONSTANT(KEY_SRSUME),
		INT_CONSTANT(KEY_SSAVE),
		INT_CONSTANT(KEY_SSUSPEND),
		INT_CONSTANT(KEY_STAB),
		INT_CONSTANT(KEY_SUNDO),
		INT_CONSTANT(KEY_SUSPEND),
		INT_CONSTANT(KEY_UNDO),
		INT_CONSTANT(KEY_UP),
		INT_CONSTANT(OK),
		{NULL, 0},
	};

#undef INT_CONSTANT

	for (int i = 0; int_constants[i].name; i++) {
		lua_pushinteger(L, int_constants[i].value);
		lua_setglobal(L, int_constants[i].name);
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
		BINDING(border),
		BINDING(box),
		BINDING(can_change_color),
		BINDING(cbreak),
		BINDING(clear),
		BINDING(clearok),
		BINDING(clrtobot),
		BINDING(clrtoeol),
		BINDING(curs_set),
		BINDING(delwin),
		BINDING(doupdate),
		BINDING(delch),
		BINDING(deleteln),
		BINDING(echo),
		BINDING(endwin),
		BINDING(erase),
		BINDING(filter),
		BINDING(flash),
		BINDING(flushinp),
		BINDING(flushok),
		BINDING(getbegx),
		BINDING(getbegy),
		BINDING(getch),
		BINDING(getcurx),
		BINDING(getcury),
		BINDING(getmaxx),
		BINDING(getmaxy),
		BINDING(getnstr),
		BINDING(getparx),
		BINDING(getpary),
		BINDING(getsyx),
		BINDING(halfdelay),
		BINDING(has_colors),
		BINDING(has_ic),
		BINDING(hline),
		BINDING(idcok),
		BINDING(idlok),
		BINDING(immedok),
		BINDING(initscr),
		BINDING(inch),
		BINDING(insch),
		BINDING(insdelln),
		BINDING(insertln),
		BINDING(intrflush),
		BINDING(isendwin),
		BINDING(keypad),
		BINDING(leaveok),
		BINDING(meta),
		BINDING(move),
		BINDING(mvaddstr),
		BINDING(mvcur),
		BINDING(mvdelch),
		BINDING(mvgetch),
		BINDING(mvinch),
		BINDING(mvwin),
		BINDING(napms),
		BINDING(nl),
		BINDING(nocbreak),
		BINDING(nodelay),
		BINDING(noecho),
		BINDING(nonl),
		BINDING(noqiflush),
		BINDING(noraw),
		BINDING(notimeout),
		BINDING(qiflush),
		BINDING(raw),
		BINDING(refresh),
		BINDING(resetty),
		BINDING(resize_term),
		BINDING(resizeterm),
		BINDING(savetty),
		BINDING(scrl),
		BINDING(scroll),
		BINDING(scrollok),
		BINDING(setscrreg),
		BINDING(setsyx),
		BINDING(standend),
		BINDING(standout),
		BINDING(syncok),
		BINDING(timeout),
		BINDING(underend),
		BINDING(underscore),
		BINDING(ungetch),
		BINDING(vline),
		BINDING(wclear),
		BINDING(wclrtobot),
		BINDING(wclrtoeol),
		BINDING(wmove),
		BINDING(wstandend),
		BINDING(wstandout),
		BINDING(wsyncdown),
		BINDING(wsyncup),
		BINDING(insstr),

#ifdef LUA_CURSES_UNSAFE
		BINDING(getstr),
#endif /* LUA_CURSES_UNSAFE */

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
