#include "GameObject.h"
#include "TimeManager.h"

GameObject::GameObject() :m_Positon{}, m_Scale{},m_Is_Alive(true),m_On_Hit(),m_Gage_Percent(),m_Max_Hp(),m_name(), m_Current_Hp(), m_Damage()
{

}

GameObject::~GameObject()
{

}

void GameObject::M_SetDead()
{
	m_Is_Alive = false;
}

void GameObject::M_Set_Name(const wchar_t* _name)
{
	m_name = _name;
}

void GameObject::M_Set_Max_Hp(int _hp)
{
	m_Max_Hp = _hp;
}
void GameObject::M_Set_Current_Hp(int _hp)
{
	m_Current_Hp = _hp;
}
int GameObject::M_Get_MAX_Hp()
{
	return m_Max_Hp;
}

int GameObject::M_Get_Current_Hp()
{
	return m_Current_Hp;
}

void GameObject::M_Set_m_Damage(int _Damage)
{
	m_Damage = _Damage;
}


void GameObject::M_SetOnhit(bool _bool)
{
	m_On_Hit = _bool;
}

void GameObject::M_Set_Gauge_Percent(float _percent)
{
	m_Gage_Percent = _percent;
}

void GameObject::M_Render(HDC hdc)
{
	Rectangle(hdc,
		(int)(m_Positon.x - m_Scale.x / 2.f),
		(int)(m_Positon.y - m_Scale.y / 2.f),
		(int)(m_Positon.x + m_Scale.x / 2.f),
		(int)(m_Positon.y + m_Scale.y / 2.f)
	);
}
