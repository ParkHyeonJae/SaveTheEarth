#include "framework.h"

CInGameUI::CInGameUI(INT tag)
{
	this->m_tag = tag;
	m_hpBarPos = { 0,0 };
	CurHP = NULL;
	HpBarSize = { 0.0f ,0.0f };
	MAXHP = 0.0f;
	MAXIMG = 0.0f;
	hpSize = 0.0f;
	m_hpPos = { 0.0f,0.0f };

	m_LongDistancBar = CGameManager::m_ImageManager->GetImages()->GetSprite("LongBar");
	m_whereDistanceBar = CGameManager::m_ImageManager->GetImages()->GetSprite("Where");
	m_wherePosX = STARTPOINT;
	m_Score = 3000.0f;
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
	m_wherePosX = ((ENDPOINT * m_Score) / MAXSCORE);
	m_LongDistancBar->Draw(D2D1::Point2F(STARTPOINT, 820));
	m_whereDistanceBar->Draw(D2D1::Point2F(m_wherePosX, 740));
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
