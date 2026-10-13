#pragma once
#include "Scene.h"

class STARTSCENE : public SCENE
{
public:
	virtual void M_Enter();
	virtual void M_Exit();

public:
	STARTSCENE();
	~STARTSCENE();
};

