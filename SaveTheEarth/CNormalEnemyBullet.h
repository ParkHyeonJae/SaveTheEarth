#pragma once
class CNormalEnemyBullet : public CGameObject
{
private:
	float BulletSpeed;
public:
	CNormalEnemyBullet(D2D1_POINT_2F m_Pos, INT tag);
	~CNormalEnemyBullet();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;
};

