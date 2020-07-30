#pragma once
class CGame : public CDX2DApp
{
private:
	std::list<CSceneObject*> m_SceneList;

	CGameScene01* m_GameScene01;
	CGameScene02* m_GameScene02;

	CObjectManager* m_ObjectManager;
	CImageManager* m_ImageManager;
	CGameManager* m_GameManager;
	cSoundManager* m_SoundManager;
	
public:
	CGame();
	~CGame();

	virtual INT		Init();
	virtual void	Destroy();

	virtual INT		FrameMove(DWORD elapsed);
	virtual INT		Render();
	virtual INT		Control(CInput* m_Input);

	virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
};

