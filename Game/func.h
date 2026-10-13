#pragma once
#include "GameObject.h"
//»ý¼ºÇÑ °´Ã¼

enum class GROUPTYPE;
class GameObject;

void CreateObject(GameObject* _pObj, GROUPTYPE _eGroup);
void DeleteObj(GameObject* _pObj);
void ChangeScene(SCENETYPE _eNext);


template<typename T>
void Safe_Delete_Vec(std::vector<T>& _vec)
{
	for (size_t i=0;i<_vec.size();++i)
	{
		if (nullptr!=_vec[i])
		{
			delete _vec[i];
		}
	}
	_vec.clear();
}