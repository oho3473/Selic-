#include "EndObject.h"
#include "pc.h"
#include "GameLogic.h"
#include "KeyManager.h"
#include "Scene.h"
#include "SceneManager.h"
#include "TITLE.h"
#include "func.h"


void EndObject::M_Update()
{
	if (KeyManager::GetInstance()->M_Get_KeyState(KEY::SPACE) == KEYSTATE::AWAY)
	{
		HWND hEdit = GetWindow(GameLogic::GetInstance()->M_Get_MainWindow(),GW_CHILD);
		SetWindowTextW(hEdit, L" ");
		SetFocus(GameLogic::GetInstance()->M_Get_MainWindow());
		ChangeScene(SCENETYPE::START);

	}
}


void EndObject::M_Render(HDC hdc)
{
	Rectangle(hdc, 100, 100, 1820, 300);
	wchar_t title[] = L"GAMEOVER!!";
	TextOutW(hdc, 920, 200, title, wcslen(title));


	Rectangle(hdc, 600, 800, 1300, 900);
	wchar_t start[] = L"END";
	TextOutW(hdc, 920, 845, start, wcslen(start));
}

void EndObject::M_String_Copy(wchar_t* destination, wchar_t* copytext)
{
	while (*copytext)
	{
		*destination = *copytext;
		destination++;
		copytext++;
	}
}


EndObject::EndObject()
{

}

EndObject::~EndObject()
{

}

