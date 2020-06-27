#pragma once
class CGameManager
{
public:
	static CGraphics* m_Gfx;
	static  CInput* m_Input;
	static CObjectManager* m_ObjectManager;
	static FLOAT m_ScrollSpeed;
public:
	CGameManager(CGraphics * m_Gfx, CInput* m_Input, CObjectManager * m_ObjectManager);
	~CGameManager();

	void Init();
	void FrameMove(DWORD elapsed);
	void Control(CInput* m_Input);
	void Render();
	void Release();
};

