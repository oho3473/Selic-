#pragma once
#include "GameObject.h"
#include "pc.h"

class Gauge:
	public GameObject
{
public:
	Gauge();
	~Gauge();

private:

	float m_GagePercent;

	Gdiplus::Image* m_GuageProgressImage;
public:
	virtual void M_Update();
	virtual void M_Render(HDC hdc);

};

