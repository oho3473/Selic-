#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <ole2.h>
#include <gdiplus.h>
#include <queue>

#pragma comment(lib, "gdiplus.lib")
//using namespace Gdiplus;


#define  SINGLE(type) public:\
				static type* GetInstance()\
				{\
					static type manager;\
					return &manager;\
				}\
				private:\
					type();\
					~type();


#define TEXTMAXLENGTH 32
/*#define TEXTMAXLENGTH 60*/
#define MAX_KEWORD 5

#define KEYWORDPOSFX		450.f
#define KEYWORDPOSSX		1170.f
#define KEYWORDPOSY			750.f
#define KEYWORDPOSINTERVAL	40

enum class GROUPTYPE
{
	DEFAULT,
	PLAYER,
	ENEMY,
	MISSILE,
	KEYWORD,
	SHIELD,
	UI,
	SHIELDKEYWORD,
	END
};
enum class SCENETYPE
{
	START,
	RESTMAP0,
	STAGE1,
	RESTMAP1,
	STAGE2,
	RESTMAP2,
	STAGE3,
	RESTMAP3,
	CLEAR,
	END,
	RESTART1,
	RESTART2,
	RESTART3,
	ARRAYSIZE
};


enum class ANIMESTATUS
{
	IDLE,
	WALK,
	START,
	ATTACK,
	HIT,
	SHIELDSTART,
	SHIELD,
	DIE,
	ANIMESTATUS_END
};

enum class LOOPSTATUS
{
	NOTLOOP,
	ONCETOIDLE,
	LOOP,

};


enum DATA_LIST
{
	TAKETIME,
	FRAME,
	DATA_LIST_END
};

//win86
#ifndef _WIN64
#include "../selic/inc/fmod.hpp"
#pragma comment (lib, "../selic/lib/x86/fmod_vc.lib")
using namespace FMOD;
#endif
//win64
#ifdef _WIN64
#include "../selic/inc/fmod.hpp"
#pragma comment (lib, "../selic/lib/x64/fmod_vc.lib")
#endif
