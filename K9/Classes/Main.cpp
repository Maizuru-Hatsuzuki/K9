#include "K9.h"
#include "K9Logic.h"
#include "kmclass.h"

int main()
{
	int nRet = C_FALSE;
	BOOL bFnRet = FALSE;
	KMHandler kmObject;
	
	printf("ready to press.\n");
	Sleep(2000);
	

	while (true)
	{
		kmObject.KMPress(VKCODE_F);
	}

	nRet = C_OK;
Exit0:
	return nRet;
}
