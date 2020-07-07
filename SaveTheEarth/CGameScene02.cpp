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
	m_Player = new CPlayer(D2D1::Point2F(50, 250), PLAYER, MAX_PLAYER_HP);
	m_BossEnemy = new CBossEnemy(D2D1::Point2F(MAX_WIN_WIDTH, rand() % MAX_WIN_HEIGHT), BOSS);


	m_GameUI = new CInGameUI(UI);

	AddObject(dynamic_cast<CGameObject*>(m_ScrollBackground01));
	AddObject(dynamic_cast<CGameObject*>(m_ScrollBackground02));
	AddObject(dynamic_cast<CGameObject*>(m_Player));

	AddObject(dynamic_cast<CGameObject*>(m_BossEnemy));
	
	for (size_t i = 0; i < 3; i++)
	{
		MisileEnemy* m_misileEnemy = new MisileEnemy(D2D1::Point2F(0, Mathf::RandomIntValue(0, 500)), MISILE);
		AddObject(dynamic_cast<CGameObject*>(m_misileEnemy));
	}

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
