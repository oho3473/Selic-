#pragma once
#include "Scene.h"
class END :
    public SCENE
{
public:
	virtual void M_Enter();
	virtual void M_Update();
	virtual void M_Exit();

public:
	END();
	~END();
};

