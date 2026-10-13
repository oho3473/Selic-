#pragma once
#include "GameObject.h"

class Shield :
    public GameObject
{
private:


public:
	//타이머가 1번 작동하게 만드려고 만든 변수

public:
	virtual void M_Render(HDC hdc);
	virtual void M_Update();

	Shield();
	~Shield();

};

