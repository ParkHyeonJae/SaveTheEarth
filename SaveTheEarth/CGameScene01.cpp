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
	
	//SOUND->InitSound();
	SOUND->StopSoundChannelFunc();
	SOUND->PlaySoundFunc("Pote_m-milky way");

	CSceneObject::Init();
	AllInitalize();
}

void CGameScene01::FrameMove(DWORD elapsed)
{
	SOUND->UpdateSound();
	CSceneObject::FrameMove(elapsed);
	AllFrameMove(elapsed);
}

void CGameScene01::Render()
{
#ifdef _DEBUG
	WCHAR fpsStr[256];
	wsprintfW(fpsStr, L"MODE:DEBUG\n fps: %d", CGameManager::m_fps);
	CGameManager::m_Gfx->DrawTextOut(fpsStr, D2D1::Point2F(0, 0));
#else
	WCHAR fpsStr[256];
	wsprintfW(fpsStr, L"MODE:RELEASE\n fps: %d", CGameManager::m_fps);
	CGameManager::m_Gfx->DrawTextOut(fpsStr, D2D1::Point2F(0, 0));
#endif

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
	//SOUND->ReleaseSound();
	CSceneObject::Release();
	AllRelease();
}
