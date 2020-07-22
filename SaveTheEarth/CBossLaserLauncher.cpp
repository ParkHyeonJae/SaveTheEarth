#include "framework.h"

CBossLaserLauncher::CBossLaserLauncher(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	Init();
}
CBossLaserLauncher::~CBossLaserLauncher()
{
}

void CBossLaserLauncher::Init()
{
	LauncherInit();
}

void CBossLaserLauncher::Render()
{
	LauncherRender();
}

void CBossLaserLauncher::FrameMove(DWORD elapsed)
{
	LauncherUpdate(elapsed);
}

void CBossLaserLauncher::Control(CInput* Input)
{
}

void CBossLaserLauncher::Release()
{
}

void CBossLaserLauncher::LauncherInit()
{
	m_LaserTimer = new CTimer(500);
	m_LaserChaging.AnimFunc = new CSpriteAnimation();
	m_LaserOn.AnimFunc = new CSpriteAnimation();
	m_LaserFire.AnimFunc = new CSpriteAnimation();
	m_LaserOff.AnimFunc = new CSpriteAnimation();

	m_LaserChaging.sequence = 0;
	m_LaserOn.sequence = 0;
	m_LaserFire.sequence = 0;
	m_LaserOff.sequence = 0;

	m_CurState = LaserLauncherState::LaserCharging;
}

void CBossLaserLauncher::LauncherUpdate(DWORD elapsed)
{
	if (m_LaserTimer->OnTimer())
	{
		m_CurState = (LAUNCHER_STATE)((INT)(m_CurState)+1);
	}

	
}


void CBossLaserLauncher::LauncherRender()
{
	switch (m_CurState)
	{
	case LaserLauncherState::LaserCharging:
		SetRun(TRUE);
		SetFinish(FALSE);
		IMAGES->MultiRender("BossLaser_Charging", m_LaserChaging.sequence, D2D1::Point2F(m_Pos.x - 370.0f, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, 1.0f);
		m_LaserChaging.sequence = m_LaserChaging.AnimFunc->OnAnimRender(100, 0, 8);
		break;
	case LaserLauncherState::LaserON:
		IMAGES->MultiRender("BossLaser_On", m_LaserOn.sequence, D2D1::Point2F(m_Pos.x - 170, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, 1.0f);
		m_LaserOn.sequence = m_LaserOn.AnimFunc->OnAnimRender(100, 0, 3);
		break;
	case LaserLauncherState::LaserFire:
		IMAGES->MultiRender("BossLaser_Fire", m_LaserFire.sequence, D2D1::Point2F(m_Pos.x - 1100, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, 1.0f);
		m_LaserFire.sequence = m_LaserFire.AnimFunc->OnAnimRender(100, 0, 5);
		break;
	case LaserLauncherState::LaserOff:
		IMAGES->MultiRender("BossLaser_Off", m_LaserOff.sequence, D2D1::Point2F(m_Pos.x - 1100, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, 1.0f);
		m_LaserOff.sequence = m_LaserOff.AnimFunc->OnAnimRender(100, 0, 6);
		if (m_LaserOff.sequence == 5) {
			SetRun(FALSE);
			SetFinish(TRUE);
		}
		break;
	default:
		SetRun(FALSE);
		SetFinish(TRUE);
		break;
	}
}

void CBossLaserLauncher::LauncherRelease()
{
}