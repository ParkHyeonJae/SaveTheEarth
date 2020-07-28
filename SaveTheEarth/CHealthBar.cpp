#include "framework.h"


CHealthBar::CHealthBar(const string NullHpKey, const string FullHpKey, Vector2 m_Pos, BOOL X, BOOL Y)
{
	m_BossHpPos = m_Pos;

	m_BossNullHp = CGameManager::m_ImageManager->GetImages()->GetSprite(NullHpKey);
	m_BossFullHp = CGameManager::m_ImageManager->GetImages()->GetSprite(FullHpKey);

	HpBarSize.width = CGameManager::m_ImageManager->GetImageSize(NullHpKey).width;
	HpBarSize.height = CGameManager::m_ImageManager->GetImageSize(FullHpKey).height;

	if (X)
		MAXIMG = HpBarSize.width;
	else if(Y)
		MAXIMG = HpBarSize.height;
}

CHealthBar::~CHealthBar()
{
}

void CHealthBar::Setting(FLOAT MAXHP, FLOAT CurHP)
{
	this->MAXHP = MAXHP;
	this->CurHP = CurHP;
}

FLOAT CHealthBar::CurIMG()
{
	return (CurHP * MAXIMG) / MAXHP;
}

FLOAT CHealthBar::RestIMG()
{
	return (MAXIMG - CurIMG());
}
