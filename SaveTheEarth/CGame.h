#pragma once
class CGame : public CDX2DApp
{
private:
	CPlayer* m_Player;
	CScrollBackground* m_ScrollBackground01;
	CScrollBackground* m_ScrollBackground02;
	CObjectManager* m_ObjectManager;

	CGameManager* m_GameManager;

	
public:
	CGame();
	~CGame();

	virtual INT		Init();
	virtual void	Destroy();

	virtual INT		FrameMove(DWORD elapsed);
	virtual INT		Render();
	virtual INT		Control(CInput* m_Input);

	virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
};

