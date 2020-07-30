#include "framework.h"

CItem::CItem(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	INT State = rand() % 3;
	switch (State) {
	case ATKUP:
		m_ItemSprite = IMAGES->GetSprite("ATKUP");
		break;
	case HPUP:
		m_ItemSprite = IMAGES->GetSprite("HPUP");
		break;
	case RPMUP:
		m_ItemSprite = IMAGES->GetSprite("RPMUP");
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
		CGameManager::m_playerAttr.m_ATKDamage += 1.0f;
		break;
	case HPUP:
		CGameManager::m_playerAttr.m_UPHP = 100.0f;
		break;
	case RPMUP:
		CGameManager::m_playerAttr.m_RPM = 10.0f;
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
