#include "SceneManager.h"

#include "CLEAR.h"
#include "STAGE1.h"
#include "TITLE.h"
#include "KeyManager.h"
#include "END.h"
#include "pc.h"
#include "RESTMAP0.h"
#include "STAGE2.h"
#include "STAGE3.h"
#include "RESTMAP1.h"
#include "RESTMAP2.h"
#include "RESTMAP3.h"

#include "RESTART1.h"
#include "RESTART2.h"
#include "RESTART3.h"


SCENEMANAGER::SCENEMANAGER()
	: m_Scene_List{}
	, m_Current_Scene(nullptr)
{
}

SCENEMANAGER::~SCENEMANAGER()
{
	for (UINT i = 0; i < (UINT)SCENETYPE::END; ++i)
	{
		if (m_Scene_List[i] != nullptr)
		{
			delete m_Scene_List[i];
		}
	}
}

void SCENEMANAGER::M_Init()
{
	//¾À »ý¼º
	m_Scene_List[(UINT)SCENETYPE::START] = new TITLE;
	m_Scene_List[(UINT)SCENETYPE::START]->M_Set_Name(L"TITLE");

	m_Scene_List[(UINT)SCENETYPE::RESTMAP0] = new RESTMAP0;
	m_Scene_List[(UINT)SCENETYPE::RESTMAP0]->M_Set_Name(L"RESTMAP0");

	m_Scene_List[(UINT)SCENETYPE::STAGE1] = new STAGE1;
	m_Scene_List[(UINT)SCENETYPE::STAGE1]->M_Set_Name(L"STAGE1");

	m_Scene_List[(UINT)SCENETYPE::RESTMAP1] = new RESTMAP1;
	m_Scene_List[(UINT)SCENETYPE::RESTMAP1]->M_Set_Name(L"RESTMAP1");

	m_Scene_List[(UINT)SCENETYPE::STAGE2] = new STAGE2;
	m_Scene_List[(UINT)SCENETYPE::STAGE2]->M_Set_Name(L"STAGE2");

	m_Scene_List[(UINT)SCENETYPE::RESTMAP2] = new RESTMAP2;
	m_Scene_List[(UINT)SCENETYPE::RESTMAP2]->M_Set_Name(L"RESTMAP2");

	m_Scene_List[(UINT)SCENETYPE::STAGE3] = new STAGE3;
	m_Scene_List[(UINT)SCENETYPE::STAGE3]->M_Set_Name(L"STAGE3");

	m_Scene_List[(UINT)SCENETYPE::RESTMAP3] = new RESTMAP3;
	m_Scene_List[(UINT)SCENETYPE::RESTMAP3]->M_Set_Name(L"RESTMAP3");

	m_Scene_List[(UINT)SCENETYPE::CLEAR] = new CLEAR;
	m_Scene_List[(UINT)SCENETYPE::CLEAR]->M_Set_Name(L"CLEAR");

	m_Scene_List[(UINT)SCENETYPE::END] = new END;
	m_Scene_List[(UINT)SCENETYPE::END]->M_Set_Name(L"END");

	m_Scene_List[(UINT)SCENETYPE::RESTART1] = new RESTART1;
	m_Scene_List[(UINT)SCENETYPE::RESTART1]->M_Set_Name(L"RESTART1");

	m_Scene_List[(UINT)SCENETYPE::RESTART2] = new RESTART2;
	m_Scene_List[(UINT)SCENETYPE::RESTART2]->M_Set_Name(L"RESTART2");

	m_Scene_List[(UINT)SCENETYPE::RESTART3] = new RESTART3;
	m_Scene_List[(UINT)SCENETYPE::RESTART3]->M_Set_Name(L"RESTART3");

	/*
	m_Scene_List[(UINT)SCENETYPE::START] = new STARTSCENE;
	m_Scene_List[(UINT)SCENETYPE::START] = new STARTSCENE;
	m_Scene_List[(UINT)SCENETYPE::START] = new STARTSCENE;
	*/


	//ÇöÀç ¾À ÁöÁ¤
	m_Current_Scene = m_Scene_List[(UINT)SCENETYPE::START];
	m_Current_Scene->M_Enter();
}

void SCENEMANAGER::M_Update()
{
	m_Current_Scene->M_Update();
}

void SCENEMANAGER::M_Render(HDC hdc)
{
	m_Current_Scene->M_Render(hdc);
}

void SCENEMANAGER::M_ChangeScene(SCENETYPE _eNext)
{
	m_Current_Scene->M_Exit();
	m_Current_Scene = m_Scene_List[(UINT)_eNext];
	m_Current_Scene->M_Enter();
}
