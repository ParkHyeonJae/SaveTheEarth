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
#include <string.h>
#include <ctime>
#include <Mmsystem.h>
#include <atlstr.h>

#include <map>
#include <list>
#include <vector>

#include <wincodec.h>
#include <d2d1.h>
#include <dwrite.h>

#include "CInput.h"
#include "CGraphics.h"
#include "CSprite.h"
#include "IGameObject.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CScrollBackground.h"
#include "CObjectManager.h"
#include "CGameManager.h"
#include "CDX2DApp.h"
#include "CGame.h"

#define MAX_WIN_WIDTH 1600
#define MAX_WIN_HEIGHT 900

enum TAG {
	PLAYER,
	PBULLET,
	ENEMY,
	EBULLET,
	BACKGROUND
};


#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /SUBSYSTEM:CONSOLE")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /SUBSYSTEM:CONSOLE")
#endif