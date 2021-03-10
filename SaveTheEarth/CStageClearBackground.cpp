#include "framework.h"

void CStageClearBackground::Init()
{
	m_CreditSprite = IMAGES->GetSprite("MenuUI/GameClearCredit");
}

void CStageClearBackground::Render()
{
	m_CreditSprite->Draw(D2D1::Point2F());
}

void CStageClearBackground::FrameMove(DWORD elapsed)
{
}

void CStageClearBackground::Control(CInput* Input)
{
	if (Input->KeyUp(VK_ESCAPE))
		CGameManager::nowStatus = TITLE;
}

void CStageClearBackground::Release()
{
}
