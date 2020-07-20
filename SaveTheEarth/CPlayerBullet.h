#pragma once
class CPlayerBullet : public CGameObject
{
private:
	CSpriteAnimation* m_RifleBulletAnimFunc;
	INT RifleBulletAnimSequence;
	float m_BulletSpeed;
	float theta;

	FLOAT m_BulletDamage;

	INT m_GUN;
	BOOL CollCheck;
	BOOL m_isDelete;

	INT RifleEffectAnimSequence;
	CSpriteAnimation* m_RifleEffectAnimFunc;


	INT ShotgunEffectAnimSequence;
	CSpriteAnimation* m_ShotgunEffectAnimFunc;


public:
	CPlayerBullet(D2D1_POINT_2F m_Pos,FLOAT m_Rot, INT tag, INT m_GUN);
	~CPlayerBullet();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;


	BOOL IsMapOut();
	BOOL IsColl() {
		return CollCheck;
	}
	void SetColl(BOOL CollCheck) { this->CollCheck = CollCheck; }
	FLOAT GetDamage() { return m_BulletDamage; }

	BOOL IsDelete() { return m_isDelete; }

};

