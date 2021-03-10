#pragma once
class CStageClearBackground : public CGameObject
{
public:
	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;

private:
	CSprite* m_CreditSprite;
};

