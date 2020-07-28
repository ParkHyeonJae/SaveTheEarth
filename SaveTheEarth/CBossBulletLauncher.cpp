#include "framework.h"

CBossBulletLauncher::CBossBulletLauncher(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	Init();
}

CBossBulletLauncher::~CBossBulletLauncher()
{
	Release();
}

void CBossBulletLauncher::Init()
{
	LauncherInit();
}

void CBossBulletLauncher::Render()
{
	LauncherRender();
}

void CBossBulletLauncher::FrameMove(DWORD elapsed)
{
	LauncherUpdate(elapsed);
}

void CBossBulletLauncher::Control(CInput* Input)
{
	
}

void CBossBulletLauncher::Release()
{
	LauncherRelease();
}

void CBossBulletLauncher::LauncherInit()
{
	m_BulletTimer = new CTimer(500);
	m_BulletSkillEndTimer = new CTimer(10000);
	m_BulletIdle.AnimFunc = new CSpriteAnimation();
	m_BulletIdle.sequence = 0;
	m_pattern = (Pattern)(rand() % 3);
}

void CBossBulletLauncher::LauncherUpdate(DWORD elapsed)
{
	if (m_BulletSkillEndTimer->OnTimer()) {
		SetRun(FALSE);
		SetFinish(TRUE);
		m_pattern = (Pattern)(rand() % 3);

	}
	if (m_BulletTimer->OnTimer())
	{
		SetRun(TRUE);
		SetFinish(FALSE);
		switch (m_pattern) {
		case Pattern::Tracking:
			m_BulletTimer->SetTimer(500);
			OBJECT->AddObject(dynamic_cast<CGameObject*>
				(new CBossBullet(D2D1::Point2F(m_Pos.x, m_Pos.y + 250.0f), Pattern::Tracking, 0.0f, BOSSBULLET)));
			break;
		case Pattern::Circle:
			m_BulletTimer->SetTimer(1000);
			for (float i = 0; i <= 360; i += 45.0f)
			{
				OBJECT->AddObject(dynamic_cast<CGameObject*>
					(new CBossBullet(D2D1::Point2F(m_Pos.x, m_Pos.y + 250.0f), Pattern::Circle, i, BOSSBULLET)));
			}
			break;
		case Pattern::Explosive:
			m_BulletTimer->SetTimer(1000);
			OBJECT->AddObject(dynamic_cast<CGameObject*>
				(new CBossBullet(D2D1::Point2F(m_Pos.x, m_Pos.y + 250.0f), Pattern::Explosive, 0.0f, BOSSBULLET)));
			break;
		}
		
	}
}

void CBossBulletLauncher::LauncherRender()
{
	if (IsRun() && !IsFinish()) {
		IMAGES->MultiRender("BossBulletIdle", m_BulletIdle.sequence, D2D1::Point2F(m_Pos.x - 215.0f, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, 1.0f);
		m_BulletIdle.sequence = m_BulletIdle.AnimFunc->OnAnimRender(100, 0, 5);
	}
}

void CBossBulletLauncher::LauncherRelease()
{
}
