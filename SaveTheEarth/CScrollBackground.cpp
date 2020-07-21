#include "framework.h"

CScrollBackground::CScrollBackground(D2D1_POINT_2F m_Pos, INT tag, FLOAT ScrollSpeed) : CGameObject()
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	this->ScrollSpeed = ScrollSpeed;


	m_CloudPos[0] = m_Pos;
	m_MountainPos[0] = m_Pos;

	m_Pos02 = m_Pos;
	m_Pos02.x += MAX_WIN_WIDTH;

	m_CloudPos[1] = m_Pos02;
	m_MountainPos[1] = m_Pos02;
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
	m_Pos02.x -= ScrollSpeed;

	if(m_Pos.x <= (MAX_WIN_WIDTH * -1))
		m_Pos.x = MAX_WIN_WIDTH;
	if (m_Pos02.x <= (MAX_WIN_WIDTH * -1))
		m_Pos02.x = MAX_WIN_WIDTH;

	m_CloudPos[0].x -= 0.5f;
	m_CloudPos[1].x -= 0.5f;


	if(m_CloudPos[0].x <= (MAX_WIN_WIDTH * -1))
		m_CloudPos[0].x = MAX_WIN_WIDTH;
	
	if(m_CloudPos[1].x <= (MAX_WIN_WIDTH * -1))
		m_CloudPos[1].x = MAX_WIN_WIDTH;

	m_MountainPos[0].x -= 1.0f;
	m_MountainPos[1].x -= 1.0f;


	if(m_MountainPos[0].x <= (MAX_WIN_WIDTH * -1))
		m_MountainPos[0].x = MAX_WIN_WIDTH;
	
	if(m_MountainPos[1].x <= (MAX_WIN_WIDTH * -1))
		m_MountainPos[1].x = MAX_WIN_WIDTH;

}

void CScrollBackground::Render()
{
	switch (CGameManager::m_Level) {
	case 1:
		CGameManager::m_ImageManager->GetImages()->Render("Stage01/SKY", D2D1::Point2F(0, 0), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
		//CGameManager::m_ImageManager->GetImages()->Render("Stage01/SKY", D2D1::Point2F(m_Pos02.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);

		CGameManager::m_ImageManager->GetImages()->Render("Stage01/CLOUD", D2D1::Point2F(m_CloudPos[0].x, 450), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
		CGameManager::m_ImageManager->GetImages()->Render("Stage01/CLOUD", D2D1::Point2F(m_CloudPos[1].x, 450), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);

		CGameManager::m_ImageManager->GetImages()->Render("Stage01/MOUNTAIN", D2D1::Point2F(m_MountainPos[0].x, 550), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
		CGameManager::m_ImageManager->GetImages()->Render("Stage01/MOUNTAIN", D2D1::Point2F(m_MountainPos[1].x, 550), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);

		CGameManager::m_ImageManager->GetImages()->Render("Stage01/SUN", D2D1::Point2F(1200, 150), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);

		CGameManager::m_ImageManager->GetImages()->Render("Stage01/TREES", D2D1::Point2F(m_Pos.x, 700), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
		CGameManager::m_ImageManager->GetImages()->Render("Stage01/TREES", D2D1::Point2F(m_Pos02.x, 700), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
		break;
	case 2:
		CGameManager::m_ImageManager->GetImages()->Render("Stage02/SKY", D2D1::Point2F(0, 0), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
		//CGameManager::m_ImageManager->GetImages()->Render("Stage02/SKY", D2D1::Point2F(m_Pos02.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);

		CGameManager::m_ImageManager->GetImages()->Render("Stage02/MOUNTAIN", D2D1::Point2F(m_MountainPos[0].x, 550), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
		CGameManager::m_ImageManager->GetImages()->Render("Stage02/MOUNTAIN", D2D1::Point2F(m_MountainPos[1].x, 550), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);

		CGameManager::m_ImageManager->GetImages()->Render("Stage02/TREES", D2D1::Point2F(m_Pos.x, 700), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
		CGameManager::m_ImageManager->GetImages()->Render("Stage02/TREES", D2D1::Point2F(m_Pos02.x, 700), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
		break;
	}



}


void CScrollBackground::Control(CInput* Input)
{
}

void CScrollBackground::Release()
{
}
