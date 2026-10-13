#pragma once
#include "pc.h"

//프레임 동기화
//동일 프레임 내에서 같은 키에  대해, 동일한 이벤트를 가져간다

//키 입력 이벤트 처리
//tap hold away

enum class KEYSTATE
{
	NONE,//눌리지도 않았고, 이전에도 안눌림
	TAP,//막 누른 시점
	HOLD,//누르고 있는
	AWAY//막 뗀 시점
	
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	SPACE,
	ENTER,
	BACK,
	ESCAPE,

	LAST
};

struct KEYINFO
{
	KEYSTATE keystate;	//키 상태
	bool is_KeyDown;	//이전 프레임에 눌렸는지
};


class KeyManager
{
	SINGLE(KeyManager);
private:
	std::vector<KEYINFO> m_key;

public:
	void M_Init();
	void M_Update();

	wchar_t m_copytext[TEXTMAXLENGTH];
	// 문자열 배열
	wchar_t* storedSTR[20];

public:
	KEYSTATE M_Get_KeyState(KEY key);
	//어디에 쓰는가?
	wchar_t* Get_m_copytext() { return m_copytext; }
	void M_Reset_m_copytext();
};

