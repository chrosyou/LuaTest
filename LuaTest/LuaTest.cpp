// LuaTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
//#include "Variant.h"

using namespace std;

extern "C" 
{  
#include <lua.h>  
#include <lualib.h>  
#include <lauxlib.h>  
} 

lua_State *L;

int luaAdd(int x, int y, int& r)
{
     int sum = 0;
     lua_getglobal(L, "add");
     lua_pushnumber(L, x);
     lua_pushnumber(L, y);
     lua_call(L, 2, 2);
     //string wsRet = (string)lua_tostring(L, -1);
	 r = (int)lua_tonumber(L, -1);
     lua_pop(L, 1);
	 sum = (int)lua_tonumber(L, -1);
	 lua_pop(L, 1);
     return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
 	int sum = 0;
 	L = luaL_newstate();  //�����߳�ջ��ȫ��ջ
 	luaopen_base(L);
 	luaL_openlibs(L);     //��ӱ�׼��
 	int iErrCode = luaL_loadfile(L, "123.lua");
 	lua_pcall(L, 0, LUA_MULTRET, 0);
	int r = 0;
 	sum = luaAdd(11, 15, r);
 	printf("The sum is %d\n", sum);
 	lua_close(L);

//	system("pause");
	return 0;
}

