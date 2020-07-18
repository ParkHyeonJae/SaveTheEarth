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
BOOL ispBulletColl = FALSE;
void CObjectManager::AllFrameMove(DWORD elapsed)
{
	for (auto iter = m_gameObjectList.begin(); iter != m_gameObjectList.end();)
	{
		(*iter)->FrameMove(elapsed);

		if ((*iter)->m_tag == PLAYER)
		{
			float CollRange = 40.0f;
			RECT rPlayerColl = {
			(*iter)->GetPos().x - CollRange,
			(*iter)->GetPos().y - CollRange,
			(*iter)->GetPos().x + CollRange,
			(*iter)->GetPos().y + CollRange,
			};

			for (auto iter02 = m_gameObjectList.begin(); iter02 != m_gameObjectList.end();)
			{
				if ((*iter02)->m_tag == MISILE)
				{
					if (dynamic_cast<MisileEnemy*>((*iter02))->IsSpawn())
					{
						if (dynamic_cast<MisileEnemy*>((*iter02))->IsMapOut())
						{
							(*iter02)->Release();
							delete (*iter02);
							iter02 = m_gameObjectList.erase(iter02);
							break;
						}
						RECT rMisileColl = {
						(*iter02)->GetPos().x - 20.0f,
						(*iter02)->GetPos().y - 20.0f,
						(*iter02)->GetPos().x + 20.0f,
						(*iter02)->GetPos().y + 20.0f,
						};

						RECT temp;
						if (IntersectRect(&temp, &rPlayerColl, &rMisileColl))
						{
							dynamic_cast<CPlayer*>((*iter))->GetDamage(100.0f);
							break;
						}
					}
				}

				iter02++;
			}

		}

		

		if ((*iter)->m_tag == EBULLET)
		{
			if (dynamic_cast<CNormalEnemyBullet*>((*iter))->IsMapOut())
			{
				(*iter)->Release();
				delete (*iter);
				iter = m_gameObjectList.erase(iter);
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
				(*iter)->GetPos().x - 20.0f,
				(*iter)->GetPos().y - 5.0f,
				(*iter)->GetPos().x + 20.0f,
				(*iter)->GetPos().y + 5.0f,
			};

			for (auto Enemyiter = m_gameObjectList.begin(); Enemyiter != m_gameObjectList.end();)
			{
				if ((*Enemyiter)->m_tag == BOSS)
				{
					RECT EnemyColl = {
					(*Enemyiter)->GetPos().x + 0.0f,
					(*Enemyiter)->GetPos().y + 0.0f,
					(*Enemyiter)->GetPos().x + 200.0f,
					(*Enemyiter)->GetPos().y + 300.0f,
					};

					RECT temp;
					if (IntersectRect(&temp, &pBulletColl, &EnemyColl))		//총알이 보스하고 닿았을때
					{
						//dynamic_cast<CPlayerBullet*>((*iter))->SetColl(TRUE);
						ispBulletColl = TRUE;
						break;
					}
				}
				if ((*Enemyiter)->m_tag == ENEMY)
				{
					float CollRange = 40.0f;
					RECT EnemyColl = {
					((*Enemyiter)->GetPos().x - CollRange),
					((*Enemyiter)->GetPos().y - CollRange),
					((*Enemyiter)->GetPos().x + CollRange),
					((*Enemyiter)->GetPos().y + CollRange),
					};

					RECT temp;
					if (IntersectRect(&temp, &pBulletColl, &EnemyColl))
					{
						if (dynamic_cast<CNormalEnemy*>((*Enemyiter))->GetHp() <= 0) {
							dynamic_cast<CNormalEnemy*>((*Enemyiter))->SetDead(TRUE);
							break;
						}
						dynamic_cast<CNormalEnemy*>((*Enemyiter))->SetHp(
							dynamic_cast<CNormalEnemy*>((*Enemyiter))->GetHp()
							- dynamic_cast<CPlayerBullet*>((*iter))->GetDamage());

						//dynamic_cast<CPlayerBullet*>((*iter))->SetColl(TRUE);

						
						ispBulletColl = TRUE;
						
						break;
					}
					if (dynamic_cast<CNormalEnemy*>((*Enemyiter))->IsDelete()) {
						m_gameObjectList.erase(Enemyiter);
						break;
					}
				}
				Enemyiter++;
			}
			//if (dynamic_cast<CPlayerBullet*>((*iter))->IsDelete())
			//{
			//	m_gameObjectList.erase(iter);
			//	break;
			//}
			if (ispBulletColl)
			{
				m_gameObjectList.erase(iter);
				ispBulletColl = FALSE;
				break;
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
