#pragma once
class CPlayerBullet : public CGameObject
{
private:
	std::vector<CSprite*> m_BulletSprites;
	CSpriteAnimation* m_RifleBulletAnimFunc;
	INT RifleBulletAnimSequence;
	float m_BulletSpeed;
	float theta;

	FLOAT m_BulletDamage = 20.0f;
public:
	CPlayerBullet(D2D1_POINT_2F m_Pos,FLOAT m_Rot, INT tag);
	~CPlayerBullet();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;

	BOOL IsMapOut();

	FLOAT GetDamage() { return m_BulletDamage; }
};

