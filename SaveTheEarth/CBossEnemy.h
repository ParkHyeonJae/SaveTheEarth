#pragma once
#define MAXBOSSHP 100000
class CBossEnemy : public CGameObject
{
private:
	D2D1_POINT_2F m_TargetPos;
	FLOAT deltaTime = 0.01f;
	INT sequence;
	CSpriteAnimation* m_BossAnimFunc;

	INT BlinkingCount;
	CTimer* m_BossHitTimer;
	BOOL m_isHit;
	BOOL m_deadCheck;
	BOOL m_isDelete;
	FLOAT m_HP;
	FLOAT colorV = 0.0f;

	CHealthBar* m_BossHP;
	CSprite* m_BossNullHp;
	CSprite* m_BossHpBar;
	Vector2 m_BossHpPos;

	//BOSS SKILLS
	BOOL m_IsBossShow;
	CBossLaserLauncher* m_LaserLauncher;
	CBossBulletLauncher* m_BulletLauncher;
	CTimer* m_SkillTimer;
public:
	CBossEnemy(D2D1_POINT_2F m_Pos, INT tag);
	~CBossEnemy();
	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;

	BOOL IsHit() { return m_isHit; }
	void SetHit(BOOL m_isHit) { this->m_isHit = m_isHit; }

	FLOAT GetHp() { return m_HP; }
	void SetHp(FLOAT hp) { m_HP = hp; }

	BOOL IsDead() { return m_deadCheck; }
	void SetDead(BOOL m_deadCheck) { this->m_deadCheck = m_deadCheck; }

	BOOL IsDelete() { return m_isDelete; }
};

