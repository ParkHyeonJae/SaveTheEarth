#include "framework.h"

CPlayerLaserLauncher::CPlayerLaserLauncher(D2D1_POINT_2F *m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	Init();
}

CPlayerLaserLauncher::~CPlayerLaserLauncher()
{
	Release();
}

void CPlayerLaserLauncher::Init()
{
	LauncherInit();
}

void CPlayerLaserLauncher::Render()
{
	LauncherRender();
}

void CPlayerLaserLauncher::FrameMove(DWORD elapsed)
{
	LauncherUpdate(elapsed);
}

void CPlayerLaserLauncher::Control(CInput* Input)
{
}

void CPlayerLaserLauncher::Release()
{
	LauncherRelease();
}

void CPlayerLaserLauncher::LauncherInit()
{
	m_PlayerLaser.AnimFunc = new CSpriteAnimation();
	m_PlayerLaser.sequence = 0;

	m_PlayerLaserTimer = new CTimer(2000);
	m_LaserDamage = 50.0f;
	SetRun(FALSE);
	SetFinish(FALSE);
}

void CPlayerLaserLauncher::LauncherUpdate(DWORD elapsed)
{
	SetCollider(
		m_Pos->x, m_Pos->y,
		m_Pos->x + 1600, m_Pos->y + 200
	);
}


void CPlayerLaserLauncher::LauncherRender()
{
	if (!m_PlayerLaserTimer->OnTimer()) {
		SetRun(TRUE);
		SetFinish(FALSE);
		//IMAGES->Render("PlayerLaserGun", *m_Pos, 1.0f);
		IMAGES->MultiRender("PlayerLaserAnim", m_PlayerLaser.sequence, *m_Pos, D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, 1.0f);
		m_PlayerLaser.sequence = m_PlayerLaser.AnimFunc->OnAnimRender(100, 0, 7);
	}
	else {
		SetRun(FALSE);
		SetFinish(TRUE);
	}
}

void CPlayerLaserLauncher::LauncherRelease()
{
}
