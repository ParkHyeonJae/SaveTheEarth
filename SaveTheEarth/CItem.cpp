#include "framework.h"

CItem::CItem(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	INT State = rand() % 5;
	switch ((ITEMS)State) {
	case ITEMS::ATKUP:
		m_ItemSprite = IMAGES->GetSprite("ATKUP");
		break;
	case ITEMS::HPUP:
		m_ItemSprite = IMAGES->GetSprite("HPUP");
		break;
	case ITEMS::RPMUP:
		m_ItemSprite = IMAGES->GetSprite("RPMUP");
		break;
	case ITEMS::LASERBEAM:
		m_ItemSprite = IMAGES->GetSprite("LASERBEAM");
		break;
	case ITEMS::BARRIER:
		m_ItemSprite = IMAGES->GetSprite("BARRIER");
		break;
	default:
		break;
	}
	ItemState = State;
	MoveAngle = (FLOAT)(rand() % 360);

}

CItem::~CItem()
{
}

void CItem::Apply()
{
	
	switch ((ITEMS)ItemState)
	{
	case ITEMS::ATKUP:
		CGameManager::m_playerAttr.m_ATKDamage += 1.0f;
		break;
	case ITEMS::HPUP:
		CGameManager::m_playerAttr.m_UPHP = 100.0f;
		break;
	case ITEMS::RPMUP:
		CGameManager::m_playerAttr.m_RPM = 10.0f;
		break;
	case ITEMS::LASERBEAM:
		m_LaserLauncher = new CPlayerLaserLauncher(CGameManager::m_PlayerPos, PLAYERLASER);
		//CPlayerLaserLauncher * m_LaserLauncher = new CPlayerLaserLauncher(&m_Pos, PLAYERLASER);
		OBJECT->AddObject(dynamic_cast<CGameObject*>(m_LaserLauncher));
		break;
	case ITEMS::BARRIER:
		m_BarrierLauncher = new CPlayerBarrierLauncher(&CGameManager::m_PlayerPos, BARRIER);
		//CPlayerBarrierLauncher * m_BarrierLauncher = new CPlayerBarrierLauncher(&m_Pos, BARRIER);
		OBJECT->AddObject(dynamic_cast<CGameObject*>(m_BarrierLauncher));
		break;
	default:
		break;
	}
}

void CItem::Init()
{

}

void CItem::Render()
{
	m_ItemSprite->Draw(m_Pos);
}

void CItem::FrameMove(DWORD elapsed)
{
	SetCollider(
		(LONG)(m_Pos.x),
		(LONG)(m_Pos.y),
		(LONG)(m_Pos.x + GetSize().width),
		(LONG)(m_Pos.y + GetSize().height)
	);

	m_Pos.x += cosf(MoveAngle * Mathf::Radian);
	m_Pos.y += sinf(MoveAngle * Mathf::Radian);

	if (m_Pos.x > MAX_WIN_WIDTH)
		MoveAngle = -MoveAngle;
	if (m_Pos.x < 0)
		MoveAngle = -MoveAngle;
	if (m_Pos.y > MAX_WIN_HEIGHT - 100)
		MoveAngle = -MoveAngle;
	if (m_Pos.y < 0)
		MoveAngle = -MoveAngle;
}

void CItem::Control(CInput* Input)
{
}

void CItem::Release()
{
}
