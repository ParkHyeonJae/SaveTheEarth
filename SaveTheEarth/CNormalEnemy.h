#pragma once
class CNormalEnemy : public CGameObject
{
private:
	CNormalEnemyBullet* m_NormalEnemyBullet;
	float angle;
	D2D1_POINT_2F m_TargetPos;

public:
	CNormalEnemy(D2D1_POINT_2F m_Pos, INT tag);
	~CNormalEnemy();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;
};

