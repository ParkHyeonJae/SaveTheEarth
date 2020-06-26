﻿// SaveTheEarth.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "SaveTheEarth.h"

extern CDX2DApp* g_pDX2App;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    CGame DX2DApp;


    g_pDX2App = &DX2DApp;

    HRESULT hr = DX2DApp.Create(hInstance);
    if (hr != S_OK)
        return -1;

    return DX2DApp.Run();
}

