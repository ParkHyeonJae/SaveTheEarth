#include "framework.h"

CGameScene02::CGameScene02()
{
}

CGameScene02::~CGameScene02()
{
	Release();
}

void CGameScene02::Init()
{
	CGameManager::m_ObjectManager = GetObjectManager();

	m_ScrollBackground01 = new CScrollBackground(D2D1::Point2F(0, 0), BACKGROUND, CGameManager::m_ScrollSpeed);
	m_ScrollBackground02 = new CScrollBackground(D2D1::Point2F(MAX_WIN_WIDTH, 0), BACKGROUND, CGameManager::m_ScrollSpeed);
	m_Player = new CPlayer(D2D1::Point2F(50, 250), PLAYER, 100.0f);

	m_GameUI = new CInGameUI(UI);

	AddObject(dynamic_cast<CGameObject*>(m_ScrollBackground01));
	AddObject(dynamic_cast<CGameObject*>(m_ScrollBackground02));
	AddObject(dynamic_cast<CGameObject*>(m_Player));


	AddObject(dynamic_cast<CGameObject*>(m_GameUI));
	CSceneObject::Init();
	AllInitalize();
}

void CGameScene02::FrameMove(DWORD elapsed)
{
	CSceneObject::FrameMove(elapsed);
	AllFrameMove(elapsed);
}

void CGameScene02::Render()
{

	CSceneObject::Render();
	AllRender();
}

void CGameScene02::Control(CInput* m_Input)
{
	static DWORD CurTime = timeGetTime();
	static DWORD OldTime = 0;

	if (CurTime - OldTime >= 250)
	{
		m_PlayerBullet = new CPlayerBullet(D2D1::Point2F(CGameManager::m_PlayerPos.x, CGameManager::m_PlayerPos.y + 30.0f), m_Player->GetRot(), PBULLET);
		CGameManager::m_ObjectManager->AddObject(dynamic_cast<CGameObject*>(m_PlayerBullet));
		OldTime = CurTime;
	}
	else CurTime = timeGetTime();



	//spawn Enemy
	if (m_Input->KeyDown(VK_F1)) {
		m_NormalEnemy = new CNormalEnemy(D2D1::Point2F(MAX_WIN_WIDTH, rand() % MAX_WIN_HEIGHT), ENEMY);
		AddObject(dynamic_cast<CGameObject*>(m_NormalEnemy));

	}

	CSceneObject::Control(m_Input);
	AllControl(m_Input);
}

void CGameScene02::Release()
{

	CSceneObject::Release();
	AllRelease();
}
