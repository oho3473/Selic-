#include "GameLogic.h"

#include "EventManager.h"
#include "KeywordManager.h"
#include "SceneManager.h"
#include "PathManager.h"
#include "SoundManager.h"
#include "pc.h"


int GameLogic::M_Init(HWND g_hWnd, POINT Resolution)
{
	m_hWnd = g_hWnd;
	m_Resolution = Resolution;


	RECT ClientRect;
	GetClientRect(m_hWnd, &ClientRect);


	int ClientWidth = 1920;	//
	int ClientHeight = 1080;

	//해상도에 맞게 윈도우 크기 조정
	RECT window_size = { 0,0,Resolution.x,Resolution.y };
	//윈도우를 window_size 크기로 지정
	AdjustWindowRect(&window_size,WS_EX_TOPMOST| WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,true);
	//실제로 우리가 사용할 영역을 지정
	SetWindowPos(m_hWnd, NULL, m_Resolution.x / 2 - ClientWidth / 2, m_Resolution.y / 2 - ClientHeight / 2, ClientWidth, ClientHeight, 0);

	m_hDC = GetDC(m_hWnd);

	//이중 버퍼링 용도의 비트맵과 DC를 만든다
	m_BackBuffer = CreateCompatibleBitmap(m_hDC, m_Resolution.x, m_Resolution.y);
	m_BackBuffer_DC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBitMap = (HBITMAP)SelectObject(m_BackBuffer_DC, m_BackBuffer);
	DeleteObject(hOldBitMap);


	//매니저 초기화
	PathManager::GetInstance()->M_Init();
	TimeManager::GetInstance()->M_Init();
	KeyManager::GetInstance()->M_Init();
	SCENEMANAGER::GetInstance()->M_Init();
	KeywordManager::GetInstance()->M_Init();
	SoundManager::GetInstance()->M_Init();

	return S_OK;
}

void GameLogic::M_Game_Loop()
{
	srand(time(NULL));

	TimeManager::GetInstance()->M_Update();
	KeyManager::GetInstance()->M_Update();
	SCENEMANAGER::GetInstance()->M_Update();
	SoundManager::GetInstance()->M_Update();

	//화면 클리어
	Rectangle(m_BackBuffer_DC, -1, -1, m_Resolution.x + 1, m_Resolution.y + 1);

	SCENEMANAGER::GetInstance()->M_Render(m_BackBuffer_DC);

	//이전 비트맵에서 현재 윈도 비트맵으로 복사
	BitBlt(m_hDC, 0, 0, m_Resolution.x, m_Resolution.y, m_BackBuffer_DC, 0, 0, SRCCOPY);

	//frame이 끝날 때
	//object 생성+삭제
	//SceneChange를 실행 시켜, Render 또는 Update가 꼬이지 않도록 방지! 중요!!!!

	EventManager::GetInstance()->update();

}

GameLogic::GameLogic() : m_hWnd(0), m_Resolution{}, m_hDC(0), m_BackBuffer(0), m_BackBuffer_DC(0)
{
}

GameLogic::~GameLogic()
{
	ReleaseDC(m_hWnd, m_hDC);
	DeleteDC(m_BackBuffer_DC);
	DeleteObject(m_BackBuffer);
}


int GameLogic::OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	CreateCaret(hWnd, NULL, 2, 17);
	ShowCaret(hWnd);

	return 1;
}


