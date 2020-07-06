#pragma once
class CPlayer : public CGameObject
{
private:
	float m_Rot;

	float MoveSpeed;
	float m_HP;
public:
	CPlayer(D2D1_POINT_2F m_Pos, INT tag, FLOAT m_HP);
	~CPlayer();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;

	FLOAT GetHp() { return m_HP; }
	void SetHp(FLOAT hp) { m_HP = hp; }

	FLOAT GetRot() { return m_Rot; }
};

