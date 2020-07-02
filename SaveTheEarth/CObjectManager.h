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


	void AllInitalize();
	void AllFrameMove(DWORD elapsed);
	void AllControl(CInput* m_Input);
	void AllRender();
	void AllRelease();

	CObjectManager* GetObjectManager() { return this; }
};

