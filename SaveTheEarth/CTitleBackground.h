#pragma once
/*
TitleBackground 클래스: Title 화면의 모든 UI부터 배경까지 담아둔 클래스
*/

struct UIForm
{
	BOOL m_UIMenuCheck;
	CSprite* m_UIMenuSprite;
};

struct OptionConditionForm
{
	CSprite* m_ConditionSprite;
	BOOL m_OptionCondition;
};

class CTitleBackground : public CGameObject
{
private:
	enum class UISTATE {
		IDLE,
		SELECT,
		PRESS
	};
	enum class UI {
		GAMESTART,
		HOWTOPLAY,
		CREDIT,
		OPTION,
		EXIT,

		UI_ENUM_COUNT
	};


	CSprite* m_Title;
	CSprite* m_Logo;
	CSprite* m_Cloud01;
	CSprite* m_Cloud02;

	UIForm m_formUI[(DWORD)UI::UI_ENUM_COUNT];

	FLOAT m_CloudPosX01;
	FLOAT m_CloudPosX02;

	FLOAT m_LogoPosY;
	FLOAT tTime = 0.0f;
	FLOAT dTime = 0.01f;

	FLOAT m_CloudMoveSpeed;

	D2D1_POINT_2F m_UIPos;
private:
	CSprite* m_GameStart[3];
	CSprite* m_HowToPlay[3];
	CSprite* m_Credit[3];
	CSprite* m_Option[3];
	CSprite* m_Exit[3];

	OptionConditionForm m_OptionConditionForm[2];

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

	void SetUIMenuProperty(UI uiType, std::string spriteName);
	void SetUIMenuSprite(UI uiType, std::string spriteName);
	bool IsOptionMenuOpened();
	int m_optionSequence = 0;

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;
};

