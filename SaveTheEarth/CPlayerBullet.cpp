#include "framework.h"

CPlayerBullet::CPlayerBullet(D2D1_POINT_2F m_Pos, FLOAT m_Rot, INT tag, INT m_GUN)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	this->m_GUN = m_GUN;

	theta = m_Rot;
	m_BulletSpeed = 1.0f;
	m_BulletDamage = CGameManager::m_PlayerAttribute.m_ATKDamage;

	m_RifleBulletAnimFunc = new CSpriteAnimation();
	m_RifleEffectAnimFunc = new CSpriteAnimation();
	m_ShotgunEffectAnimFunc = new CSpriteAnimation();
	Init();
}

CPlayerBullet::~CPlayerBullet()
{
	if (m_ShotgunEffectAnimFunc) {
		delete m_ShotgunEffectAnimFunc;
		m_ShotgunEffectAnimFunc = nullptr;
	}
	if (m_RifleEffectAnimFunc){
		delete m_RifleEffectAnimFunc;
		m_RifleEffectAnimFunc = nullptr;
	}
}

void CPlayerBullet::Init()
{
	RifleBulletAnimSequence = 0;

	RifleEffectAnimSequence = 0;
	ShotgunEffectAnimSequence = 0;
	CollCheck = FALSE;
	m_isDelete = FALSE;
}
void CPlayerBullet::Render()
{
	if (!CollCheck) {
		switch (m_GUN)
		{
		case Rifle:
			IMAGES->MultiRender("RifleBullet", RifleBulletAnimSequence, m_Pos, D2D1::SizeF(1.5f, 1.5f), NULL, theta);
			//m_BulletSprites[RifleBulletAnimSequence]->Draw(m_Pos, D2D1::SizeF(1.0f, 1.0f), NULL, theta);
			RifleBulletAnimSequence = m_RifleBulletAnimFunc->OnAnimRender(100, 0, 3);
			break;
		case Shotgun:
			IMAGES->Render("ShotgunBullet", m_Pos, D2D1::SizeF(1.5f, 1.5f), NULL, theta);
			break;
		}
	}
	else
	{
		switch (m_GUN)
		{
		case Rifle:
			IMAGES
				->MultiRender("RifleEffectAnim", RifleEffectAnimSequence
					,m_Pos, D2D1::SizeF(1.0f, 1.0f), NULL, theta);
			RifleEffectAnimSequence = m_RifleEffectAnimFunc->OnAnimRender(50, 0, 8);
			
			break;
		case Shotgun:
			IMAGES
				->MultiRender("ShotgunEffectAnim", ShotgunEffectAnimSequence
					, m_Pos, D2D1::SizeF(1.0f, 1.0f), NULL, theta);
			ShotgunEffectAnimSequence = m_ShotgunEffectAnimFunc->OnAnimRender(50, 0, 6);
			break;
		}
		if (m_RifleEffectAnimFunc->IsEndFrame() || m_ShotgunEffectAnimFunc->IsEndFrame()) {
			m_isDelete = TRUE;
			m_RifleEffectAnimFunc->InitSequence();
			m_ShotgunEffectAnimFunc->InitSequence();
		}
	}
}

void CPlayerBullet::FrameMove(DWORD elapsed)
{
	if (!CollCheck) {
		switch (m_GUN)
		{
		case Rifle:
			m_BulletSpeed = 20;
			break;
		case Shotgun:
			m_BulletSpeed = 10;
			break;
		}
		FLOAT Angle = theta * CGameManager::radian;
		m_Pos.x += cosf(Angle) * m_BulletSpeed;
		m_Pos.y += sinf(Angle) * m_BulletSpeed;
	}
}

void CPlayerBullet::Control(CInput* Input)
{
}

void CPlayerBullet::Release()
{
	if (m_RifleBulletAnimFunc)
	{
		delete m_RifleBulletAnimFunc;
		m_RifleBulletAnimFunc = nullptr;
	}
}


BOOL CPlayerBullet::IsMapOut()
{
	if (m_Pos.x < 0 || MAX_WIN_WIDTH < m_Pos.x)
		return TRUE;
	if (MAX_WIN_HEIGHT < m_Pos.y || m_Pos.y < 0)
		return TRUE;

	return FALSE;
}
