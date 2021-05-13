# $NetBSD$

LUA_MODULES=		curses
LUA_SRCS.curses=	curses.c
LUA_DPLIBS+=		curses ${.CURDIR}/../../libcurses

.include <bsd.lua.mk>
