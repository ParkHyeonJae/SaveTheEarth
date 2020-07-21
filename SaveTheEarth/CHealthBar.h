#pragma once
class CHealthBar
{
private:
	CSprite* m_BossNullHp;
	CSprite* m_BossFullHp;
	D2D1_SIZE_F HpBarSize;
	Vector2 m_BossHpPos;

	FLOAT MAXHP;
	FLOAT CurHP;
	FLOAT MAXIMG;
public:
	CHealthBar(const string NullHpKey, const string FullHpKey, Vector2 m_Pos, BOOL X, BOOL Y);
	~CHealthBar();

	void Setting(FLOAT MAXHP, FLOAT CurHP);
	FLOAT CurIMG();
	FLOAT RestIMG();
};

