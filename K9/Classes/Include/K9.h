/********************************************************
* Filename		: K9.h
* Creator		: ac
* Date time		: 2024.10.10
* Description	: Base header.
********************************************************/


#ifndef __K9_H__
#define __K9_H__

#include <stdio.h>
#include <Windows.h>
#include "BaseRecord.h"

#ifdef _DEBUG
#define K9_PAK9_KMCDLL "kmclassdllX64D.dll"
#else
#define K9_PAK9_KMCDLL "kmclassdllX64.dll"
#endif // _DEBUG

#define K9_PAK9_KMCSYS "F:\\AutoWork\\K9\\K9\\Lib\\kmclass\\kmclass.sys"

#define VKCODE_F 0x46


#endif // !__K9_H__
