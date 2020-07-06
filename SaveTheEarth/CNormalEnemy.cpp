#include "framework.h"

CNormalEnemy::CNormalEnemy(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	m_TargetPos = { static_cast<FLOAT>(rand() % MAX_WIN_WIDTH), static_cast<FLOAT>(rand() % MAX_WIN_HEIGHT) };
	m_TargetPos.x -= 1600.0f;
	
	
	
	m_Sprite = new CSprite(L"../Images/Enemy.png", CGameManager::m_Gfx);
}

CNormalEnemy::~CNormalEnemy()
{
}

void CNormalEnemy::Init()
{
	
}

void CNormalEnemy::Render()
{
	
	angle = atan2f(m_Pos.y - m_TargetPos.y, m_Pos.x - m_TargetPos.x) * (180.0f / PI);
	//printf("Target: x= %f, y=%f\n angle:%f\n", m_TargetPos.x, m_TargetPos.y, angle);
	D2D1_POINT_2F center = { m_Pos.x + (m_Sprite->GetBmp()->GetSize().width / 2), m_Pos.y + (m_Sprite->GetBmp()->GetSize().height / 2) };
	m_Sprite->Draw(m_Pos, D2D1::SizeF(1.0f, 1.0f), &center, angle);
	
}

void CNormalEnemy::FrameMove(DWORD elapsed)
{
	
	if (m_Pos.x < m_TargetPos.x)
		m_Pos.x++;
	if (m_Pos.x > m_TargetPos.x)
		m_Pos.x--;
	if (m_Pos.y < m_TargetPos.y)
		m_Pos.y++;
	if (m_Pos.y > m_TargetPos.y)
		m_Pos.y--;
	
}

void CNormalEnemy::Control(CInput* Input)
{

	//m_NormalEnemyBullet = new CNormalEnemyBullet(m_Pos, EBULLET);
	//CGameManager::m_ObjectManager->AddObject(dynamic_cast<CGameObject*>(m_NormalEnemyBullet));
}

void CNormalEnemy::Release()
{
}
