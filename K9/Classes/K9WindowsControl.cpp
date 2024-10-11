/********************************************************
* Filename		: K9WindowsControl.cpp
* Creator		: ac
* Date time		: 2024.10.10
* Description	: windows handler.
********************************************************/

#include "K9Logic.h"


K9WindowControl* K9WindowControl::m_pSelf;


K9WindowControl::K9WindowControl() {}
K9WindowControl::~K9WindowControl() {}


K9WindowControl* K9WindowControl::getInstance()
{
	if (NULL == m_pSelf)
	{
		m_pSelf = new K9WindowControl;
	}
	return m_pSelf;
}

BOOL K9WindowControl::getKMSysAbsolutePath(char* szarrRet)
{
	BOOL bRet = FALSE;
	const char* cszpKmFilename = "kmclass.sys";
	DWORD dwRet = GetFullPathNameA(cszpKmFilename, MAX_PATH, szarrRet, NULL);

	if ( 0 < dwRet && dwRet < MAX_PATH )
	{
		K9LOG("Get kmclass.sys successful.");
		bRet = TRUE;
	}
	else
	{
		K9LOG("Get kmclass.sys faild.");
	}
	
Exit0:
	return bRet;
}