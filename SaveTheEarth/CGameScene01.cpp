#include "framework.h"

CGameScene01::CGameScene01()
{
}

CGameScene01::~CGameScene01()
{
	Release();
}

void CGameScene01::Init()
{
	CGameManager::m_ObjectManager = GetObjectManager();
	m_TitleBG = new CTitleBackground(D2D1::Point2F(0, 0), BACKGROUND);
	AddObject(dynamic_cast<CGameObject*>(m_TitleBG));
	
	CSceneObject::Init();
	AllInitalize();
}

void CGameScene01::FrameMove(DWORD elapsed)
{


	CSceneObject::FrameMove(elapsed);
	AllFrameMove(elapsed);
}

void CGameScene01::Render()
{


	CSceneObject::Render();
	AllRender();
}

void CGameScene01::Control(CInput* m_Input)
{
	
	CSceneObject::Control(m_Input);
	AllControl(m_Input);
}

void CGameScene01::Release()
{

	CSceneObject::Release();
	AllRelease();
}
