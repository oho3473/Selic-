#include "StartScene.h"
#include "GameObject.h"
#include "pc.h"
#include "TextBox.h"

//sample
#include "Monster.h"
#include "Player.h"


void STARTSCENE::M_Enter()
{
	//player 추가
	/*GameObject* player = new Player;

	player->M_Set_Position(Vec2(640.f,384.f));
	player->M_Set_Scale(Vec2(100.f,100.f));
	M_AddObject(player, GROUPTYPE::DEFAULT);*/

	//monster 추가
	/*Monster* monster = new Monster;
	monster->M_Set_Position(Vec2(640.f, 100.f));
	monster->M_Set_SpawnPosition(monster->M_Get_Position());
	monster->M_Set_Scale(Vec2(50.f, 50.f));
	M_AddObject(monster, GROUPTYPE::DEFAULT);*/

	GameObject* text_Box = new TextBox;
	text_Box->M_Set_Position(Vec2(640.f, 650.f));
	text_Box->M_Set_Scale(Vec2(1200.f,200.f));
	M_AddObject(text_Box, GROUPTYPE::DEFAULT);
	
}

void STARTSCENE::M_Exit()
{

}

STARTSCENE::STARTSCENE()
{

}

STARTSCENE::~STARTSCENE()
{

}
