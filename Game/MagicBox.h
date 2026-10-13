#pragma once
#include "GameObject.h"
#include "pc.h"

class MagicdBox :
	public GameObject
{
private:
	Vec2 m_centerPosition;

public:
	virtual void M_Update();
	virtual void M_Render(HDC hdc);

	MagicdBox* M_Get_Instance() { return this; }

	void M_String_Copy(wchar_t* destination, wchar_t* copytext);

	MagicdBox();
	~MagicdBox();
};

