#pragma once
/*
CBossBullet 클래스 : 보스가 발사하는 총알 클래스
보스 패턴 중 하나인 총알 패탄에서 발사되는 총알 이다
*/
class CBossBullet : public CGameObject
{
private:
	Animation m_Bullet;
	Animation m_BulletEffect;
	float BulletSpeed;
	FLOAT m_BulletDamage;

	BOOL CollCheck;
	BOOL m_isDelete;

	FLOAT theta;
public:
	CBossBullet(D2D1_POINT_2F m_Pos, INT tag);
	~CBossBullet();

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

