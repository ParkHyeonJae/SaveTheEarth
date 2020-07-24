#include "framework.h"

CBossBullet::CBossBullet(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	BulletSpeed = 10.0f;
	Init();
}

CBossBullet::~CBossBullet()
{
}

void CBossBullet::Init()
{
	m_BulletDamage = 200.0f;
	m_Bullet.AnimFunc = new CSpriteAnimation();
	m_Bullet.sequence = 0;

	m_BulletEffect.AnimFunc = new CSpriteAnimation();
	m_BulletEffect.sequence = 0;
	CollCheck = FALSE;
	m_isDelete = FALSE;
	theta = atan2f(m_Pos.y - CGameManager::m_PlayerPos.y, m_Pos.x - CGameManager::m_PlayerPos.x) * Mathf::Radian;
}

void CBossBullet::Render()
{

	if (!CollCheck) {		//충돌안됬을때
		IMAGES->MultiRender("BossBullet", m_Bullet.sequence, m_Pos, D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, 1.0f);
		m_Bullet.sequence = m_Bullet.AnimFunc->OnAnimRender(100, 0, 3);
	}
	else  //충돌 됬을 시
	{
		IMAGES->MultiRender("BossBulletEffect", m_BulletEffect.sequence, m_Pos, D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, 1.0f);
		m_BulletEffect.sequence = m_BulletEffect.AnimFunc->OnAnimRender(100, 0, 8);

		if (m_BulletEffect.AnimFunc->IsEndFrame()) {
			m_isDelete = TRUE;
			m_BulletEffect.AnimFunc->InitSequence();
		}
	}
}

void CBossBullet::FrameMove(DWORD elapsed)
{
	SetCollider(
		(LONG)(m_Pos.x - 15.0f),
		(LONG)(m_Pos.y - 15.0f),
		(LONG)(m_Pos.x + 15.0f),
		(LONG)(m_Pos.y + 15.0f)
	);
	 m_Pos.y += sinf(theta) * BulletSpeed;
	 m_Pos.x -= BulletSpeed;
}

void CBossBullet::Control(CInput* Input)
{
}

void CBossBullet::Release()
{
}

BOOL CBossBullet::IsMapOut()
{
	if (m_Pos.x < 0 || MAX_WIN_WIDTH < m_Pos.x)
		return TRUE;
	if (MAX_WIN_HEIGHT < m_Pos.y || m_Pos.y < 0)
		return TRUE;

	return FALSE;
}
