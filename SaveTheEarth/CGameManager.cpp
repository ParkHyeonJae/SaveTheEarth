#include "framework.h"

CGraphics* CGameManager::m_Gfx = NULL;
CInput* CGameManager::m_Input = NULL;
CObjectManager* CGameManager::m_ObjectManager = NULL;
FLOAT CGameManager::m_ScrollSpeed = 10.0f;
CGameManager::CGameManager(CGraphics* m_Gfx, CInput* m_Input, CObjectManager* m_ObjectManager)
{
	this->m_Gfx = m_Gfx;
	this->m_Input = m_Input;
	this->m_ObjectManager = m_ObjectManager;
}

CGameManager::~CGameManager()
{
}

void CGameManager::Init()
{
	m_ObjectManager->Init();
}

void CGameManager::FrameMove(DWORD elapsed)
{
	m_ObjectManager->FrameMove(elapsed);
}

void CGameManager::Control(CInput* m_Input)
{
	m_ObjectManager->Control(m_Input);
}

void CGameManager::Render()
{
	m_ObjectManager->Render();
}

void CGameManager::Release()
{
	m_ObjectManager->Release();
}
