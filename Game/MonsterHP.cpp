#include "MonsterHP.h"
#include "TimeManager.h"
#include "pc.h"
#include "SceneManager.h"
#include "END.h"
#include "func.h"



void MonsterHP::M_Reset()
{
	m_Flowing_Time = m_Timer_Second;
	M_Set_Scale(m_InitScale);
	m_is_reset = 1;


	for (size_t i = 0; i < SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object_Array(GROUPTYPE::PLAYER).size(); i++)
	{
		if (SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::PLAYER, i)->M_get_Name() == L"Player")
		{
			M_Set_Current_Hp(SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::PLAYER, i)->M_Get_Current_Hp());
		}
	}



}

void MonsterHP::M_Set_Timer(float _time)
{
	m_Timer_Second = _time;
	m_Flowing_Time = m_Timer_Second;
	m_InitScale = M_Get_Scale();
}

void MonsterHP::M_Set_NextScene(SCENETYPE _NextScene)
{
	m_NextScene = _NextScene;
}


void MonsterHP::M_Render(HDC hdc)
{
		if (m_Flowing_Time > 0)
	{
				//안쪽 게이지
		Gdiplus::Graphics graphics(hdc);

		//4/5 일때 다 없어진거 처럼 보임

		//DrawImage(&image,initx,inity,출력사이즈x,출력사이즈y)
		graphics.DrawImage(m_HPfenceImage, (int)M_Get_Position().x, (int)M_Get_Position().y, m_HPfenceImage->GetWidth(), m_HPfenceImage->GetHeight());
		//DrawImage(&image,initx,inity,출력할 사진의 x시작점,출력할 사진의 y시작점,출력할 사진의 x끝점,출력할 사진의 y끝점,단위)
		graphics.DrawImage(m_HpProgressBarImage
			, (int)M_Get_Position().x+21+ (int)(m_HpProgressBarImage->GetWidth() - (int)(m_HpProgressBarImage->GetWidth() * m_GaugePercent))
			, (int)M_Get_Position().y
			, (int)(m_HpProgressBarImage->GetWidth()-(int)(m_HpProgressBarImage->GetWidth() * m_GaugePercent)), (int)0
			, (int)(m_HpProgressBarImage->GetWidth()), (int)(m_HpProgressBarImage->GetHeight()), Gdiplus::UnitPixel);

	}
}

void MonsterHP::M_Update()
{
	Vec2 timer_Scale = M_Get_Scale();
	m_GaugePercent = m_Flowing_Time / m_Timer_Second;
	for (size_t i=0;i<SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object_Array(GROUPTYPE::ENEMY).size();i++)
	{
		if (SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::ENEMY,i)->M_get_Name()==L"Enemy")
		{
			M_Set_Current_Hp(SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::ENEMY, i)->M_Get_Current_Hp());
			break;
		}
	}

	if ((float)M_Get_Current_Hp() / (float)M_Get_MAX_Hp() < m_GaugePercent)
	{
		m_Flowing_Time = m_Flowing_Time - TimeManager::GetInstance()->M_Get_Frame_Time_Float();
		timer_Scale.x = (m_InitScale.x * m_Flowing_Time / m_Timer_Second);
		M_Set_Scale(timer_Scale);
	}

	//프레임타임을 초기화 하기위해 한번 리셋
	if (m_is_reset)
	{
		MonsterHP::M_Reset();
		m_is_reset = 0;
	}

	if (m_GaugePercent <= 0)
	{

		//잘 넣어주기
		if (true)
		{
			ChangeScene(m_NextScene);
		}
	}

}

MonsterHP::MonsterHP():
	m_InitScale()
	, m_Flowing_Time()
	, m_Timer_Second()
	, m_is_reset(1)
	, m_HpProgressBarImage(Gdiplus::Image::FromFile(L"Resources\\UI\\Hpbar\\MonsterHPProgress.png"))
	, m_HPfenceImage(Gdiplus::Image::FromFile(L"Resources\\UI\\Hpbar\\MonsterHPFence.png"))
	, m_GaugePercent()
	, m_NextScene()
{

}

MonsterHP::~MonsterHP()
{

}
