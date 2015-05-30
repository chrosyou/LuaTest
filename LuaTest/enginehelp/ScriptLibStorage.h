#pragma once
#include "IScriptLibStorage.h"
#include <Shlwapi.h>
#include <atlbase.h>
#include <atlcom.h>
#include "rtlmem.h"
#include <string>
#include <map>
#include "memory/ref_counted.h"

class CScriptLibStorage;

//////////////////////////////////////////////////////////////////////////
// CScriptLibStream
class CScriptLibStream : public elex::lua::IScriptLibStream,public elex::RefCountedImpl<CScriptLibStream>
{
	friend CScriptLibStorage;
	CRtlMemFileT<> m_file;
public:
	// IScriptLibStream
	virtual void AddRef()
	{
		InternalAddRef();
	}

	virtual void Release()
	{
		InternalRelease();
	}
	virtual long Read(void *pv,ULONG cb,ULONG *pcbRead);
};

//////////////////////////////////////////////////////////////////////////
// CScriptFileStream
class CScriptFileStream : public elex::lua::IScriptLibStream,public elex::RefCountedImpl<CScriptFileStream>
{
	friend CScriptLibStorage;
	CRtlMemFileT<> m_file;
public:
	// IScriptLibStream
	virtual void AddRef()
	{
		InternalAddRef();
	}

	virtual void Release()
	{
		InternalRelease();
	}
	virtual long Read(void *pv,ULONG cb,ULONG *pcbRead);
};


//////////////////////////////////////////////////////////////////////////
// CScriptLibStorage
class CScriptLibStorage : public elex::lua::IScriptLibStorage,public elex::RefCountedImpl<CScriptLibStorage>
{
	std::wstring m_strPath;
	struct NodeInfo 
	{
		DWORD dwOffset;
		DWORD dwLen;
		NodeInfo()
		{
			dwOffset = 0;
			dwLen = 0;
		}
	};
	std::map<std::wstring,NodeInfo> m_mapGuid;
	CRtlMemFileT<> m_mem;
public:
	static CScriptLibStorage* GetInstance();
	// IScriptLibStorage
	virtual void AddRef()
	{
		InternalAddRef();
	}

	virtual void Release()
	{
		InternalRelease();
	}
	virtual long Open(const std::wstring& strFileName);
	virtual long OpenBuff(const std::vector<char>& vecBuff);
	virtual long OpenStream(const std::wstring& strStreamName,elex::lua::IScriptLibStream** ppstm);
};
