#include "framework.h"
#include "CScoreManager.h"

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
			(LONG)((*iter)->GetPos().x - CollRange),
			(LONG)((*iter)->GetPos().y - CollRange),
			(LONG)((*iter)->GetPos().x + CollRange),
			(LONG)((*iter)->GetPos().y + CollRange - 20.0f),
			};

			for (auto iter02 = m_gameObjectList.begin(); iter02 != m_gameObjectList.end();)
			{
				if ((*iter02)->m_tag == ENEMY)
				{
					float CollRange = 40.0f;
					RECT EnemyColl = {
					(LONG)((*iter02)->GetPos().x - CollRange),
					(LONG)((*iter02)->GetPos().y - CollRange),
					(LONG)((*iter02)->GetPos().x + CollRange),
					(LONG)((*iter02)->GetPos().y + CollRange),
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
					(LONG)((*iter02)->GetPos().x + 0.0f),
					(LONG)((*iter02)->GetPos().y + 0.0f),
					(LONG)((*iter02)->GetPos().x + 200.0f),
					(LONG)((*iter02)->GetPos().y + 300.0f),
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
						(LONG)((*iter02)->GetPos().x - 20.0f),
						(LONG)((*iter02)->GetPos().y - 15.0f),
						(LONG)((*iter02)->GetPos().x + 20.0f),
						(LONG)((*iter02)->GetPos().y + 20.0f),
						};

						RECT temp;
						if (IntersectRect(&temp, &rPlayerColl, &rMisileColl))
						{
							m_cPlayer->GetDamage(100.0f);
							break;
						}
					}
				}
				if ((*iter02)->m_tag == ITEM)
				{
					CItem* m_Item = dynamic_cast<CItem*>((*iter02));
					RECT rItemColl = {
						(LONG)((*iter02)->GetPos().x),
						(LONG)((*iter02)->GetPos().y),
						(LONG)((*iter02)->GetPos().x + m_Item->GetSize().width ),
						(LONG)((*iter02)->GetPos().y + m_Item->GetSize().height),
					};

					RECT temp;
					if (IntersectRect(&temp, &rPlayerColl, &rItemColl))
					{
						if (m_Item->GetItemState() == HPUP) {
							if (m_cPlayer->GetHp() < MAX_PLAYER_HP) {
								m_Item->Apply();
								m_gameObjectList.erase(iter02);
								break;
							}
						}
						else {
							m_Item->Apply();
							m_gameObjectList.erase(iter02);
							break;
						}
					}
				}
				if ((*iter02)->m_tag == BOSSLASER)
				{
					CBossLaserLauncher* m_BossLaser = dynamic_cast<CBossLaserLauncher*>((*iter02));
					if (m_BossLaser->IsRun() && !m_BossLaser->IsFinish())
					{
						if (m_BossLaser->GetLaserState() == LAUNCHER_STATE::LaserFire) {
							RECT rBOSSLaser = {
								(LONG)((*iter02)->GetPos().x - 1600),
								(LONG)((*iter02)->GetPos().y + 100),
								(LONG)((*iter02)->GetPos().x + 500),
								(LONG)((*iter02)->GetPos().y + 400)
							};
							RECT temp;
							if (IntersectRect(&temp, &rPlayerColl, &rBOSSLaser))
							{
								m_cPlayer->GetDamage(100.0f);
								break;
							}
						}
					}
				}

				iter02++;
			}

		}

		if ((*iter)->m_tag == BOSSBULLET)
		{
			CBossBullet* m_cBossBullet = dynamic_cast<CBossBullet*>((*iter));
			if (m_cBossBullet->IsMapOut())
			{
				m_gameObjectList.erase(iter);
				break;
			}
			RECT BossBulletColl = {
				(LONG)((*iter)->GetPos().x - 15.0f),
				(LONG)((*iter)->GetPos().y - 15.0f),
				(LONG)((*iter)->GetPos().x + 15.0f),
				(LONG)((*iter)->GetPos().y + 15.0f),
			};

			for (auto iter02 = m_gameObjectList.begin(); iter02 != m_gameObjectList.end();)
			{
				if ((*iter02)->m_tag == PLAYER)	// Enemyiter가 BOSS(보스 몬스터)일 경우
				{
					CPlayer* m_cPlayer = dynamic_cast<CPlayer*>((*iter02));
					float CollRange = 40.0f;
					RECT rPlayerColl = {
					(LONG)((*iter02)->GetPos().x - CollRange),
					(LONG)((*iter02)->GetPos().y - CollRange),
					(LONG)((*iter02)->GetPos().x + CollRange),
					(LONG)((*iter02)->GetPos().y + CollRange - 20.0f),
					};

					RECT temp;
					if (IntersectRect(&temp, &BossBulletColl, &rPlayerColl))		//총알이 보스하고 닿았을때
					{
						m_cBossBullet->SetColl(TRUE);
						m_cPlayer->GetDamage(m_cBossBullet->GetDamage());		//데미지
						m_cPlayer->SetPos(D2D1::Point2F(m_cPlayer->GetPos().x - 5.0f, m_cPlayer->GetPos().y));		//넉백
						break;
					}

				}
				iter02++;
			}
			if (m_cBossBullet->IsColl())		// 플레이어 총알이 충돌되었을 때
			{
				if (m_cBossBullet->IsDelete()) {		//플레이어 총알의 애니메이션이 모두 끝났을 때
					m_gameObjectList.erase(iter);		//총알 객체 제거
					break;
				}
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
		if ((*iter)->m_tag == PLAYERLASER)
		{
			CPlayerLaserLauncher* m_cPlayerLaser = dynamic_cast<CPlayerLaserLauncher*>((*iter));
			for (auto Enemyiter = m_gameObjectList.begin(); Enemyiter != m_gameObjectList.end();)
			{
				if ((*Enemyiter)->m_tag == ENEMY)		// Enemyiter가 ENEMY(일반 몬스터)일 경우
				{
					CNormalEnemy* m_cNormalEnemy = dynamic_cast<CNormalEnemy*>((*Enemyiter));
					float CollRange = 40.0f;
					RECT EnemyColl = {
					(LONG)((*Enemyiter)->GetPos().x - CollRange),
					(LONG)((*Enemyiter)->GetPos().y - CollRange),
					(LONG)((*Enemyiter)->GetPos().x + CollRange),
					(LONG)((*Enemyiter)->GetPos().y + CollRange),
					};

					RECT temp;
					if (IntersectRect(&temp, &m_cPlayerLaser->GetCollider(), &EnemyColl))		//플레이어 총알이 몬스터를 맞췄을 때
					{
						if (m_cNormalEnemy->GetHp() > 0) {		//몬스터가 죽지 않았을 때
							m_cNormalEnemy->SetHp(
								m_cNormalEnemy->GetHp()
								- m_cPlayerLaser->GetDamage());	//체력적용(몬스터의 현재HP - 플레이어 총알 데미지)
							break;
						}
						else
						{
							m_cNormalEnemy->SetDead(TRUE);		//몬스터 죽음
							break;
						}
						break;
					}

				}
				if ((*Enemyiter)->m_tag == BOSS)	// Enemyiter가 BOSS(보스 몬스터)일 경우
				{
					CBossEnemy* m_cBossEnemy = dynamic_cast<CBossEnemy*>((*Enemyiter));
					RECT EnemyColl = {
					(LONG)((*Enemyiter)->GetPos().x + 0.0f),
					(LONG)((*Enemyiter)->GetPos().y + 0.0f),
					(LONG)((*Enemyiter)->GetPos().x + 200.0f),
					(LONG)((*Enemyiter)->GetPos().y + 300.0f),
					};

					RECT temp;
					if (IntersectRect(&temp, &m_cPlayerLaser->GetCollider(), &EnemyColl))		//총알이 보스하고 닿았을때
					{
						if (m_cBossEnemy->GetHp() >= 0) {
							m_cBossEnemy->SetHp(
								m_cBossEnemy->GetHp()
								- m_cPlayerLaser->GetDamage());


							if (m_cBossEnemy->IsHit()) {
								break;
							}
							m_cBossEnemy->SetHit(TRUE);
							break;
						}
						else
						{
							m_cBossEnemy->SetDead(TRUE);
							break;
						}
						break;
					}

				}
				
				Enemyiter++;
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
				(LONG)((*iter)->GetPos().x - 20.0f),
				(LONG)((*iter)->GetPos().y - 5.0f),
				(LONG)((*iter)->GetPos().x + 20.0f),
				(LONG)((*iter)->GetPos().y + 5.0f),
			};

			for (auto Enemyiter = m_gameObjectList.begin(); Enemyiter != m_gameObjectList.end();)
			{
				if ((*Enemyiter)->m_tag == BOSS)	// Enemyiter가 BOSS(보스 몬스터)일 경우
				{
					CBossEnemy* m_cBossEnemy = dynamic_cast<CBossEnemy*>((*Enemyiter));
					RECT EnemyColl = {
					(LONG)((*Enemyiter)->GetPos().x + 0.0f),
					(LONG)((*Enemyiter)->GetPos().y + 0.0f),
					(LONG)((*Enemyiter)->GetPos().x + 200.0f),
					(LONG)((*Enemyiter)->GetPos().y + 300.0f),
					};

					RECT temp;
					if (IntersectRect(&temp, &pBulletColl, &EnemyColl))		//총알이 보스하고 닿았을때
					{
						m_cPlayerBullet->SetColl(TRUE);
						if (m_cBossEnemy->GetHp() >= 0) {
							m_cBossEnemy->SetHp(
								m_cBossEnemy->GetHp()
								- m_cPlayerBullet->GetDamage());

							
							if (m_cBossEnemy->IsHit()) {
								break;
							}
							m_cBossEnemy->SetHit(TRUE);
							break;
						}
						else
						{
							m_cBossEnemy->SetDead(TRUE);
							break;
						}
						break;
					}
					
				}
				if ((*Enemyiter)->m_tag == ENEMY)		// Enemyiter가 ENEMY(일반 몬스터)일 경우
				{
					CNormalEnemy* m_cNormalEnemy = dynamic_cast<CNormalEnemy*>((*Enemyiter));
					float CollRange = 40.0f;
					RECT EnemyColl = {
					(LONG)((*Enemyiter)->GetPos().x - CollRange),
					(LONG)((*Enemyiter)->GetPos().y - CollRange),
					(LONG)((*Enemyiter)->GetPos().x + CollRange),
					(LONG)((*Enemyiter)->GetPos().y + CollRange),
					};

					RECT temp;
					if (IntersectRect(&temp, &pBulletColl, &EnemyColl))		//플레이어 총알이 몬스터를 맞췄을 때
					{
						m_cPlayerBullet->SetColl(TRUE);		//총알 충돌
						if (m_cNormalEnemy->GetHp() > 0) {		//몬스터가 죽지 않았을 때
							m_cNormalEnemy->SetHp(
								m_cNormalEnemy->GetHp()
								- m_cPlayerBullet->GetDamage());	//체력적용(몬스터의 현재HP - 플레이어 총알 데미지)
							break;
						}
						else
						{
							m_cNormalEnemy->SetDead(TRUE);		//몬스터 죽음
							break;
						}
						break;
					}
					
				}
				Enemyiter++;
			}
			if (m_cPlayerBullet->IsColl())		// 플레이어 총알이 충돌되었을 때
			{
				if (m_cPlayerBullet->IsDelete()) {		//플레이어 총알의 애니메이션이 모두 끝났을 때
					m_gameObjectList.erase(iter);		//총알 객체 제거
					break;
				}
			}
		}
		if ((*iter)->m_tag == BOSS)	// Enemyiter가 BOSS(보스 몬스터)일 경우
		{
			if (dynamic_cast<CBossEnemy*>((*iter))->IsDelete()) {
				m_gameObjectList.erase(iter);
				CGameManager::nowStatus = TITLE;
				break;
			}
		}
		if ((*iter)->m_tag == ENEMY)	// Enemyiter가 BOSS(보스 몬스터)일 경우
		{
			if (dynamic_cast<CNormalEnemy*>((*iter))->IsDelete()) {		//몬스터가 죽고, 죽는 애니메이션까지 모두 끝낱을 때
				Score::CScoreManager::ApplyScore(CGameManager::ApplyScore);		//n점 추가
				m_gameObjectList.erase(iter);		//몬스터 객체 제거
				break;
			}
		}
		if ((*iter)->m_tag == BOSSBULLETLAUNCHER)	// Enemyiter가 BOSS(보스 몬스터)일 경우
		{
			CBossBulletLauncher* m_BossBullet = dynamic_cast<CBossBulletLauncher*>((*iter));
			if (!m_BossBullet->IsRun() && m_BossBullet->IsFinish())
			{
				m_gameObjectList.erase(iter);		//몬스터 객체 제거
				break;
			}
		}
		if ((*iter)->m_tag == BOSSLASER)	// Enemyiter가 BOSS(보스 몬스터)일 경우
		{
			CBossLaserLauncher* m_BossLaser = dynamic_cast<CBossLaserLauncher*>((*iter));
			if (!m_BossLaser->IsRun() && m_BossLaser->IsFinish())
			{
				m_gameObjectList.erase(iter);		//몬스터 객체 제거
				break;
			}
		}
		if ((*iter)->m_tag == BARRIER)	// Enemyiter가 BOSS(보스 몬스터)일 경우
		{
			CPlayerBarrierLauncher * m_Barrier = dynamic_cast<CPlayerBarrierLauncher*>((*iter));
			if (!m_Barrier->IsRun() && m_Barrier->IsFinish())
			{
				m_gameObjectList.erase(iter);		//몬스터 객체 제거
				break;
			}
		}
		if ((*iter)->m_tag == PLAYERLASER)	// Enemyiter가 BOSS(보스 몬스터)일 경우
		{
			CPlayerLaserLauncher* m_PlayerLaser = dynamic_cast<CPlayerLaserLauncher*>((*iter));
			if (!m_PlayerLaser->IsRun() && m_PlayerLaser->IsFinish())
			{
				m_gameObjectList.erase(iter);		//몬스터 객체 제거
				break;
			}
		}
		iter++;
	}
	for (auto iter = m_uiList.begin(); iter != m_uiList.end();)
	{
		//UI FrameMove
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
		//UI Control
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
		//UI Render
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
