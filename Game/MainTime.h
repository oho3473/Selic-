#pragma once
#include "GameObject.h"
#include "pc.h"

class MainTime :
    public GameObject
{
private:
	//초기 타이머 셋팅 값
	float m_Timer_Second;

	//흐르는 시간
	float m_Flowing_Time;

	//초기 박스 크기
	Vec2 m_InitScale;

	Gdiplus::Image* m_TimerImage;
public:
	//타이머가 1번 작동하게 만드려고 만든 변수
	int m_is_reset;
	SCENETYPE m_NextScene;
public:
	virtual void M_Update();
	virtual void M_Render(HDC hdc);
	void M_Set_Image(Gdiplus::Image* image) { m_TimerImage = image; }
	void M_Set_Timer(float _time);
	void M_Set_NextScene(SCENETYPE _NextScene);
	void TimerReset();
	virtual void M_Reset();

	float M_Get_Flowing_Time() { return m_Flowing_Time; }
	float M_Get_Timer() { return m_Timer_Second; }


public:
	MainTime();
	~MainTime();

};

