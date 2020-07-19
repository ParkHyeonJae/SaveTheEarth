#pragma once
class CObjectManager
{
private:
	std::list<CGameObject*> m_gameObjectList;
	std::list<CGameObject*> m_uiList;
public:
	CObjectManager();
	~CObjectManager();

	INT AddObject(CGameObject* object);
	INT AddUI(CGameObject* object);
	CGameObject FindObject(CGameObject* object);
	BOOL IsExistObject(CGameObject* object);
	BOOL IsEmpty();


	void AllInitalize();
	void AllFrameMove(DWORD elapsed);
	void AllControl(CInput* m_Input);
	void AllRender();
	void AllRelease();

	std::list<CGameObject*> GetObjectList() { return m_gameObjectList; }
	CObjectManager* GetObjectManager() { return this; }
};

