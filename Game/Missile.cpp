#include "pc.h"
#include "Missile.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "Scene.h"

#include "func.h"
#include "SoundManager.h"

Missile::Missile() :m_damage()
{
	M_animeintance = new Animation;
	M_animeintance->M_AddAnimation(L"Resources\\Missile\\IDLE.png", 4, 0.5f, ANIMESTATUS::IDLE);
	M_animeintance->M_AddAnimation(L"Resources\\Missile\\START.png", 8, 0.6f, ANIMESTATUS::START);
	M_animeintance->M_AddAnimation(L"Resources\\Missile\\SmallHIT.png", 10, 0.40f, ANIMESTATUS::HIT);
	Damaged = false;

	M_animeintance->M_SetAnimation(ANIMESTATUS::START, LOOPSTATUS::ONCETOIDLE);
}

Missile::~Missile()
{

}


void Missile::M_Update()
{
	Vec2 missile_Position = M_Get_Position();
	//미사일 속도
	if (M_animeintance->M_Get_m_current_status() == ANIMESTATUS::IDLE)
	{
		missile_Position.x = missile_Position.x + 800.f * TimeManager::GetInstance()->M_Get_Frame_Time_Float();
		M_Set_Position(missile_Position);
	}

	// 미사일 피격시
	if (missile_Position.x > 1130.f && M_animeintance->M_Get_m_current_status() == ANIMESTATUS::IDLE)
	{
		if (M_Get_m_Damage() > 15)
		{
			M_animeintance->M_AddAnimation(L"Resources\\Missile\\HIT.png", 15, 0.45f, ANIMESTATUS::HIT);
			SoundManager::GetInstance()->M_PlayEffect(SOUND_LIST::MISSILEBOMB, SOUND_CHANNEL::SOUND_CHANNEL_MISSILE, 1.6f);

		}
		else
		{
			SoundManager::GetInstance()->M_PlayEffect(SOUND_LIST::MISSILEBOMB, SOUND_CHANNEL::SOUND_CHANNEL_MISSILE, 1.f);
		}
		M_Set_Position(Vec2(missile_Position.x + 50.f, missile_Position.y - 220.f));
		M_animeintance->M_SetAnimation(ANIMESTATUS::HIT, LOOPSTATUS::NOTLOOP);




	}



	//미사일 데미지 주기
	if (M_animeintance->M_Get_m_current_status() == ANIMESTATUS::HIT && M_animeintance->M_Get_Current_Frame()
		== (M_animeintance->M_Get_Current_m_imageInfo(DATA_LIST::FRAME) - 7) && Damaged == false)

	{

		for (size_t i = 0; i < SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object_Array(GROUPTYPE::ENEMY).size(); i++)
		{
			if (SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::ENEMY, i)->M_get_Name() == L"Enemy")
			{
				//적을 가르키고 데미지를 줌
				SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::ENEMY, i)
				->M_Set_Current_Hp(	SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::ENEMY, i)
					->M_Get_Current_Hp() - GameObject::M_Get_m_Damage());
				break;
			}
		}
		Damaged = true;
	}



	// 미사일 삭제
	if (M_animeintance->M_Get_m_current_status() == ANIMESTATUS::HIT && M_animeintance->M_Get_Current_Frame()
		== (M_animeintance->M_Get_Current_m_imageInfo(DATA_LIST::FRAME) - 1))
	{
		DeleteObj(this);
	}

}

void Missile::M_Render(HDC hdc)
{
	Vec2 position = M_Get_Position();
	Vec2 scale = M_Get_Scale();

	M_animeintance->M_PlayAnimation((int)M_Get_Position().x, (int)M_Get_Position().y, hdc);
}


