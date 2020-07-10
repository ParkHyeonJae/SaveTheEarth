#pragma once
class CPlayerBullet : public CGameObject
{
private:
	std::vector<CSprite*> m_BulletSprites;
	CSprite* m_ShotgunSprite;
	CSpriteAnimation* m_RifleBulletAnimFunc;
	INT RifleBulletAnimSequence;
	float m_BulletSpeed;
	float theta;

	FLOAT m_BulletDamage = 20.0f;

	INT m_GUN;
	BOOL CollCheck;
	BOOL m_isDelete;
	std::vector<CSprite*> m_RifleEffectAnim;
	INT RifleEffectAnimSequence;
	CSpriteAnimation* m_RifleEffectAnimFunc;

	std::vector<CSprite*> m_ShotgunEffectAnim;
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

