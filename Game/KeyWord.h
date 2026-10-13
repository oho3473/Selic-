#pragma once
#include "GameObject.h"
class KeyWord :
    public GameObject
{
public:
	virtual void M_Update();
	virtual void M_Render(HDC hdc);
	virtual void M_Set_Keyword(const wchar_t* _keyword);
	virtual const wchar_t* M_Get_KeyWord();

	KeyWord();
	~KeyWord();
private:
	const wchar_t* m_Keyword;

};

