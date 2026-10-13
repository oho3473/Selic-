#include "MainTimer.h"
#include "TimeManager.h"

void MainTimer::M_Update()
{
	Vec2 timer_Scale = M_Get_Scale();

	float flowtime = M_Get_Flowing_Time();
	flowtime = flowtime - TimeManager::GetInstance()->M_Get_Frame_Time_Float();
	M_Set_Flowing_Time(flowtime);

	Vec2 scale = M_Get_Scale();
	scale.x = scale.x * flowtime / M_Get_Timer_Second();
	M_Set_Scale(timer_Scale);
}

void MainTimer::M_Render(HDC hdc)
{
	Vec2 position = M_Get_Position();
	Vec2 scale = M_Get_Scale();

	if (M_Get_Flowing_Time() > -1)
	{
		//테두리
		Rectangle(hdc, M_Get_Position().x, M_Get_Position().y + M_Get_Scale().x / 2, M_Get_Position().x + M_Get_Scale().x, M_Get_Position().y - M_Get_Scale().y / 2);
	}

	if (M_Get_Flowing_Time() > 0)
	{

		//안쪽 게이지
		Rectangle(hdc, M_Get_Position().x, M_Get_Position().y + M_Get_Scale().y / 2, M_Get_Position().x + M_Get_Scale().x, M_Get_Position().y - M_Get_Scale().y / 2);
	}
}

void MainTimer::M_Reset()
{
	M_Set_Flowing_Time(M_Get_Timer_Second());
	M_Set_Scale(M_Get_InitScale());
}
