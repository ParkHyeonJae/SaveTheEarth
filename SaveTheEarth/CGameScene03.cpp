#include "framework.h"

CGameScene03::CGameScene03()
{
}

CGameScene03::~CGameScene03()
{
	Release();
}

void CGameScene03::Init()
{
	CGameManager::m_ObjectManager = GetObjectManager();
	m_StageClearBackground = new CStageClearBackground();

	AddObject(dynamic_cast<CGameObject*>(m_StageClearBackground));
	SOUND->StopSoundChannelFunc();
	CSceneObject::Init();
	AllInitalize();
}

void CGameScene03::FrameMove(DWORD elapsed)
{
	SOUND->UpdateSound();
	CSceneObject::FrameMove(elapsed);
	AllFrameMove(elapsed);
}

void CGameScene03::Render()
{
	

	CSceneObject::Render();
	AllRender();
}

void CGameScene03::Control(CInput* m_Input)
{
	CSceneObject::Control(m_Input);
	AllControl(m_Input);
}

void CGameScene03::Release()
{
	SOUND->ReleaseSound();
	CSceneObject::Release();
	AllRelease();
}
