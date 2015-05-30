// DllTest.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

extern "C" { 
#include "lua.h"  
#include "lualib.h"  
#include "lauxlib.h"
}

#include <windows.h>
#include <tchar.h>

#pragma comment(lib, "lua52.lib")

static int MyLuaDLL_HelloWorld(lua_State* L)  
{  
	MessageBox(NULL, _T("Hello"), _T("World"), MB_OK);  
	return 0;  
}  
static int MyLuaDLL_average(lua_State *L)  
{  

	int n = lua_gettop(L);  
	double sum = 0;  
	int i;  

	for (i = 1; i <= n; i++)  
	{  

		sum += lua_tonumber(L, i);  
	}  

	lua_pushnumber(L, sum / n);  

	lua_pushnumber(L, sum);  

	return 2;  
}

static int MyLuaDLL_Add(lua_State *L)
{
	int x = lua_tonumber(L, 1);
	int y = lua_tonumber(L, 2);
	lua_pushnumber(L, x+y);
	return 1;
}

static int MyLuaDLL_GetClientPath(lua_State *L)
{
	char cPath[MAX_PATH] = {0};
	GetModuleFileNameA(NULL, cPath, MAX_PATH);
	lua_pushlstring(L, cPath, strlen(cPath));
	return 1;
}

static const luaL_Reg MyLuaDLLFunctions [] =  
{  
	{"HelloWorld",MyLuaDLL_HelloWorld},  
	{"average",MyLuaDLL_average},
	{"add", MyLuaDLL_Add},
	{"GetClientPath", MyLuaDLL_GetClientPath},
	{NULL, NULL}  
};  

extern "C" __declspec(dllexport) int luaopen_MyLuaDLL(lua_State* L)  
{  
	luaL_openlib(L, "MyLuaDLL", MyLuaDLLFunctions, 0);  
	return 1;  
}  
