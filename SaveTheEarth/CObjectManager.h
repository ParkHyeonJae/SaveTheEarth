#pragma once
class CObjectManager
{
private:
	std::list<CGameObject*> m_gameObjectList;
public:
	CObjectManager();
	~CObjectManager();

	INT AddObject(CGameObject* object);
	CGameObject FindObject(CGameObject* object);
	BOOL IsExistObject(CGameObject* object);
	BOOL IsEmpty();


	void Init();
	void FrameMove(DWORD elapsed);
	void Control(CInput* m_Input);
	void Render();
	void Release();
};

