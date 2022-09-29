// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <metahost.h>
#include <Windows.h>
#include <mscoree.h>
#include <metahost.h>
#include <wchar.h>
#include <fstream>
#include <iostream>
#pragma comment(lib, "mscoree.lib")

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

static const LPCWSTR Assembly = L"\\CodeInject.dll"; //dllname.dll (Needs To Start With '\\') (Can also be inside a folder, eg '\\Folder\\dllname.dll')
static const LPCWSTR Class = L"ISpace.IClass"; //namespace.class
static const LPCWSTR Method = L"IMain"; //method name
static const LPCWSTR Param = L"It works!!"; //string paramaters


DWORD WINAPI Main()
{
    ICLRMetaHost* metaHost = NULL; 
    ICLRRuntimeInfo* runtimeInfo = NULL;
    ICLRRuntimeHost* runtimeHost = NULL; 

    FILE* file;
    LPWSTR AppPath = new WCHAR[_MAX_PATH];
    ::GetModuleFileNameW((HINSTANCE)&__ImageBase, AppPath, _MAX_PATH);

    std::wstring tempPath = AppPath;
    int index = tempPath.rfind('\\');
    tempPath.erase(index, tempPath.length() - index);
    tempPath += Assembly;


    if (CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)&metaHost) == S_OK) 
        if (metaHost->GetRuntime(L"v4.0.30319", IID_ICLRRuntimeInfo, (LPVOID*)&runtimeInfo) == S_OK) 
            if (runtimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_ICLRRuntimeHost, (LPVOID*)&runtimeHost) == S_OK) 
                if (runtimeHost->Start() == S_OK) 
                {
                    DWORD pReturnValue;
                    runtimeHost->ExecuteInDefaultAppDomain((LPWSTR)tempPath.c_str(), Class, Method, Param, &pReturnValue);
                    std::cout << (int)pReturnValue;
                    runtimeInfo->Release();
                    metaHost->Release();
                    runtimeHost->Release();
                }





    return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        case DLL_THREAD_ATTACH:
        {
            DisableThreadLibraryCalls(hModule);
            CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Main, hModule, 0, nullptr);
        }
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

