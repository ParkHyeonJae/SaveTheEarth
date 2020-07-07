#pragma once
class CSceneObject : public IGameObject
{

public:
	CSceneObject();
	~CSceneObject();

	virtual void Init() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Render() override;
	virtual void Control(CInput* m_Input) override;
	virtual void Release() override;
};

