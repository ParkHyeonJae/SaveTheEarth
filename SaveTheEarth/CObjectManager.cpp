#include "framework.h"

CObjectManager::CObjectManager()
{
}

CObjectManager::~CObjectManager()
{
	Release();
}

INT CObjectManager::AddObject(CGameObject* object)
{
	m_gameObjectList.push_back(object);
	return 0;
}

CGameObject CObjectManager::FindObject(CGameObject* object)
{
	return CGameObject();
}

BOOL CObjectManager::IsExistObject(CGameObject* object)
{
	for (auto iter = m_gameObjectList.begin(); iter != m_gameObjectList.end();)
	{
		if ((*iter) == object)
		{
			return TRUE;
		}
		iter++;
	}
	return FALSE;
}

BOOL CObjectManager::IsEmpty()
{
	return m_gameObjectList.empty();
}

void CObjectManager::Init()
{
	for (auto iter = m_gameObjectList.begin(); iter != m_gameObjectList.end();)
	{
		(*iter)->Init();
		iter++;
	}
}

void CObjectManager::FrameMove(DWORD elapsed)
{
	for (auto iter = m_gameObjectList.begin(); iter != m_gameObjectList.end();)
	{

		if ((*iter)->m_tag == PBULLET)
		{
			if (dynamic_cast<CPlayerBullet*>((*iter))->IsMapOut())
			{
				m_gameObjectList.erase(iter);
				break;
			}
		}
		(*iter)->FrameMove(elapsed);
		iter++;
	}
}

void CObjectManager::Control(CInput* m_Input)
{
	for (auto iter = m_gameObjectList.begin(); iter != m_gameObjectList.end();)
	{
		(*iter)->Control(m_Input);
		iter++;
	}
}

void CObjectManager::Render()
{
	for (auto iter = m_gameObjectList.begin(); iter != m_gameObjectList.end();)
	{
		(*iter)->Render();
		iter++;
	}
}

void CObjectManager::Release()
{
	for (auto iter = m_gameObjectList.begin(); iter != m_gameObjectList.end();)
	{
		(*iter)->Release();
		iter++;
	}
}
