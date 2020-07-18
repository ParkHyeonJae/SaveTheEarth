#pragma once
class CScrollBackground : public CGameObject
{
private:
	float ScrollSpeed;

	//CSprite* m_Sky;
	//CSprite* m_Cloud;
	//CSprite* m_Mountain;
	//CSprite* m_Sun;
	//CSprite* m_Trees;

	D2D1_POINT_2F m_CloudPos;
	D2D1_POINT_2F m_MountainPos;
public:
	CScrollBackground(D2D1_POINT_2F m_Pos, INT tag, FLOAT ScrollSpeed);
	~CScrollBackground();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;
};

