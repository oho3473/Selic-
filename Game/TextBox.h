#pragma once

#include "GameObject.h"
#include "pc.h"


class TextBox :
    public GameObject
{

private:
	Vec2 m_centerPosition;

public:
	wchar_t m_str[TEXTMAXLENGTH] = L"";
	//안쓰는듯?
	wchar_t m_str_mk2[TEXTMAXLENGTH] = L"";

public:
	virtual void M_Update();
	virtual void M_Render(HDC hdc);

	TextBox* M_Get_Instance() { return this; }

	void M_String_Copy(wchar_t* destination, wchar_t* copytext);

	void M_Clear_m_str();

	TextBox();
	~TextBox();

	
};

