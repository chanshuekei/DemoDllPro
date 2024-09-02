// LoadDll.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h>
typedef int(__stdcall* MT_DLL_Test)(int a, int b);


int main()
{
    std::cout << "Typing Under The Moon And Thinking Over The Moon.\n";
    // 加载动态库
    HMODULE hModule = LoadLibraryA("DemoDll.dll");
    if (!hModule)
    {
        std::cout << "Failed to load library:" << GetLastError() << std::endl;
        return -1;
    }
    MT_DLL_Test funcCall = nullptr;
    funcCall = (MT_DLL_Test)GetProcAddress(hModule, "MT_DLL_Test");
    if (nullptr == funcCall)
    {
        std::cout << "Failed to load interface:" << GetLastError() << std::endl;
        return -1;
    }
    else {
        int a = 10;
        int b = 20;
        auto c = funcCall(a, b);
        std::cout << a << " + " << b << " = " << c << std::endl;
        std::cout << "Call dll functon succeed!" << std::endl;
    }
    // 释放动态库
    FreeLibrary(hModule);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
