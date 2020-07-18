#pragma once
class CInGameUI : public CGameObject
{
private:
	D2D1_POINT_2F m_hpBarPos;
	D2D1_POINT_2F m_hpPos;
	FLOAT hpSize;


	FLOAT MAXHP;
	FLOAT CurHP;
	FLOAT MAXIMG;

	FLOAT CurIMG = 0;

	D2D1_SIZE_F HpBarSize;
public:
	CInGameUI(INT tag);
	~CInGameUI();
	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;
};

