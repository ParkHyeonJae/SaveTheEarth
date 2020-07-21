#include "framework.h"

CItem::CItem(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	INT State = rand() % 3;
	switch (State) {
	case ATKUP:
		m_ItemSprite = CGameManager::m_ImageManager->GetImages()->GetSprite("ATKUP");
		break;
	case HPUP:
		m_ItemSprite = CGameManager::m_ImageManager->GetImages()->GetSprite("HPUP");
		break;
	case RPMUP:
		m_ItemSprite = CGameManager::m_ImageManager->GetImages()->GetSprite("RPMUP");
		break;
	}
	ItemState = State;
	MoveAngle = rand() % 360;

}

CItem::~CItem()
{
}

void CItem::Apply()
{
	switch (ItemState)
	{
	case ATKUP:
		CGameManager::m_PlayerAttribute.m_ATKDamage += 10.0f;
		break;
	case HPUP:
		CGameManager::m_PlayerAttribute.m_IncreaseHP = 25.0f;
		break;
	case RPMUP:
		CGameManager::m_PlayerAttribute.m_RPM = 10.0f;
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
