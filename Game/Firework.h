#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "TimeManager.h"
#include "func.h"
#include "pc.h"
#include "Scene.h"
#include "SceneManager.h"

class Firework :
    public GameObject
{
private:
    int m_fixedpositionX;
	int m_fixedpositionY;
    bool m_isStart=false;
    bool m_resetAnime;

public:
    virtual void M_Update();
    void M_Render(HDC hdc);

public:
    Firework();
    ~Firework();
    Animation* M_animeintance;
    Animation* M_Fixedanime;
};

