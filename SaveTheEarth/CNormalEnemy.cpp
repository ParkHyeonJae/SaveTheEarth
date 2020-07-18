#include "framework.h"

CNormalEnemy::CNormalEnemy(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	m_TargetPos = { static_cast<FLOAT>(rand() % MAX_WIN_WIDTH), static_cast<FLOAT>(rand() % MAX_WIN_HEIGHT) };
	m_TargetPos.x -= 1600.0f;
	
	
	m_SharkAnimFunc = new CSpriteAnimation();
	m_ExplosiveAnimFunc = new CSpriteAnimation();

	m_HP = 100.0f;
	ExplosiveSequence = 0;
	SharkAnimSequence = 0;
	m_deadCheck = FALSE;
	m_isDelete = FALSE;
}

CNormalEnemy::~CNormalEnemy()
{
}

void CNormalEnemy::Init()
{

}

void CNormalEnemy::Render()
{
	if (!m_deadCheck)
	{
		angle = atan2f(m_Pos.y - m_TargetPos.y, m_Pos.x - m_TargetPos.x) * (180.0f / PI);
		SharkAnimSize = CGameManager::m_ImageManager->GetMultiImageSize("SharkAnim", SharkAnimSequence);
		D2D1_POINT_2F center = { m_Pos.x + (SharkAnimSize.width / 2), m_Pos.y + (SharkAnimSize.height / 2) };
		CGameManager::m_ImageManager->GetImages()
			->MultiRender("SharkAnim", SharkAnimSequence, m_Pos, D2D1::SizeF(1.0f, 1.0f), &center, angle);
		SharkAnimSequence = m_SharkAnimFunc->OnAnimRender(100, 0, 5);
	}
	else
	{
		CGameManager::m_ImageManager->GetImages()
			->MultiRender("ExplosiveAnim", SharkAnimSequence, m_Pos, D2D1::SizeF(1.0f, 1.0f), NULL, angle);
		SharkAnimSequence = m_ExplosiveAnimFunc->OnAnimRender(50, 0, 10);

		if (SharkAnimSequence == 9)
			m_isDelete = TRUE;
	}
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
	if (m_SharkAnimFunc)
	{
		delete m_SharkAnimFunc;
		m_SharkAnimFunc = nullptr;
	}
}
