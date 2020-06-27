#include "framework.h"

CPlayer::CPlayer(D2D1_POINT_2F m_Pos, INT tag) : CGameObject()
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;

	m_Sprite = new CSprite(L"../Images/Player.png", CGameManager::m_Gfx);
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Init()
{
	//printf("Pos X: %f Pos Y : %f\n TAG : %d",m_Pos.x, m_Pos.y, m_tag);
	MoveSpeed = 15.0f;
}


void CPlayer::FrameMove(DWORD elapsed)
{
}

void CPlayer::Control(CInput* m_Input)
{
	if (m_Input->KeyPress(VK_UP))
	{
		m_Pos.y -= MoveSpeed;
	}
	if (m_Input->KeyPress(VK_DOWN))
	{
		m_Pos.y += MoveSpeed;
	}
	if (m_Input->KeyPress(VK_LEFT))
	{
		m_Pos.x -= MoveSpeed;
	}
	if (m_Input->KeyPress(VK_RIGHT))
	{
		m_Pos.x += MoveSpeed;
	}
}

void CPlayer::Render()
{
	D2D1_POINT_2F center = { 0,0 };
	CGameManager::m_Gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	m_Sprite->Draw(D2D1::Point2F(m_Pos.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), &center, 0.0f);
}


void CPlayer::Release()
{
}
