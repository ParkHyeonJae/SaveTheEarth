#pragma once
class CGameScene02 : public CSceneObject, CObjectManager
{
private:
	CTimer* m_EnemySpawnTimer;
	CTimer* m_MisileSpawnTimer;
	CTimer* m_BossSpawnTimer;
	CTimer* m_BalanceTimer;
	CPlayer* m_Player;
	CNormalEnemy* m_NormalEnemy;

	CScrollBackground* m_ScrollBackground01;
	CScrollBackground* m_ScrollBackground02;
	MisileEnemy* m_misileEnemy;

	CBossEnemy* m_BossEnemy;

	CInGameUI* m_GameUI;
public:
	CGameScene02();
	~CGameScene02();

	void Init() override;
	void FrameMove(DWORD elapsed) override;
	void Render() override;
	void Control(CInput* m_Input) override;
	void Release() override;

};

