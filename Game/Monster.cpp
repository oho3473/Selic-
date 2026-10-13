#include "Monster.h"
#include "TimeManager.h"


void Monster::M_Set_attacktime(float _time)
{
	m_attackCycle = _time;
	m_flowingtime = m_attackCycle;
}


Monster::Monster()
	:m_centerPosition(Vec2(0.f, 0.f)), m_speed(100.f), m_maxDistance(100.f), m_direction(1)
{

}

Monster::~Monster()
{

}

void Monster::M_Update()
{
	static int time = 0;

	//어택 싸이클 만들기
	m_flowingtime = m_flowingtime - TimeManager::GetInstance()->M_Get_Frame_Time_Float();

	
}

void Monster::M_Render(HDC hdc)
{
	
	/*Rectangle(hdc,
		M_Get_Position().x -M_Get_Scale().x / 2.f,
		M_Get_Position().y - M_Get_Scale().y / 2.f,
		M_Get_Position().x + M_Get_Scale().x / 2.f,
		M_Get_Position().y + M_Get_Scale().y / 2.f
	);*/

	TextOut(hdc, M_Get_Position().x, M_Get_Position().y, L"몬스터", 3);
}
