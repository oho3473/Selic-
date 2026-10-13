#pragma once
#include "GameObject.h"
#include "pc.h"

class StartButton :
    public GameObject
{
private:
	Vec2 m_centerPosition;
	Gdiplus::Image* m_pstartbuttonImage;
public:
	wchar_t m_str[TEXTMAXLENGTH] = L"";


public:
	virtual void M_Update();
	virtual void M_Render(HDC hdc);

	StartButton* M_Get_Instance() { return this; }

	void M_String_Copy(wchar_t* destination, wchar_t* copytext);
	void M_SetFileName(const wchar_t* _filename);

	StartButton();
	~StartButton();


};

