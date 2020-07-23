#pragma once
class CPlayerLaserLauncher : public CGameObject, public ILauncher
{
private:
	Animation m_PlayerLaser;
	CTimer* m_PlayerLaserTimer;
	FLOAT m_LaserDamage;
	Vector2* m_Pos;
public:
	CPlayerLaserLauncher(D2D1_POINT_2F *m_Pos, INT tag);
	~CPlayerLaserLauncher();
	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;

	virtual void LauncherInit() override;
	virtual void LauncherUpdate(DWORD elapsed) override;
	virtual void LauncherRender() override;
	virtual void LauncherRelease() override;

	FLOAT GetDamage() { return m_LaserDamage; }
};

