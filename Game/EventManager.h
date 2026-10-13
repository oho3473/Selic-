#pragma once
#include <windows.h>
#include "pc.h"
#include "func.h"

class GameObject;

enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,



	END
};



struct TEVENT
{
	EVENT_TYPE		eEven;
	DWORD_PTR		lParam;
	DWORD_PTR		wParam;
};


class EventManager
{
	SINGLE(EventManager)

private:
	std::vector<TEVENT> m_vecEvent;
	std::vector<GameObject*> m_vecDead;

private:
	//이벤트를 처리해주는 함수
	void Excute(const TEVENT& _eve);


public:
	void update();
	void AddEvnet(const TEVENT& event);
};

