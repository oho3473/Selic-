#pragma once
#include "pc.h"
#include "GameObject.h"
#include "Animation.h"


class Missile :
	public GameObject
{
	int m_damage;
	bool Damaged;

public:
	virtual void M_Update();
	virtual void M_Render(HDC hdc);


public:
	Missile();
	~Missile();
	Animation* M_animeintance;
};

