// Lua530.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "lua.hpp"

lua_State *L;

int luaAdd()
{
	int sum = 0;
	L = luaL_newstate();  //创建线程栈和全局栈
	//luaopen_base(L);
	luaL_openlibs(L);     //添加标准库


	int iErrCode = luaL_loadfile(L, "test530.lua");
	if (0 != iErrCode)
	{
		return 0;
	}

	lua_pcall(L, 0, LUA_MULTRET, 0);

	lua_getglobal(L, "add");
	lua_pushnumber(L, 3);
	lua_pushnumber(L, 4);
	lua_call(L, 2, 1);
	//string wsRet = (string)lua_tostring(L, -1);
	sum = (int)lua_tonumber(L, -1);
	lua_pop(L, 1);

	printf("The sum is %d\n", sum);
	lua_close(L);
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	luaAdd();

	return 0;
}

