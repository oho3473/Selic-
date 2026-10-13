#include "Gameover.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "STAGE1.h"

void Gameover::M_Enter()
{
	Gameover* gameover = new Gameover;
	gameover->M_Set_Position(Vec2(700.f, 700.f));
	gameover->M_Set_Scale(Vec2(1200.f, 200.f));
	M_AddObject(gameover, GROUPTYPE::DEFAULT);
}

void Gameover::M_Exit()
{

}

Gameover::Gameover()
{

}

Gameover::~Gameover()
{

}
