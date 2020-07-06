#pragma once
class CGameManager
{
public:
	static CGraphics* m_Gfx;
	static  CInput* m_Input;
	static CObjectManager* m_ObjectManager;
	static FLOAT m_ScrollSpeed;
	static D2D1_POINT_2F m_PlayerPos;
	static FLOAT radian;
	static INT nowStatus;
	static DWORD m_fps;
	static FLOAT m_playerHp;
public:
	CGameManager(CGraphics * m_Gfx, CInput* m_Input, CObjectManager * m_ObjectManager);
	~CGameManager();

	void Init();
	void FrameMove(DWORD elapsed);
	void Control(CInput* m_Input);
	void Render();
	void Release();
};

