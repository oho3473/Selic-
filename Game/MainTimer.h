#pragma once
#include "TimeSystem.h"
class MainTimer :
    public TimeSystem
{
public:
    virtual void M_Update();
    virtual void M_Render(HDC hdc);
    virtual void M_Reset();
};

