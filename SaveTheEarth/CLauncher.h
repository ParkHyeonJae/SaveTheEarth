#pragma once
class ILauncher {
protected:
	struct Animation {
		CSpriteAnimation* AnimFunc;
		INT sequence;
	};
	BOOL m_bRunCheck;
	BOOL m_bFinish;
	RECT m_LaucherCollision;
public:
	virtual ~ILauncher() {};

	virtual void LauncherInit() = 0;
	virtual void LauncherUpdate(DWORD elapsed) = 0;
	virtual void LauncherRender() = 0;
	virtual void LauncherRelease() = 0;


	RECT GetColl() { return m_LaucherCollision; }
	VOID SetCOll(RECT launcherColl) { m_LaucherCollision = launcherColl; }

	VOID SetRun(BOOL m_bRunCheck) { this->m_bRunCheck = m_bRunCheck; }
	BOOL IsRun() { return m_bRunCheck; }

	VOID SetFinish(BOOL m_bFinish) { this->m_bFinish = m_bFinish; }
	BOOL IsFinish() { return m_bFinish; }
};