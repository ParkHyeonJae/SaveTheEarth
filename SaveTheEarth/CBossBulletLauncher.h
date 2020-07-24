#pragma once
/*
CBossBulletLauncher 클래스 : 보스 총알 생성을 위한 런처
보스에서 CBossBullletLauncher 오브젝트만 추가해도 Bullet 들을 생성이 가능하다
*/
class CBossBulletLauncher : public CGameObject, public ILauncher
{
private:
	Animation m_BulletIdle;
	CTimer* m_BulletTimer;

	CTimer* m_BulletSkillEndTimer;
public:
	CBossBulletLauncher(D2D1_POINT_2F m_Pos, INT tag);
	~CBossBulletLauncher();
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

