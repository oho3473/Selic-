#include "Scene.h"
#include "GameObject.h"
#include "func.h"


void SCENE::M_Update()
{
	for (UINT i = 0; i < (UINT)GROUPTYPE::END; ++i)
	{
		for (size_t j = 0; j < m_Object_Array[i].size(); ++j)
		{
			if (!m_Object_Array[i][j]->M_Is_Dead())
			{
				m_Object_Array[i][j]->M_Update();
			}
		}
	}
}

void SCENE::M_Render(HDC hdc)
{

	//두개 비교해보기
	/*for (UINT i = 0; i < (UINT)GROUPTYPE::END; ++i)
	{
		for (size_t j = 0; j < m_Object_Array[i].size(); ++j)
		{
			m_Object_Array[i][j]->M_Render(hdc);
		}
	}*/
	//두개 비교해보기

	for (UINT i = 0; i < (UINT)GROUPTYPE::END; ++i)
	{

		std::vector<GameObject*>::iterator iter = m_Object_Array[i].begin();

		for (; iter != m_Object_Array[i].end();)
		{
			if (!(*iter)->M_Is_Dead())
			{
				(*iter)->M_Render(hdc);
				++iter;
			}
			else
			{
				iter = m_Object_Array[i].erase(iter);
			}
		}

	}
}

void SCENE::M_AddObject(GameObject* obj, GROUPTYPE type)
{
	m_Object_Array[(UINT)type].push_back(obj);
}

void SCENE::M_DelateGroup(GROUPTYPE _eTarget)
{
	Safe_Delete_Vec<GameObject*>(m_Object_Array[(UINT)_eTarget]);
}

void SCENE::M_DelateAll()
{
	for (UINT i = 0; i < (UINT)GROUPTYPE::END; ++i)
	{
		M_DelateGroup((GROUPTYPE)i);
	}
}

SCENE::SCENE()
{

}

SCENE::~SCENE()
{
	for (int i = 0; i < (UINT)GROUPTYPE::END; ++i)
	{
		for (size_t j = 0; j < m_Object_Array[i].size(); ++j)
		{
			delete m_Object_Array[i][j];
		}
	}
}

GameObject* SCENE::M_Get_Object(int grouptype,int index)
{
	return m_Object_Array[grouptype][index];
}
