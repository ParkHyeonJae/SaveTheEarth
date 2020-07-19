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

INT CObjectManager::AddUI(CGameObject* object)
{
	m_uiList.push_back(object);
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
	for (auto iter = m_uiList.begin(); iter != m_uiList.end();)
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
			CPlayer* m_cPlayer = dynamic_cast<CPlayer*>((*iter));
			float CollRange = 40.0f;
			RECT rPlayerColl = {
			(*iter)->GetPos().x - CollRange,
			(*iter)->GetPos().y - CollRange,
			(*iter)->GetPos().x + CollRange,
			(*iter)->GetPos().y + CollRange,
			};

			for (auto iter02 = m_gameObjectList.begin(); iter02 != m_gameObjectList.end();)
			{
				if ((*iter02)->m_tag == ENEMY)
				{
					float CollRange = 40.0f;
					RECT EnemyColl = {
					((*iter02)->GetPos().x - CollRange),
					((*iter02)->GetPos().y - CollRange),
					((*iter02)->GetPos().x + CollRange),
					((*iter02)->GetPos().y + CollRange),
					};

					RECT temp;
					if (IntersectRect(&temp, &rPlayerColl, &EnemyColl))
					{
						m_cPlayer->GetDamage(100.0f);
						break;
					}
				}
				if ((*iter02)->m_tag == BOSS)
				{
					RECT EnemyColl = {
					(*iter02)->GetPos().x + 0.0f,
					(*iter02)->GetPos().y + 0.0f,
					(*iter02)->GetPos().x + 200.0f,
					(*iter02)->GetPos().y + 300.0f,
					};

					RECT temp;
					if (IntersectRect(&temp, &rPlayerColl, &EnemyColl))
					{
						m_cPlayer->GetDamage(100.0f);
						break;
					}
				}
				if ((*iter02)->m_tag == MISILE)
				{
					MisileEnemy* m_misileEnemy = dynamic_cast<MisileEnemy*>((*iter02));
					if (m_misileEnemy->IsSpawn())
					{
						if (m_misileEnemy->IsMapOut())
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
							m_cPlayer->GetDamage(100.0f);
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
			CPlayerBullet* m_cPlayerBullet = dynamic_cast<CPlayerBullet*>((*iter));
			if (m_cPlayerBullet->IsMapOut())
			{
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
					CNormalEnemy* m_cNormalEnemy = dynamic_cast<CNormalEnemy*>((*Enemyiter));
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
						m_cPlayerBullet->SetColl(TRUE);
						if (m_cNormalEnemy->GetHp() >= 0) {
							m_cNormalEnemy->SetHp(
								m_cNormalEnemy->GetHp()
								- m_cPlayerBullet->GetDamage());
							break;
						}
						else
						{
							m_cNormalEnemy->SetDead(TRUE);
							break;
						}


						
						ispBulletColl = TRUE;
						break;
					}
					if (m_cNormalEnemy->IsDelete()) {
						m_gameObjectList.erase(Enemyiter);
						break;
					}
				}
				Enemyiter++;
			}
			if (m_cPlayerBullet->IsColl())
			{
				if (m_cPlayerBullet->IsDelete()) {
					m_gameObjectList.erase(iter);
					break;
				}
			}
			if (ispBulletColl)
			{
				//m_gameObjectList.erase(iter);
				ispBulletColl = FALSE;
				break;
			}
		}
		iter++;
	}
	for (auto iter = m_uiList.begin(); iter != m_uiList.end();)
	{
		(*iter)->FrameMove(elapsed);
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
	for (auto iter = m_uiList.begin(); iter != m_uiList.end();)
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
	for (auto iter = m_uiList.begin(); iter != m_uiList.end();)
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
	for (auto iter : m_uiList) {
		if (iter) {
			iter->Release();
			delete iter;
			iter = nullptr;
		}
	}
	m_gameObjectList.clear();
	m_uiList.clear();
}
