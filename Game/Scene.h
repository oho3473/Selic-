#pragma once

#include "windows.h"
#include <iostream>
#include "pc.h"



class GameObject;

class SCENE
{
private:
	std::vector<GameObject*> m_Object_Array[(UINT)GROUPTYPE::END];	//오브젝트를 그룹 개수만큼 선언
	std::wstring m_SceneName;
public:
	void M_Set_Name(const std::wstring& name) { m_SceneName = name; }
	const std::wstring& M_Get_Name() { return m_SceneName; }

	virtual void M_Update();
	void M_Render(HDC hdc);
	

public:
	void M_AddObject(GameObject* obj, GROUPTYPE type);
	void M_DelateGroup(GROUPTYPE _eTarget);
	void M_DelateAll();
	std::vector<GameObject*> M_Get_Object_Array(GROUPTYPE _grouptype) {return m_Object_Array[(UINT)_grouptype];}


public:
	SCENE();
	virtual ~SCENE();

	virtual void M_Enter() = 0;	//씬 진입시
	virtual void M_Exit() = 0;	//씬 탈출시

	GameObject* M_Get_Object(int grouptype,int index);
};
