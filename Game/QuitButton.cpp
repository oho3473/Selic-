#include "QuitButton.h"

#include "func.h"
#include "pc.h"
#include "GameLogic.h"
#include "KeyManager.h"
#include "Scene.h"

void QuitButton::M_Update()
{
	if (KeyManager::GetInstance()->M_Get_KeyState(KEY::ESCAPE) == KEYSTATE::AWAY)
	{
		//¾À Ã¼ÀÎÁö
		HWND hWnd = GameLogic::GetInstance()->M_Get_MainWindow();
		DestroyWindow(hWnd);
	}
}

void QuitButton::M_Render(HDC hdc)
{
	Gdiplus::Graphics G(hdc);
	G.DrawImage(m_pquitbuttonImage, M_Get_Position().x, M_Get_Position().y, M_Get_Scale().x, M_Get_Scale().y);
	//Rectangle(hdc, M_Get_Position().x, M_Get_Position().y, M_Get_Position().x + M_Get_Scale().x, M_Get_Position().y + M_Get_Scale().y);
}

void QuitButton::M_String_Copy(wchar_t* destination, wchar_t* copytext)
{
	while (*copytext)
	{
		*destination = *copytext;
		destination++;
		copytext++;
	}
}

void QuitButton::M_SetFileName(const wchar_t* _filename)
{
	m_pquitbuttonImage = Gdiplus::Image::FromFile(_filename);
}

QuitButton::QuitButton()
{

}

QuitButton::~QuitButton()
{

}