#pragma once
/*
CBossBullet Ŭ���� : ������ �߻��ϴ� �Ѿ� Ŭ����
���� ���� �� �ϳ��� �Ѿ� ��ź���� �߻�Ǵ� �Ѿ� �̴�
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

	Pattern m_pattern;
	FLOAT theta;
	INT Offset;
	CTimer* m_explosiveTimer;
public:
	CBossBullet(D2D1_POINT_2F m_Pos, Pattern pattern, FLOAT theta, INT tag);
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

