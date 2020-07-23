#include "framework.h"

CImageManager::CImageManager()
{
	m_Images = new Cimage();
}

CImageManager::~CImageManager()
{

}

INT CImageManager::ImageInit()
{
	// 플레이어 무기 : 라이플 총알
	std::vector<CSprite*> m_BulletSprites;
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (0).png", CGameManager::m_Gfx));
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (1).png", CGameManager::m_Gfx));
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (2).png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("RifleBullet", m_BulletSprites);

	// 플레이어 무기 : 샷건 총알
	m_Images->AddImage("ShotgunBullet", new CSprite(L"../Images/PlayerBullet (3).png", CGameManager::m_Gfx));

	// 플레이어 무기 : 라이플 총알 (충돌 시 이펙트)
	std::vector<CSprite*> m_RifleEffectAnim;
	m_RifleEffectAnim.push_back(new CSprite(L"../Images/Sprites/03 Rifle Effect/1.png", CGameManager::m_Gfx));
	m_RifleEffectAnim.push_back(new CSprite(L"../Images/Sprites/03 Rifle Effect/2.png", CGameManager::m_Gfx));
	m_RifleEffectAnim.push_back(new CSprite(L"../Images/Sprites/03 Rifle Effect/3.png", CGameManager::m_Gfx));
	m_RifleEffectAnim.push_back(new CSprite(L"../Images/Sprites/03 Rifle Effect/4.png", CGameManager::m_Gfx));
	m_RifleEffectAnim.push_back(new CSprite(L"../Images/Sprites/03 Rifle Effect/5.png", CGameManager::m_Gfx));
	m_RifleEffectAnim.push_back(new CSprite(L"../Images/Sprites/03 Rifle Effect/6.png", CGameManager::m_Gfx));
	m_RifleEffectAnim.push_back(new CSprite(L"../Images/Sprites/03 Rifle Effect/7.png", CGameManager::m_Gfx));
	m_RifleEffectAnim.push_back(new CSprite(L"../Images/Sprites/03 Rifle Effect/8.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("RifleEffectAnim", m_RifleEffectAnim);

	// 플레이어 무기 : 샷건 총알 (충돌 시 이펙트)
	std::vector<CSprite*> m_ShotgunEffectAnim;
	m_ShotgunEffectAnim.push_back(new CSprite(L"../Images/Sprites/07 Shotgun Effect/1.png", CGameManager::m_Gfx));
	m_ShotgunEffectAnim.push_back(new CSprite(L"../Images/Sprites/07 Shotgun Effect/2.png", CGameManager::m_Gfx));
	m_ShotgunEffectAnim.push_back(new CSprite(L"../Images/Sprites/07 Shotgun Effect/3.png", CGameManager::m_Gfx));
	m_ShotgunEffectAnim.push_back(new CSprite(L"../Images/Sprites/07 Shotgun Effect/4.png", CGameManager::m_Gfx));
	m_ShotgunEffectAnim.push_back(new CSprite(L"../Images/Sprites/07 Shotgun Effect/5.png", CGameManager::m_Gfx));
	m_ShotgunEffectAnim.push_back(new CSprite(L"../Images/Sprites/07 Shotgun Effect/6.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("ShotgunEffectAnim", m_ShotgunEffectAnim);

	// 스테이지 01 - 스크롤 배경 요소 (하늘, 구름, 산, 태양, 나무)
	m_Images->AddImage("Stage01/SKY", new CSprite(L"../Images/Stage01/Stage01_Sky.png", CGameManager::m_Gfx));
	m_Images->AddImage("Stage01/CLOUD", new CSprite(L"../Images/Stage01/Stage01_Cloud.png", CGameManager::m_Gfx));
	m_Images->AddImage("Stage01/MOUNTAIN", new CSprite(L"../Images/Stage01/Stage01_Mountain.png", CGameManager::m_Gfx));
	m_Images->AddImage("Stage01/SUN", new CSprite(L"../Images/Stage01/Stage01_Sun.png", CGameManager::m_Gfx));
	m_Images->AddImage("Stage01/TREES", new CSprite(L"../Images/Stage01/Stage01_Trees.png", CGameManager::m_Gfx));
	
	// 스테이지 02 - 스크롤 배경 요소 (하늘, 산, 나무)
	m_Images->AddImage("Stage02/SKY", new CSprite(L"../Images/Stage02/Stage02_Sky.png", CGameManager::m_Gfx));
	m_Images->AddImage("Stage02/MOUNTAIN", new CSprite(L"../Images/Stage02/Stage02_Mountain.png", CGameManager::m_Gfx));
	m_Images->AddImage("Stage02/TREES", new CSprite(L"../Images/Stage02/Stage02_Trees.png", CGameManager::m_Gfx));

	// 보스 기본 대기 애니메이션
	std::vector<CSprite*> m_BossAnim;
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/1.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/2.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/3.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/4.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/5.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/6.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/7.png", CGameManager::m_Gfx));
	m_BossAnim.push_back(new CSprite(L"../Images/Sprites/04 Boss/8.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("BossIdleAnim", m_BossAnim);

	// 플레이어 체력
	m_Images->AddImage("playerHpBar_background", new CSprite(L"../Images/null hp.png", CGameManager::m_Gfx));
	m_Images->AddImage("playerHpBar_foreground", new CSprite(L"../Images/HP bar.png", CGameManager::m_Gfx));
	
	// 플레이어 애니메이션 : 대기
	std::vector<CSprite*> m_playerIdleMotion;
	m_playerIdleMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/IDLE/1.png", CGameManager::m_Gfx));
	m_playerIdleMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/IDLE/2.png", CGameManager::m_Gfx));
	m_playerIdleMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/IDLE/3.png", CGameManager::m_Gfx));
	m_playerIdleMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/IDLE/4.png", CGameManager::m_Gfx));
	m_playerIdleMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/IDLE/5.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("playerIdleMotion", m_playerIdleMotion);

	// 플레이어 애니메이션 : 후진
	std::vector<CSprite*> m_playerBackMotion;
	m_playerBackMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/FORWARD/1.png", CGameManager::m_Gfx));
	m_playerBackMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/FORWARD/2.png", CGameManager::m_Gfx));
	m_playerBackMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/FORWARD/3.png", CGameManager::m_Gfx));
	m_playerBackMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/FORWARD/4.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("playerBackMotion", m_playerBackMotion);

	// 플레이어 애니메이션 : 전진
	std::vector<CSprite*> m_playerForwardMotion;
	m_playerForwardMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/BACK/1.png", CGameManager::m_Gfx));
	m_playerForwardMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/BACK/2.png", CGameManager::m_Gfx));
	m_playerForwardMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/BACK/3.png", CGameManager::m_Gfx));
	m_playerForwardMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/BACK/4.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("playerForwardMotion", m_playerForwardMotion);

	// 플레이어 무기 : 기본
	m_Images->AddImage("DefaultGun", new CSprite(L"../Images/Sprites/DefaultGun.png", CGameManager::m_Gfx));

	// 플레이어 무기 : 라이플 (발사)
	std::vector<CSprite*> m_RifleMotion;
	m_RifleMotion.push_back(new CSprite(L"../Images/Sprites/02 Rifle Motion/1.png", CGameManager::m_Gfx));
	m_RifleMotion.push_back(new CSprite(L"../Images/Sprites/02 Rifle Motion/2.png", CGameManager::m_Gfx));
	m_RifleMotion.push_back(new CSprite(L"../Images/Sprites/02 Rifle Motion/3.png", CGameManager::m_Gfx));
	m_RifleMotion.push_back(new CSprite(L"../Images/Sprites/02 Rifle Motion/4.png", CGameManager::m_Gfx));
	m_RifleMotion.push_back(new CSprite(L"../Images/Sprites/02 Rifle Motion/5.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("RifleMotion", m_RifleMotion);

	// 플레이어 무기 : 샷건 (발사)
	std::vector<CSprite*> m_ShotgunMotion;
	m_ShotgunMotion.push_back(new CSprite(L"../Images/Sprites/06 Shotgun Motion/1.png", CGameManager::m_Gfx));
	m_ShotgunMotion.push_back(new CSprite(L"../Images/Sprites/06 Shotgun Motion/2.png", CGameManager::m_Gfx));
	m_ShotgunMotion.push_back(new CSprite(L"../Images/Sprites/06 Shotgun Motion/3.png", CGameManager::m_Gfx));
	m_ShotgunMotion.push_back(new CSprite(L"../Images/Sprites/06 Shotgun Motion/4.png", CGameManager::m_Gfx));
	m_ShotgunMotion.push_back(new CSprite(L"../Images/Sprites/06 Shotgun Motion/5.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("ShotgunMotion", m_ShotgunMotion);

	// 일반 몬스터 (샤크)
	std::vector<CSprite*> m_SharkAnim;
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/1.png", CGameManager::m_Gfx));
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/2.png", CGameManager::m_Gfx));
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/3.png", CGameManager::m_Gfx));
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/4.png", CGameManager::m_Gfx));
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/5.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("SharkAnim", m_SharkAnim);

	// 일반 몬스터 (샤크) 죽음
	std::vector<CSprite*> m_SharkDeadAnim;
	m_SharkDeadAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/Dead/1.png", CGameManager::m_Gfx));
	m_SharkDeadAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/Dead/2.png", CGameManager::m_Gfx));
	m_SharkDeadAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/Dead/3.png", CGameManager::m_Gfx));
	m_SharkDeadAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/Dead/4.png", CGameManager::m_Gfx));
	m_SharkDeadAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/Dead/5.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("SharkDeadAnim", m_SharkDeadAnim);

	// Explosive (폭팔)
	std::vector<CSprite*> m_ExplosiveAnim;
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/1.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/2.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/3.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/4.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/5.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/6.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/7.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/8.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/9.png", CGameManager::m_Gfx));
	m_ExplosiveAnim.push_back(new CSprite(L"../Images/Sprites/08 Explosive/10.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("ExplosiveAnim", m_ExplosiveAnim);

	// ENEMY - Misile
	m_Images->AddImage("warning", new CSprite(L"../Images/warnnig.png", CGameManager::m_Gfx));
	m_Images->AddImage("Misile", new CSprite(L"../Images/Misile.png", CGameManager::m_Gfx));

	// 타이틀 BG
	m_Images->AddImage("Title/Title", new CSprite(L"../Images/Title/TitleBG.png", CGameManager::m_Gfx));
	m_Images->AddImage("Title/Logo", new CSprite(L"../Images/Title/Logo.png", CGameManager::m_Gfx));
	m_Images->AddImage("Title/Cloud", new CSprite(L"../Images/Title/Cloud.png", CGameManager::m_Gfx));

	// UI/GameStart
	m_Images->AddImage("UI/GameStart", new CSprite(L"../Images/Title/UI/GameStart.png", CGameManager::m_Gfx));
	m_Images->AddImage("UI/GameStart_SELECT", new CSprite(L"../Images/Title/UI/GameStart_SELECT.png", CGameManager::m_Gfx));
	m_Images->AddImage("UI/GameStart_PRESS", new CSprite(L"../Images/Title/UI/GameStart_PRESS.png", CGameManager::m_Gfx));
	
	// UI/HowToPlay
	m_Images->AddImage("UI/HowToPlay", new CSprite(L"../Images/Title/UI/HowToPlay.png", CGameManager::m_Gfx));
	m_Images->AddImage("UI/HowToPlay_SELECT", new CSprite(L"../Images/Title/UI/HowToPlay_SELECT.png", CGameManager::m_Gfx));
	m_Images->AddImage("UI/HowToPlay_PRESS", new CSprite(L"../Images/Title/UI/HowToPlay_PRESS.png", CGameManager::m_Gfx));
	
	// UI/Credit
	m_Images->AddImage("UI/Credit", new CSprite(L"../Images/Title/UI/Credit.png", CGameManager::m_Gfx));
	m_Images->AddImage("UI/Credit_SELECT", new CSprite(L"../Images/Title/UI/Credit_SELECT.png", CGameManager::m_Gfx));
	m_Images->AddImage("UI/Credit_PRESS", new CSprite(L"../Images/Title/UI/Credit_PRESS.png", CGameManager::m_Gfx));
	
	// UI/Option
	m_Images->AddImage("UI/Option", new CSprite(L"../Images/Title/UI/Option.png", CGameManager::m_Gfx));
	m_Images->AddImage("UI/Option_SELECT", new CSprite(L"../Images/Title/UI/Option_SELECT.png", CGameManager::m_Gfx));
	m_Images->AddImage("UI/Option_PRESS", new CSprite(L"../Images/Title/UI/Option_PRESS.png", CGameManager::m_Gfx));
	
	// UI/Exit
	m_Images->AddImage("UI/Exit", new CSprite(L"../Images/Title/UI/Exit.png", CGameManager::m_Gfx));
	m_Images->AddImage("UI/Exit_SELECT", new CSprite(L"../Images/Title/UI/Exit_SELECT.png", CGameManager::m_Gfx));
	m_Images->AddImage("UI/Exit_PRESS", new CSprite(L"../Images/Title/UI/Exit_PRESS.png", CGameManager::m_Gfx));

	std::vector<CSprite*> m_UISelectAnim;
	m_UISelectAnim.push_back(new CSprite(L"../Images/Title/01 UI Select Animation/1.png", CGameManager::m_Gfx));
	m_UISelectAnim.push_back(new CSprite(L"../Images/Title/01 UI Select Animation/2.png", CGameManager::m_Gfx));
	m_UISelectAnim.push_back(new CSprite(L"../Images/Title/01 UI Select Animation/3.png", CGameManager::m_Gfx));
	m_UISelectAnim.push_back(new CSprite(L"../Images/Title/01 UI Select Animation/4.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("UISelectAnim", m_UISelectAnim);

	//Credit Image
	m_Images->AddImage("Credit", new CSprite(L"../Images/Title/Credit.png", CGameManager::m_Gfx));

	// Distance Bar
	m_Images->AddImage("LongBar", new CSprite(L"../Images/Sprites/10 Distance Bar/long bar.png", CGameManager::m_Gfx));
	m_Images->AddImage("Where", new CSprite(L"../Images/Sprites/10 Distance Bar/where.png", CGameManager::m_Gfx));
	
	//BOSS HP Bar
	m_Images->AddImage("BossNullHp", new CSprite(L"../Images/Sprites/04 Boss/BossHPBar/bossNullHP.png", CGameManager::m_Gfx));
	m_Images->AddImage("BossHpBar", new CSprite(L"../Images/Sprites/04 Boss/BossHPBar/bossHPbar.png", CGameManager::m_Gfx));

	//Shark HP Bar
	m_Images->AddImage("SharkNullHp", new CSprite(L"../Images/Sprites/05 Shark Animation/HpBar/SharkHPBar_Back.png", CGameManager::m_Gfx));
	m_Images->AddImage("SharkHpBar", new CSprite(L"../Images/Sprites/05 Shark Animation/HpBar/SharkHPBar_Fore.png", CGameManager::m_Gfx));

	//Items
	m_Images->AddImage("ATKUP", new CSprite(L"../Images/Sprites/01 Items/01 ATKUP.png", CGameManager::m_Gfx));
	m_Images->AddImage("HPUP", new CSprite(L"../Images/Sprites/01 Items/02 HPUP.png", CGameManager::m_Gfx));
	m_Images->AddImage("RPMUP", new CSprite(L"../Images/Sprites/01 Items/03 RPMUP.png", CGameManager::m_Gfx));

	//Boss Laser Skills
	// 보스 스킬 - 레이저 (차징)
	std::vector<CSprite*> m_BossLaser_Charging;
	m_BossLaser_Charging.push_back(new CSprite(L"../Images/Sprites/04 Boss/01 BossLaserCharging/1.png", CGameManager::m_Gfx));
	m_BossLaser_Charging.push_back(new CSprite(L"../Images/Sprites/04 Boss/01 BossLaserCharging/2.png", CGameManager::m_Gfx));
	m_BossLaser_Charging.push_back(new CSprite(L"../Images/Sprites/04 Boss/01 BossLaserCharging/3.png", CGameManager::m_Gfx));
	m_BossLaser_Charging.push_back(new CSprite(L"../Images/Sprites/04 Boss/01 BossLaserCharging/4.png", CGameManager::m_Gfx));
	m_BossLaser_Charging.push_back(new CSprite(L"../Images/Sprites/04 Boss/01 BossLaserCharging/5.png", CGameManager::m_Gfx));
	m_BossLaser_Charging.push_back(new CSprite(L"../Images/Sprites/04 Boss/01 BossLaserCharging/6.png", CGameManager::m_Gfx));
	m_BossLaser_Charging.push_back(new CSprite(L"../Images/Sprites/04 Boss/01 BossLaserCharging/7.png", CGameManager::m_Gfx));
	m_BossLaser_Charging.push_back(new CSprite(L"../Images/Sprites/04 Boss/01 BossLaserCharging/8.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("BossLaser_Charging", m_BossLaser_Charging);

	// 보스 스킬 - 레이저 (가동)
	std::vector<CSprite*> m_BossLaser_On;
	m_BossLaser_On.push_back(new CSprite(L"../Images/Sprites/04 Boss/02 BossLaserOn/1.png", CGameManager::m_Gfx));
	m_BossLaser_On.push_back(new CSprite(L"../Images/Sprites/04 Boss/02 BossLaserOn/2.png", CGameManager::m_Gfx));
	m_BossLaser_On.push_back(new CSprite(L"../Images/Sprites/04 Boss/02 BossLaserOn/3.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("BossLaser_On", m_BossLaser_On);

	// 보스 스킬 - 레이저 (발사)
	std::vector<CSprite*> m_BossLaser_Fire;
	m_BossLaser_Fire.push_back(new CSprite(L"../Images/Sprites/04 Boss/03 BossLaserFire/1.png", CGameManager::m_Gfx));
	m_BossLaser_Fire.push_back(new CSprite(L"../Images/Sprites/04 Boss/03 BossLaserFire/2.png", CGameManager::m_Gfx));
	m_BossLaser_Fire.push_back(new CSprite(L"../Images/Sprites/04 Boss/03 BossLaserFire/3.png", CGameManager::m_Gfx));
	m_BossLaser_Fire.push_back(new CSprite(L"../Images/Sprites/04 Boss/03 BossLaserFire/4.png", CGameManager::m_Gfx));
	m_BossLaser_Fire.push_back(new CSprite(L"../Images/Sprites/04 Boss/03 BossLaserFire/5.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("BossLaser_Fire", m_BossLaser_Fire);

	// 보스 스킬 - 레이저 (종료)
	std::vector<CSprite*> m_BossLaser_Off;
	m_BossLaser_Off.push_back(new CSprite(L"../Images/Sprites/04 Boss/04 BossLaserOff/1.png", CGameManager::m_Gfx));
	m_BossLaser_Off.push_back(new CSprite(L"../Images/Sprites/04 Boss/04 BossLaserOff/2.png", CGameManager::m_Gfx));
	m_BossLaser_Off.push_back(new CSprite(L"../Images/Sprites/04 Boss/04 BossLaserOff/3.png", CGameManager::m_Gfx));
	m_BossLaser_Off.push_back(new CSprite(L"../Images/Sprites/04 Boss/04 BossLaserOff/4.png", CGameManager::m_Gfx));
	m_BossLaser_Off.push_back(new CSprite(L"../Images/Sprites/04 Boss/04 BossLaserOff/5.png", CGameManager::m_Gfx));
	m_BossLaser_Off.push_back(new CSprite(L"../Images/Sprites/04 Boss/04 BossLaserOff/6.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("BossLaser_Off", m_BossLaser_Off);

	// 보스 스킬 - 총알(보스 총알 발사 애니메이션)
	std::vector<CSprite*> m_BossBulletIdle;
	m_BossBulletIdle.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/BossIdle/1.png", CGameManager::m_Gfx));
	m_BossBulletIdle.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/BossIdle/2.png", CGameManager::m_Gfx));
	m_BossBulletIdle.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/BossIdle/3.png", CGameManager::m_Gfx));
	m_BossBulletIdle.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/BossIdle/4.png", CGameManager::m_Gfx));
	m_BossBulletIdle.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/BossIdle/5.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("BossBulletIdle", m_BossBulletIdle);

	// 보스 스킬 - 총알
	std::vector<CSprite*> m_BossBullet;
	m_BossBullet.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/Bullet/1.png", CGameManager::m_Gfx));
	m_BossBullet.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/Bullet/2.png", CGameManager::m_Gfx));
	m_BossBullet.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/Bullet/3.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("BossBullet", m_BossBullet);

	// 보스 스킬 - 총알(총알 충돌 이펙트)
	std::vector<CSprite*> m_BossBulletEffect;
	m_BossBulletEffect.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/BulletEffect/1.png", CGameManager::m_Gfx));
	m_BossBulletEffect.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/BulletEffect/2.png", CGameManager::m_Gfx));
	m_BossBulletEffect.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/BulletEffect/3.png", CGameManager::m_Gfx));
	m_BossBulletEffect.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/BulletEffect/4.png", CGameManager::m_Gfx));
	m_BossBulletEffect.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/BulletEffect/5.png", CGameManager::m_Gfx));
	m_BossBulletEffect.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/BulletEffect/6.png", CGameManager::m_Gfx));
	m_BossBulletEffect.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/BulletEffect/7.png", CGameManager::m_Gfx));
	m_BossBulletEffect.push_back(new CSprite(L"../Images/Sprites/04 Boss/BossBullet/BulletEffect/8.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("BossBulletEffect", m_BossBulletEffect);

	// 플레이어 스킬 - 배리어
	std::vector<CSprite*> m_PlayerBarrier;
	m_PlayerBarrier.push_back(new CSprite(L"../Images/Sprites/11 Player Skill/BARRIER/1.png", CGameManager::m_Gfx));
	m_PlayerBarrier.push_back(new CSprite(L"../Images/Sprites/11 Player Skill/BARRIER/2.png", CGameManager::m_Gfx));
	m_PlayerBarrier.push_back(new CSprite(L"../Images/Sprites/11 Player Skill/BARRIER/3.png", CGameManager::m_Gfx));
	m_PlayerBarrier.push_back(new CSprite(L"../Images/Sprites/11 Player Skill/BARRIER/4.png", CGameManager::m_Gfx));
	m_PlayerBarrier.push_back(new CSprite(L"../Images/Sprites/11 Player Skill/BARRIER/5.png", CGameManager::m_Gfx));
	m_PlayerBarrier.push_back(new CSprite(L"../Images/Sprites/11 Player Skill/BARRIER/6.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("PlayerBarrier", m_PlayerBarrier);

	// 플레이어 스킬 - 레이저빔 (총)
	m_Images->AddImage("PlayerLaserGun", new CSprite(L"../Images/Sprites/11 Player Skill/LASERBEAM/LaserGun.png", CGameManager::m_Gfx));

	// 플레이어 스킬 - 레이저빔 (빔)
	std::vector<CSprite*> m_PlayerLaserAnim;
	m_PlayerLaserAnim.push_back(new CSprite(L"../Images/Sprites/11 Player Skill/LASERBEAM/Laser Fire/1.png", CGameManager::m_Gfx));
	m_PlayerLaserAnim.push_back(new CSprite(L"../Images/Sprites/11 Player Skill/LASERBEAM/Laser Fire/2.png", CGameManager::m_Gfx));
	m_PlayerLaserAnim.push_back(new CSprite(L"../Images/Sprites/11 Player Skill/LASERBEAM/Laser Fire/3.png", CGameManager::m_Gfx));
	m_PlayerLaserAnim.push_back(new CSprite(L"../Images/Sprites/11 Player Skill/LASERBEAM/Laser Fire/4.png", CGameManager::m_Gfx));
	m_PlayerLaserAnim.push_back(new CSprite(L"../Images/Sprites/11 Player Skill/LASERBEAM/Laser Fire/5.png", CGameManager::m_Gfx));
	m_PlayerLaserAnim.push_back(new CSprite(L"../Images/Sprites/11 Player Skill/LASERBEAM/Laser Fire/6.png", CGameManager::m_Gfx));
	m_PlayerLaserAnim.push_back(new CSprite(L"../Images/Sprites/11 Player Skill/LASERBEAM/Laser Fire/7.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("PlayerLaserAnim", m_PlayerLaserAnim);
	return 0;
}
