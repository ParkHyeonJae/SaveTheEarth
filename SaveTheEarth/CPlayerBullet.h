#pragma once

/*
CPlayerBullet 클래스 : 플레이어가 발사하는 총알 클래스
경우에 따라서 샷건의 총알, 라이플의 총알이 될 수 있음

*/

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
	FLOAT GetDamage() {
		switch (m_GUN) {
		case Rifle:
			return m_BulletDamage * 2.0f;
		case Shotgun:
			return m_BulletDamage;
		}
		
	}

	BOOL IsDelete() { return m_isDelete; }

};

