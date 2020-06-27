#include "framework.h"

CScrollBackground::CScrollBackground(D2D1_POINT_2F m_Pos, INT tag, FLOAT ScrollSpeed) : CGameObject()
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	this->ScrollSpeed = ScrollSpeed;
	m_Sprite = new CSprite(L"../Images/BG.jpg", CGameManager::m_Gfx);
}

CScrollBackground::~CScrollBackground()
{
}

void CScrollBackground::Init()
{

}
void CScrollBackground::FrameMove(DWORD elapsed)
{
	m_Pos.x -= ScrollSpeed;


	if(m_Pos.x <= (MAX_WIN_WIDTH * -1))
		m_Pos.x = MAX_WIN_WIDTH;

}

void CScrollBackground::Render()
{
	D2D1_POINT_2F center = { 0,0 };
	CGameManager::m_Gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	m_Sprite->Draw(D2D1::Point2F(m_Pos.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), &center, 0.0f);
}


void CScrollBackground::Control(CInput* Input)
{
}

void CScrollBackground::Release()
{
}
