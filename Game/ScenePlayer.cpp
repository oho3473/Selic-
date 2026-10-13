#include "ScenePlayer.h"

ScenePlayer::ScenePlayer()
{
	m_currentImage = Gdiplus::Image::FromFile(L"Resources\\UI\\Next.png");
	M_animeintance = new Animation;
	M_animeintance->M_AddAnimation(L"Resources\\Player\\IDLE.png", 12, 0.5f, ANIMESTATUS::WALK);

	M_animeintance->M_SetAnimation(ANIMESTATUS::WALK, LOOPSTATUS::LOOP);
}

ScenePlayer::~ScenePlayer()
{

}

void ScenePlayer::M_Update()
{
	Vec2 player_Position = M_Get_Position();

	if (player_Position.x < 1920.f && M_animeintance->M_Get_m_current_status() == ANIMESTATUS::WALK)
	{
		player_Position.x = player_Position.x + 500.f * TimeManager::GetInstance()->M_Get_Frame_Time_Float();
		M_Set_Position(player_Position);
	}
	else
	{
		DeleteObj(this);
	}

}

void ScenePlayer::M_Render(HDC hdc)
{

	Gdiplus::Graphics graphics(hdc);

	if (M_get_Name() == L"RestartScenePlayer")
	{
		graphics.DrawImage(m_currentImage, (Gdiplus::REAL)550, (Gdiplus::REAL)100, (Gdiplus::REAL)m_currentImage->GetWidth(), (Gdiplus::REAL)m_currentImage->GetHeight());
	}
	else
	{
		graphics.DrawImage(m_currentImage, (Gdiplus::REAL)300, (Gdiplus::REAL)100, (Gdiplus::REAL)m_currentImage->GetWidth(), (Gdiplus::REAL)m_currentImage->GetHeight());
	}
	
	

	Vec2 position = M_Get_Position();
	Vec2 scale = M_Get_Scale();

	M_animeintance->M_PlayAnimation((int)M_Get_Position().x, (int)M_Get_Position().y, hdc);
}
