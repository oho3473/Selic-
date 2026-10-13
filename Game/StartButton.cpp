#include "StartButton.h"

#include "func.h"
#include "pc.h"
#include "GameLogic.h"
#include "KeyManager.h"
#include "Scene.h"
#include "SoundManager.h"


void StartButton::M_Update()
{
	if (SoundManager::GetInstance()->M_Get_Bgm_Current_Play()!= SOUND_LIST::TITLEBGM)
	{
		
		SoundManager::GetInstance()->M_PlayBGM(SOUND_LIST::TITLEBGM, 0.5, 3);
	}



	if (KeyManager::GetInstance()->M_Get_KeyState(KEY::SPACE) == KEYSTATE::AWAY)
	{
		//¾À Ã¼ÀÎÁö
		ChangeScene(SCENETYPE::RESTMAP0);


		SetFocus(GetWindow(GameLogic::GetInstance()->M_Get_MainWindow(), GW_CHILD));
	}
}

void StartButton::M_Render(HDC hdc)
{
	Gdiplus::Graphics G(hdc);
	G.DrawImage(m_pstartbuttonImage, 228, 800, 425, 200);
}

void StartButton::M_String_Copy(wchar_t* destination, wchar_t* copytext)
{
	while (*copytext)
	{
		*destination = *copytext;
		destination++;
		copytext++;
	}
}

void StartButton::M_SetFileName(const wchar_t* _filename)
{
	m_pstartbuttonImage = Gdiplus::Image::FromFile(_filename);
}

StartButton::StartButton()
{

}

StartButton::~StartButton()
{

}