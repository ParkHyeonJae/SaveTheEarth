#pragma once
class CScrollBackground : public CGameObject
{
private:
	float ScrollSpeed;
public:
	CScrollBackground(D2D1_POINT_2F m_Pos, INT tag, FLOAT ScrollSpeed);
	~CScrollBackground();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;
};

