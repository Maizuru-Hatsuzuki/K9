/********************************************************
* Filename		: K9Logic.cpp
* Creator		: ac
* Date time		: 2024.10.10
* Description	: Base logic.
********************************************************/


#include "K9Logic.h"
#include "BaseRecord.h"
#include "kmclass.h"


KMHandler::KMHandler()
{
	BOOL bRet = FALSE;
	bRet = InitKM();
	ASSERT(bRet);
}

KMHandler::~KMHandler() 
{
	UnloadNTDriver(m_szarrDriverName);
}

BOOL KMHandler::InitKM()
{
	DWORD dwErr = 0;
	BOOL bRet = FALSE;
	char szarrKmSysPath[MAX_PATH] = { 0 };

	bRet = K9WindowControl::getInstance()->getKMSysAbsolutePath(szarrKmSysPath);
	K9LOG_PROCESS_ERROR(bRet);

	bRet = LoadNTDriver(m_szarrDriverName, K9_PAK9_KMCSYS);
	dwErr = GetLastError();
	if (FALSE == bRet && ERROR_SERVICE_MARKED_FOR_DELETE == dwErr)
	{
		UnloadNTDriver(m_szarrDriverName);
		LoadNTDriver(m_szarrDriverName, K9_PAK9_KMCSYS);
	}
	else
	{
		K9LOG_PROCESS_ERROR(bRet);
	}
	SetHandle();

	bRet = TRUE;
Exit0:
	return bRet;
}

void KMHandler::KMKeyDown(USHORT usKeyCode)
{
	KeyDown(usKeyCode);
}

void KMHandler::KMKeyUp(USHORT usKeyCode)
{
	KeyUp(usKeyCode);
}

void KMHandler::KMPress(USHORT usKeyCode)
{
	KeyDown(usKeyCode);
	Sleep(10);
	KeyUp(usKeyCode);
}

void k9LogA(const CHAR* cszpText, ...)
{
	CHAR szarrText[1024] = { 0 };
	va_list vlArgs;

	va_start(vlArgs, cszpText);
	_vsnprintf_s(szarrText, 1024, 1024, cszpText, vlArgs);
	va_end(vlArgs);
	OutputDebugStringA(szarrText);

	return;
}