#include "Timer.h"
#include "TimeManager.h"
#include "pc.h"

void Timer::M_Update()
{

	Vec2 timer_Scale = M_Get_Scale();
	m_Flowing_Time = m_Flowing_Time - TimeManager::GetInstance()->M_Get_Frame_Time_Float();
	timer_Scale.x = m_InitScale.x * m_Flowing_Time / m_Timer_Second;
	M_Set_Scale(timer_Scale);
}

void Timer::M_Render(HDC hdc)
{
	Vec2 position = M_Get_Position();
	Vec2 scale = M_Get_Scale();

	if (m_Flowing_Time>-1)
	{
		//테두리
		Rectangle(hdc, M_Get_Position().x, M_Get_Position().y + m_InitScale.y / 2, M_Get_Position().x + m_InitScale.x, M_Get_Position().y - m_InitScale.y / 2);
	}

	if (m_Flowing_Time > 0)
	{

		//안쪽 게이지
		Rectangle(hdc, M_Get_Position().x, M_Get_Position().y + m_InitScale.y / 2, M_Get_Position().x + M_Get_Scale().x, M_Get_Position().y - m_InitScale.y / 2);
	}
}

void Timer::M_Set_Timer(float _time)
{
	m_Timer_Second = _time;
	m_Flowing_Time = _time;
	m_InitScale = M_Get_Scale();
}

Timer::Timer()
	:m_InitScale()
,m_Deltatime()
,m_Flowing_Time()
,m_Timer_Second()
{

}

Timer::~Timer()
{

}
