/********************************************************
*Name: lidiankai
*Date time: 2022.08.09
*Description: base record header files
********************************************************/


#ifndef __BASERECORD_H__
#define __BASERECORD_H__

#define ARR_NULL	{ 0 }
#define C_OK		0
#define C_FALSE		-1

#define ASSERT(func) if (!(func)) __debugbreak()
#define ASSERT_FAILED(func) if (FAILED(func)) __debugbreak()

#ifndef VSLOGW
#define K9LOG(fmt, ...) k9LogA(fmt, ##__VA_ARGS__)
#else
#endif

#define K9_COM_RELEASE(pCom) { if(pCom) { (pCom)->Release(); (pCom) = NULL; } }
#define K9_C_COM_RELEASE(pCom) { if(pCom) { (pCom)->lpVtbl->Release(pCom); (pCom) = NULL;} }
#define K9_FREE(p) { if(p) { free(p); (p) = NULL; } }
#define K9LOG_PROCESS_ERROR(condition)																							\
do																																\
{																																\
	if (!(condition))																											\
	{																															\
		K9LOG("[K9LOG_PROCESS_ERROR] ERR '%s' at line %d in %s::%s.\n", #condition, __LINE__, __FILE__, __FUNCTION__);	\
		goto Exit0;																												\
	}																															\
} while (0);

#define K9_CHECKERR_FAILED(condition)																							\
do																																\
{																																\
	if (FAILED(condition))																										\
	{																															\
		K9LOG("[K9_CHECKERR_FAILED] ERR '%s' at line %d in %s::%s.\n", #condition, __LINE__, __FILE__, __FUNCTION__);			\
		goto Exit0;																												\
	}																															\
} while (0);

#define K9_CHECKERR_FAILED_UNLESS(condition, unless)																			\
do																																\
{																																\
	if (FAILED(condition) && unless != condition)																				\
	{																															\
		K9LOG("[K9_CHECKERR_FAILED] ERR '%s' at line %d in %s::%s.\n", #condition, __LINE__, __FILE__, __FUNCTION__);			\
		goto Exit0;																												\
	}																															\
} while (0);

#define K9_CHECKERR_SUCCESS(condition)																							\
do																																\
{																																\
	if (SUCCEEDED(condition))																									\
	{																															\
		K9LOG("[CHECK_ERR_SUCCESS] ERR '%s' at line %d in %s::%s.\n", #condition, __LINE__, __FILE__, __FUNCTION__);	\
		goto Exit0;																												\
	}																															\
} while (0);

#define FSM_CHECK_ERR_FALSE(condition)																							\
do																																\
{																																\
	if (!(condition))																											\
	{																															\
		K9LOG("[CHECK_ERR_FALSE] ERR '%s' at line %d in %s::%s.\n", #condition, __LINE__, __FILE__, __FUNCTION__);		\
		FSMSetFaildExit();																										\
		continue;																												\
	}																															\
} while (0);

#define K9_CHECKERR_NEGATIVE(condition)																						\
do																																\
{																																\
	if (condition < 0)																											\
	{																															\
		K9LOG("[CHECK_ERR_NEGATIVE] ERR '%s' at line %d in %s::%s.\n", #condition, __LINE__, __FILE__, __FUNCTION__);	\
		goto Exit0;																												\
	}																															\
} while (0);


#define CHECK_ERR_FAILED(condition)																							\
do																																\
{																																\
	if (FAILED(condition))																											\
	{																															\
		K9LOG("[CHECK_ERR_FAILED] ERR '%s' at line %d in %s::%s.\n", #condition, __LINE__, __FILE__, __FUNCTION__);	\
		goto Exit0;																												\
	}																															\
} while (0);



#define CHECK_RETURN_FALSE(condition)\
do										\
{										\
	if (!(condition))					\
	{									\
		return;							\
	}									\
} while (0);


#define CHECK_RETURN_SUCCESS(condition)	\
do											\
{											\
	if (condition)							\
	{										\
		return;								\
	}										\
} while (0);


#define CHECK_FALSE_BREAK(condition)	\
do											\
{											\
	if (!condition)							\
	{										\
		break;								\
	}										\
} while (0);


#endif // !__BASERECORD_H__
