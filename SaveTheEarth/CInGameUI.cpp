#include "framework.h"
#include "CScoreManager.h"

CInGameUI::CInGameUI(INT tag)
{
	this->m_tag = tag;
	CurHP = NULL;
	m_hpPos = { 183, 58 };

	m_LongDistancBar = CGameManager::m_ImageManager->GetImages()->GetSprite("LongBar");
	m_whereDistanceBar = CGameManager::m_ImageManager->GetImages()->GetSprite("Where");
	m_wherePosX = STARTPOINT;

	Init();
}

CInGameUI::~CInGameUI()
{
}

void CInGameUI::Init()
{
	m_UserHP = new CHealthBar("playerHpBar_background", "playerHpBar_foreground", m_hpPos, TRUE, FALSE);
}

void CInGameUI::Render()
{
	CurHP = CGameManager::m_playerHp;
	m_UserHP->Setting(MAX_PLAYER_HP, CurHP);

	CGameManager::m_ImageManager->GetImages()->Render("playerHpBar_background", m_Pos, 1.0f);
	D2D1_RECT_F hpSrc = {
		0,
		0,
		m_UserHP->RestIMG() * -1,
		0
	};
	CGameManager::m_ImageManager->GetImages()->Render("playerHpBar_foreground", m_hpPos, &hpSrc);
	m_wherePosX = ((ENDPOINT * Score::GETSCORE) / MAXSCORE);
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
