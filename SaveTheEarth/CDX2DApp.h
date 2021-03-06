#pragma once
class CDX2DApp
{
protected:
	LPCWSTR m_sCls;
	HINSTANCE m_hInst;
	HWND m_hWnd;
	DWORD m_dWinStyle;
	DWORD m_ScreenX;
	DWORD m_ScreenY;
	BOOL m_bShowCursor;

	RECT m_rcWin;

	DWORD m_fps;

	CInput* m_Input;
protected:
	CGraphics* m_Gfx;
public:
	CDX2DApp();
	virtual ~CDX2DApp();

	INT Create(HINSTANCE hInst);
	INT Run();
	void CleanUp();

	INT RenderLoop();

	virtual INT Init();
	virtual INT Render();
	virtual INT FrameMove(DWORD elapsed);
	virtual INT Control(CInput* m_Input);

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);

	static LRESULT WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);

};

