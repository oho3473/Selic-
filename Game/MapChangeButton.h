#pragma once
#include "GameObject.h"
#include "pc.h"
class MapChangeButton :
    public GameObject
{
private:
	Vec2 m_centerPosition;
	SCENETYPE m_NextScene;
	Gdiplus::Image* m_startbuttonImage1;
	Gdiplus::Image* m_startbuttonImage2;
	Gdiplus::Image* m_currentImage;

public:
	wchar_t m_str[TEXTMAXLENGTH] = L"";
	wchar_t m_str_mk2[TEXTMAXLENGTH] = L"";

public:
	virtual void M_Update();
	virtual void M_Render(HDC hdc);


	void M_Set_Next_Scene(SCENETYPE _nextSCENETYPE);
	void M_Set_Image(Gdiplus::Image* image) { m_currentImage = image; }

	MapChangeButton* M_Get_Instance() { return this; }

	void M_String_Copy(wchar_t* destination, wchar_t* copytext);

	MapChangeButton();
	~MapChangeButton();
};

