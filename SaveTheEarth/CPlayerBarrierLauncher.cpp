#include "framework.h"

CPlayerBarrierLauncher::CPlayerBarrierLauncher(D2D1_POINT_2F* m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	Init();
}

CPlayerBarrierLauncher::~CPlayerBarrierLauncher()
{
	Release();
}

void CPlayerBarrierLauncher::Init()
{
	LauncherInit();
}

void CPlayerBarrierLauncher::Render()
{
	LauncherRender();
}

void CPlayerBarrierLauncher::FrameMove(DWORD elapsed)
{
	LauncherUpdate(elapsed);
}

void CPlayerBarrierLauncher::Control(CInput* Input)
{
}

void CPlayerBarrierLauncher::Release()
{
	LauncherRelease();
}

void CPlayerBarrierLauncher::LauncherInit()
{
	m_Barrier.AnimFunc = new CSpriteAnimation();
	m_Barrier.sequence = 0;

	m_BarrierTimer = new CTimer(5000);
}

void CPlayerBarrierLauncher::LauncherUpdate(DWORD elapsed)
{
	SetCollider(
		m_Pos->x - 100, m_Pos->y - 120,
		m_Pos->x, m_Pos->y
	);
}

void CPlayerBarrierLauncher::LauncherRender()
{
	if (!m_BarrierTimer->OnTimer()) {		//n초가 안됬을 때
		SetRun(TRUE);
		SetFinish(FALSE);
		CGameManager::isinvincibility = TRUE;
		IMAGES->MultiRender("PlayerBarrier", m_Barrier.sequence,
			D2D1::Point2F(GetCollider().left, GetCollider().top), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, 1.0f);
		m_Barrier.sequence = m_Barrier.AnimFunc->OnAnimRender(100, 0, 6);
	}
	else {		//n초가 되었을 시
		CGameManager::isinvincibility = FALSE;
		SetRun(FALSE);
		SetFinish(TRUE);
	}
}

void CPlayerBarrierLauncher::LauncherRelease()
{
}
