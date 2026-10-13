#pragma once
#include "GameObject.h"
#include "pc.h"
#include "Animation.h"

class Player :
    public GameObject
{
private:
    Vec2 m_centerPosition;
    bool m_shieldON;
    SCENETYPE m_current_Scene;
public:
    wchar_t m_str[TEXTMAXLENGTH] = L"";

    void M_String_Copy(wchar_t* destination, wchar_t* copytext);
    void M_Clear_m_str();

    bool M_Can_Shield();

    void M_Set_Current_Scene(SCENETYPE sceneType) { m_current_Scene = sceneType; }
 

    Player();
    virtual ~Player();

    Animation* M_animeintance;

    virtual void M_Update();
    virtual void M_Render(HDC hdc);

private:
};

