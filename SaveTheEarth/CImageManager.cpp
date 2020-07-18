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

	return 0;
}
