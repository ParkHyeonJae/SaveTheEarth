#pragma once
#define STARTPOINT 200
#define ENDPOINT 1260
#define MIDDLEPOINT 725
class CInGameUI : public CGameObject
{
private:
	D2D1_POINT_2F m_hpPos;

	CHealthBar* m_UserHP;
	FLOAT CurHP;

	//Distance Bar
	CSprite* m_LongDistancBar;
	CSprite* m_whereDistanceBar;
	FLOAT m_wherePosX;
public:
	CInGameUI(INT tag);
	~CInGameUI();
	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;
};

