
#include "stdafx.h"
#include "lclcalib.h"
#include <stdlib.h>
#include <math.h>


#undef PI
#define PI	((lua_Number)(3.1415926535897932384626433832795))
#define RADIANS_PER_DEGREE	((lua_Number)(PI/180.0))


static int math_abs (lua_State *L) {
	lua_pushnumber(L, l_mathop(fabs)(luaL_checknumber(L, 1)));
	return 1;
}

static int math_add (lua_State *L) {
	lua_Number x = luaL_checknumber(L, 1);
	lua_Number y = luaL_checknumber(L, 2);
	lua_pushnumber(L, l_mathop(x + y));
	return 1;
}

static const luaL_Reg mathlib[] = {
	{"abs",  math_abs},
	{"add",  math_add},
//	{"mul",  math_asin},
//	{"abs", math_atan2},

	{NULL, NULL}
};


int luaopen_clca (lua_State *L) {
	luaL_newlib(L, mathlib);
	lua_pushnumber(L, PI);
	lua_setfield(L, -2, "pi");
	lua_pushnumber(L, HUGE_VAL);
	lua_setfield(L, -2, "huge");
	return 1;
}