#ifndef __ELEXSTRINGSHELPER_H__
#define __ELEXSTRINGSHELPER_H__
#include <windows.h>
#include <vector>
//#include "strings\iImportLibDefine.h"
#define IIMPORTLIB_API

namespace elex{namespace strings{

	IIMPORTLIB_API std::wstring Trim(const std::wstring &source, const std::wstring &targets);

	IIMPORTLIB_API std::string  ws2s(const std::wstring& s_src,UINT CodePage = CP_UTF8);
	IIMPORTLIB_API std::wstring s2ws( const std::string& s_src,UINT CodePage = CP_UTF8);

	IIMPORTLIB_API std::wstring int2persent(int nNum);

	IIMPORTLIB_API std::string&  replace_all_distinct(std::string& str,const std::string& old_value,const std::string&  new_value);
	IIMPORTLIB_API std::wstring  replace_all_distinct(std::wstring& str,const std::wstring old_value,const std::wstring  new_value);

	IIMPORTLIB_API size_t utf8_2_utf16(const char *src, wchar_t *dest);

	IIMPORTLIB_API bool   getTwoString(const std::wstring& sValues,const wchar_t sTag,std::wstring& s1,std::wstring& s2);
	IIMPORTLIB_API void   splitString(const std::wstring& sSrc,const wchar_t sTag,std::vector<std::wstring>& retVec);
	IIMPORTLIB_API void   splitString2(const std::wstring& sSrc, const std::wstring& sTag, std::vector<std::wstring>& retVec);
	IIMPORTLIB_API void   splitStringA(const std::string& sSrc,const char sTag,std::vector<std::string>& retVec);
	IIMPORTLIB_API void   splitStringA2(const std::string& sSrc,const std::string& sTag,std::vector<std::string>& retVec);

	// Returns true if the string passed in matches the pattern. The pattern
	// string can contain wildcards like * and ?
	// The backslash character (\) is an escape character for * and ?
	// We limit the patterns to having a max of 16 * or ? characters.
	// ? matches 0 or 1 character, while * matches 0 or more characters.
	IIMPORTLIB_API bool MatchPattern(const std::wstring& eval, const std::wstring& pattern);

	IIMPORTLIB_API bool IsPatternString(const std::wstring& str);
	
	IIMPORTLIB_API std::string url_encode(const std::string& in, const char* valid = "._-=");
	IIMPORTLIB_API std::string url_decode(const std::string& in);

	IIMPORTLIB_API std::wstring trim_all(const std::wstring& in);

	IIMPORTLIB_API bool HexStringToInt(const char* ptr, int len, int* val);

	IIMPORTLIB_API bool StringToInt(const char* ptr, int len, int* val);

	IIMPORTLIB_API bool StringToInt(const std::wstring& str, int* val);


	IIMPORTLIB_API bool StringToDouble(const char* ptr, int len, double* val);

	IIMPORTLIB_API std::string HexEncode( const void* bytes, size_t size );

	IIMPORTLIB_API std::wstring to_lower(const std::wstring& in);
	IIMPORTLIB_API std::string to_lower(const std::string& in);

	IIMPORTLIB_API std::wstring to_upper(const std::wstring& in);
	IIMPORTLIB_API std::string to_upper(const std::string& in);

	IIMPORTLIB_API bool CompareNoCaseA(const std::string &l,const std::string &r);
	IIMPORTLIB_API bool CompareNoCase(const std::wstring &l,const std::wstring &r);
}}


#endif