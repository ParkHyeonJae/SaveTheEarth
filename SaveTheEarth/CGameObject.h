#pragma once
class CGameObject : public IGameObject
{

protected:
	D2D1_POINT_2F m_Pos;
	CSprite* m_Sprite;
	RECT m_Collider;
	BOOL m_bDelete = FALSE;
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


	VOID SetDelete(BOOL m_bDelete) { this->m_bDelete = m_bDelete; }
	BOOL IsDelete() {
		return m_bDelete;
	}
	D2D1_POINT_2F GetPos() { return m_Pos; }
	CSprite* GetSprite() { return m_Sprite; }

	void SetPos(Vector2 m_Pos) { this->m_Pos = m_Pos; }

	RECT GetCollider() { return m_Collider; }
	VOID SetCollider(RECT r) { m_Collider = r; }
	VOID SetCollider(LONG left, LONG top, LONG right, LONG bottom) { m_Collider = {left,top,right,bottom}; }
};

