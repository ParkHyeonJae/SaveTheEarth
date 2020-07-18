#include "framework.h"

CScrollBackground::CScrollBackground(D2D1_POINT_2F m_Pos, INT tag, FLOAT ScrollSpeed) : CGameObject()
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	this->ScrollSpeed = ScrollSpeed;


	m_CloudPos = m_Pos;
	m_MountainPos = m_Pos;

	//m_Sky = new CSprite(L"../Images/Stage01/Stage01_Sky.png", CGameManager::m_Gfx);
	//m_Cloud = new CSprite(L"../Images/Stage01/Stage01_Cloud.png", CGameManager::m_Gfx);
	//m_Mountain = new CSprite(L"../Images/Stage01/Stage01_Mountain.png", CGameManager::m_Gfx);
	//m_Sun = new CSprite(L"../Images/Stage01/Stage01_Sun.png", CGameManager::m_Gfx);
	//m_Trees = new CSprite(L"../Images/Stage01/Stage01_Trees.png", CGameManager::m_Gfx);
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

	m_CloudPos.x -= ScrollSpeed;


	if(m_CloudPos.x <= (MAX_WIN_WIDTH * -1))
		m_CloudPos.x = MAX_WIN_WIDTH;

	m_MountainPos.x -= ScrollSpeed;


	if(m_MountainPos.x <= (MAX_WIN_WIDTH * -1))
		m_MountainPos.x = MAX_WIN_WIDTH;

}

void CScrollBackground::Render()
{
	CGameManager::m_ImageManager->GetImages()->Render("Stage01/SKY", D2D1::Point2F(m_Pos.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
	CGameManager::m_ImageManager->GetImages()->Render("Stage01/CLOUD", D2D1::Point2F(m_CloudPos.x, 450), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
	CGameManager::m_ImageManager->GetImages()->Render("Stage01/MOUNTAIN", D2D1::Point2F(m_MountainPos.x, 550), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
	CGameManager::m_ImageManager->GetImages()->Render("Stage01/SUN", D2D1::Point2F(1200, 150), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
	CGameManager::m_ImageManager->GetImages()->Render("Stage01/TREES", D2D1::Point2F(m_Pos.x, 700), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f);
}


void CScrollBackground::Control(CInput* Input)
{
}

void CScrollBackground::Release()
{
}
