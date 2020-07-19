#include "framework.h"

CBossEnemy::CBossEnemy(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;

	m_BossAnimFunc = new CSpriteAnimation();
	m_TargetPos = { 1200, 200 };
	sequence = 0;


}

CBossEnemy::~CBossEnemy()
{
}

void CBossEnemy::Init()
{
	
}
void CBossEnemy::Render()
{
	CGameManager::m_ImageManager->GetImages()->MultiRender("BossIdleAnim", sequence, m_Pos, D2D1::SizeF(1.f, 1.f), NULL, 0.0f);
	
	//CGameManager::m_Gfx->GetRenderTarget()->Clear(D2D1::ColorF(1.0f, 1.0f, 1.0f, 1.0f));
	sequence = m_BossAnimFunc->OnAnimRender(50, 0, 8);
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
