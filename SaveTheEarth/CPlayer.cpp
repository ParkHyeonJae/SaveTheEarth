#include "framework.h"

CPlayer::CPlayer(D2D1_POINT_2F m_Pos, INT tag, FLOAT m_HP) : CGameObject()
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	CGameManager::m_PlayerPos = m_Pos;
	this->m_HP = m_HP;

	m_playerBulletFireTimer = new CTimer(150);

	for (INT i = 0; i < PLAYER_ANIM_COUNT; i++)
	{
		m_PlayerMotionAnimSequence[i] = 0;
		m_PlayerMotionAnimFunc[i] = new CSpriteAnimation();
	}
	m_RifleMotionFunc = new CSpriteAnimation();
	m_ShotgunMotionFunc = new CSpriteAnimation();
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
	m_playerState = IDLE;

	m_GunState = DEFAULT;

	m_RifleMotionSequence = 0;
	m_ShotgunMotionSequence = 0;

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
	m_playerState = IDLE;
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
		m_playerState = FORWARD;
	}
	if (m_Input->KeyPress(VK_RIGHT) || m_Input->KeyPress('D'))
	{
		m_Pos.x += MoveSpeed;
		m_playerState = BACK;
	}

	if (m_Pos.x > MAX_WIN_WIDTH - 120)
		m_Pos.x = MAX_WIN_WIDTH - 120;
	if (m_Pos.x < 0)
		m_Pos.x = 0;
	if (m_Pos.y > MAX_WIN_HEIGHT - 100)
		m_Pos.y = MAX_WIN_HEIGHT - 100;
	if (m_Pos.y < 0)
		m_Pos.y = 0;

	float RotDegree = atan2f(m_Pos.y - m_Input->GetMousePos().y, m_Pos.x - m_Input->GetMousePos().x);
	m_Rot = (RotDegree * (180.0f / PI)) + 180.0f;

	if (m_Input->BtnDown(VK_LBUTTON))
	{
		if (m_playerBulletFireTimer->OnTimer())
		{
			m_GunState = Rifle;
			m_PlayerBullet = new CPlayerBullet(D2D1::Point2F(CGameManager::m_PlayerPos.x, CGameManager::m_PlayerPos.y + 15.0f), m_Rot, PBULLET, m_GunState);
			CGameManager::m_ObjectManager->AddObject(dynamic_cast<CGameObject*>(m_PlayerBullet));
		}
	}
	if (m_Input->BtnDown(VK_RBUTTON))
	{
		if (m_playerBulletFireTimer->OnTimer())
		{
			m_GunState = Shotgun;
			for (int i = m_Rot - 10; i < m_Rot + 10; i += 5)
			{
				m_PlayerBullet = new CPlayerBullet(D2D1::Point2F(CGameManager::m_PlayerPos.x, CGameManager::m_PlayerPos.y + 30.0f), i, PBULLET, m_GunState);
				CGameManager::m_ObjectManager->AddObject(dynamic_cast<CGameObject*>(m_PlayerBullet));
			}
		}
	}

	CGameManager::m_PlayerPos = m_Pos;
}

void CPlayer::Render()
{
	switch (m_playerState)
	{
	case IDLE:
		CGameManager::m_ImageManager->GetImages()
			->MultiRender("playerIdleMotion", m_PlayerMotionAnimSequence[m_playerState]
				, D2D1::Point2F(m_Pos.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, overlay);
		m_PlayerMotionAnimSequence[m_playerState] = m_PlayerMotionAnimFunc[m_playerState]->OnAnimRender(50, 0, 5);
		break;
	case BACK:
		CGameManager::m_ImageManager->GetImages()
			->MultiRender("playerBackMotion", m_PlayerMotionAnimSequence[m_playerState]
				, D2D1::Point2F(m_Pos.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, overlay);
		m_PlayerMotionAnimSequence[m_playerState] = m_PlayerMotionAnimFunc[m_playerState]->OnAnimRender(50, 0, 4);
		break;
	case FORWARD:
		CGameManager::m_ImageManager->GetImages()
			->MultiRender("playerForwardMotion", m_PlayerMotionAnimSequence[m_playerState]
				, D2D1::Point2F(m_Pos.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, overlay);
		m_PlayerMotionAnimSequence[m_playerState] = m_PlayerMotionAnimFunc[m_playerState]->OnAnimRender(50, 0, 4);
		break;
	}
	
	switch (m_GunState)
	{
	case DEFAULT:
		CGameManager::m_ImageManager->GetImages()
			->Render("DefaultGun", D2D1::Point2F(m_Pos.x + 30, m_Pos.y + 20), D2D1::SizeF(1.0f, 1.0f), NULL, m_Rot, overlay);
		break;
	case Rifle:
		if (!m_RifleMotionFunc->IsEndFrame()) {
			m_RifleImageSize = CGameManager::m_ImageManager->GetMultiImageSize("RifleMotion" , m_RifleMotionSequence);
			D2D1_POINT_2F center = { (m_Pos.x + m_RifleImageSize.width / 2)
				, (m_Pos.y + m_RifleImageSize.height / 2) };
			CGameManager::m_ImageManager->GetImages()
				->MultiRender("RifleMotion", m_RifleMotionSequence, D2D1::Point2F(m_Pos.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), &center, m_Rot, overlay);
			m_RifleMotionSequence = m_RifleMotionFunc->OnAnimRender(50, 0, 5);
		}
		else {
			m_RifleMotionSequence = 0;
			m_RifleMotionFunc->InitSequence();
			m_GunState = DEFAULT;
		}
		
		break;
	case Shotgun:
		if (!m_ShotgunMotionFunc->IsEndFrame()) {
			CGameManager::m_ImageManager->GetImages()
				->MultiRender("ShotgunMotion", m_ShotgunMotionSequence, D2D1::Point2F(m_Pos.x, m_Pos.y - 5), D2D1::SizeF(1.0f, 1.0f), NULL, m_Rot, overlay);
			m_ShotgunMotionSequence = m_ShotgunMotionFunc->OnAnimRender(50, 0, 5);
		}
		else {
			m_ShotgunMotionSequence = 0;
			m_ShotgunMotionFunc->InitSequence();
			m_GunState = DEFAULT;
		}
		break;
	}
	

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
