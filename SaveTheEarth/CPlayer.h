#pragma once
#define PLAYER_ANIM_COUNT 3
#define PLAYER_HIT_OVERLAY_COUNT 6
class CPlayer : public CGameObject
{
private:
	BOOL IsStart;
private:
	INT m_playerState;
	INT m_PlayerMotionAnimSequence[PLAYER_ANIM_COUNT];
	CSpriteAnimation* m_PlayerMotionAnimFunc[PLAYER_ANIM_COUNT];
private:
	INT m_GunState;

	D2D1_SIZE_F m_RifleImageSize;
	INT m_RifleMotionSequence;
	INT m_ShotgunMotionSequence;

	CSpriteAnimation* m_RifleMotionFunc;
	CSpriteAnimation* m_ShotgunMotionFunc;

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
	FLOAT dTime;
	FLOAT HitOverlaySpeed;
	CTimer* m_playerBulletFireTimer;

private:
	CPlayerBarrierLauncher* m_BarrierLauncher;
public:
	CPlayer(D2D1_POINT_2F m_Pos, INT tag, FLOAT m_HP);
	~CPlayer();

	virtual void Init() override;
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
	virtual void Release() override;

	void MoveR();		//오른쪽으로 이동 (연출용 함수)

	FLOAT GetHp() { return m_HP; }
	void SetHp(FLOAT hp) { m_HP = hp; }

	FLOAT GetRot() { return m_Rot; }

	BOOL GetDamage(FLOAT damage);
};

