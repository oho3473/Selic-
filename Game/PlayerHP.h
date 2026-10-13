#pragma once
#include "GameObject.h"
#include "pc.h"

class PlayerHP :
    public GameObject
{
private:
	//초기 타이머 셋팅 값
	float m_Timer_Second;

	//흐르는 시간
	float m_Flowing_Time;
	float m_GaugePercent;

	//초기 박스 크기
	Vec2 m_InitScale;

	Gdiplus::Image* m_TimerImage;
	Gdiplus::Image* m_HpProgressBarImage;
	Gdiplus::Image* m_HPfenceImage;

public:
	//타이머가 1번 작동하게 만드려고 만든 변수
	int m_is_reset;
	SCENETYPE m_NextScene;
	virtual void M_Reset();
	void M_Set_Timer(float _time);
	void M_Set_NextScene(SCENETYPE _NextScene);
	void M_SetFileName(const wchar_t* _filename);

public:
	virtual void M_Render(HDC hdc);
	virtual void M_Update();

	PlayerHP();
	~PlayerHP();

};

