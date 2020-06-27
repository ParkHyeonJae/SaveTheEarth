#include "framework.h"

CDX2DApp* g_pDX2App;

CDX2DApp::CDX2DApp()
{
    g_pDX2App = this;

    m_sCls = L"Save The Earth";

    m_hInst = NULL;
    m_hWnd = NULL;

    m_dWinStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE;
    m_ScreenX = MAX_WIN_WIDTH;
    m_ScreenY = MAX_WIN_HEIGHT;

    m_bShowCursor = TRUE;

    m_fps = 0;

    m_rcWin = { 0,0,0,0 };
}

CDX2DApp::~CDX2DApp()
{
}

INT CDX2DApp::Create(HINSTANCE hInst)
{
    m_hInst = hInst; // 인스턴스 핸들을 전역 변수에 저장합니다.

    WNDCLASS wc =								// Register the window class
    {
        CS_CLASSDC
        , WndProc
        , 0L
        , 0L
        , m_hInst
        , NULL
        , LoadCursor(NULL, IDC_ARROW)
        , (HBRUSH)GetStockObject(LTGRAY_BRUSH)
        , NULL
        , m_sCls
    };

    RegisterClass(&wc);

    

    int iScreenX = GetSystemMetrics(SM_CXSCREEN);
    int iScreenY = GetSystemMetrics(SM_CYSCREEN);


    int ScreenXCenter = (iScreenX / 2) - (m_ScreenX / 2);
    int ScreenYCenter = (iScreenY / 2) - (m_ScreenY / 2);

    m_hWnd = CreateWindowW(m_sCls, m_sCls, m_dWinStyle,
        ScreenXCenter, ScreenYCenter, MAX_WIN_WIDTH, MAX_WIN_HEIGHT, nullptr, nullptr, m_hInst, nullptr);


    GetWindowRect(m_hWnd, &m_rcWin);

    m_Gfx = new CGraphics();
    m_Gfx->Init(m_hWnd, m_rcWin);

    ShowWindow(m_hWnd, SW_SHOW);
    UpdateWindow(m_hWnd);

    Init();

    return 0;
}

INT CDX2DApp::Run()
{
    MSG msg;

    memset(&msg, 0, sizeof(msg));

    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            RenderLoop();
        }
    }
    
    UnregisterClass(m_sCls, m_hInst);
    return 0;
}

void CDX2DApp::CleanUp()
{
    delete m_Input;
    delete m_Gfx;
}

INT CDX2DApp::RenderLoop()
{
    static DWORD dlastTime = timeGetTime();
    static DWORD frameCount = 0;
    static DWORD TotalElapsed = 0;
    
    DWORD dCurTime = timeGetTime();
    DWORD elapsed = dCurTime - dlastTime;
    TotalElapsed += elapsed;
    frameCount++;

    if (TotalElapsed >= 1000) {
        m_fps = frameCount;
        frameCount = 0;
        TotalElapsed -= 1000;
    }
    dlastTime = dCurTime;

    HRESULT hr = FrameMove(elapsed);
    if (!SUCCEEDED(hr))
        return -1;
    hr = Render();
    if (!SUCCEEDED(hr))
        return -1;

	return 0;
}

INT CDX2DApp::Init()
{
    m_Input = new CInput();
    m_Input->Create(m_hWnd);
    
	return 0;
}

INT CDX2DApp::Render()
{
	return 0;
}

INT CDX2DApp::FrameMove(DWORD elapsed)
{
    if (m_Input) m_Input->FrameMove();
    Control(m_Input);
    
	return 0;
}

INT CDX2DApp::Control(CInput* m_Input)
{
    
	return 0;
}

LRESULT CDX2DApp::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            SendMessage(hWnd, WM_DESTROY, 0, 0);
            break;
        }
    break;
    case WM_DESTROY:
        CleanUp();
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT WINAPI CDX2DApp::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return g_pDX2App->MsgProc(hWnd, message, wParam, lParam);
}
