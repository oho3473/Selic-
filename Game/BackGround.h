#pragma once
#include "pc.h"
#include "GameObject.h"



class BackGround :
    public GameObject
{
private:
	Gdiplus::Image* m_pbackgroundImage;
	HBITMAP m_hBitmap = {};

public:
	virtual void M_Update();
	virtual void M_Render(HDC hdc);
	void M_SetFileName(const wchar_t* _filename);


	BackGround();
	~BackGround();

};

