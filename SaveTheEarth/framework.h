// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "windowscodecs.lib")
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cmath>
#include <ctime>
#include <Mmsystem.h>
#include <atlstr.h>
#include <string>

#include <map>
#include <list>
#include <vector>

#include <wincodec.h>
#include <d2d1.h>
#include <dwrite.h>

using namespace std;
enum OpacityBrush
{
	RED,
	BLACK,
	WHITE
};
#define SAFE_DELETE( p ) { if( p ) { delete ( p ); ( p ) = nullptr; } }

#define  SAFE_RELEASE( p ) { if( p ) { ( p )->Release(); } }
//#define SAFE_DELETE( p ) {if( p ){delete ( p ); ( p ) = nullptr;}}

#define Vector2 D2D1_POINT_2F

#define MAX_WIN_WIDTH 1600
#define MAX_WIN_HEIGHT 900

#define PI 3.141592

#define MAX_PLAYER_HP 1000
enum TAG {
	PLAYER,
	PBULLET,
	ENEMY,
	EBULLET,
	BACKGROUND,
	BOSS,
	BOSSLASER,
	BOSSBULLET,
	MISILE,
	UI,
	ITEM,
};

enum SCENE {
	TITLE,
	GAME01,
	GAMEOVER
};
enum PLAYERSTATE
{
	IDLE,
	BACK,
	FORWARD
};
enum GUNS
{
	DEFAULT,
	Rifle,
	Shotgun
};
enum ITEMS
{
	ATKUP,
	HPUP,
	RPMUP
};


#include "CInput.h"
#include "CGraphics.h"
#include "CSprite.h"
#include "Cimage.h"
#include "CImageManager.h"
#include "CSpriteAnimation.h"
#include "IGameObject.h"
#include "CGameObject.h"
#include "CTimer.h"
#include "CHealthBar.h"
#include "CItem.h"
#include "CNormalEnemyBullet.h"
#include "CNormalEnemy.h"
#include "CLauncher.h"
#include "CBossLaserLauncher.h"
#include "CBossBullet.h"
#include "CBossBulletLauncher.h"
#include "CBossEnemy.h"
#include "MisileEnemy.h"
#include "CPlayerBullet.h"
#include "CPlayer.h"
#include "CScrollBackground.h"
#include "CTitleBackground.h"
#include "CInGameUI.h"

#include "CObjectManager.h"
#include "CSceneObject.h"
#include "CGameScene01.h"
#include "CGameScene02.h"
#include "CGameManager.h"
#include "CDX2DApp.h"
#include "CGame.h"
#include "Mathf.h"



#ifdef _DEBUG

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /SUBSYSTEM:CONSOLE")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /SUBSYSTEM:CONSOLE")
#endif

#endif