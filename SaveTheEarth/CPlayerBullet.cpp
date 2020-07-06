#include "framework.h"

CPlayerBullet::CPlayerBullet(D2D1_POINT_2F m_Pos, FLOAT m_Rot, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	//printf("%f\n", m_Rot);
	theta = m_Rot;
	m_BulletSpeed = 1.0f;
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (0).png", CGameManager::m_Gfx));
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (1).png", CGameManager::m_Gfx));
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (2).png", CGameManager::m_Gfx));
}

CPlayerBullet::~CPlayerBullet()
{
}

void CPlayerBullet::Init()
{
	CurAnimTime = timeGetTime();
	OldAnimTime = 0;
	sequence = 0;
}

void CPlayerBullet::Render()
{
	D2D1_POINT_2F center = { m_Pos.x + (m_BulletSprites[sequence]->GetBmp()->GetSize().width / 2), m_Pos.y + (m_BulletSprites[sequence]->GetBmp()->GetSize().height / 2) };
	m_BulletSprites[sequence]->Draw(m_Pos, D2D1::SizeF(1.0f, 1.0f), &center, theta);

	if (CurAnimTime - OldAnimTime > 100)
	{
		sequence++;
		if (sequence == 3)
			sequence = 0;
		OldAnimTime = CurAnimTime;
	}
	else
	{
		CurAnimTime = timeGetTime();
	}
	//m_Sprite->Draw(m_Pos);
}

void CPlayerBullet::FrameMove(DWORD elapsed)
{
	m_Pos.x += cosf(theta * CGameManager::radian) * m_BulletSpeed * elapsed;
	m_Pos.y += sinf(theta * CGameManager::radian) * m_BulletSpeed * elapsed;
}

void CPlayerBullet::Control(CInput* Input)
{
}

void CPlayerBullet::Release()
{
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
