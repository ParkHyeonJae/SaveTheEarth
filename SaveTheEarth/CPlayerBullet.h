#pragma once
class CPlayerBullet : public CGameObject
{
private:
	std::vector<CSprite*> m_BulletSprites;
	DWORD CurAnimTime;
	DWORD OldAnimTime;
	INT sequence;
	float m_BulletSpeed;
	float theta;
public:
	CPlayerBullet(D2D1_POINT_2F m_Pos,FLOAT m_Rot, INT tag);
	~CPlayerBullet();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;

	BOOL IsMapOut();
};

