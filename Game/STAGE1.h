#pragma once
#include "Scene.h"

class STAGE1 : public SCENE
{
public:
	virtual void M_Enter();
	virtual void M_Exit();
	virtual void M_Update();

public:
	STAGE1();
	~STAGE1();
};

