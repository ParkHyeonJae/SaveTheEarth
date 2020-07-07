#include "framework.h"

CNormalEnemy::CNormalEnemy(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	m_TargetPos = { static_cast<FLOAT>(rand() % MAX_WIN_WIDTH), static_cast<FLOAT>(rand() % MAX_WIN_HEIGHT) };
	m_TargetPos.x -= 1600.0f;
	
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/1.png", CGameManager::m_Gfx));
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/2.png", CGameManager::m_Gfx));
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/3.png", CGameManager::m_Gfx));
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/4.png", CGameManager::m_Gfx));
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/5.png", CGameManager::m_Gfx));
	m_SharkAnimFunc = new CSpriteAnimation();

	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/1.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/2.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/3.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/4.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/5.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/6.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/7.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/8.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/9.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/10.png", CGameManager::m_Gfx));
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
		//printf("Target: x= %f, y=%f\n angle:%f\n", m_TargetPos.x, m_TargetPos.y, angle);
		D2D1_POINT_2F center = { m_Pos.x + (m_SharkAnim[SharkAnimSequence]->GetBmp()->GetSize().width / 2), m_Pos.y + (m_SharkAnim[SharkAnimSequence]->GetBmp()->GetSize().height / 2) };
		m_SharkAnim[SharkAnimSequence]->Draw(m_Pos, D2D1::SizeF(1.0f, 1.0f), &center, angle);

		SharkAnimSequence = m_SharkAnimFunc->OnAnimRender(100, 0, 5);
	}
	else
	{
		m_ExplosiveAnim[SharkAnimSequence]->Draw(m_Pos);
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
