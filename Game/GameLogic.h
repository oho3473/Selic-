#pragma once
#include <windows.h>
#include "TimeManager.h"
#include "KeyManager.h"
#include "pc.h"

class GameLogic
{
	SINGLE(GameLogic);
public:
	//게임의 전반적인 모든 것을 초기화
	int M_Init(HWND g_hWnd, POINT Resolution);

	//게임 메인 루프
	void M_Game_Loop();
private:
	HWND m_hWnd;			//메인 윈도우 핸들
	POINT m_Resolution;		//메인 윈도우 해상도
	HDC	m_hDC;				//메인 윈도우 DC

	HBITMAP m_BackBuffer;	//backbuffer BitMap
	HDC	m_BackBuffer_DC;	//backbuffer BitMap의 DC
public:
	//캐럿 생성
	int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam);

	//메인 윈도우 핸들 받기
	HWND M_Get_MainWindow() { return m_hWnd; }

	//BackBuffer의 BitMap 받기
	HBITMAP M_Get_BackBuffer() { return m_BackBuffer; }

	//메인 윈도우 DC 받기
	HDC M_Get_DC() { return m_hDC; }

	//메인 윈도우 해상도
	POINT M_Get_Resolution() { return m_Resolution; }
};



