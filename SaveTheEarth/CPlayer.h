#pragma once
#define PLAYER_ANIM_COUNT 3
class CPlayer : public CGameObject
{
private:
	INT m_playerState;
	std::vector<CSprite*> m_playerIdleMotion;
	std::vector<CSprite*> m_playerBackMotion;
	std::vector<CSprite*> m_playerForwardMotion;
	INT m_PlayerMotionAnimSequence[PLAYER_ANIM_COUNT];
	CSpriteAnimation* m_PlayerMotionAnimFunc[PLAYER_ANIM_COUNT];
private:
	INT m_GunState;
	std::vector<CSprite*> m_RifleMotion;
	std::vector<CSprite*> m_ShotgunMotion;
	CSprite* m_DefaultGun;
private:
	float m_Rot;
	float MoveSpeed;
	float m_HP;
	CPlayerBullet* m_PlayerBullet;
private:
	
	BOOL isHit;
	INT m_hitEffectCount;
	FLOAT overlay;
	FLOAT tTime = 0.0f;
	FLOAT dTime = 0.2f;

	CTimer* m_playerBulletFireTimer;
public:
	CPlayer(D2D1_POINT_2F m_Pos, INT tag, FLOAT m_HP);
	~CPlayer();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;

	FLOAT GetHp() { return m_HP; }
	void SetHp(FLOAT hp) { m_HP = hp; }

	FLOAT GetRot() { return m_Rot; }

	BOOL GetDamage(FLOAT damage);
};

