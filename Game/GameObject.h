#pragma once
#include <windows.h>
#include "Vec2.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

private:
	Vec2	m_Positon;
	Vec2	m_Scale;
	bool	m_Is_Alive;
	bool	m_On_Hit;
	float	m_Gage_Percent;

	void M_SetDead();

	int		m_Max_Hp=1000;
	int		m_Current_Hp;
	const wchar_t* m_name;
	int m_Damage;

public:
	Vec2 M_Get_Position()	{ return m_Positon; }
	Vec2 M_Get_Scale()	{ return m_Scale; }
	bool M_Is_Dead()	{ return !m_Is_Alive; }

	void M_Set_Position(Vec2 pos)	{ m_Positon = pos; }
	void M_Set_Scale(Vec2 scale)	{ m_Scale = scale; }
	void M_Set_Name(const wchar_t* _name);
	void M_Set_Max_Hp(int _hp);
	void M_Set_Current_Hp(int _hp);
	int M_Get_MAX_Hp();
	int M_Get_Current_Hp();
	const wchar_t* M_get_Name()	{ return m_name; }

	void M_Set_m_Damage(int _Damage);
	int M_Get_m_Damage()	{ return m_Damage; }

	void M_SetOnhit(bool _bool);
	bool M_GetOnhit()		{ return m_On_Hit; }

	float M_Get_Gauge_Percent() { return m_Gage_Percent; }
	void M_Set_Gauge_Percent(float _percent);


	virtual void M_Update() = 0;
	virtual void M_Render(HDC hdc);

	friend class EventManager;
};

