#pragma once
class MisileEnemy : public CGameObject
{
private:
	FLOAT m_MoveSpeed;
	BOOL m_SpawnCheck;
	INT m_warningCount;
	FLOAT overlay;
	FLOAT tTime = 0.0f;
	FLOAT dTime = 0.02f;
public:
	MisileEnemy(D2D1_POINT_2F m_Pos, INT tag);
	~MisileEnemy();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;

	BOOL IsSpawn() { return m_SpawnCheck; }
	BOOL IsMapOut();
};

