#include "Firework.h"

Firework::Firework()
	:m_resetAnime(false)
{
	M_animeintance = new Animation;
	M_animeintance->M_AddAnimation(L"Resources\\FireWork\\FireWorkIdle.png", 1, 1, ANIMESTATUS::IDLE);

	M_animeintance->M_AddAnimation(L"Resources\\FireWork\\FireWorkWalk.png", 5, 0.5f, ANIMESTATUS::WALK);
	M_animeintance->M_AddAnimation(L"Resources\\FireWork\\FireWorkHit.png", 13, 1.2f, ANIMESTATUS::HIT);

	/*M_animeintance->M_SetAnimation(ANIMESTATUS::IDLE, LOOPSTATUS::LOOP);
	M_animeintance->M_SetAnimation(ANIMESTATUS::WALK, LOOPSTATUS::LOOP);
	M_animeintance->M_SetAnimation(ANIMESTATUS::HIT, LOOPSTATUS::ONCETOIDLE);
	M_Fixedanime->M_SetAnimation(ANIMESTATUS::IDLE, LOOPSTATUS::NOTLOOP);
	M_animeintance->M_SetAnimation(ANIMESTATUS::WALK, LOOPSTATUS::LOOP);
	M_animeintance->M_SetAnimation(ANIMESTATUS::HIT, LOOPSTATUS::ONCETOIDLE);*/

	


	M_Fixedanime = new Animation;
	M_Fixedanime->M_AddAnimation(L"Resources\\FireWork\\FixedFireWork.png", 5, 0.5f, ANIMESTATUS::IDLE);
	M_Fixedanime->M_SetAnimation(ANIMESTATUS::IDLE, LOOPSTATUS::NOTLOOP);

	M_animeintance->M_SetAnimation(ANIMESTATUS::IDLE, LOOPSTATUS::NOTLOOP);

	


}

Firework::~Firework()
{

}

void Firework::M_Update()
{
	if (!m_isStart)
	{
		m_fixedpositionX = (int)M_Get_Position().x;
		m_fixedpositionY = (int)M_Get_Position().y;
		m_isStart = true;
	}

	if (M_animeintance->M_Get_m_current_status() == ANIMESTATUS::IDLE&& m_resetAnime)
	{
		M_Fixedanime->M_SetAnimation(ANIMESTATUS::IDLE, LOOPSTATUS::NOTLOOP);

		m_resetAnime = false;
	}

	if (M_Fixedanime->M_Get_m_current_status() == ANIMESTATUS::IDLE
		&& M_Fixedanime->M_Get_Current_Frame() == (M_Fixedanime->M_Get_Current_m_imageInfo(DATA_LIST::FRAME) - 1)
		&& M_animeintance->M_Get_m_current_status()== ANIMESTATUS::IDLE)
	{
		M_Set_Position(Vec2(m_fixedpositionX, m_fixedpositionY));
		M_animeintance->M_SetAnimation(ANIMESTATUS::WALK,LOOPSTATUS::NOTLOOP);
	}

	if (M_animeintance->M_Get_m_current_status()== ANIMESTATUS::WALK
		&& M_animeintance->M_Get_Current_Frame() == (M_animeintance->M_Get_Current_m_imageInfo(DATA_LIST::FRAME) - 1))
	{
		M_Set_Position(Vec2(m_fixedpositionX- 402+117-14, m_fixedpositionY-360));

		M_animeintance->M_SetAnimation(ANIMESTATUS::HIT, LOOPSTATUS::ONCETOIDLE);
		m_resetAnime = true;
	}


}

void Firework::M_Render(HDC hdc)
{
	Vec2 position = M_Get_Position();
	Vec2 scale = M_Get_Scale();
	M_animeintance->M_PlayAnimation((int)M_Get_Position().x, (int)M_Get_Position().y, hdc);

	M_Fixedanime->M_PlayAnimation((int)m_fixedpositionX, (int)m_fixedpositionY, hdc);
}