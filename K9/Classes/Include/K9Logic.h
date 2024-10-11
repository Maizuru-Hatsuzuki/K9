/********************************************************
* Filename		: K9Logic.h
* Creator		: ac
* Date time		: 2024.10.10
* Description	: Base logic.
********************************************************/

#ifndef __K9LOGIC_H__
#define __K9LOGIC_H__

#include "K9.h"


class K9WindowControl
{
public:

	// BOOL SetWindowPosition(const int cnX, const int cnY);
	static K9WindowControl* getInstance();
	BOOL getKMSysAbsolutePath(char* szarrRet);

private:
	K9WindowControl();
	~K9WindowControl();
	K9WindowControl(const K9WindowControl& pSelf);
	const K9WindowControl& operator=(const K9WindowControl& pSelf);

private:
	static K9WindowControl* m_pSelf;
};

class KMHandler
{
public:
	KMHandler();
	~KMHandler();

	BOOL InitKM();
	void KMKeyDown(USHORT usKeyCode);
	void KMKeyUp(USHORT usKeyCode);
	void KMPress(USHORT usKeyCode);

protected:
	
private:
	char m_szarrDriverName[16] = "kmclass";
};


void k9LogA(const CHAR* cszpText, ...);

#endif
