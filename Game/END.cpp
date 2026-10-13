#include "END.h"

#include "MapChangeButton.h"
#include "func.h"
#include "GameLogic.h"
#include "BackGround.h"
#include "SoundManager.h"

void END::M_Enter()
{
	SetFocus(GameLogic::GetInstance()->M_Get_MainWindow());

	BackGround* backgroundStage1 = new BackGround;
	backgroundStage1->M_Set_Position(Vec2(0.f, 0.f));
	//backgroundStage1->M_Set_Scale(Vec2(1000.f, 200.f));
	backgroundStage1->M_SetFileName(L"Resources\\BG\\End.bmp");
	CreateObject(backgroundStage1, GROUPTYPE::DEFAULT);

	MapChangeButton* mapChangeButton = new MapChangeButton;
	mapChangeButton->M_Set_Position(Vec2(46.f, 782.f));
	mapChangeButton->M_Set_Next_Scene(SCENETYPE::START);
	mapChangeButton->M_Set_Image(Gdiplus::Image::FromFile(L"Resources\\NULL.png"));
	CreateObject(mapChangeButton, GROUPTYPE::DEFAULT);

	SoundManager::GetInstance()->M_PlayBGM(SOUND_LIST::ENDBGM, 1, 2);



}
void END::M_Update()
{

	SCENE::M_Update();
}

void END::M_Exit()
{
	HWND hEdit = GetWindow(GameLogic::GetInstance()->M_Get_MainWindow(), GW_CHILD);
	DestroyWindow(hEdit);
	M_DelateAll();
}


END::END()
{

}

END::~END()
{

}
