#include "framework.h"
#include "CFadeInOut.h"

CBossEnemy::CBossEnemy(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;

	m_BossHitTimer = new CTimer(300);
	m_SkillTimer = new CTimer(10000);
	m_BossAnimFunc = new CSpriteAnimation();

	m_BossNullHp = IMAGES->GetSprite("BossNullHp");
	m_BossHpBar =  IMAGES->GetSprite("BossHpBar");
	m_Sprite =	   IMAGES->GetMultiSprite("BossIdleAnim")[0];
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
	m_BulletLauncher = new CBossBulletLauncher(D2D1::Point2F(m_Pos.x, m_Pos.y), BOSSBULLETLAUNCHER);
	m_WarningFadeInOut = new CFadeInOut(5, 0.02f);
}

void CBossEnemy::Render()
{
	IMAGES->Render("WarningText", D2D1::Point2F(0.0f, 0.0f)
		, D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, m_WarningFadeInOut->Blinking());

	if (m_WarningFadeInOut->IsFinish()) {
		CSprite* m_texture = IMAGES->GetMultiSprite("BossIdleAnim", sequence);
		if (!m_deadCheck) {
			if (m_LaserLauncher->IsRun()) {		//런처가 실행중일때 원래 이미지를 감추고 스킬 애니메이션을 보여준다
				m_IsBossShow = FALSE;
			}
			else if (m_LaserLauncher->IsFinish() == TRUE) m_IsBossShow = TRUE;		//런처 작동이 끝났을 때 원래 이미지를 보여줌

			if (m_BulletLauncher->IsRun()) {
				m_IsBossShow = FALSE;
			}
			else if (m_BulletLauncher->IsFinish() == TRUE) m_IsBossShow = TRUE;

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
			m_texture->MaskDraw(m_Pos, D2D1::SizeF(1.f, 1.f), NULL, 0.0f, 1.0f, color, OpacityBrush::WHITE);
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
}

void CBossEnemy::FrameMove(DWORD elapsed)
{
	SetCollider(
		(LONG)(m_Pos.x + 0.0f),
		(LONG)(m_Pos.y + 0.0f),
		(LONG)(m_Pos.x + 200.0f),
		(LONG)(m_Pos.y + 300.0f)
	);

	if (m_WarningFadeInOut->IsFinish()) {
		m_Pos.x = Mathf::Lerp(m_Pos.x, m_TargetPos.x, deltaTime);
		m_Pos.y = Mathf::Lerp(m_Pos.y, m_TargetPos.y, deltaTime);
		if (deltaTime <= 1.0f)
			deltaTime += 0.01f;
		else {
			m_TargetPos = { 1060,  static_cast<FLOAT>(Mathf::RandomIntValue(100,200)) };
			deltaTime = 0.01f;
		}
		if (m_LaserLauncher->IsRun())
			m_LaserLauncher->SetPos(D2D1::Point2F(m_Pos.x, m_Pos.y));

		if (m_BulletLauncher->IsRun())
			m_BulletLauncher->SetPos(D2D1::Point2F(m_Pos.x, m_Pos.y));
	}
}

void CBossEnemy::Control(CInput* Input)
{
	if (m_WarningFadeInOut->IsFinish()) {
		if (m_SkillTimer->OnTimer()) {
			switch (rand() % 4) {
			case 0:
				m_LaserLauncher = new CBossLaserLauncher(D2D1::Point2F(m_Pos.x, m_Pos.y), BOSSLASER);
				OBJECT->AddObject(dynamic_cast<CGameObject*>(m_LaserLauncher));
				break;
			case 1:
				m_BulletLauncher = new CBossBulletLauncher(D2D1::Point2F(m_Pos.x, m_Pos.y), BOSSBULLETLAUNCHER);
				OBJECT->AddObject(dynamic_cast<CGameObject*>(m_BulletLauncher));
				break;
			case 2:
				for (size_t i = 0; i < 5; i++)
				{
					OBJECT->AddObject(dynamic_cast<CGameObject*>(new MisileEnemy(D2D1::Point2F(0.0f, (FLOAT)Mathf::RandomIntValue(0, 1000)), MISILE)));
				}
			default:
				for (size_t i = 0; i < 10; i++)
				{
					OBJECT->AddObject(dynamic_cast<CGameObject*>(new CNormalEnemy(D2D1::Point2F((FLOAT)MAX_WIN_WIDTH, (FLOAT)(rand() % MAX_WIN_HEIGHT)), ENEMY)));
				}
				break;
			}

		}
		if (Input->KeyDown(VK_F4))
		{
			m_LaserLauncher = new CBossLaserLauncher(D2D1::Point2F(m_Pos.x, m_Pos.y), BOSSLASER);
			OBJECT->AddObject(dynamic_cast<CGameObject*>(m_LaserLauncher));
		}
		if (Input->KeyDown(VK_F5))
		{
			m_BulletLauncher = new CBossBulletLauncher(D2D1::Point2F(m_Pos.x, m_Pos.y), BOSSBULLETLAUNCHER);
			OBJECT->AddObject(dynamic_cast<CGameObject*>(m_BulletLauncher));
		}
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
