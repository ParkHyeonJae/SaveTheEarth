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
	std::vector<CSprite*> m_BulletSprites;
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (0).png", CGameManager::m_Gfx));
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (1).png", CGameManager::m_Gfx));
	m_BulletSprites.push_back(new CSprite(L"../Images/PlayerBullet (2).png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("RifleBullet", m_BulletSprites);

	m_Images->AddImage("ShotgunBullet", new CSprite(L"../Images/PlayerBullet (3).png", CGameManager::m_Gfx));

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

	std::vector<CSprite*> m_ShotgunEffectAnim;
	m_ShotgunEffectAnim.push_back(new CSprite(L"../Images/Sprites/07 Shotgun Effect/1.png", CGameManager::m_Gfx));
	m_ShotgunEffectAnim.push_back(new CSprite(L"../Images/Sprites/07 Shotgun Effect/2.png", CGameManager::m_Gfx));
	m_ShotgunEffectAnim.push_back(new CSprite(L"../Images/Sprites/07 Shotgun Effect/3.png", CGameManager::m_Gfx));
	m_ShotgunEffectAnim.push_back(new CSprite(L"../Images/Sprites/07 Shotgun Effect/4.png", CGameManager::m_Gfx));
	m_ShotgunEffectAnim.push_back(new CSprite(L"../Images/Sprites/07 Shotgun Effect/5.png", CGameManager::m_Gfx));
	m_ShotgunEffectAnim.push_back(new CSprite(L"../Images/Sprites/07 Shotgun Effect/6.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("ShotgunEffectAnim", m_ShotgunEffectAnim);

	m_Images->AddImage("Stage01/SKY", new CSprite(L"../Images/Stage01/Stage01_Sky.png", CGameManager::m_Gfx));
	m_Images->AddImage("Stage01/CLOUD", new CSprite(L"../Images/Stage01/Stage01_Cloud.png", CGameManager::m_Gfx));
	m_Images->AddImage("Stage01/MOUNTAIN", new CSprite(L"../Images/Stage01/Stage01_Mountain.png", CGameManager::m_Gfx));
	m_Images->AddImage("Stage01/SUN", new CSprite(L"../Images/Stage01/Stage01_Sun.png", CGameManager::m_Gfx));
	m_Images->AddImage("Stage01/TREES", new CSprite(L"../Images/Stage01/Stage01_Trees.png", CGameManager::m_Gfx));
	
	m_Images->AddImage("Stage02/SKY", new CSprite(L"../Images/Stage02/Stage02_Sky.png", CGameManager::m_Gfx));
	m_Images->AddImage("Stage02/MOUNTAIN", new CSprite(L"../Images/Stage02/Stage02_Mountain.png", CGameManager::m_Gfx));
	m_Images->AddImage("Stage02/TREES", new CSprite(L"../Images/Stage02/Stage02_Trees.png", CGameManager::m_Gfx));


	m_Images->AddImage("NormalEnemyBullet", new CSprite(L"../Images/energy_blast-01.png", CGameManager::m_Gfx));

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

	m_Images->AddImage("playerHpBar_background", new CSprite(L"../Images/null hp.png", CGameManager::m_Gfx));
	m_Images->AddImage("playerHpBar_foreground", new CSprite(L"../Images/HP bar.png", CGameManager::m_Gfx));
	
	std::vector<CSprite*> m_playerIdleMotion;
	m_playerIdleMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/IDLE/1.png", CGameManager::m_Gfx));
	m_playerIdleMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/IDLE/2.png", CGameManager::m_Gfx));
	m_playerIdleMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/IDLE/3.png", CGameManager::m_Gfx));
	m_playerIdleMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/IDLE/4.png", CGameManager::m_Gfx));
	m_playerIdleMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/IDLE/5.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("playerIdleMotion", m_playerIdleMotion);

	std::vector<CSprite*> m_playerBackMotion;
	m_playerBackMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/FORWARD/1.png", CGameManager::m_Gfx));
	m_playerBackMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/FORWARD/2.png", CGameManager::m_Gfx));
	m_playerBackMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/FORWARD/3.png", CGameManager::m_Gfx));
	m_playerBackMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/FORWARD/4.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("playerBackMotion", m_playerBackMotion);

	std::vector<CSprite*> m_playerForwardMotion;
	m_playerForwardMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/BACK/1.png", CGameManager::m_Gfx));
	m_playerForwardMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/BACK/2.png", CGameManager::m_Gfx));
	m_playerForwardMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/BACK/3.png", CGameManager::m_Gfx));
	m_playerForwardMotion.push_back(new CSprite(L"../Images/Sprites/09 Player Motion/BACK/4.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("playerForwardMotion", m_playerForwardMotion);

	m_Images->AddImage("DefaultGun", new CSprite(L"../Images/Sprites/DefaultGun.png", CGameManager::m_Gfx));

	std::vector<CSprite*> m_RifleMotion;
	m_RifleMotion.push_back(new CSprite(L"../Images/Sprites/02 Rifle Motion/1.png", CGameManager::m_Gfx));
	m_RifleMotion.push_back(new CSprite(L"../Images/Sprites/02 Rifle Motion/2.png", CGameManager::m_Gfx));
	m_RifleMotion.push_back(new CSprite(L"../Images/Sprites/02 Rifle Motion/3.png", CGameManager::m_Gfx));
	m_RifleMotion.push_back(new CSprite(L"../Images/Sprites/02 Rifle Motion/4.png", CGameManager::m_Gfx));
	m_RifleMotion.push_back(new CSprite(L"../Images/Sprites/02 Rifle Motion/5.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("RifleMotion", m_RifleMotion);

	std::vector<CSprite*> m_ShotgunMotion;
	m_ShotgunMotion.push_back(new CSprite(L"../Images/Sprites/06 Shotgun Motion/1.png", CGameManager::m_Gfx));
	m_ShotgunMotion.push_back(new CSprite(L"../Images/Sprites/06 Shotgun Motion/2.png", CGameManager::m_Gfx));
	m_ShotgunMotion.push_back(new CSprite(L"../Images/Sprites/06 Shotgun Motion/3.png", CGameManager::m_Gfx));
	m_ShotgunMotion.push_back(new CSprite(L"../Images/Sprites/06 Shotgun Motion/4.png", CGameManager::m_Gfx));
	m_ShotgunMotion.push_back(new CSprite(L"../Images/Sprites/06 Shotgun Motion/5.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("ShotgunMotion", m_ShotgunMotion);

	std::vector<CSprite*> m_SharkAnim;
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/1.png", CGameManager::m_Gfx));
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/2.png", CGameManager::m_Gfx));
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/3.png", CGameManager::m_Gfx));
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/4.png", CGameManager::m_Gfx));
	m_SharkAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/5.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("SharkAnim", m_SharkAnim);

	std::vector<CSprite*> m_SharkDeadAnim;
	m_SharkDeadAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/Dead/1.png", CGameManager::m_Gfx));
	m_SharkDeadAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/Dead/2.png", CGameManager::m_Gfx));
	m_SharkDeadAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/Dead/3.png", CGameManager::m_Gfx));
	m_SharkDeadAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/Dead/4.png", CGameManager::m_Gfx));
	m_SharkDeadAnim.push_back(new CSprite(L"../Images/Sprites/05 Shark Animation/Dead/5.png", CGameManager::m_Gfx));
	m_Images->AddMultiImage("SharkDeadAnim", m_SharkDeadAnim);

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

	m_Images->AddImage("warning", new CSprite(L"../Images/warnnig.png", CGameManager::m_Gfx));
	m_Images->AddImage("Misile", new CSprite(L"../Images/Misile.png", CGameManager::m_Gfx));


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
	
	
	m_Images->AddImage("BossNullHp", new CSprite(L"../Images/Sprites/04 Boss/BossHPBar/bossNullHP.png", CGameManager::m_Gfx));
	m_Images->AddImage("BossHpBar", new CSprite(L"../Images/Sprites/04 Boss/BossHPBar/bossHPbar.png", CGameManager::m_Gfx));

	m_Images->AddImage("SharkNullHp", new CSprite(L"../Images/Sprites/05 Shark Animation/HpBar/SharkHPBar_Back.png", CGameManager::m_Gfx));
	m_Images->AddImage("SharkHpBar", new CSprite(L"../Images/Sprites/05 Shark Animation/HpBar/SharkHPBar_Fore.png", CGameManager::m_Gfx));

	m_Images->AddImage("ATKUP", new CSprite(L"../Images/Sprites/01 Items/01 ATKUP.png", CGameManager::m_Gfx));
	m_Images->AddImage("HPUP", new CSprite(L"../Images/Sprites/01 Items/02 HPUP.png", CGameManager::m_Gfx));
	m_Images->AddImage("RPMUP", new CSprite(L"../Images/Sprites/01 Items/03 RPMUP.png", CGameManager::m_Gfx));

	return 0;
}
