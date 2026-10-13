#include "MainTime.h"
#include "TimeManager.h"
#include "pc.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "END.h"
#include "func.h"

void MainTime::M_Update()
{
	
	Vec2 timer_Scale = M_Get_Scale();
	m_Flowing_Time = m_Flowing_Time - TimeManager::GetInstance()->M_Get_Frame_Time_Float();
	timer_Scale.x = m_InitScale.x * m_Flowing_Time / m_Timer_Second;
	M_Set_Scale(timer_Scale);

	//프레임타임을 초기화 하기위해 한번 리셋
	if (m_is_reset)
	{
		MainTime::M_Reset();
		m_is_reset = 0;
	}

	if (m_Flowing_Time <= 0)
	{
		//잘 넣어주기
		if (true)
		{
			ChangeScene(m_NextScene);
		}
	}
}

void MainTime::M_Render(HDC hdc)
{

	if (m_Flowing_Time > 0)
	{
		Gdiplus::Graphics graphics(hdc);

		Gdiplus::Rect rect_size((int)M_Get_Position().x, (int)M_Get_Position().y, (int)(m_TimerImage->GetWidth()* m_Flowing_Time / m_Timer_Second), (int)(m_TimerImage->GetHeight()));
	
		////그리기
		graphics.DrawImage(
			m_TimerImage,
			rect_size,
			0, 0,
			(int)(m_TimerImage->GetWidth() * m_Flowing_Time / m_Timer_Second),
			(int)(m_TimerImage->GetHeight()), Gdiplus::UnitPixel);
	}
}

void MainTime::M_Set_Timer(float _time)
{
	m_Timer_Second = _time;
	m_Flowing_Time = -1;
	m_InitScale = M_Get_Scale();
}

void MainTime::M_Set_NextScene(SCENETYPE _NextScene)
{
	m_NextScene = _NextScene;
}

void MainTime::TimerReset()
{
}

void MainTime::M_Reset()
{
	m_Flowing_Time = m_Timer_Second;
	M_Set_Scale(m_InitScale);
	m_is_reset = 1;
}



MainTime::MainTime()
	:m_InitScale()
	, m_Flowing_Time()
	, m_Timer_Second()
	, m_is_reset(1)
	, m_TimerImage(Gdiplus::Image::FromFile(L"Resources\\UI\\Timer\\TimerRope.png"))
,m_NextScene()
{
}

MainTime::~MainTime()
{
}