#pragma once
class IGameObject
{
public:
	virtual ~IGameObject() {};

	virtual void Init() = 0;
	virtual void FrameMove(DWORD elapsed) = 0;
	virtual void Render() = 0;
	virtual void Control(CInput* m_Input) = 0;
	virtual void Release() = 0;
};

