#include "STAGE1.h"
#include "GameObject.h"
#include "KeywordManager.h"
#include "pc.h"
#include "func.h"

//Gameobject
#include "Goblin.h"
#include "Player.h"
#include "MainTime.h"
#include "KeyWord.h"
#include "PlayerHP.h"
#include "MonsterHP.h"
#include"BackGround.h"
#include "Fire.h"
#include "GameLogic.h"
#include "Gauge.h"
#include "SoundManager.h"
#include "QuitButton.h"

void STAGE1::M_Enter()
{
	//배경화면
	BackGround* backgroundStage1 = new BackGround;
	backgroundStage1->M_Set_Position(Vec2(0.f, 0.f));
	//backgroundStage1->M_Set_Scale(Vec2(1000.f, 200.f));
	backgroundStage1->M_SetFileName(L"Resources\\BG\\STAGE1.bmp");
	CreateObject(backgroundStage1, GROUPTYPE::DEFAULT);

	//타이머
	MainTime* main_timer = new MainTime;
	main_timer->M_Set_Position(Vec2(0.f, 40.f));
	main_timer->M_Set_NextScene(SCENETYPE::END);
	main_timer->M_Set_Timer(110);
	main_timer->M_Set_Name(L"Main_timer");
	CreateObject(main_timer, GROUPTYPE::DEFAULT);

	//타이머 불
	Fire* fire = new Fire;
	fire->M_Set_Position(Vec2(1920.f, -5.f));		//540
	fire->M_Set_Name(L"Fire");
	fire->M_Set_Timer(main_timer->M_Get_Timer());
	CreateObject(fire, GROUPTYPE::DEFAULT);


	KeywordManager::GetInstance()->M_ResetAnswerKeyword();

	//// 키워드 생성
	for (size_t i = 0; i < MAX_KEWORD; i++)
	{
		KeyWord* key_Word_1 = new KeyWord;
		key_Word_1->M_Set_Position(Vec2(KEYWORDPOSFX, KEYWORDPOSY + KEYWORDPOSINTERVAL * i));
		key_Word_1->M_Set_Keyword(KeywordManager::GetInstance()->M_GetFkeyword(i));
		CreateObject(key_Word_1, GROUPTYPE::KEYWORD);
	}
	for (size_t i = 0; i < MAX_KEWORD; i++)
	{
		KeyWord* key_Word_1 = new KeyWord;
		key_Word_1->M_Set_Position(Vec2(KEYWORDPOSSX, KEYWORDPOSY + i * KEYWORDPOSINTERVAL));
		key_Word_1->M_Set_Keyword(KeywordManager::GetInstance()->M_GetSkeyword((size_t)i));
		CreateObject(key_Word_1, GROUPTYPE::KEYWORD);
	}

	//게임종료버튼
	QuitButton* quit_Box = new QuitButton;
	quit_Box->M_Set_Position(Vec2(1740.f, 950.f));
	quit_Box->M_Set_Scale(Vec2(150.f, 80.f));
	//quit_Box->M_SetFileName(L"Resources\\UI\\");
	CreateObject(quit_Box, GROUPTYPE::DEFAULT);

	//플레이어
	Player* player = new Player;
	player->M_Set_Position(Vec2(365.f, 290.f));
	player->M_Set_Name(L"Player");
	player->M_Set_Max_Hp((int)60);
	player->M_Set_Current_Hp(player->M_Get_MAX_Hp());
	player->M_Set_Current_Scene(SCENETYPE::STAGE1);
	CreateObject(player, GROUPTYPE::PLAYER);
	//플레이어 hp
	PlayerHP* player_Hp = new PlayerHP;
	player_Hp->M_Set_Position(Vec2(330.f,190.f));
	//player_Hp->M_Set_Scale(Vec2(100.f, 10.f));
	player_Hp->M_Set_Max_Hp(player->M_Get_MAX_Hp());
	player_Hp->M_Set_Timer(2);
	player_Hp->M_Set_NextScene(SCENETYPE::END);
	CreateObject(player_Hp, GROUPTYPE::UI);

	//몬스터
	Goblin* monster = new Goblin;
	monster->M_Set_Position(Vec2(1268.f, 320.f));
	//monster->M_Set_Scale(Vec2(360.f, 360.f));
	monster->M_Set_Name(L"Enemy");
	monster->M_Set_Max_Hp((int)90);
	monster->M_Set_Current_Hp(monster->M_Get_MAX_Hp());
	//n초에 한번 공격
	monster->M_Set_attacktime(30);
	CreateObject(monster, GROUPTYPE::ENEMY);

	//몬스터 hp
	MonsterHP* monster_Hp = new MonsterHP;
	monster_Hp->M_Set_Position(Vec2(1250.f,190.f));
	monster_Hp->M_Set_Max_Hp(monster->M_Get_MAX_Hp());
	monster_Hp->M_Set_Timer(2);
	monster_Hp->M_Set_NextScene(SCENETYPE::RESTMAP1);
	CreateObject(monster_Hp, GROUPTYPE::UI);

	//몬스터 Gage
	Gauge* monster_Gauge = new Gauge;
	monster_Gauge->M_Set_Position(Vec2(monster_Hp->M_Get_Position().x+15, monster_Hp->M_Get_Position().y));
	CreateObject(monster_Gauge, GROUPTYPE::UI);

	SoundManager::GetInstance()->M_PlayBGM(SOUND_LIST::STAGE1BGM, 0.5, 2);
}


void STAGE1::M_Update()
{
	SCENE::M_Update();

}

void STAGE1::M_Exit()
{
	HWND hEdit = GetWindow(GameLogic::GetInstance()->M_Get_MainWindow(), GW_CHILD);
	DestroyWindow(hEdit);
	M_DelateAll();
}


STAGE1::STAGE1()
{

}

STAGE1::~STAGE1()
{

}
