#include "framework.h"

CPlayerBullet::CPlayerBullet(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	m_Sprite = new CSprite(L"../Images/energy_blast-01.png", CGameManager::m_Gfx);
}

CPlayerBullet::~CPlayerBullet()
{
}

void CPlayerBullet::Init()
{
}

void CPlayerBullet::Render()
{
	
	m_Sprite->Draw(m_Pos);
}

void CPlayerBullet::FrameMove(DWORD elapsed)
{

	m_Pos.x += 5.0f * elapsed;
}

void CPlayerBullet::Control(CInput* Input)
{
}

void CPlayerBullet::Release()
{
}

BOOL CPlayerBullet::IsMapOut()
{
	if (MAX_WIN_WIDTH < 0 || MAX_WIN_WIDTH < m_Pos.x)
		return TRUE;
	if (MAX_WIN_HEIGHT < m_Pos.y || m_Pos.y < 0)
		return TRUE;

	return FALSE;
}
