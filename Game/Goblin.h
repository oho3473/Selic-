#pragma once
#include "Animation.h"
#include "GameObject.h"
class Goblin :
    public GameObject
{
private:
	Vec2 m_centerPosition;
	float m_attackCycle;
	float m_attackCycle_flowingTime;
	bool m_IsHpUnderZero;
	bool m_CanAttack;
	Animation* M_animeintance;

public:

	void M_Set_attacktime(float _time);
	void M_Set_SpawnPosition(Vec2 position) { m_centerPosition = position; }


	Goblin();
	~Goblin();

	virtual void M_Update();
	virtual void M_Render(HDC hdc);
};

