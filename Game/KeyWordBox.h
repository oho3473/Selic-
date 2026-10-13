#pragma once
#include "GameObject.h"
#include "pc.h"

class KeyWordBox :
    public GameObject
{
private:
	Vec2 m_centerPosition;

public:
	virtual void M_Update();
	virtual void M_Render(HDC hdc);

	KeyWordBox* M_Get_Instance() { return this; }

	void M_String_Copy(wchar_t* destination, wchar_t* copytext);

	KeyWordBox();
	~KeyWordBox();
};

