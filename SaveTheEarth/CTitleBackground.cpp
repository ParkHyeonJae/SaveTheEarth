#include "framework.h"

CTitleBackground::CTitleBackground(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	m_Title = IMAGES->GetSprite("Title/Title");
	m_Logo = IMAGES->GetSprite("Title/Logo");
	m_Cloud01 = IMAGES->GetSprite("Title/Cloud");
	m_Cloud02 = IMAGES->GetSprite("Title/Cloud");

	m_GameStart[(DWORD)UISTATE::IDLE]	=		IMAGES->GetSprite("UI/GameStart");
	m_GameStart[(DWORD)UISTATE::SELECT] =	IMAGES->GetSprite("UI/GameStart_SELECT");
	m_GameStart[(DWORD)UISTATE::PRESS]	=	IMAGES->GetSprite("UI/GameStart_PRESS");

	m_HowToPlay[(DWORD)UISTATE::IDLE]	=		IMAGES->GetSprite("UI/HowToPlay");
	m_HowToPlay[(DWORD)UISTATE::SELECT] =	IMAGES->GetSprite("UI/HowToPlay_SELECT");
	m_HowToPlay[(DWORD)UISTATE::PRESS]	=	IMAGES->GetSprite("UI/HowToPlay_PRESS");

	m_Credit[(DWORD)UISTATE::IDLE]		=	IMAGES->GetSprite("UI/Credit");
	m_Credit[(DWORD)UISTATE::SELECT]	=	IMAGES->GetSprite("UI/Credit_SELECT");
	m_Credit[(DWORD)UISTATE::PRESS]		=	IMAGES->GetSprite("UI/Credit_PRESS");

	m_Option[(DWORD)UISTATE::IDLE]		=	IMAGES->GetSprite("UI/Option");
	m_Option[(DWORD)UISTATE::SELECT]	=	IMAGES->GetSprite("UI/Option_SELECT");
	m_Option[(DWORD)UISTATE::PRESS]		=	IMAGES->GetSprite("UI/Option_PRESS");

	m_Exit[(DWORD)UISTATE::IDLE]		=		IMAGES->GetSprite("UI/Exit");
	m_Exit[(DWORD)UISTATE::SELECT]		=	IMAGES->GetSprite("UI/Exit_SELECT");
	m_Exit[(DWORD)UISTATE::PRESS]		=		IMAGES->GetSprite("UI/Exit_PRESS");

	m_ReturnUI[0] = IMAGES->GetSprite("Return/Return_SELECT");
	m_ReturnUI[1] = IMAGES->GetSprite("Return/Return_PRESS");


	m_UISelectAnimFunc = new CSpriteAnimation();
	m_UISelectAnim = IMAGES->GetMultiSprite("UISelectAnim");

	//m_formUI[(DWORD)UI::CREDIT].m_UIMenuSprite = IMAGES->GetSprite("Credit");
	//m_formUI[(DWORD)UI::CREDIT].m_UIMenuCheck = FALSE;

	SetUIMenuProperty(UI::CREDIT, "MenuUI/TitleCredit");
	SetUIMenuProperty(UI::HOWTOPLAY, "MenuUI/GameRule");
	SetUIMenuProperty(UI::OPTION, "MenuUI/Options/Highlight_BGM");

	m_OptionConditionForm[0].m_ConditionSprite = IMAGES->GetSprite("MenuUI/Options/False"); 
	m_OptionConditionForm[0].m_OptionCondition = TRUE;

	m_OptionConditionForm[1].m_ConditionSprite = IMAGES->GetSprite("MenuUI/Options/True");
	m_OptionConditionForm[1].m_OptionCondition = TRUE;


	m_bReturnUICheck = FALSE;
	m_returnState = 0;

}

CTitleBackground::~CTitleBackground()
{
}
void CTitleBackground::SetUIMenuProperty(UI uiType, std::string spriteName)
{
	m_formUI[(DWORD)uiType].m_UIMenuSprite = IMAGES->GetSprite(std::move(spriteName));
	m_formUI[(DWORD)uiType].m_UIMenuCheck = FALSE;

}

void CTitleBackground::SetUIMenuSprite(UI uiType, std::string spriteName)
{
	m_formUI[(DWORD)uiType].m_UIMenuSprite = IMAGES->GetSprite(std::move(spriteName));
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
	case (DWORD)UI::GAMESTART:

		m_UISelectAnim[m_UISelectAnimSequence]->Draw(D2D1::Point2F(GameStartUIPos.x + 60, GameStartUIPos.y + 10));

		if (m_UISelectAnimSequence != 3) {
			m_uiState[(DWORD)UI::EXIT]		=	(DWORD)UISTATE::IDLE;
			m_uiState[(DWORD)UI::GAMESTART] =	(DWORD)UISTATE::SELECT;
			m_uiState[(DWORD)UI::HOWTOPLAY] =	(DWORD)UISTATE::IDLE;
			m_UISelectAnimSequence = m_UISelectAnimFunc->OnAnimRender(50, 0, 4);
		}
		break;
	case (DWORD)UI::HOWTOPLAY:


		m_UISelectAnim[m_UISelectAnimSequence]->Draw(D2D1::Point2F(HowToPlayUIPos.x + 60, HowToPlayUIPos.y + 10));
		
		if (m_UISelectAnimSequence != 3) {
			m_uiState[(DWORD)UI::GAMESTART]	= (DWORD)UISTATE::IDLE;
			m_uiState[(DWORD)UI::HOWTOPLAY]	= (DWORD)UISTATE::SELECT;
			m_uiState[(DWORD)UI::CREDIT]	= (DWORD)UISTATE::IDLE;
			m_UISelectAnimSequence = m_UISelectAnimFunc->OnAnimRender(50, 0, 4);
		}
		break;
	case (DWORD)UI::CREDIT:


		m_UISelectAnim[m_UISelectAnimSequence]->Draw(D2D1::Point2F(CreditUIPos.x + 10, CreditUIPos.y + 10));

		if (m_UISelectAnimSequence != 3) {
			m_uiState[(DWORD)UI::HOWTOPLAY] = (DWORD)UISTATE::IDLE;
			m_uiState[(DWORD)UI::CREDIT]	= (DWORD)UISTATE::SELECT;
			m_uiState[(DWORD)UI::OPTION]	= (DWORD)UISTATE::IDLE;
			m_UISelectAnimSequence = m_UISelectAnimFunc->OnAnimRender(50, 0, 4);
		}
		break;
	case (DWORD)UI::OPTION:


		m_UISelectAnim[m_UISelectAnimSequence]->Draw(D2D1::Point2F(OptionUIPos.x - 50, OptionUIPos.y + 10));

		if (m_UISelectAnimSequence != 3) {
			m_uiState[(DWORD)UI::CREDIT]	= (DWORD)UISTATE::IDLE;
			m_uiState[(DWORD)UI::OPTION]	= (DWORD)UISTATE::SELECT;
			m_uiState[(DWORD)UI::EXIT]		= (DWORD)UISTATE::IDLE;
			m_UISelectAnimSequence = m_UISelectAnimFunc->OnAnimRender(50, 0, 4);
		}
		break;
	case (DWORD)UI::EXIT:


		m_UISelectAnim[m_UISelectAnimSequence]->Draw(D2D1::Point2F(ExitUIPos.x - 50, ExitUIPos.y + 10));

		if (m_UISelectAnimSequence != 3) {
			m_uiState[(DWORD)UI::OPTION]	= (DWORD)UISTATE::IDLE;
			m_uiState[(DWORD)UI::EXIT]		= (DWORD)UISTATE::SELECT;
			m_uiState[(DWORD)UI::GAMESTART] = (DWORD)UISTATE::IDLE;
			m_UISelectAnimSequence = m_UISelectAnimFunc->OnAnimRender(50, 0, 4);
		}
		break;
	default:
		if (m_uiSequence == 5)
			m_uiSequence = (DWORD)UI::GAMESTART;
		if (m_uiSequence == -1)
			m_uiSequence = (DWORD)UI::EXIT;
		break;
	}

	if (m_uiState[(DWORD)UI::GAMESTART] != (DWORD)UISTATE::SELECT) m_GameStart[m_uiState[(DWORD)UI::GAMESTART]]->Draw(D2D1::Point2F(m_UIPos.x, m_UIPos.y));
	else m_GameStart[m_uiState[(DWORD)UI::GAMESTART]]->Draw(GameStartUIPos);


	if (m_uiState[(DWORD)UI::HOWTOPLAY] != (DWORD)UISTATE::SELECT) m_HowToPlay[m_uiState[(DWORD)UI::HOWTOPLAY]]->Draw(D2D1::Point2F(m_UIPos.x, m_UIPos.y + 100));
	else m_HowToPlay[m_uiState[(DWORD)UI::HOWTOPLAY]]->Draw(HowToPlayUIPos);


	if (m_uiState[(DWORD)UI::CREDIT] != (DWORD)UISTATE::SELECT) m_Credit[m_uiState[(DWORD)UI::CREDIT]]->Draw(D2D1::Point2F(m_UIPos.x + 50, m_UIPos.y + 200));
	else m_Credit[m_uiState[(DWORD)UI::CREDIT]]->Draw(CreditUIPos);


	if (m_uiState[(DWORD)UI::OPTION] != (DWORD)UISTATE::SELECT) m_Option[m_uiState[(DWORD)UI::OPTION]]->Draw(D2D1::Point2F(m_UIPos.x + 110.0f, m_UIPos.y + 300));
	else m_Option[m_uiState[(DWORD)UI::OPTION]]->Draw(OptionUIPos);


	if (m_uiState[(DWORD)UI::EXIT] != (DWORD)UISTATE::SELECT) m_Exit[m_uiState[(DWORD)UI::EXIT]]->Draw(D2D1::Point2F(m_UIPos.x + 110.0f, m_UIPos.y + 400));
	else m_Exit[m_uiState[(DWORD)UI::EXIT]]->Draw(ExitUIPos);

	for (size_t i = 0; i < (DWORD)UI::UI_ENUM_COUNT; i++)
		if (m_formUI[i].m_UIMenuCheck)
			m_formUI[i].m_UIMenuSprite->Draw(m_Pos);
	

	//if (m_bReturnUICheck) {
	//	Vector2 Pos = D2D1::Point2F(1100.0f, 50.0f);
	//	
	//	m_UISelectAnim[m_UISelectAnimSequence]->Draw(D2D1::Point2F(Pos.x + 30, Pos.y + 10));

	//	if (m_UISelectAnimSequence != 3) {
	//		m_UISelectAnimSequence = m_UISelectAnimFunc->OnAnimRender(50, 0, 4);
	//	}
	//	m_ReturnUI[m_returnState]->Draw(Pos);
	//}

	if (IsOptionMenuOpened())
	{
		m_OptionConditionForm[m_OptionConditionForm[0].m_OptionCondition].m_ConditionSprite->Draw(D2D1::Point2F(925, 330));

		m_OptionConditionForm[m_OptionConditionForm[1].m_OptionCondition].m_ConditionSprite->Draw(D2D1::Point2F(925, 530));
	}
	
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

bool CTitleBackground::IsOptionMenuOpened()
{
	return m_bReturnUICheck && m_uiSequence == (DWORD)UI::OPTION;
}


void CTitleBackground::Control(CInput* Input)
{
	if (!m_bReturnUICheck) {
		if (Input->KeyDown('W'))
			m_uiSequence--;
		if (Input->KeyDown('S'))
			m_uiSequence++;
	}

	if (IsOptionMenuOpened())
	{
		if (Input->KeyDown('W')) {
			m_optionSequence--;
			m_optionSequence %= 2;
		}
		if (Input->KeyDown('S')) {
			m_optionSequence++;
			m_optionSequence %= 2;
		}
		
		if (Input->KeyDown('A')) {
			m_OptionConditionForm[m_optionSequence].m_OptionCondition 
				= !m_OptionConditionForm[m_optionSequence].m_OptionCondition;
		}
		if (Input->KeyDown('D')) {
			m_OptionConditionForm[m_optionSequence].m_OptionCondition 
				= !m_OptionConditionForm[m_optionSequence].m_OptionCondition;
		}

		if (m_OptionConditionForm[0].m_OptionCondition)
			SOUND->SetBGMVolume(1.0f);
		else SOUND->SetBGMVolume(0.0f);
		if (m_OptionConditionForm[1].m_OptionCondition)
			SOUND->SetSFXVolume(1.0f);
		else {
			SOUND->SetSFXVolume(0.0f);
		}
		switch (m_optionSequence)
		{
		case 0:
			SetUIMenuSprite(UI::OPTION, "MenuUI/Options/Highlight_BGM");
			break;
		case 1:
			SetUIMenuSprite(UI::OPTION, "MenuUI/Options/Highlight_SFX");
			break;
		default:
			break;
		}
	}

	if (Input->KeyPress(VK_RETURN) || Input->KeyPress(VK_ESCAPE))
	{
		m_uiState[m_uiSequence] = (DWORD)UISTATE::PRESS;
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
			case (DWORD)UI::GAMESTART:
				CGameManager::nowStatus = GAME01;
				m_uiSelected = -1;
				break;
			case (DWORD)UI::HOWTOPLAY:
				m_bReturnUICheck = !m_bReturnUICheck;
				m_formUI[m_uiSequence].m_UIMenuCheck = !m_formUI[m_uiSequence].m_UIMenuCheck;
				m_uiSelected = -1;
				break;
			case (DWORD)UI::CREDIT:
				m_bReturnUICheck = !m_bReturnUICheck;
				m_formUI[m_uiSequence].m_UIMenuCheck = !m_formUI[m_uiSequence].m_UIMenuCheck;
				m_uiSelected = -1;
				break;
			case (DWORD)UI::OPTION:
				m_bReturnUICheck = !m_bReturnUICheck;
				m_formUI[m_uiSequence].m_UIMenuCheck = !m_formUI[m_uiSequence].m_UIMenuCheck;
				m_uiSelected = -1;
				break;
			case (DWORD)UI::EXIT:
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
