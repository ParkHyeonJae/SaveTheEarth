#include "framework.h"

CGraphics* CGameManager::m_Gfx = NULL;
CInput* CGameManager::m_Input = NULL;
CObjectManager* CGameManager::m_ObjectManager = NULL;
FLOAT CGameManager::m_ScrollSpeed = 10.0f;
D2D1_POINT_2F CGameManager::m_PlayerPos = { 0,0 };
FLOAT CGameManager::radian = PI / 180.0f;
INT CGameManager::nowStatus = TITLE;
DWORD CGameManager::m_fps = 0;
FLOAT CGameManager::m_playerHp = 1000.0f;
Cimage* CGameManager::m_Images = NULL;

CGameManager::CGameManager(CGraphics* m_Gfx, CInput* m_Input, CObjectManager* m_ObjectManager)
{
	this->m_Gfx = m_Gfx;
	this->m_Input = m_Input;
	this->m_ObjectManager = m_ObjectManager;

	m_Images = new Cimage();

	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (0).png", CGameManager::m_Gfx));
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (1).png", CGameManager::m_Gfx));
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (2).png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("RifleBullet", m_BulletSprites);
}

CGameManager::~CGameManager()
{
}

void CGameManager::Init()
{
	
}

void CGameManager::FrameMove(DWORD elapsed)
{
	
}

void CGameManager::Control(CInput* m_Input)
{
	
}

void CGameManager::Render()
{
	
}

void CGameManager::Release()
{
	
}
