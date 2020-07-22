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
}

void CBossBulletLauncher::LauncherUpdate(DWORD elapsed)
{
}

void CBossBulletLauncher::LauncherRender()
{
}

void CBossBulletLauncher::LauncherRelease()
{
}
