#include "framework.h"

CPlayer::CPlayer(D2D1_POINT_2F m_Pos, INT tag, FLOAT m_HP) : CGameObject()
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	CGameManager::m_PlayerPos = m_Pos;
	this->m_HP = m_HP;

	m_Sprite = new CSprite(L"../Images/Player.png", CGameManager::m_Gfx);
	
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Init()
{
	isHit = FALSE;
	overlay = 1.0f;
	m_hitEffectCount = 6;
	m_Rot = 0.0f;
	MoveSpeed = 15.0f;
	m_playerShootMode = Rifle;
}


void CPlayer::FrameMove(DWORD elapsed)
{
	static FLOAT wasPlayerHP = m_HP;
	if (wasPlayerHP != m_HP)		//HP에 변화를 감지했을 때
	{
		if (m_HP < wasPlayerHP)		//HP가 감소했을 때
		{
			isHit = TRUE;
		}
		wasPlayerHP = m_HP;
	}

	if (isHit)
	{
		if (m_hitEffectCount >= 0)
		{
			overlay = Mathf::Lerp(0.0f, 1.0f, tTime);

			if (tTime > 1.0f || tTime < 0.0f) {
				m_hitEffectCount--;
				dTime *= -1;
			}
			tTime += dTime;
		}
		else
		{

		}
	}

	CGameManager::m_playerHp = m_HP;
}

void CPlayer::Control(CInput* m_Input)
{

	if (m_Input->KeyPress(VK_UP) || m_Input->KeyPress('W'))
	{
		m_Pos.y -= MoveSpeed;
	}
	if (m_Input->KeyPress(VK_DOWN) || m_Input->KeyPress('S'))
	{
		m_Pos.y += MoveSpeed;
	}
	if (m_Input->KeyPress(VK_LEFT) || m_Input->KeyPress('A'))
	{
		m_Pos.x -= MoveSpeed;
	}
	if (m_Input->KeyPress(VK_RIGHT) || m_Input->KeyPress('D'))
	{
		m_Pos.x += MoveSpeed;
	}

	if (m_Pos.x > MAX_WIN_WIDTH - 120)
		m_Pos.x = MAX_WIN_WIDTH - 120;
	if (m_Pos.x < 0)
		m_Pos.x = 0;
	if (m_Pos.y > MAX_WIN_HEIGHT - 100)
		m_Pos.y = MAX_WIN_HEIGHT - 100;
	if (m_Pos.y < 0)
		m_Pos.y = 0;

	float RotDegree;
	switch (m_playerShootMode)
	{
	case Rifle:
		RotDegree = atan2f(m_Pos.y - m_Input->GetMousePos().y, m_Pos.x - m_Input->GetMousePos().x);
		m_Rot = (RotDegree * (180.0f / PI)) + 180.0f;
		break;

	case Shotgun:

		break;
	}


	CGameManager::m_PlayerPos = m_Pos;
}

void CPlayer::Render()
{
	D2D1_POINT_2F center = { m_Pos.x + (m_Sprite->GetBmp()->GetSize().width / 2),m_Pos.y + (m_Sprite->GetBmp()->GetSize().height / 2) };
	CGameManager::m_Gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	m_Sprite->Draw(D2D1::Point2F(m_Pos.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), &center, m_Rot, overlay);
}


void CPlayer::Release()
{
}

BOOL CPlayer::GetDamage(FLOAT damage)
{
	if (GetHp() <= 0)
		return FALSE;
	SetHp(GetHp() - damage);
	return TRUE;
}
