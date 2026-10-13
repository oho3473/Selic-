#pragma once
#include "Scene.h"
class CLEAR :
    public SCENE
{
public:
	virtual void M_Enter();
	virtual void M_Exit();
	virtual void M_Update();

	void M_Render(HDC hdc);

public:
	CLEAR();
	~CLEAR();
};

