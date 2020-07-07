#pragma once
class CGameScene01 : public CSceneObject, CObjectManager
{
private:
	CTitleBackground* m_TitleBG;
public:
	CGameScene01();
	~CGameScene01();

	void Init() override;
	void FrameMove(DWORD elapsed) override;
	void Render() override;
	void Control(CInput* m_Input) override;
	void Release() override;

};

