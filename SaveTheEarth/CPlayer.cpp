#include "framework.h"
#include "CFadeInOut.h"

CPlayer::CPlayer(D2D1_POINT_2F m_Pos, INT tag, FLOAT m_HP) : CGameObject()
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	this->m_HP = m_HP;

	CGameManager::m_PlayerPos = m_Pos;


	for (INT i = 0; i < PLAYER_ANIM_COUNT; i++)
	{
		m_PlayerMotionAnimSequence[i] = 0;
		m_PlayerMotionAnimFunc[i] = new CSpriteAnimation();
	}
	m_RifleMotionFunc = new CSpriteAnimation();
	m_ShotgunMotionFunc = new CSpriteAnimation();

	m_playerBulletFireTimer = new CTimer(550);
	m_HitFadeInOut = new CFadeInOut(PLAYER_HIT_OVERLAY_COUNT, 0.2f);
	Init();
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Init()
{
	isHit = FALSE;
	overlay = 1.0f;
	m_Rot = 0.0f;
	MoveSpeed = 15.0f;
	m_playerState = IDLE;

	m_GunState = DEFAULT;

	m_RifleMotionSequence = 0;
	m_ShotgunMotionSequence = 0;

	IsStart = TRUE;
}


void CPlayer::FrameMove(DWORD elapsed)
{
	
	SetCollider(
		(LONG)(m_Pos.x - CollRange),
		(LONG)(m_Pos.y - CollRange),
		(LONG)(m_Pos.x + CollRange),
		(LONG)(m_Pos.y + CollRange - 20.0f)
	
	);
	if (IsStart)
	{
		if (m_Pos.x > 150.0f)
			IsStart = FALSE;
		MoveR();
	}
	if (CGameManager::m_PlayerAttribute.m_IncreaseHP != 0 
		&& m_HP <= MAX_PLAYER_HP - CGameManager::m_PlayerAttribute.m_IncreaseHP)
	{
		m_HP += CGameManager::m_PlayerAttribute.m_IncreaseHP;
		CGameManager::m_PlayerAttribute.m_IncreaseHP = 0;
	}
	else {
		static FLOAT wasPlayerHP = m_HP;
		if (wasPlayerHP != m_HP)		//HP에 변화를 감지했을 때
		{
			if (m_HP < wasPlayerHP)		//HP가 감소했을 때
			{
				m_HitFadeInOut->Initialize();
				overlay = 1.0f;
				isHit = TRUE;
			}
			wasPlayerHP = m_HP;
		}
	}
	if (isHit)
	{
		overlay = m_HitFadeInOut->Blinking();

		if (!m_HitFadeInOut->IsFinish())
			CGameManager::isinvincibility = TRUE;
		else {
			isHit = FALSE;
			CGameManager::isinvincibility = FALSE;
		}
	}

	CGameManager::m_playerHp = m_HP;
}
void CPlayer::MoveR()
{
	m_Pos.x += MoveSpeed;
	m_playerState = BACK;
}
void CPlayer::Control(CInput* m_Input)
{
	m_playerState = IDLE;
	if (CGameManager::EnableInput) {
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
	}
	if (!IsStart) {
		if (m_Pos.x > MAX_WIN_WIDTH - 120)
			m_Pos.x = MAX_WIN_WIDTH - 120;
		if (m_Pos.x < 0)
			m_Pos.x = 0;
		if (m_Pos.y > MAX_WIN_HEIGHT - 100)
			m_Pos.y = MAX_WIN_HEIGHT - 100;
		if (m_Pos.y < 0)
			m_Pos.y = 0;
	}
	float RotDegree = atan2f(m_Pos.y - m_Input->GetMousePos().y, m_Pos.x - m_Input->GetMousePos().x);
	m_Rot = (RotDegree * (180.0f / PI)) + 180.0f;

	if (CGameManager::m_PlayerAttribute.m_RPM != 0 && 0 < m_playerBulletFireTimer->GetDestTime() - CGameManager::m_PlayerAttribute.m_RPM)
	{
		m_playerBulletFireTimer->SetTimer(m_playerBulletFireTimer->GetDestTime() - CGameManager::m_PlayerAttribute.m_RPM);
		CGameManager::m_PlayerAttribute.m_RPM = 0;
	}
	if (CGameManager::EnableInput) {
		if (m_Input->BtnPress(VK_LBUTTON))
		{

			if (m_playerBulletFireTimer->OnTimer())
			{
				m_GunState = Rifle;
				m_PlayerBullet = new CPlayerBullet(D2D1::Point2F(CGameManager::m_PlayerPos.x, CGameManager::m_PlayerPos.y + 15.0f), m_Rot, PBULLET, m_GunState);
				OBJECT->AddObject(dynamic_cast<CGameObject*>(m_PlayerBullet));
			}
		}
		if (m_Input->BtnPress(VK_RBUTTON))
		{
			if (m_playerBulletFireTimer->OnTimer())
			{
				m_GunState = Shotgun;
				for (int i = m_Rot - 10; i < m_Rot + 10; i += 5)
				{
					m_PlayerBullet = new CPlayerBullet(D2D1::Point2F(CGameManager::m_PlayerPos.x, CGameManager::m_PlayerPos.y + 30.0f), i, PBULLET, m_GunState);
					OBJECT->AddObject(dynamic_cast<CGameObject*>(m_PlayerBullet));
				}
			}
		}
		if (m_Input->KeyDown('B') || m_Input->KeyDown('b')) {
			m_BarrierLauncher = new CPlayerBarrierLauncher(&m_Pos, BARRIER);
			OBJECT->AddObject(dynamic_cast<CGameObject*>(m_BarrierLauncher));
		}
		if (m_Input->KeyDown('V') || m_Input->KeyDown('v')) {
			m_LaserLauncher = new CPlayerLaserLauncher(&m_Pos, PLAYERLASER);
			OBJECT->AddObject(dynamic_cast<CGameObject*>(m_LaserLauncher));
		}
	}
	CGameManager::m_PlayerPos = m_Pos;
}

void CPlayer::Render()
{
	switch (m_playerState)
	{
	case IDLE:
		IMAGES
			->MultiRender("playerIdleMotion", m_PlayerMotionAnimSequence[m_playerState]
				, D2D1::Point2F(m_Pos.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, overlay);
		m_PlayerMotionAnimSequence[m_playerState] = m_PlayerMotionAnimFunc[m_playerState]->OnAnimRender(50, 0, 5);
		break;
	case BACK:
		IMAGES
			->MultiRender("playerBackMotion", m_PlayerMotionAnimSequence[m_playerState]
				, D2D1::Point2F(m_Pos.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, overlay);
		m_PlayerMotionAnimSequence[m_playerState] = m_PlayerMotionAnimFunc[m_playerState]->OnAnimRender(50, 0, 4);
		break;
	case FORWARD:
		IMAGES
			->MultiRender("playerForwardMotion", m_PlayerMotionAnimSequence[m_playerState]
				, D2D1::Point2F(m_Pos.x, m_Pos.y), D2D1::SizeF(1.0f, 1.0f), NULL, 0.0f, overlay);
		m_PlayerMotionAnimSequence[m_playerState] = m_PlayerMotionAnimFunc[m_playerState]->OnAnimRender(50, 0, 4);
		break;
	}
	
	switch (m_GunState)
	{
	case DEFAULT:
		IMAGES
			->Render("DefaultGun", D2D1::Point2F(m_Pos.x + 30, m_Pos.y + 20), D2D1::SizeF(1.0f, 1.0f), NULL, m_Rot, overlay);
		break;
	case Rifle:
		if (!m_RifleMotionFunc->IsEndFrame()) {
			m_RifleImageSize = CGameManager::m_ImageManager->GetMultiImageSize("RifleMotion" , m_RifleMotionSequence);
			D2D1_POINT_2F center = { (m_Pos.x + m_RifleImageSize.width / 2)
				, (m_Pos.y + m_RifleImageSize.height / 2) };
			IMAGES
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
			IMAGES
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
	if (!CGameManager::isinvincibility)
	{
		if (GetHp() <= 0)
			return FALSE;
		SetHp(GetHp() - damage);
	return TRUE;
	}
}
