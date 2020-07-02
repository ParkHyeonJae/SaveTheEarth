#pragma once
class CPlayer : public CGameObject
{
private:
	float MoveSpeed;
	
public:
	CPlayer(D2D1_POINT_2F m_Pos, INT tag);
	~CPlayer();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;
};

