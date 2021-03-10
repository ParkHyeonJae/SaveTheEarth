#pragma once
class CGameScene03 : public CSceneObject, CObjectManager
{
private:
	CStageClearBackground* m_StageClearBackground;


public:
	CGameScene03();
	~CGameScene03();

	void Init() override;
	void FrameMove(DWORD elapsed) override;
	void Render() override;
	void Control(CInput* m_Input) override;
	void Release() override;

};

