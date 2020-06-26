#pragma once
class CGame : public CDX2DApp
{
public:
	CGame();
	~CGame();

	virtual INT		Init();
	virtual void	Destroy();

	virtual INT		FrameMove(DWORD elpased);
	virtual INT		Render();
	virtual INT		Control();

	virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
};

