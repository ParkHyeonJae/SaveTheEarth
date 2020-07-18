#include "framework.h"

CInGameUI::CInGameUI(INT tag)
{
	this->m_tag = tag;
	m_hpBarPos = { 0,0 };
}

CInGameUI::~CInGameUI()
{
}



void CInGameUI::Init()
{
	MAXHP = MAX_PLAYER_HP;
	HpBarSize.width = MAXIMG = CGameManager::m_ImageManager->GetImageSize("playerHpBar_foreground").width;
	HpBarSize.height = CGameManager::m_ImageManager->GetImageSize("playerHpBar_foreground").height;
}

void CInGameUI::Render()
{
	CurHP = CGameManager::m_playerHp;
	
	CGameManager::m_ImageManager->GetImages()->Render("playerHpBar_background", m_Pos, 1.0f);

	CurIMG = (CurHP * MAXIMG) / MAXHP;

	m_hpPos = { m_Pos.x + 183, m_Pos.y + 58 };
	D2D1_RECT_F hpSrc = {
		m_hpPos.x,
		m_hpPos.y,
		m_hpPos.x + CurIMG,
		m_hpPos.y + HpBarSize.height
	};
	CGameManager::m_ImageManager->GetImages()->Render("playerHpBar_foreground", m_hpPos, &hpSrc);
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
