#pragma once
#include "Scene.h"
class RESTMAP3 :
    public SCENE
{
public:
	virtual void M_Enter();
	virtual void M_Exit();
	virtual void M_Update();

	void M_Render(HDC hdc);

public:
	RESTMAP3();
	~RESTMAP3();
};

