#include "CLEAR.h"
#include "func.h"
#include "GameLogic.h"
#include "MapChangeButton.h"
#include "BackGround.h"
#include "SoundManager.h"
#include "Firework.h"

void CLEAR::M_Enter()
{
	BackGround* backgroundStage1 = new BackGround;
	backgroundStage1->M_Set_Position(Vec2(0.f, 0.f));
	//backgroundStage1->M_Set_Scale(Vec2(1000.f, 200.f));
	backgroundStage1->M_SetFileName(L"Resources\\BG\\CLEAR.bmp");
	CreateObject(backgroundStage1, GROUPTYPE::DEFAULT);

	Firework* firework = new Firework;
	firework->M_Set_Position(Vec2(709.f, 480.f));
	firework->M_Set_Name(L"firework1");
	CreateObject(firework, GROUPTYPE::DEFAULT);

	SetFocus(GameLogic::GetInstance()->M_Get_MainWindow());
	MapChangeButton* mapChangeButton = new MapChangeButton;
	mapChangeButton->M_Set_Position(Vec2(830.f, 980.f));
	mapChangeButton->M_Set_Scale(Vec2(1200.f, 200.f));
	mapChangeButton->M_Set_Next_Scene(SCENETYPE::START);
	mapChangeButton->M_Set_Image(Gdiplus::Image::FromFile(L"Resources\\UI\\selic_press-to-space.png"));
	CreateObject(mapChangeButton, GROUPTYPE::DEFAULT);

	SoundManager::GetInstance()->M_PlayBGM(SOUND_LIST::CLEARBGM, 1, 2);
}

void CLEAR::M_Exit()
{
	HWND hEdit = GetWindow(GameLogic::GetInstance()->M_Get_MainWindow(), GW_CHILD);
	DestroyWindow(hEdit);
	M_DelateAll();

}

void CLEAR::M_Update()
{
	SCENE::M_Update();

}

void CLEAR::M_Render(HDC hdc)
{

}

CLEAR::CLEAR()
{

}

CLEAR::~CLEAR()
{

}
