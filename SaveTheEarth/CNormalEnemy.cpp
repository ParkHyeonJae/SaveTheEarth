#include "framework.h"

CNormalEnemy::CNormalEnemy(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;
	m_TargetPos = { static_cast<FLOAT>(rand() % MAX_WIN_WIDTH), static_cast<FLOAT>(rand() % MAX_WIN_HEIGHT) };
	m_TargetPos.x -= 1800.0f;
	
	
	m_SharkAnimFunc = new CSpriteAnimation();
	m_SharkDeadAnimFunc = new CSpriteAnimation();
	m_SharkDeadAnimFunc->SetLoop(FALSE);
	m_ExplosiveAnimFunc = new CSpriteAnimation();

	m_HP = SHARKMAXHP;
	ExplosiveSequence = 0;
	SharkDeadAnimSequence = 0;
	SharkAnimSequence = 0;
	m_deadCheck = FALSE;
	m_isDelete = FALSE;
	m_Sprite = IMAGES
		->GetMultiSprite("SharkAnim")[0];
	m_SharkNullHP = IMAGES->GetSprite("SharkNullHp");
	m_SharkFullHP = IMAGES->GetSprite("SharkHpBar");
	m_SharkHP = new CHealthBar("SharkNullHp", "SharkHpBar", m_Pos, TRUE, FALSE);
}

CNormalEnemy::~CNormalEnemy()
{
}

void CNormalEnemy::Init()
{

}

void CNormalEnemy::Render()
{
	if (!m_isDelete) {
		if (!m_deadCheck)
		{
			angle = atan2f(m_Pos.y - m_TargetPos.y, m_Pos.x - m_TargetPos.x) * (180.0f / PI);
			SharkAnimSize = CGameManager::m_ImageManager->GetMultiImageSize("SharkAnim", SharkAnimSequence);
			D2D1_POINT_2F center = { m_Pos.x + (SharkAnimSize.width / 2), m_Pos.y + (SharkAnimSize.height / 2) };
			IMAGES
				->MultiRender("SharkAnim", SharkAnimSequence, m_Pos, D2D1::SizeF(1.0f, 1.0f), &center, angle);
			SharkAnimSequence = m_SharkAnimFunc->OnAnimRender(100, 0, 5);

			m_SharkHP->Setting(SHARKMAXHP, m_HP);
			D2D1_RECT_F hpSrc = {
				0,
				0,
				m_SharkHP->RestIMG() * -1,
				0
			};
			m_SharkNullHP->Draw(m_Pos);
			m_SharkFullHP->Draw(m_Pos, &hpSrc);
		}
		else
		{
			IMAGES
				->MultiRender("ExplosiveAnim", SharkAnimSequence, m_Pos, D2D1::SizeF(1.0f, 1.0f), NULL, angle);
			
			if (SharkDeadAnimSequence != 5) {
				IMAGES
					->MultiRender("SharkDeadAnim", SharkDeadAnimSequence, m_Pos, D2D1::SizeF(1.0f, 1.0f), NULL, angle);
				SharkDeadAnimSequence = m_SharkDeadAnimFunc->OnAnimRender(100, 0, 5);
			}
			SharkAnimSequence = m_ExplosiveAnimFunc->OnAnimRender(50, 0, 10);
			if (SharkAnimSequence == 9) {
				m_isDelete = TRUE;
				if (Mathf::Probability(50))
					OBJECT
					->AddObject(dynamic_cast<CGameObject*>
					(new CItem(m_Pos, ITEM)));
			}
		}
	}


}

void CNormalEnemy::FrameMove(DWORD elapsed)
{
	if (m_Pos.x < m_TargetPos.x)
		m_Pos.x++;
	if (m_Pos.x > m_TargetPos.x)
		m_Pos.x--;
	if (m_Pos.y < m_TargetPos.y)
		m_Pos.y++;
	if (m_Pos.y > m_TargetPos.y)
		m_Pos.y--;
}

void CNormalEnemy::Control(CInput* Input)
{

	//m_NormalEnemyBullet = new CNormalEnemyBullet(m_Pos, EBULLET);
	//CGameManager::m_ObjectManager->AddObject(dynamic_cast<CGameObject*>(m_NormalEnemyBullet));
}

void CNormalEnemy::Release()
{
	if (m_SharkAnimFunc)
	{
		delete m_SharkAnimFunc;
		m_SharkAnimFunc = nullptr;
	}
}
