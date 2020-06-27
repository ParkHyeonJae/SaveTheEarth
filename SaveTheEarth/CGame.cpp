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


	m_ScrollBackground01 = new CScrollBackground(D2D1::Point2F(0, 0), BACKGROUND, CGameManager::m_ScrollSpeed);
	m_ScrollBackground02 = new CScrollBackground(D2D1::Point2F(MAX_WIN_WIDTH, 0), BACKGROUND, CGameManager::m_ScrollSpeed);
	m_Player = new CPlayer(D2D1::Point2F(50, 250), PLAYER);

	
	m_ObjectManager->AddObject((CGameObject*)m_ScrollBackground01);
	m_ObjectManager->AddObject((CGameObject*)m_ScrollBackground02);
	m_ObjectManager->AddObject((CGameObject*)m_Player);



	m_GameManager->Init();
	return 0;
}

void CGame::Destroy()
{
	if (m_GameManager)
	{
		m_GameManager->Release();
		delete m_GameManager;
	}
	delete m_ObjectManager;
}

INT CGame::FrameMove(DWORD elapsed)
{
	CDX2DApp::FrameMove(elapsed);

	m_GameManager->FrameMove(elapsed);
	return 0;
}
INT CGame::Control(CInput* m_Input)
{
	m_GameManager->Control(m_Input);
	return 0;
}
INT CGame::Render()
{
	m_Gfx->BeginDraw();
	m_Gfx->ClearScreen(1.0f, 1.0f, 1.0f);
	
	m_GameManager->Render();

	/*D2D1_POINT_2F center = { 0,0 };
	m_bg->Draw(D2D1::Point2F(0, 0), D2D1::SizeF(2.2f, 2.1f), &center, 0.0f);
	m_Gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());

	
	m_sprite->Draw(D2D1::Point2F(500, 420), D2D1::SizeF(1.0f, 1.0f), &center, 0.0f);


	m_Gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	m_Gfx->DrawTextOut(L"Click The Button!", D2D1::Point2F(0, 0));
	*/


	m_Gfx->EndDraw();
	return 0;
}



LRESULT CGame::MsgProc(HWND, UINT, WPARAM, LPARAM)
{
	return LRESULT();
}
