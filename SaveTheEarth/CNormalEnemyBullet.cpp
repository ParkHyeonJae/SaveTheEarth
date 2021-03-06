#include "framework.h"

CNormalEnemyBullet::CNormalEnemyBullet(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	BulletSpeed = 10.0f;
}

CNormalEnemyBullet::~CNormalEnemyBullet()
{
}

void CNormalEnemyBullet::Init()
{
}

void CNormalEnemyBullet::Render()
{
	//CGameManager::m_ImageManager->GetImages()->Render("NormalEnemyBullet", m_Pos, 1.0f);
}

void CNormalEnemyBullet::FrameMove(DWORD elapsed)
{
	m_Pos.x-= BulletSpeed;
}

void CNormalEnemyBullet::Control(CInput* Input)
{
	

}

void CNormalEnemyBullet::Release()
{

}

BOOL CNormalEnemyBullet::IsMapOut()
{
	if (m_Pos.x < 0 || MAX_WIN_WIDTH < m_Pos.x)
		return TRUE;
	if (MAX_WIN_HEIGHT < m_Pos.y || m_Pos.y < 0)
		return TRUE;

	return FALSE;
}