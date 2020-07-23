#pragma once
class CPlayerBarrierLauncher : public CGameObject, public ILauncher
{
private:
	Animation m_Barrier;
	CTimer* m_BarrierTimer;
	D2D1_POINT_2F* m_Pos;
	
public:
	CPlayerBarrierLauncher(D2D1_POINT_2F* m_Pos, INT tag);
	~CPlayerBarrierLauncher();
	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;

	virtual void LauncherInit() override;
	virtual void LauncherUpdate(DWORD elapsed) override;
	virtual void LauncherRender() override;
	virtual void LauncherRelease() override;


};

