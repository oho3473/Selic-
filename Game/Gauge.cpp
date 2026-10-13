#include "Gauge.h"
#include "TimeManager.h"
#include "pc.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "func.h"
#include "Scene.h"

Gauge::Gauge()
	:m_GuageProgressImage(Gdiplus::Image::FromFile(L"Resources\\UI\\Hpbar\\Monster_Gage.png"))
	, m_GagePercent()
{
}

Gauge::~Gauge()
{

}

void Gauge::M_Update()
{
	for (size_t i = 0; i < SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object_Array(GROUPTYPE::ENEMY).size(); i++)
	{
		if (SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::ENEMY,i)->M_get_Name()==L"Enemy")
		{
			m_GagePercent =SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::ENEMY, i)->M_Get_Gauge_Percent();
		}
	}
}

void Gauge::M_Render(HDC hdc)
{
	Gdiplus::Graphics graphics(hdc);
	Gdiplus::Rect rect_size((int)M_Get_Position().x+235, (int)M_Get_Position().y, (int)(m_GuageProgressImage->GetWidth()* (m_GagePercent-1)), (int)m_GuageProgressImage->GetHeight());
	graphics.DrawImage(
		m_GuageProgressImage
		, rect_size
		, 0
		, 0
		, (int)(m_GuageProgressImage->GetWidth() * (1-m_GagePercent))
		, (int)(m_GuageProgressImage->GetHeight()), Gdiplus::UnitPixel);
}

