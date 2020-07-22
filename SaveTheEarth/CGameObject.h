#pragma once
class CGameObject : public IGameObject
{
	
protected:
	D2D1_POINT_2F m_Pos;
	CSprite* m_Sprite;

public:
	struct Animation {
		CSpriteAnimation* AnimFunc;
		INT sequence;
	};

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

	void SetPos(Vector2 m_Pos) { this->m_Pos = m_Pos; }
};

