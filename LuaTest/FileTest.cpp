
#include "stdafx.h"
#include "FileTest.h"

int ReadLine(LPCWSTR lpName)
{
	char test[MAX_PATH] = {0};
	int iRead = 0;

	FILE* lpFile = _wfopen(lpName, _T("r"));
	if (NULL == lpFile)
	{
		throw 2;
	}

	fread(test, 10, iRead, lpFile);
	fclose(lpFile);
	return 0;
}

int TestRead(LPCWSTR lpName)
{
	int iRet = 0;
	try
	{
		ReadLine(lpName);
	}
	catch (int i)
	{
		int a = i;
	}
	catch (...)
	{
		iRet = 1;
	}
	return iRet;
}
