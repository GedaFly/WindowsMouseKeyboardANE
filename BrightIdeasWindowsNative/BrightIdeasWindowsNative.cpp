// BrightIdeasWindowsNative.cpp : �w�q DLL ���ε{�����ץX�禡�C
//

#include "BrightIdeasWindowsNative.h"
#include <stdlib.h>
#include <windows.h>

extern "C"
{

	FREObject setMousePosition(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
	{
		//AS3�ǨӪ��ѼƷ|�s�bargv[]��
		int32_t x, y;

		//�NAS3�ƾ��নC++
		FREGetObjectAsInt32(argv[0], &x);
		FREGetObjectAsInt32(argv[1], &y);

		//�]�w�t�Ϊ��y��,��Windows.h�̪���k
		SetCursorPos(x, y);

		//�p�G���b�N�^�ǼƭȴN�^�ǲĤ@�ӰѼ�
		//�p�G�ݭn�^�Ǹg�p��L���ƭȽаO�o�Q��FRE Object�নAS3�ݱo�����ƾ�
		return argv[0];
	}

	FREObject mouseClick(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
	{
		//Ĳ�o�ƹ��ƥ�,click�ƥ���N�Omousedown��mouseup���զX
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		return argv[0];
	}

	FREObject mouseDown(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
	{
		//Ĳ�o�ƹ��ƥ�
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		return argv[0];
	}

	FREObject mouseUp(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
	{
		//Ĳ�o�ƹ��ƥ�
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		return argv[0];
	}

	FREObject keyDown(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
	{
		//Ĳ�o��L�ƥ�
		int32_t keyNum;
		FREGetObjectAsInt32(argv[0], &keyNum);

		keybd_event(keyNum, 0, 0, 0);
		return argv[0];
	}

	void ContextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions)
	{
		//�b��l�Ʈɫŧi�i�H�QAS3�եΪ���k
		*numFunctions = 5;
		FRENamedFunction* func = (FRENamedFunction*)malloc(sizeof(FRENamedFunction)*(*numFunctions));


		func[0].name = (const uint8_t*)"setMousePosition";
		func[0].functionData = NULL;
		func[0].function = &setMousePosition;

		func[1].name = (const uint8_t*)"mouseClick";
		func[1].functionData = NULL;
		func[1].function = &mouseClick;

		func[2].name = (const uint8_t*)"mouseDown";
		func[2].functionData = NULL;
		func[2].function = &mouseDown;

		func[3].name = (const uint8_t*)"mouseUp";
		func[3].functionData = NULL;
		func[3].function = &mouseUp;

		func[4].name = (const uint8_t*)"keyDown";
		func[4].functionData = NULL;
		func[4].function = &keyDown;
		
		*functions = func;
	}


	void ContextFinalizer(FREContext ctx)
	{
		return;
	}

	void ExtInitializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer)
	{

		*ctxInitializer = &ContextInitializer;
		*ctxFinalizer = &ContextFinalizer;
	}

	void ExtFinalizer(void* extData)
	{
		return;
	}
}


