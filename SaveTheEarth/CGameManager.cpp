#include "framework.h"

CGraphics* CGameManager::m_Gfx = NULL;
CInput* CGameManager::m_Input = NULL;
CObjectManager* CGameManager::m_ObjectManager = NULL;
CImageManager* CGameManager::m_ImageManager = NULL;
FLOAT CGameManager::m_ScrollSpeed = 10.0f;
D2D1_POINT_2F CGameManager::m_PlayerPos = { -100, 350 };
FLOAT CGameManager::radian = PI / 180.0f;
INT CGameManager::nowStatus = TITLE;
DWORD CGameManager::m_fps = 0;
FLOAT CGameManager::m_playerHp = 1000.0f;
BOOL CGameManager::isinvincibility = FALSE;
BOOL CGameManager::EnableInput = TRUE;
PLAYER_ATTR CGameManager::m_PlayerAttribute = { 20.0f, 0.0f, 0.0f };
INT CGameManager::m_Level = 1;

CGameManager::CGameManager(CGraphics* m_Gfx, CInput* m_Input, CObjectManager* m_ObjectManager, CImageManager* m_ImageManager)
{
	this->m_Gfx = m_Gfx;
	this->m_Input = m_Input;
	this->m_ObjectManager = m_ObjectManager;
	this->m_ImageManager = m_ImageManager;


}

CGameManager::~CGameManager()
{
}

void CGameManager::Init()
{
	CGameManager::m_ScrollSpeed = 10.0f;
	CGameManager::m_PlayerPos = { -100, 350 };
	CGameManager::radian = PI / 180.0f;
	CGameManager::isinvincibility = FALSE;
	CGameManager::EnableInput = TRUE;
	CGameManager::m_PlayerAttribute = { 20.0f, 0.0f, 0.0f };
	CGameManager::m_Level = 1;
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
