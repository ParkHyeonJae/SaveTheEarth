#include "framework.h"
CBossEnemy::CBossEnemy(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;

	m_BossHitTimer = new CTimer(300);
	m_BossAnimFunc = new CSpriteAnimation();

	m_BossNullHp = CGameManager::m_ImageManager->GetImages()->GetSprite("BossNullHp");
	m_BossHpBar = CGameManager::m_ImageManager->GetImages()->GetSprite("BossHpBar");
	m_Sprite = CGameManager::m_ImageManager->GetImages()->GetMultiSprite("BossIdleAnim")[0];
	Init();
}

CBossEnemy::~CBossEnemy()
{
}

void CBossEnemy::Init()
{
	m_BossHpPos = { 900,0 };
	m_HP = MAXBOSSHP;
	m_deadCheck = FALSE;
	m_isDelete = FALSE;
	m_isHit = FALSE;
	m_BossHitTimer->LoopCheck(FALSE);
	m_TargetPos = { 1060, 200 };
	sequence = 0;
	m_BossHP = new CHealthBar("BossNullHp", "BossHpBar", m_BossHpPos, FALSE, TRUE);
	m_IsBossShow = TRUE;
	m_LaserLauncher = new CBossLaserLauncher(D2D1::Point2F(m_Pos.x, m_Pos.y), BOSSLASER);
	
}

void CBossEnemy::Render()
{
	CSprite* m_texture = CGameManager::m_ImageManager->GetImages()->GetMultiSprite("BossIdleAnim", sequence);
	if (!m_deadCheck) {
		if (m_LaserLauncher->IsRun()) {
			m_IsBossShow = FALSE;
		}
		else m_IsBossShow = TRUE;
		if (m_IsBossShow) {
			m_texture->Draw(m_Pos, D2D1::SizeF(1.f, 1.f), NULL, 0.0f);
			if (m_isHit) {
				m_texture->MaskDraw(m_Pos, D2D1::SizeF(1.f, 1.f), NULL, 0.0f, OpacityBrush::BLACK);
				m_isHit = FALSE;
			}
		}
		
	}
	else //When BOSS is Dead
	{
		
		if (colorV > 1.0f)
			m_isDelete = TRUE;
		colorV += 0.0025f;
		D2D1_COLOR_F color = D2D1::ColorF(colorV, colorV, colorV, colorV);
		m_Pos.x += (rand() % 20 * ((rand() % 2) ? 1 : -1));
		m_Pos.y += (rand() % 20 * ((rand() % 2) ? 1 : -1));
		m_texture->Draw(m_Pos, D2D1::SizeF(1.f, 1.f), NULL, 0.0f);
		m_texture->MaskDraw(m_Pos, D2D1::SizeF(1.f, 1.f), NULL, 0.0f,1.0f, color, OpacityBrush::WHITE);
	}
	sequence = m_BossAnimFunc->OnAnimRender(50, 0, 8);

	//CurIMG = (m_HP * MAXIMG) / MAXHP;
	m_BossHP->Setting(MAXBOSSHP, m_HP);
	D2D1_RECT_F hpSrc = {
		0,
		m_BossHP->RestIMG() * 1,
		0,
		0,
	};
	m_BossNullHp->Draw(m_BossHpPos);
	m_BossHpBar->Draw(m_BossHpPos, &hpSrc);
}

void CBossEnemy::FrameMove(DWORD elapsed)
{
	 m_Pos.x = Mathf::Lerp(m_Pos.x, m_TargetPos.x, deltaTime);
	 m_Pos.y = Mathf::Lerp(m_Pos.y, m_TargetPos.y, deltaTime);
	 if (deltaTime <= 1.0f)
		 deltaTime += 0.01;
	 else {
		 m_TargetPos = { 1060,  static_cast<FLOAT>(Mathf::RandomIntValue(100,200)) };
		 deltaTime = 0.01f;
	 }
	 if (m_LaserLauncher->IsRun())
		 m_LaserLauncher->SetPos(D2D1::Point2F(m_Pos.x, m_Pos.y));
}

void CBossEnemy::Control(CInput* Input)
{
	if (Input->KeyDown(VK_F4))
	{
		m_LaserLauncher = new CBossLaserLauncher(D2D1::Point2F(m_Pos.x, m_Pos.y), BOSSLASER);
		OBJECT->AddObject(dynamic_cast<CGameObject*>(m_LaserLauncher));
	}
}

void CBossEnemy::Release()
{
	if (m_BossAnimFunc)
	{
		delete m_BossAnimFunc;
		m_BossAnimFunc = nullptr;
	}
}
