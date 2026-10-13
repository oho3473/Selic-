#include "pc.h"
#include "EventManager.h"

void CreateObject(GameObject* _pObj, GROUPTYPE _eGroup)
{
	TEVENT evn = {};
	evn.eEven = EVENT_TYPE::CREATE_OBJECT;
	//오브젝트의 힙메모리에 동적할당된 저장된 주소값
	evn.lParam = (DWORD_PTR)_pObj;
	//이넘값
	evn.wParam = (DWORD_PTR)_eGroup;
	EventManager::GetInstance()->AddEvnet(evn);
}

void DeleteObj(GameObject* _pObj)
{
	TEVENT evn = {};
	evn.eEven = EVENT_TYPE::DELETE_OBJECT;
	//오브젝트의 힙메모리에 동적할당된 저장된 주소값
	evn.lParam = (DWORD_PTR)_pObj;
	//이넘값
	EventManager::GetInstance()->AddEvnet(evn);
}

void ChangeScene(SCENETYPE _eNext)
{
	TEVENT evn = {  };
	evn.eEven = EVENT_TYPE::SCENE_CHANGE;
	evn.lParam = (DWORD_PTR)_eNext;

	EventManager::GetInstance()->AddEvnet(evn);

}
