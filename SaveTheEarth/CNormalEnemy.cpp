#include "framework.h"

CNormalEnemy::CNormalEnemy(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;

	m_Sprite = new CSprite(L"../Images/Enemy.png", CGameManager::m_Gfx);
}

CNormalEnemy::~CNormalEnemy()
{
}

void CNormalEnemy::Init()
{
	m_TargetPos = { static_cast<FLOAT>(MAX_WIN_WIDTH + (rand() % MAX_WIN_WIDTH + 20)), static_cast<FLOAT>(rand() % MAX_WIN_HEIGHT) };

}

void CNormalEnemy::Render()
{
	D2D1_POINT_2F center = { m_Pos.x + (m_Sprite->GetBmp()->GetSize().width / 2),  m_Pos.y + (m_Sprite->GetBmp()->GetSize().height) };
	m_Sprite->Draw(m_Pos, D2D1::SizeF(1.0f, 1.0f), &center, angle);
}

void CNormalEnemy::FrameMove(DWORD elapsed)
{
	angle = atan2f((CGameManager::m_PlayerPos.y - m_TargetPos.y), CGameManager::m_PlayerPos.x - m_TargetPos.x);
	if (m_Pos.x < m_TargetPos.x)
		m_Pos.x--;
	if (m_Pos.x > m_TargetPos.x)
		m_Pos.x++;
	if (m_Pos.y < m_TargetPos.y)
		m_Pos.y++;
	if (m_Pos.y > m_TargetPos.y)
		m_Pos.y--;

}

void CNormalEnemy::Control(CInput* Input)
{
}

void CNormalEnemy::Release()
{
}
