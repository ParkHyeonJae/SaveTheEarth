#pragma once
class CBossLaserLauncher : public CGameObject, public ILauncher
{
private:
	LAUNCHER_STATE m_CurState;
	Animation m_LaserChaging;
	Animation m_LaserOn;
	Animation m_LaserFire;
	Animation m_LaserOff;
	CTimer* m_LaserTimer;
public:
	CBossLaserLauncher(D2D1_POINT_2F m_Pos, INT tag);
	~CBossLaserLauncher();
	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;

	virtual void LauncherInit() override;
	virtual void LauncherUpdate(DWORD elapsed) override;
	virtual void LauncherRender() override;
	virtual void LauncherRelease() override;

	LAUNCHER_STATE GetLaserState() { return m_CurState; }
};

