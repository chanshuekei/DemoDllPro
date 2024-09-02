// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <iostream>
#define MT_DLL_EXPORT __declspec(dllexport)

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


#ifdef __cplusplus
extern "C" {
#endif
    int MT_DLL_EXPORT __stdcall MT_DLL_Test(int a, int b);
#ifdef __cplusplus
}
#endif

int MT_DLL_EXPORT __stdcall MT_DLL_Test(int a, int b)
{
    std::cout << "Typing Under The Moon And Thinking Over The Moon." << std::endl;
    return a + b;
}
