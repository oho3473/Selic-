#pragma once
#include "GameObject.h"
#include "Animation.h"

class Golem :
    public GameObject
{
private:
	Vec2 m_centerPosition;
	float m_attackCycle;
	float m_attackCycle_flowingTime;
	bool m_IsHpUnderZero;
	bool m_CanAttack;
	Animation* M_animeintance;
	bool m_SoundStart;
	float M_flowingtime;

public:

	void M_Set_attacktime(float _time);
	void M_Set_SpawnPosition(Vec2 position) { m_centerPosition = position; }


	Golem();
	~Golem();

	virtual void M_Update();
	virtual void M_Render(HDC hdc);
};

