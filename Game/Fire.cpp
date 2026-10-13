#include "Fire.h"
#include "SceneManager.h"
#include "Scene.h"
#include "TimeManager.h"
#include "MainTime.h"

Fire::Fire()
{
	M_animeintance = new Animation;
	M_animeintance->M_AddAnimation(L"Resources\\UI\\Timer\\TimerFire.png", 4, 1, ANIMESTATUS::IDLE);
	M_animeintance->M_SetAnimation(ANIMESTATUS::IDLE, LOOPSTATUS::LOOP);
}

Fire::~Fire()
{

}


void Fire::M_Set_Timer(float _time)
{
	m_initTime = _time;
	m_flowtime = _time;
}

void Fire::M_Update()
{
	m_flowtime = m_flowtime - TimeManager::GetInstance()->M_Get_Frame_Time_Float();

}

void Fire::M_Render(HDC hdc)
{
	M_animeintance->M_PlayAnimation((int)(M_Get_Position().x* (m_flowtime / m_initTime)-20.f), (int)(M_Get_Position().y+20.f), hdc);
}
