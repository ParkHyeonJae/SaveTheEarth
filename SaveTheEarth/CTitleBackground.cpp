#include "framework.h"

CTitleBackground::CTitleBackground(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	m_Title = CGameManager::m_ImageManager->GetImages()->GetSprite("Title/Title");
	m_Logo = CGameManager::m_ImageManager->GetImages()->GetSprite("Title/Logo");
	m_Cloud01 = CGameManager::m_ImageManager->GetImages()->GetSprite("Title/Cloud");
	m_Cloud02 = CGameManager::m_ImageManager->GetImages()->GetSprite("Title/Cloud");

	m_GameStart[IDLE] =		CGameManager::m_ImageManager->GetImages()->GetSprite("UI/GameStart");
	m_GameStart[SELECT] =	CGameManager::m_ImageManager->GetImages()->GetSprite("UI/GameStart_SELECT");
	m_GameStart[PRESS] =	CGameManager::m_ImageManager->GetImages()->GetSprite("UI/GameStart_PRESS");

	m_HowToPlay[IDLE] = CGameManager::m_ImageManager->GetImages()->GetSprite("UI/HowToPlay");
	m_HowToPlay[SELECT] = CGameManager::m_ImageManager->GetImages()->GetSprite("UI/HowToPlay_SELECT");
	m_HowToPlay[PRESS] = CGameManager::m_ImageManager->GetImages()->GetSprite("UI/HowToPlay_PRESS");

	m_Credit[IDLE] = CGameManager::m_ImageManager->GetImages()->GetSprite("UI/Credit");
	m_Credit[SELECT] = CGameManager::m_ImageManager->GetImages()->GetSprite("UI/Credit_SELECT");
	m_Credit[PRESS] = CGameManager::m_ImageManager->GetImages()->GetSprite("UI/Credit_PRESS");

	m_Option[IDLE] = CGameManager::m_ImageManager->GetImages()->GetSprite("UI/Option");
	m_Option[SELECT] = CGameManager::m_ImageManager->GetImages()->GetSprite("UI/Option_SELECT");
	m_Option[PRESS] = CGameManager::m_ImageManager->GetImages()->GetSprite("UI/Option_PRESS");

	m_Exit[IDLE] = CGameManager::m_ImageManager->GetImages()->GetSprite("UI/Exit");
	m_Exit[SELECT] = CGameManager::m_ImageManager->GetImages()->GetSprite("UI/Exit_SELECT");
	m_Exit[PRESS] = CGameManager::m_ImageManager->GetImages()->GetSprite("UI/Exit_PRESS");

	
	m_UISelectAnimFunc = new CSpriteAnimation();
	m_UISelectAnim = CGameManager::m_ImageManager->GetImages()->GetMultiSprite("UISelectAnim");

	m_CreditSprite = CGameManager::m_ImageManager->GetImages()->GetSprite("Credit");
	m_CreditCheck = FALSE;
}

CTitleBackground::~CTitleBackground()
{
}
void CTitleBackground::Init()
{
	m_CloudPosX01 = 0.0f;
	m_CloudPosX02 = MAX_WIN_WIDTH;
	m_CloudMoveSpeed = 0.15f;

	m_LogoPosY = 50.0f;
	m_UIPos = { 1200,350 };

	m_uiSequence = 0;
	for (INT i = 0; i < (sizeof(m_uiState) / sizeof(INT)); i++)
	{
		m_uiState[i] = IDLE;
	}
	m_uiSelected = -1;

	UIOffset = 26.0f;

	m_UISelectAnimSequence = 0;

	
	GameStartUIPos = D2D1::Point2F(m_UIPos.x - UIOffset, m_UIPos.y - UIOffset);
	HowToPlayUIPos = D2D1::Point2F(m_UIPos.x - UIOffset, m_UIPos.y + 100 - UIOffset);
	CreditUIPos = D2D1::Point2F(m_UIPos.x - UIOffset + 50.0f, m_UIPos.y + 200 - UIOffset);
	OptionUIPos = D2D1::Point2F(m_UIPos.x - UIOffset + 110.0f, m_UIPos.y + 300 - UIOffset);
	ExitUIPos = D2D1::Point2F(m_UIPos.x - UIOffset + 110.0f, m_UIPos.y + 400 - UIOffset);

	wasSequence = m_uiSequence;
}
void CTitleBackground::Render()
{

	D2D1_POINT_2F center = { 0,0 };
	CGameManager::m_Gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	m_Title->Draw(D2D1::Point2F(m_Pos.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), &center, 0.0f);
	m_Cloud01->Draw(D2D1::Point2F(m_CloudPosX01, 200));
	m_Cloud02->Draw(D2D1::Point2F(m_CloudPosX02, 200));
	m_Logo->Draw(D2D1::Point2F(70, m_LogoPosY));

	
	if (wasSequence != m_uiSequence) {
		m_UISelectAnimSequence = 0;
		wasSequence = m_uiSequence;
	}

	switch (m_uiSequence)
	{
	case GAMESTART:

		m_UISelectAnim[m_UISelectAnimSequence]->Draw(D2D1::Point2F(GameStartUIPos.x + 60, GameStartUIPos.y + 10));

		if (m_UISelectAnimSequence != 3) {
			m_uiState[EXIT] = IDLE;
			m_uiState[GAMESTART] = SELECT;
			m_uiState[HOWTOPLAY] = IDLE;
			m_UISelectAnimSequence = m_UISelectAnimFunc->OnAnimRender(50, 0, 4);
		}
		break;
	case HOWTOPLAY:


		m_UISelectAnim[m_UISelectAnimSequence]->Draw(D2D1::Point2F(HowToPlayUIPos.x + 60, HowToPlayUIPos.y + 10));
		
		if (m_UISelectAnimSequence != 3) {
			m_uiState[GAMESTART] = IDLE;
			m_uiState[HOWTOPLAY] = SELECT;
			m_uiState[CREDIT] = IDLE;
			m_UISelectAnimSequence = m_UISelectAnimFunc->OnAnimRender(50, 0, 4);
		}
		break;
	case CREDIT:


		m_UISelectAnim[m_UISelectAnimSequence]->Draw(D2D1::Point2F(CreditUIPos.x + 10, CreditUIPos.y + 10));

		if (m_UISelectAnimSequence != 3) {
			m_uiState[HOWTOPLAY] = IDLE;
			m_uiState[CREDIT] = SELECT;
			m_uiState[OPTION] = IDLE;
			m_UISelectAnimSequence = m_UISelectAnimFunc->OnAnimRender(50, 0, 4);
		}
		break;
	case OPTION:


		m_UISelectAnim[m_UISelectAnimSequence]->Draw(D2D1::Point2F(OptionUIPos.x - 50, OptionUIPos.y + 10));

		if (m_UISelectAnimSequence != 3) {
			m_uiState[CREDIT] = IDLE;
			m_uiState[OPTION] = SELECT;
			m_uiState[EXIT] = IDLE;
			m_UISelectAnimSequence = m_UISelectAnimFunc->OnAnimRender(50, 0, 4);
		}
		break;
	case EXIT:


		m_UISelectAnim[m_UISelectAnimSequence]->Draw(D2D1::Point2F(ExitUIPos.x - 50, ExitUIPos.y + 10));

		if (m_UISelectAnimSequence != 3) {
			m_uiState[OPTION] = IDLE;
			m_uiState[EXIT] = SELECT;
			m_uiState[GAMESTART] = IDLE;
			m_UISelectAnimSequence = m_UISelectAnimFunc->OnAnimRender(50, 0, 4);
		}
		break;
	default:
		if (m_uiSequence == 5)
			m_uiSequence = GAMESTART;
		if (m_uiSequence == -1)
			m_uiSequence = EXIT;
		break;
	}

	if (m_uiState[GAMESTART] != SELECT) m_GameStart[m_uiState[GAMESTART]]->Draw(D2D1::Point2F(m_UIPos.x, m_UIPos.y));
	else m_GameStart[m_uiState[GAMESTART]]->Draw(GameStartUIPos);


	if (m_uiState[HOWTOPLAY] != SELECT) m_HowToPlay[m_uiState[HOWTOPLAY]]->Draw(D2D1::Point2F(m_UIPos.x, m_UIPos.y + 100));
	else m_HowToPlay[m_uiState[HOWTOPLAY]]->Draw(HowToPlayUIPos);


	if (m_uiState[CREDIT] != SELECT) m_Credit[m_uiState[CREDIT]]->Draw(D2D1::Point2F(m_UIPos.x + 50, m_UIPos.y + 200));
	else m_Credit[m_uiState[CREDIT]]->Draw(CreditUIPos);


	if (m_uiState[OPTION] != SELECT) m_Option[m_uiState[OPTION]]->Draw(D2D1::Point2F(m_UIPos.x + 110.0f, m_UIPos.y + 300));
	else m_Option[m_uiState[OPTION]]->Draw(OptionUIPos);


	if (m_uiState[EXIT] != SELECT) m_Exit[m_uiState[EXIT]]->Draw(D2D1::Point2F(m_UIPos.x + 110.0f, m_UIPos.y + 400));
	else m_Exit[m_uiState[EXIT]]->Draw(ExitUIPos);

	if (m_CreditCheck)
	{
		printf("BOOL Check : %d\n", m_CreditCheck);
		m_CreditSprite->Draw(m_Pos);
	}
	//CGameManager::m_Gfx->DrawTextOut(L"Press Space Key To Start", D2D1::Point2F(MAX_WIN_WIDTH / 2, 200));
}

void CTitleBackground::FrameMove(DWORD elapsed)
{
	m_CloudPosX01 -= m_CloudMoveSpeed;
	m_CloudPosX02 -= m_CloudMoveSpeed;

	if (m_CloudPosX01 <= -MAX_WIN_WIDTH)
		m_CloudPosX01 = MAX_WIN_WIDTH;

	if (m_CloudPosX02 <= -MAX_WIN_WIDTH)
		m_CloudPosX02 = MAX_WIN_WIDTH;

	m_LogoPosY = Mathf::Lerp(50.0f, 60.0f, tTime);

	if (tTime > 1.0f || tTime < 0.0f) {
		dTime *= -1;
	}
	tTime += dTime;
}

void CTitleBackground::Control(CInput* Input)
{
	if (Input->KeyDown('W'))
		m_uiSequence--;
	if (Input->KeyDown('S'))
		m_uiSequence++;

	if (Input->KeyPress(VK_RETURN))
	{
		m_uiState[m_uiSequence] = PRESS;
		m_uiSelected = m_uiSequence;
		CurLoadTime = timeGetTime();
		OldLoadTime = CurLoadTime;
	}

	if (m_uiSelected != -1)
	{
		if (CurLoadTime - OldLoadTime > 50)
		{
			switch (m_uiSequence)
			{
			case GAMESTART:
				CGameManager::nowStatus = GAME01;
				m_uiSelected = -1;
				break;
			case HOWTOPLAY:
				m_uiSelected = -1;
				break;
			case CREDIT:
				if (m_CreditCheck)
					m_CreditCheck = FALSE;
				else
					m_CreditCheck = TRUE;

				m_uiSelected = -1;
				break;
			case OPTION:
				m_uiSelected = -1;
				break;
			case EXIT:
				m_uiSelected = -1;
				PostQuitMessage(0);
				break;
			}
			OldLoadTime = CurLoadTime;
		}
		else CurLoadTime = timeGetTime();
	}
}

void CTitleBackground::Release()
{
}
