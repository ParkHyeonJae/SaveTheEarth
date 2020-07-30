#include "framework.h"
#include "CScoreManager.h"


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
	m_Player = new CPlayer(D2D1::Point2F(-100, 350), PLAYER, MAX_PLAYER_HP);
	


	m_GameUI = new CInGameUI(UI);

	AddObject(dynamic_cast<CGameObject*>(m_ScrollBackground01));
	AddObject(dynamic_cast<CGameObject*>(m_Player));

	
	m_EnemySpawnTimer = new CTimer(2500);
	m_MisileSpawnTimer = new CTimer(1500);
	m_BossSpawnTimer = new CTimer(4500);
	m_BalanceTimer = new CTimer(5000);

	m_BossSpawnTimer->LoopCheck(FALSE);

	AddUI(dynamic_cast<CGameObject*>(m_GameUI));

	Score::CScoreManager::SetScore(3000);
	SOUND->InitSound();
	SOUND->PlaySoundFunc("Alan Walker - Fade");
	CSceneObject::Init();
	AllInitalize();
}

void CGameScene02::FrameMove(DWORD elapsed)
{
	if (m_Player->GetHp() <= 0)
		CGameManager::nowStatus = TITLE;
	if (Score::CScoreManager::GetScore() > 11500)
		CGameManager::m_Level = 2;

	if (CGameManager::m_Level == 1) {
		Score::CScoreManager::ApplyScore(1.0f);		//n점 추가

		if (m_BalanceTimer->OnTimer()) {
			if (m_EnemySpawnTimer->GetDestTime() - 10 >= 500)
				m_EnemySpawnTimer->SetTimer(m_EnemySpawnTimer->GetDestTime() - 20);
		}
		if (m_EnemySpawnTimer->OnTimer())
		{
			m_NormalEnemy = new CNormalEnemy(D2D1::Point2F((FLOAT)MAX_WIN_WIDTH, (FLOAT)(rand() % MAX_WIN_HEIGHT)), ENEMY);
			AddObject(dynamic_cast<CGameObject*>(m_NormalEnemy));
		}
		if (m_MisileSpawnTimer->OnTimer())
		{
			m_misileEnemy = new MisileEnemy(D2D1::Point2F(0.0f, (FLOAT)Mathf::RandomIntValue(0, 1000)), MISILE);
			AddObject(dynamic_cast<CGameObject*>(m_misileEnemy));
		}
	}
	else {
		Score::CScoreManager::ApplyScore(1.0f);		//n점 추가

		//m_Player->SetHp(m_Player->GetHp() - 0.1f);
		if (m_BossSpawnTimer->OnTimer())
		{
			m_BossEnemy = new CBossEnemy(D2D1::Point2F((FLOAT)MAX_WIN_WIDTH, (FLOAT)(rand() % MAX_WIN_HEIGHT)), BOSS);
			AddObject(dynamic_cast<CGameObject*>(m_BossEnemy));
		}

	}
	SOUND->UpdateSound();
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
		m_NormalEnemy = new CNormalEnemy(D2D1::Point2F((FLOAT)MAX_WIN_WIDTH, (FLOAT)(rand() % MAX_WIN_HEIGHT)), ENEMY);
		AddObject(dynamic_cast<CGameObject*>(m_NormalEnemy));

	}
	if (m_Input->KeyDown(VK_F2)) {
		m_misileEnemy = new MisileEnemy(D2D1::Point2F(0.0f, (FLOAT)Mathf::RandomIntValue(0, 500)), MISILE);
		AddObject(dynamic_cast<CGameObject*>(m_misileEnemy));
	}
	if (m_Input->KeyDown(VK_F3)) {
		m_BossEnemy = new CBossEnemy(D2D1::Point2F((FLOAT)MAX_WIN_WIDTH, (FLOAT)(rand() % MAX_WIN_HEIGHT)), BOSS);
		AddObject(dynamic_cast<CGameObject*>(m_BossEnemy));
	}

	if (m_Input->KeyDown(VK_BACK)) {
		CGameManager::nowStatus = TITLE;
	}


	if (m_Input->KeyDown(VK_F9)) {
		CGameManager::isinvincibility = TRUE;
		CGameManager::m_playerAttr.m_ATKDamage = 500;
		CGameManager::ApplyScore = 1000.0f;
	}
	CSceneObject::Control(m_Input);
	AllControl(m_Input);
}

void CGameScene02::Release()
{
	SOUND->ReleaseSound();
	CSceneObject::Release();
	AllRelease();
}
