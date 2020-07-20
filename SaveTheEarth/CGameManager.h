#pragma once
struct PLAYER_ATTR {
	FLOAT m_ATKDamage;
	FLOAT m_IncreaseHP;
	FLOAT m_RPM;
};
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
	static 	CImageManager* m_ImageManager;
	static BOOL isinvincibility;

	static PLAYER_ATTR m_PlayerAttribute;
public:
	CGameManager(CGraphics * m_Gfx, CInput* m_Input, CObjectManager * m_ObjectManager, CImageManager* m_ImageManager);
	~CGameManager();

	void Init();
	void FrameMove(DWORD elapsed);
	void Control(CInput* m_Input);
	void Render();
	void Release();
};

