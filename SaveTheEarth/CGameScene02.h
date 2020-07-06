#pragma once
class CGameScene02 : public CSceneObject, CObjectManager
{
private:
	CPlayer* m_Player;
	CPlayerBullet* m_PlayerBullet;
	CNormalEnemy* m_NormalEnemy;

	CScrollBackground* m_ScrollBackground01;
	CScrollBackground* m_ScrollBackground02;


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

