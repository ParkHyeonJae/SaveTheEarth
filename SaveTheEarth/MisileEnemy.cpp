#include "framework.h"

MisileEnemy::MisileEnemy(D2D1_POINT_2F m_Pos, INT tag)
{
	this->m_Pos = m_Pos;
	this->m_tag = tag;

	overlay = 1.0f;
	m_warningCount = 6;
	m_MoveSpeed = 100.0f;
	m_SpawnCheck = FALSE;
}

MisileEnemy::~MisileEnemy()
{
}

void MisileEnemy::Init()
{

}

void MisileEnemy::Render()
{
	IMAGES
		->Render("warning", m_Pos, overlay);

	if (m_SpawnCheck) {
		IMAGES
			->Render("Misile", D2D1::Point2F(m_Pos.x, m_Pos.y + 40.0f), 1.0f);
	}
}

void MisileEnemy::FrameMove(DWORD elapsed)
{
	SetCollider(
		(LONG)(m_Pos.x - 20.0f),
		(LONG)(m_Pos.y - 15.0f),
		(LONG)(m_Pos.x + 20.0f),
		(LONG)(m_Pos.y + 20.0f)
	);
	if (m_warningCount > 0)
	{
		overlay = Mathf::Lerp(0.0f, 1.0f, tTime);
		if (tTime > 1.0f || tTime < 0.0f) {
			m_warningCount--;
			dTime *= -1;
		}
		tTime += dTime;

		if (m_warningCount == 0)
			m_Pos.x = MAX_WIN_WIDTH + 50;
	}
	else
	{
		m_SpawnCheck = TRUE;
		m_Pos.x -= m_MoveSpeed;
	}
}

void MisileEnemy::Control(CInput* Input)
{
}

void MisileEnemy::Release()
{
}

BOOL MisileEnemy::IsMapOut()
{
	if (m_Pos.x < 0 || MAX_WIN_WIDTH < m_Pos.x)
		return TRUE;
	if (MAX_WIN_HEIGHT < m_Pos.y || m_Pos.y < 0)
		return TRUE;

	return FALSE;
}