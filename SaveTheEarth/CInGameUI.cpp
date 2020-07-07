#include "framework.h"

CInGameUI::CInGameUI(INT tag)
{
	this->m_tag = tag;
	m_hpBarPos = { 0,0 };
	m_playerHpBar_background = new CSprite(L"../Images/null hp.png", CGameManager::m_Gfx);
	m_playerHpBar_foreground = new CSprite(L"../Images/HP bar.png", CGameManager::m_Gfx);
}

CInGameUI::~CInGameUI()
{
}


FLOAT CurIMG = 0;
void CInGameUI::Init()
{
	MAXHP = MAX_PLAYER_HP;
	MAXIMG = m_playerHpBar_foreground->GetBmp()->GetSize().width;
}

void CInGameUI::Render()
{
	CurHP = CGameManager::m_playerHp;
	
	m_playerHpBar_background->Draw(m_Pos);

	CurIMG = (CurHP * MAXIMG) / MAXHP;

	m_hpPos = { m_Pos.x + 183, m_Pos.y + 58 };
	D2D1_RECT_F hpSrc = {
		m_hpPos.x,
		m_hpPos.y,
		m_hpPos.x + CurIMG,
		m_hpPos.y + m_playerHpBar_foreground->GetBmp()->GetSize().height,
	};
	//D2D1_POINT_2F center = { m_hpPos.x + m_playerHpBar_foreground->GetBmp()->GetSize().width / 2, m_hpPos.x + m_playerHpBar_foreground->GetBmp()->GetSize().height / 2 };
	//m_playerHpBar_foreground->Draw(&hpSrc, m_hpPos, D2D1::Point2F(1.0f, 1.0f), &center, 0.0f);
	m_playerHpBar_foreground->Draw(m_hpPos, &hpSrc);
}

void CInGameUI::FrameMove(DWORD elapsed)
{
}

void CInGameUI::Control(CInput* Input)
{
}

void CInGameUI::Release()
{
}
