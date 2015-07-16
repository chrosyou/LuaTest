// LuaTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "LuaVarint.h"
#include "iLuaAcitveScriptImpl.h"
#include "ScriptLibStorage.h"
#include "FileTest.h"
#include "lclcalib.h"
#include "lEquation.h"

using namespace std;
using namespace elex::lua;


lua_State *L;

int luaAdd()
{
	int sum = 0;
	L = luaL_newstate();  //创建线程栈和全局栈
	//luaopen_base(L);
	luaL_openlibs(L);     //添加标准库

// 	luaL_requiref(L, "clca", luaopen_clca, 1);
// 	lua_pop(L, 1);  /* remove lib */
// 	luaL_requiref(L, "equation", luaopen_Equation, 1);
// 	lua_pop(L, 1);  /* remove lib */
	
	int iErrCode = luaL_loadfile(L, "123.lua");
	lua_pcall(L, 0, LUA_MULTRET, 0);


	lua_getglobal(L, "add");
	lua_pushnumber(L, 3);
	lua_pushnumber(L, 4);
	int iRet = lua_pcall(L, 2, 1, 0);
	//string wsRet = (string)lua_tostring(L, -1);
	sum = (int)lua_tonumber(L, -1);
	lua_pop(L, 1);

	printf("The sum is %d\n", sum);
	lua_close(L);
	return sum;
}

int LuaEngineTest()
{
	DISP_PARAMS rdp;
	CLuaVariant rvarRes;
	CLuaAcitveScriptImpl* lEngineTest = CLuaAcitveScriptImpl::GetInstance();
	CScriptLibStorage* lpLuaStorge = new CScriptLibStorage;
	lEngineTest->SetStorage(lpLuaStorge);
	lEngineTest->Open();
	lEngineTest->Load(_T("123.lua"));
	lEngineTest->Invoke(_T("add"), rdp, rvarRes);

	int i = rvarRes.getValue<int>();

	lEngineTest->Release();

	return 0;
}

void Test()
{
	//ReadLine(_T("123"));
	TestRead(_T("123"));
}

#define  A  1
#define  B  A + 1

#undef   A
#define  A  10
//#define  B  A + 2

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 0, b = 2;
    
	//	TEST();

	int test; 
	luaAdd();

//	LuaEngineTest();
//	system("pause");
	return 0;
}

