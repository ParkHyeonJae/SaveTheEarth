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




	//SAFE_DELETE(m_ShotgunSprite);
	m_RifleEffectAnim.clear();
	m_ShotgunEffectAnim.clear();
	return 0;
}
