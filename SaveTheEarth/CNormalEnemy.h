#pragma once
#define SHARKMAXHP 500
class CNormalEnemy : public CGameObject
{
private:
	CNormalEnemyBullet* m_NormalEnemyBullet;
	float angle;
	D2D1_POINT_2F m_TargetPos;

	BOOL m_deadCheck;
	BOOL m_isDelete;
	FLOAT m_HP;
private:
	INT SharkAnimSequence;
	D2D1_SIZE_F SharkAnimSize;
	CSpriteAnimation* m_SharkAnimFunc;

private:
	INT ExplosiveSequence;
	INT SharkDeadAnimSequence;
	CSpriteAnimation* m_ExplosiveAnimFunc;
	CSpriteAnimation* m_SharkDeadAnimFunc;

private:
	CHealthBar* m_SharkHP;
	CSprite* m_SharkNullHP;
	CSprite* m_SharkFullHP;
private:
	float CollRange = 40.0f;
public:
	CNormalEnemy(D2D1_POINT_2F m_Pos, INT tag);
	~CNormalEnemy();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;

	FLOAT GetHp() { return m_HP; }
	void SetHp(FLOAT hp) { m_HP = hp; }

	BOOL IsDead() { return m_deadCheck; }
	void SetDead(BOOL m_deadCheck) { this->m_deadCheck = m_deadCheck; }

	BOOL IsDelete() { return m_isDelete; }
};

