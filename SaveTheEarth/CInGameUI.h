#pragma once
class CInGameUI : public CGameObject
{
private:
	D2D1_POINT_2F m_hpBarPos;
	CSprite* m_playerHpBar_background;
	CSprite* m_playerHpBar_foreground;
	D2D1_POINT_2F m_hpPos;
	FLOAT hpSize;


	FLOAT MAXHP;
	FLOAT CurHP;
	FLOAT MAXIMG;
public:
	CInGameUI(INT tag);
	~CInGameUI();
	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;
};

