#pragma once
class CItem : public CGameObject
{
private:
	INT ItemState;

	FLOAT MoveAngle;
	CSprite* m_ItemSprite;
public:
	CItem(D2D1_POINT_2F m_Pos, INT tag);
	~CItem();

	void Apply();
	D2D1_SIZE_F GetSize() { return m_ItemSprite->GetBmp()->GetSize(); }

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;
};
