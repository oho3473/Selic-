#include "pc.h"
#include "EntMonster.h"
#include "TimeManager.h"
#include "Missile.h"
#include "Scene.h"
#include "SceneManager.h"
#include "KeywordManager.h"
#include "KeyWord.h"
#include "func.h"
#include "SoundManager.h"

void EntMonster::M_Set_attacktime(float _time)
{
	m_attackCycle = _time;
	m_attackCycle_flowingTime = m_attackCycle;
}


EntMonster::EntMonster()
	:m_CanAttack(true)
	, m_attackCycle()
	, m_attackCycle_flowingTime()
	, m_IsHpUnderZero()
{
	M_SetOnhit(false);
	M_animeintance = new Animation;
	M_animeintance->M_AddAnimation(L"Resources\\enemy\\Ent\\Ent_IDLE.png", 1, 1, ANIMESTATUS::IDLE);
	M_animeintance->M_AddAnimation(L"Resources\\enemy\\Ent\\Ent_ATTACK.png", 10, 0.7f, ANIMESTATUS::ATTACK);
	M_animeintance->M_AddAnimation(L"Resources\\enemy\\Ent\\Ent_IDLE.png", 1, 1, ANIMESTATUS::DIE);
	//M_animeintance->M_AddAnimation(L"Resources\\Ent\\wood2_attack.png", 10, 1, ANIMESTATUS::HIT);

	M_animeintance->M_SetAnimation(ANIMESTATUS::IDLE, LOOPSTATUS::LOOP);

}

EntMonster::~EntMonster()
{

}

void EntMonster::M_Update()
{
	//몬스터의 공격력
	int Damage = 20;

	if (m_CanAttack && !m_IsHpUnderZero)
	{
		m_attackCycle_flowingTime = m_attackCycle_flowingTime - TimeManager::GetInstance()->M_Get_Frame_Time_Float();
		M_Set_Gauge_Percent(m_attackCycle_flowingTime / m_attackCycle);
	}


	if (M_GetOnhit() == true)
	{
		M_animeintance->M_SetAnimation(ANIMESTATUS::HIT, LOOPSTATUS::ONCETOIDLE);
		if (SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object_Array(GROUPTYPE::MISSILE).size())
		{
			//몬스터가 미사일에 맞은 데미지
			SoundManager::GetInstance()->M_PlayEffect(SOUND_LIST::ENT_HIT, SOUND_CHANNEL::SOUND_CHANNEL_MOSTERHIT, 1.f);

			int hit_Damage = SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::MISSILE, 0)->M_Get_m_Damage();
			M_Set_Current_Hp(M_Get_MAX_Hp() - hit_Damage);
		}
		M_SetOnhit(false);
	}

	if (M_Get_Current_Hp() <= 0 && !m_IsHpUnderZero)
	{
		M_animeintance->M_SetAnimation(ANIMESTATUS::DIE, LOOPSTATUS::NOTLOOP);
		m_IsHpUnderZero = true;
	}

	if (m_attackCycle_flowingTime < 0 && m_IsHpUnderZero == false)
	{
		SoundManager::GetInstance()->M_PlayEffect(SOUND_LIST::ENT_ATTACK, SOUND_CHANNEL::SOUND_CHANNEL_MOSTERATTACK, 1.f);

		m_attackCycle_flowingTime = m_attackCycle;
		M_animeintance->M_SetAnimation(ANIMESTATUS::ATTACK, LOOPSTATUS::ONCETOIDLE);
		m_CanAttack = false;

	}


	if (M_animeintance->M_Get_m_current_status() == ANIMESTATUS::ATTACK && M_animeintance->M_Get_Current_Frame() == (M_animeintance->M_Get_Current_m_imageInfo(DATA_LIST::FRAME) - 1) && m_CanAttack == false)
	{
		//플레이어가 방어

		if (SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object_Array(GROUPTYPE::SHIELD).size())
		{
			SoundManager::GetInstance()->M_PlayEffect(SOUND_LIST::SHIELD_HIT, SOUND_CHANNEL::SOUND_CHANNEL_SHIELD, 1.f);

			// 키워드 생성
			SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_DelateGroup(GROUPTYPE::KEYWORD);
			KeywordManager::GetInstance()->M_ResetAnswerKeyword();
			for (size_t i = 0; i < MAX_KEWORD; i++)
			{
				KeyWord* key_Word_1 = new KeyWord;
				key_Word_1->M_Set_Position(Vec2(KEYWORDPOSFX, KEYWORDPOSY + KEYWORDPOSINTERVAL*i));
				key_Word_1->M_Set_Keyword(KeywordManager::GetInstance()->M_GetFkeyword(i));
				CreateObject(key_Word_1, GROUPTYPE::KEYWORD);
			}
			for (size_t i = 0; i < MAX_KEWORD; i++)
			{
				KeyWord* key_Word_1 = new KeyWord;
				key_Word_1->M_Set_Position(Vec2(KEYWORDPOSSX, KEYWORDPOSY + i * KEYWORDPOSINTERVAL));
				key_Word_1->M_Set_Keyword(KeywordManager::GetInstance()->M_GetSkeyword((size_t)i));
				CreateObject(key_Word_1, GROUPTYPE::KEYWORD);
			}
			SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_DelateGroup(GROUPTYPE::SHIELD);
		}
		else
		{
			for (size_t i = 0; i < SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object_Array(GROUPTYPE::PLAYER).size(); i++)
			{
				if (SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::PLAYER, i)->M_get_Name() == L"Player")
				{

					SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::PLAYER, i)->M_SetOnhit(true);


					SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::PLAYER, i)
						->M_Set_Current_Hp(SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::PLAYER, i)->M_Get_Current_Hp() - Damage);
					break;
				}

			}

		}
		m_CanAttack = true;
	}
}





void EntMonster::M_Render(HDC hdc)
{
	M_animeintance->M_PlayAnimation((int)M_Get_Position().x, (int)M_Get_Position().y, hdc);
}
