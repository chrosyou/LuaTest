// LuaRun.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

extern "C" { 
#include "lua.h"  
#include "lualib.h"  
#include "lauxlib.h"
}


int _tmain(int argc, _TCHAR* argv[])
{
	lua_gettop(NULL);

	return 0;
}

