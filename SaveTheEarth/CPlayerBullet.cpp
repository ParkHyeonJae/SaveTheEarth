#include "framework.h"

CPlayerBullet::CPlayerBullet(D2D1_POINT_2F m_Pos, FLOAT m_Rot, INT tag, INT m_GUN)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	this->m_GUN = m_GUN;
	//printf("%f\n", m_Rot);
	theta = m_Rot;
	m_BulletSpeed = 1.0f;
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (0).png", CGameManager::m_Gfx));
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (1).png", CGameManager::m_Gfx));
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (2).png", CGameManager::m_Gfx));
	m_RifleBulletAnimFunc = new CSpriteAnimation();
}

CPlayerBullet::~CPlayerBullet()
{
}

void CPlayerBullet::Init()
{
	RifleBulletAnimSequence = 0;
}

void CPlayerBullet::Render()
{
	D2D1_POINT_2F center = { m_Pos.x + (m_BulletSprites[RifleBulletAnimSequence]->GetBmp()->GetSize().width / 2), m_Pos.y + (m_BulletSprites[RifleBulletAnimSequence]->GetBmp()->GetSize().height / 2) };
	m_BulletSprites[RifleBulletAnimSequence]->Draw(m_Pos, D2D1::SizeF(1.0f, 1.0f), &center, theta);
	m_RifleBulletAnimFunc->OnAnimRender(100, 0, 3);

	
	//m_Sprite->Draw(m_Pos);
}

void CPlayerBullet::FrameMove(DWORD elapsed)
{
	switch (m_GUN)
	{
	case Rifle:
		m_BulletSpeed = 2;
		break;
	case Shotgun:

		break;
	}
	m_Pos.x += cosf(theta * CGameManager::radian) * m_BulletSpeed * elapsed;
	m_Pos.y += sinf(theta * CGameManager::radian) * m_BulletSpeed * elapsed;
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
	if (!m_BulletSprites.empty()) {
		m_BulletSprites.clear();
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
