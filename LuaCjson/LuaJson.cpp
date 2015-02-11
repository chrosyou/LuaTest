// LuaTest.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
#include <tchar.h>

#pragma comment(lib, "sqlite3.lib")
using namespace std;

extern "C" 
{  
#include <lua.h>  
#include <lualib.h>  
#include <lauxlib.h>  
} 

lua_State *L;

int luaAdd(int x, int y)
{
     int sum = 0;
     lua_getglobal(L, "add");
     lua_pushnumber(L, x);
     lua_pushnumber(L, y);
     lua_call(L, 2, 1);
     string wsRet = (string)lua_tostring(L, -1);
     lua_pop(L, 1);
     return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
 	int sum = 0;
 	L = luaL_newstate();
 	luaopen_base(L);
 	luaL_openlibs(L);
 	luaL_loadfile(L, "add.lua");
 	lua_pcall(L, 0, LUA_MULTRET, 0);
 	sum = luaAdd(11, 15);
 	printf("The sum is %d\n", sum);
 	lua_close(L);


	return 0;
}

