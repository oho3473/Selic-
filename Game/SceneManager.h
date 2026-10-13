#pragma once
#include "pc.h"


class SCENE;

class SCENEMANAGER
{
	SINGLE(SCENEMANAGER);
private:
	SCENE* m_Scene_List[(unsigned int)SCENETYPE::ARRAYSIZE];
	SCENE* m_Current_Scene;
public:
	void M_Init();
	void M_Update();
	void M_Render(HDC hdc);
	SCENE* M_Get_CurrentScene() { return m_Current_Scene; }
	void M_ChangeScene(SCENETYPE _eNext);

	//SCENE** M_Get_SceneList() { return m_Scene_List; }
	//void M_Set_CurrentScene(SCENE* scenename) { m_Current_Scene = scenename; }
};


