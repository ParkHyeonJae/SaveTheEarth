#include "framework.h"

CGame::CGame()
{
}

CGame::~CGame()
{
	Destroy();
}

INT CGame::Init()
{
	CDX2DApp::Init();

	m_ObjectManager = new CObjectManager();
	m_GameManager = new CGameManager(m_Gfx, m_Input, m_ObjectManager);


	m_GameScene01 = new CGameScene01();
	m_GameScene02 = new CGameScene02();

	m_SceneList.push_back(m_GameScene01);
	m_SceneList.push_back(m_GameScene02);

	m_GameManager->Init();


	auto iter = m_SceneList.begin();
	std::advance(iter, CGameManager::nowStatus);

	(*iter)->Init();
	
	return 0;
}

void CGame::Destroy()
{
	auto iter = m_SceneList.begin();
	std::advance(iter, CGameManager::nowStatus);

	(*iter)->Release();
	if (m_GameManager)
	{
		m_GameManager->Release();
		delete m_GameManager;
	}
}

INT CGame::FrameMove(DWORD elapsed)
{
	CDX2DApp::FrameMove(elapsed);

	static INT wasStatus = CGameManager::nowStatus;

	auto iter = m_SceneList.begin();
	std::advance(iter, CGameManager::nowStatus);

	if (wasStatus != CGameManager::nowStatus) {
		(*iter)->Init();
		wasStatus = CGameManager::nowStatus;
	}


	(*iter)->FrameMove(elapsed);

	m_GameManager->FrameMove(elapsed);


	return 0;
}
INT CGame::Control(CInput* m_Input)
{
	auto iter = m_SceneList.begin();
	std::advance(iter, CGameManager::nowStatus);
	(*iter)->Control(m_Input);

	m_GameManager->Control(m_Input);


	return 0;
}
INT CGame::Render()
{
	m_Gfx->BeginDraw();
	m_Gfx->ClearScreen(1.0f, 1.0f, 1.0f);
	
	m_GameManager->Render();

	auto iter = m_SceneList.begin();
	std::advance(iter, CGameManager::nowStatus);
	(*iter)->Render();

	

#ifdef _DEBUG
	WCHAR fpsStr[256];
	wsprintfW(fpsStr, L"MODE:DEBUG\n fps: %d", m_fps);
	m_Gfx->DrawTextOut(fpsStr, D2D1::Point2F(0, 0));
#else
	WCHAR fpsStr[256];
	wsprintfW(fpsStr, L"MODE:RELEASE\n fps: %d", m_fps);
	m_Gfx->DrawTextOut(fpsStr, D2D1::Point2F(0, 0));
#endif

	m_Gfx->EndDraw();
	return 0;
}



LRESULT CGame::MsgProc(HWND, UINT, WPARAM, LPARAM)
{
	return LRESULT();
}
