#pragma once
/*
TitleBackground 클래스: Title 화면의 모든 UI부터 배경까지 담아둔 클래스
*/
class CTitleBackground : public CGameObject
{
	CSprite* m_Title;
	CSprite* m_Logo;
	CSprite* m_Cloud01;
	CSprite* m_Cloud02;

	BOOL m_CreditCheck;
	CSprite* m_CreditSprite;

	FLOAT m_CloudPosX01;
	FLOAT m_CloudPosX02;

	FLOAT m_LogoPosY;
	FLOAT tTime = 0.0f;
	FLOAT dTime = 0.01f;

	FLOAT m_CloudMoveSpeed;

	D2D1_POINT_2F m_UIPos;
private:
	enum UISTATE {
		IDLE,
		SELECT,
		PRESS
	};
	enum UI {
		GAMESTART,
		HOWTOPLAY,
		CREDIT,
		OPTION,
		EXIT
	};
	CSprite* m_GameStart[3];
	CSprite* m_HowToPlay[3];
	CSprite* m_Credit[3];
	CSprite* m_Option[3];
	CSprite* m_Exit[3];

	INT m_returnState;
	BOOL m_bReturnUICheck;
	CSprite* m_ReturnUI[2];

	INT m_uiSequence;
	INT wasSequence;
	INT m_uiState[5];
	INT m_uiSelected;

	DWORD CurLoadTime;
	DWORD OldLoadTime;
	FLOAT UIOffset;
private:
	std::vector<CSprite*> m_UISelectAnim;
	INT m_UISelectAnimSequence;
	CSpriteAnimation* m_UISelectAnimFunc;

	D2D1_POINT_2F GameStartUIPos;
	D2D1_POINT_2F HowToPlayUIPos;
	D2D1_POINT_2F CreditUIPos;
	D2D1_POINT_2F OptionUIPos;
	D2D1_POINT_2F ExitUIPos;
public:
	CTitleBackground(D2D1_POINT_2F m_Pos, INT tag);
	~CTitleBackground();
	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;
};

