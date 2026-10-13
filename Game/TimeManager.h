#pragma once
#include <windows.h>
#include "pc.h"


class TimeManager
{
	SINGLE(TimeManager);

private:
	LARGE_INTEGER m_Current_Count;
	LARGE_INTEGER m_Prev_Count;
	LARGE_INTEGER m_Frequency_Count;

	double		m_FrameTime;	//프레임 간의 시간, 프레임 1번 걸리는 시간
	double		m_AccumTime;	//1초 확인을 위한 누적 시간
	UINT		m_CallCount;	//초당 호출 횟수
	UINT		m_FPS;			//초당 프레임
public:
	void M_Init();
	void M_Update();

public:
	double M_Get_Frame_Time() { return m_FrameTime; }
	float M_Get_Frame_Time_Float() { return (float)m_FrameTime; }

};

