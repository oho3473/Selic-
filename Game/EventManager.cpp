#include  "pc.h"
#include "EventManager.h"
#include "GameObject.h"

#include "Scene.h"
#include "SceneManager.h"


void EventManager::update()
{
	//===============================================
	//이전 프레임에서 등록해둔 Dead Object 들을 삭제한다.
	//===============================================
	for(size_t i=0;i<m_vecDead.size();++i)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();


	//==========================================
	//1프레임에 일어난 이벤트들을 다 함께 처리한다.
	//==========================================

	for (size_t i = 0; i < m_vecEvent.size(); ++i)
	{
		Excute(m_vecEvent[i]);
	}
	m_vecEvent.clear();


}


void EventManager::Excute(const TEVENT& _eve)
{
	_eve.eEven;

	switch (_eve.eEven)
	{
	case EVENT_TYPE::CREATE_OBJECT:
		{
			//lParam:Object Adress
			//wParam: Group Type

		GameObject* pNewObj = (GameObject*)_eve.lParam;
		GROUPTYPE eType = (GROUPTYPE)_eve.wParam;
		SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_AddObject(pNewObj, eType);
		}
		break;
	case EVENT_TYPE::DELETE_OBJECT:
		{
			//삭제 예정인 것들을 넣어주고 다음 프레임을 넘어갔을 때 삭제

			//lParam:Object Adress
			//wParam: Group Type
			//Object를 Dead상태로 변경
			//삭제 예정 오브젝트들을 모아둔다.

		GameObject* p_Deadobject = (GameObject*)_eve.lParam;
		p_Deadobject->M_SetDead();
		m_vecDead.push_back(p_Deadobject);


		}
		break;
	case EVENT_TYPE::SCENE_CHANGE:
		{
			//lParam: Next Scene Type
		SCENEMANAGER::GetInstance()->M_ChangeScene((SCENETYPE)_eve.lParam);
		}
		break;
	}

}



void EventManager::AddEvnet(const TEVENT& _eve)
{
	m_vecEvent.push_back(_eve);
}

EventManager::EventManager()
{
	
}

EventManager::~EventManager()
{
	
}
