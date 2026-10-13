#pragma once
#include "GameObject.h"
class Timer :
    public GameObject
{
private:
    float m_Timer_Second;
    float m_Deltatime;
    float m_Flowing_Time;
    Vec2 m_InitScale;

public:
    virtual void M_Update();
    virtual void M_Render(HDC hdc);
    void M_Set_Timer(float _time);



public:
    Timer();
    ~Timer();
};
