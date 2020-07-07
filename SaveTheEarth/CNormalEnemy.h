#pragma once
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
	std::vector<CSprite*> m_SharkAnim;
	CSpriteAnimation* m_SharkAnimFunc;

private:
	INT ExplosiveSequence;
	std::vector<CSprite*> m_ExplosiveAnim;
	CSpriteAnimation* m_ExplosiveAnimFunc;
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

