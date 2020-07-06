#include "framework.h"

CTitleBackground::CTitleBackground(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	Title = new CSprite(L"../Images/Title.jpg", CGameManager::m_Gfx);
}

CTitleBackground::~CTitleBackground()
{
}

void CTitleBackground::Init()
{
}

void CTitleBackground::Render()
{

	D2D1_POINT_2F center = { 0,0 };
	CGameManager::m_Gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	Title->Draw(D2D1::Point2F(m_Pos.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), &center, 0.0f);

	//CGameManager::m_Gfx->DrawTextOut(L"Press Space Key To Start", D2D1::Point2F(MAX_WIN_WIDTH / 2, 200));
}

void CTitleBackground::FrameMove(DWORD elapsed)
{
}

void CTitleBackground::Control(CInput* Input)
{
	if (Input->KeyDown(VK_SPACE))
	{
		CGameManager::nowStatus = GAME01;
	}
}

void CTitleBackground::Release()
{
}
