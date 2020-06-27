#pragma once
class CGameObject : public IGameObject
{
protected:
	D2D1_POINT_2F m_Pos;
	CSprite* m_Sprite;

public:
	D2D1_POINT_2F			m_Scale;
	INT						m_tag;

	CGameObject();
	virtual ~CGameObject();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;

	D2D1_POINT_2F GetPos() { return m_Pos; }
	CSprite* GetSprite() { return m_Sprite; }
};

