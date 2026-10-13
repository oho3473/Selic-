#pragma once
#include "pc.h"
#include "GameObject.h"
#include "Animation.h"

class Fire:
	public GameObject
{

private:
	float m_flowtime;
	float m_initTime;
public:
	Fire();
	~Fire();
	Animation* M_animeintance;
	void M_Set_Timer(float _time); 

	virtual void M_Update();
	virtual void M_Render(HDC hdc);
};

