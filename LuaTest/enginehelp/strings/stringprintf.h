#pragma once
#include <stdarg.h>   // va_list
#include <string>

//#include "strings/iImportLibDefine.h"
#define IIMPORTLIB_API

namespace elex
{
	namespace strings
	{
		IIMPORTLIB_API std::string Printf(const char* format, ...);
		IIMPORTLIB_API std::wstring Printf(const wchar_t* format, ...);
		IIMPORTLIB_API std::string PrintV(const char* format, va_list ap);
		IIMPORTLIB_API const std::string& SPrintf(std::string* dst,
			const char* format, ...);
		IIMPORTLIB_API const std::wstring& SPrintf(std::wstring* dst,
			const wchar_t* format, ...);
		IIMPORTLIB_API void AppendF(std::string* dst, const char* format, ...);
		IIMPORTLIB_API void AppendF(std::wstring* dst, const wchar_t* format, ...);
		IIMPORTLIB_API void AppendV(std::string* dst, const char* format, va_list ap);
		IIMPORTLIB_API void AppendV(std::wstring* dst, const wchar_t* format, va_list ap);
	}
}