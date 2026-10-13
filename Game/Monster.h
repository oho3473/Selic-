#pragma once
#include "pc.h"
#include "GameObject.h"
class Monster :
    public GameObject
{
private:
    Vec2 m_centerPosition;
    float m_speed;
    float m_maxDistance;
    int m_direction;    //1:정방향 오른쪽(아래), -1:역방향 왼쪽(위)
    int m_hp;
    float m_attackCycle;
    float m_flowingtime;

public:

    float M_Get_Speed() { return m_speed; }
    void M_SetSpeed(float f) { m_speed = f; }
    void M_Set_attacktime(float _time);
    void M_Set_SpawnPosition(Vec2 position) { m_centerPosition = position; }

    Monster();
    ~Monster();

    virtual void M_Update();
    virtual void M_Render(HDC hdc);
};

