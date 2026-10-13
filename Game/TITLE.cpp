#include "TITLE.h"

#include "func.h"
//#include "KeyManager.h"
#include "STAGE1.h"
#include "StartButton.h"
#include "BackGround.h"
#include "GameLogic.h"
#include "SoundManager.h"
#include "QuitButton.h"

void TITLE::M_Enter()
{
	////배경화면 GDI
	BackGround* backgroundStage1 = new BackGround;
	backgroundStage1->M_Set_Position(Vec2(0.f, 0.f));
	backgroundStage1->M_Set_Scale(Vec2(1000.f, 200.f));
	backgroundStage1->M_SetFileName(L"Resources\\BG\\title.bmp");
	CreateObject(backgroundStage1, GROUPTYPE::DEFAULT);

	//게임시작버튼
	StartButton* start_Box = new StartButton;
	start_Box->M_Set_Position(Vec2(700.f, 700.f));
	start_Box->M_Set_Scale(Vec2(200.f, 200.f));
	start_Box->M_SetFileName(L"Resources\\UI\\selic_start.png");
	CreateObject(start_Box, GROUPTYPE::DEFAULT);

	HWND hEdit = GetWindow(GameLogic::GetInstance()->M_Get_MainWindow(), GW_CHILD);
	DestroyWindow(hEdit);

	//게임종료버튼
	QuitButton* quit_Box = new QuitButton;
	quit_Box->M_Set_Position(Vec2(1740.f, 950.f));
	quit_Box->M_Set_Scale(Vec2(150.f, 80.f));
	//quit_Box->M_SetFileName(L"Resources\\UI\\");
	CreateObject(quit_Box, GROUPTYPE::DEFAULT);

}
void TITLE::M_Update()
{
	SCENE::M_Update();

}
void TITLE::M_Exit()
{
	
	M_DelateAll();
}
TITLE::TITLE()
{

}

TITLE::~TITLE()
{

}
