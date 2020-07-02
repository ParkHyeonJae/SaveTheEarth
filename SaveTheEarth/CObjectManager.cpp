#include "framework.h"

CObjectManager::CObjectManager()
{
}

CObjectManager::~CObjectManager()
{
	AllRelease();
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

void CObjectManager::AllInitalize()
{
	for (auto iter = m_gameObjectList.begin(); iter != m_gameObjectList.end();)
	{
		(*iter)->Init();
		iter++;
	}
}

void CObjectManager::AllFrameMove(DWORD elapsed)
{
	for (auto iter = m_gameObjectList.begin(); iter != m_gameObjectList.end();)
	{
		(*iter)->FrameMove(elapsed);
		if ((*iter)->m_tag == EBULLET)
		{
			if (dynamic_cast<CNormalEnemyBullet*>((*iter))->IsMapOut())
			{
				m_gameObjectList.erase(iter);
				break;
			}
		}

		if ((*iter)->m_tag == PBULLET)
		{
			if (dynamic_cast<CPlayerBullet*>((*iter))->IsMapOut())
			{
				(*iter)->Release();
				m_gameObjectList.erase(iter);
				break;
			}

			RECT pBulletColl = {
				(*iter)->GetPos().x - 20,
				(*iter)->GetPos().y - 20,
				(*iter)->GetPos().x + 20,
				(*iter)->GetPos().y + 20,
			};

			for (auto Enemyiter = m_gameObjectList.begin(); Enemyiter != m_gameObjectList.end();)
			{
				(*Enemyiter)->FrameMove(elapsed);
				if ((*Enemyiter)->m_tag == ENEMY)
				{
					float CollRange = 40.0f;
					RECT EnemyColl = {
					(*Enemyiter)->GetPos().x - CollRange,
					(*Enemyiter)->GetPos().y - CollRange,
					(*Enemyiter)->GetPos().x + CollRange,
					(*Enemyiter)->GetPos().y + CollRange,
					};

					RECT temp;
					if (IntersectRect(&temp, &pBulletColl, &EnemyColl))
					{
						m_gameObjectList.erase(Enemyiter);
						break;
					}
				}
				Enemyiter++;
			}

		}
		
		iter++;
	}
}

void CObjectManager::AllControl(CInput* m_Input)
{
	for (auto iter = m_gameObjectList.begin(); iter != m_gameObjectList.end();)
	{
		(*iter)->Control(m_Input);
		iter++;
	}
}

void CObjectManager::AllRender()
{
	for (auto iter = m_gameObjectList.begin(); iter != m_gameObjectList.end();)
	{
		(*iter)->Render();
		iter++;
	}
}


void CObjectManager::AllRelease()
{
	for (auto iter : m_gameObjectList) {
		if (iter) {
			iter->Release();
			delete iter;
			iter = nullptr;
		}
	}
	m_gameObjectList.clear();
}
