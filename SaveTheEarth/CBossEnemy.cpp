#include "framework.h"

CBossEnemy::CBossEnemy(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/1.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/2.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/3.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/4.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/5.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/6.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/7.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/8.png", CGameManager::m_Gfx));
	m_BossAnimFunc = new CSpriteAnimation();
	m_TargetPos = { 1200, 200 };
}

CBossEnemy::~CBossEnemy()
{
}

void CBossEnemy::Init()
{
	
}

void CBossEnemy::Render()
{
	m_BossAnim[sequence]->Draw(m_Pos);

	sequence = m_BossAnimFunc->OnAnimRender(50, 0, 8);

	//m_Sprite->Draw(m_Pos);
}

void CBossEnemy::FrameMove(DWORD elapsed)
{
	 m_Pos.x = Mathf::Lerp(m_Pos.x, m_TargetPos.x, deltaTime);
	 m_Pos.y = Mathf::Lerp(m_Pos.y, m_TargetPos.y, deltaTime);
	 if (deltaTime <= 1.0f)
		 deltaTime += 0.01;
	 else {
		 m_TargetPos = { 1200,  static_cast<FLOAT>(Mathf::RandomIntValue(100,200)) };
		 deltaTime = 0.01f;
	 }
	 
}

void CBossEnemy::Control(CInput* Input)
{
}

void CBossEnemy::Release()
{
	if (m_BossAnimFunc)
	{
		delete m_BossAnimFunc;
		m_BossAnimFunc = nullptr;
	}
}
