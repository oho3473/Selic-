#pragma once
#include "Scene.h"
class STAGE2 :
    public SCENE
{
public:
    virtual void M_Enter();
    virtual void M_Exit();
    virtual void M_Update();

public:
    STAGE2();
    ~STAGE2();
};

