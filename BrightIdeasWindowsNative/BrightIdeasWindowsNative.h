
#include "FlashRuntimeExtensions.h"  
//�� extern "C"�NC++���O�ഫ��C�y�� 
//��]�O����C++�W�٭��㾹�y����ƦW�٪�����
extern "C"
{
	__declspec(dllexport) void ExtInitializer(void** extDataToSet, FREContextInitializer* ctxInitializerToSet, FREContextFinalizer* ctxFinalizerToSet);

	__declspec(dllexport) void ExtFinalizer(void* extData);

	__declspec(dllexport) FREObject setMousePosition(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);

	__declspec(dllexport) FREObject mouseClick(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);

	__declspec(dllexport) FREObject mouseDown(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);

	__declspec(dllexport) FREObject mouseUp(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);

	__declspec(dllexport) FREObject keyDown(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
}