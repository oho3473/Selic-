#include "TimeManager.h"

#ifdef _DEBUG
#include "GameLogic.h"
#endif // DEBUG

TimeManager::TimeManager() 
	: m_Current_Count{},
	m_Prev_Count{},
	m_Frequency_Count{},
	m_FrameTime(0),
	m_AccumTime(0),
	m_CallCount(0)
{

}

TimeManager::~TimeManager()
{

}

void TimeManager::M_Init()
{
	//현재 카운트
	QueryPerformanceCounter(&m_Current_Count);
	//초당 카운트 횟수
	QueryPerformanceFrequency(&m_Frequency_Count);
}

void TimeManager::M_Update()
{
	QueryPerformanceCounter(&m_Current_Count);

	//이전 프레임의 카운팅과 현재 프레임 카운팅 값의 차이
	m_FrameTime = (float)(m_Current_Count.QuadPart - m_Prev_Count.QuadPart) / (double)m_Frequency_Count.QuadPart;

	m_Prev_Count = m_Current_Count;

	++m_CallCount;
	m_AccumTime += m_FrameTime;	//프레임 시간 누적

	if (m_AccumTime >= 1.)
	{
		m_FPS = m_CallCount;
		m_AccumTime = 0.;
		m_CallCount = 0;

#ifdef _DEBUG
		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, FramTime : %f", m_FPS, m_FrameTime);
		SetWindowText(GameLogic::GetInstance()->M_Get_MainWindow(), szBuffer);
#endif
	}
}