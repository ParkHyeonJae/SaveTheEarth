#pragma once
class CTitleBackground : public CGameObject
{
	CSprite* Title;
public:
	CTitleBackground(D2D1_POINT_2F m_Pos, INT tag);
	~CTitleBackground();
	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;
};

