#pragma once
#include "pc.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Animation.h"
#include "GameObject.h"
#include "TimeManager.h"
#include "func.h"

class ScenePlayer :
	public GameObject
{
public:
	ScenePlayer();
	~ScenePlayer();

	Animation* M_animeintance;

	Gdiplus::Image* m_currentImage;

public:
	virtual void M_Update();
	void M_Render(HDC hdc);
	void M_Set_CurrentImage(Gdiplus::Image* image) { m_currentImage = image; }
};

