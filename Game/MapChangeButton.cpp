#include "MapChangeButton.h"
#include "pc.h"
#include "GameLogic.h"
#include "KeyManager.h"
#include "Scene.h"
#include "func.h"
#include "SceneManager.h"

MapChangeButton::MapChangeButton()
	:m_startbuttonImage1(Gdiplus::Image::FromFile(L"Resources\\UI\\selic_start.png")),
	m_startbuttonImage2(Gdiplus::Image::FromFile(L"Resources\\UI\\selic_press-to-space.png")),
	m_currentImage(m_startbuttonImage1)
{
}

void MapChangeButton::M_Update()
{

	if (KeyManager::GetInstance()->M_Get_KeyState(KEY::SPACE) == KEYSTATE::AWAY)
	{
		ChangeScene(m_NextScene);
	}
}


void MapChangeButton::M_Render(HDC hdc)
{
	const wchar_t* title=L"";

#ifdef _DEBUG
	SCENETYPE a = m_NextScene;
	switch (a )
	{
	case SCENETYPE::STAGE2:
		{
			title=L"1에서 2가는중";
		}
		break;
	case SCENETYPE::STAGE3:
	{
		title = L"2에서 3가는중";

	}
	break;
	case SCENETYPE::START:
	{
		title = L"타이틀 가능중";

	}
	break;

	}
	TextOutW(hdc, 920, 200, title, wcslen(title));
#endif
	Gdiplus::Graphics graphics(hdc);

	graphics.DrawImage(m_currentImage,M_Get_Position().x, M_Get_Position().y, (Gdiplus::REAL)m_currentImage->GetWidth(), (Gdiplus::REAL)m_currentImage->GetHeight());
}

void MapChangeButton::M_Set_Next_Scene(SCENETYPE _nextSCENETYPE)
{
	m_NextScene = _nextSCENETYPE;
}

void MapChangeButton::M_String_Copy(wchar_t* destination, wchar_t* copytext)
{
	while (*copytext)
	{
		*destination = *copytext;
		destination++;
		copytext++;
	}
}




MapChangeButton::~MapChangeButton()
{

}

