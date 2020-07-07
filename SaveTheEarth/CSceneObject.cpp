#include "framework.h"

CSceneObject::CSceneObject()
{
}

CSceneObject::~CSceneObject()
{
	Release();
}

void CSceneObject::Init()
{
	//AllInitalize();
}

void CSceneObject::FrameMove(DWORD elapsed)
{
	//AllFrameMove(elapsed);
}

void CSceneObject::Render()
{
	//AllRender();
}

void CSceneObject::Control(CInput* m_Input)
{
	//AllControl(m_Input);
}

void CSceneObject::Release()
{
	//AllRelease();
}
