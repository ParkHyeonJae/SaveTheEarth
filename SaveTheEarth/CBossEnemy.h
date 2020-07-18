#pragma once
class CBossEnemy : public CGameObject
{
private:
	D2D1_POINT_2F m_TargetPos;
	FLOAT deltaTime = 0.01f;
	DWORD CurAnimTime;
	DWORD OldAnimTime;
	INT sequence;
	CSpriteAnimation* m_BossAnimFunc;

public:
	CBossEnemy(D2D1_POINT_2F m_Pos, INT tag);
	~CBossEnemy();
	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;
};

