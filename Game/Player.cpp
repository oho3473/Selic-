#include "pc.h"
#include "Player.h"
#include "func.h"
#include "GameLogic.h"
#include "SceneManager.h"
#include "KeyManager.h"
#include "KeyWord.h"
#include "KeywordManager.h"
#include "Missile.h"
#include "Scene.h"
#include "Shield.h"
#include "SoundManager.h"


void Player::M_Clear_m_str()
{
	for (size_t i = 0; m_str[i] != '\0'; i++)
	{
		m_str[i] = '\0';
	}
}

bool Player::M_Can_Shield()
{
	KeywordManager::GetInstance()->M_GetShieldWord();
	size_t size = wcslen(KeywordManager::GetInstance()->M_GetShieldWord());
	if (!wcsncmp(m_str, KeywordManager::GetInstance()->M_GetShieldWord(), size))
	{
		return true;
	}
	return false;

}

Player::Player()
{
	M_animeintance = new Animation;
	M_animeintance->M_AddAnimation(L"Resources\\Player\\IDLE.png", 12, 0.8f, ANIMESTATUS::IDLE);
	M_animeintance->M_AddAnimation(L"Resources\\Player\\SHIELDSTART.png", 4, 0.5f, ANIMESTATUS::SHIELDSTART);
	M_animeintance->M_AddAnimation(L"Resources\\Player\\SHIELD.png", 4, 0.5f, ANIMESTATUS::SHIELD);
	M_animeintance->M_AddAnimation(L"Resources\\Player\\HITHIT.png", 12, 0.8f, ANIMESTATUS::HIT);
	M_animeintance->M_AddAnimation(L"Resources\\Player\\ATTACK.png", 11, 0.6f, ANIMESTATUS::ATTACK);

	m_shieldON = false;
	M_animeintance->M_SetAnimation(ANIMESTATUS::IDLE,LOOPSTATUS::LOOP);
	M_SetOnhit(false);

	KeyWord* shieldKeyWord = new KeyWord;
	shieldKeyWord->M_Set_Keyword(KeywordManager::GetInstance()->M_GetShieldWord());
	shieldKeyWord->M_Set_Position(Vec2(750, 120));
	CreateObject(shieldKeyWord, GROUPTYPE::SHIELDKEYWORD);

	HWND hEdit = GetWindow(GameLogic::GetInstance()->M_Get_MainWindow(), GW_CHILD);
	DestroyWindow(hEdit);
	hEdit = CreateWindowW(L"edit",
		NULL,
		WS_CHILD |
		WS_VISIBLE |
		/*WS_BORDER |*/
		ES_AUTOHSCROLL,
		300, 1500, 300, 1500, GameLogic::GetInstance()->M_Get_MainWindow(), (HMENU)100,
		NULL, NULL);
	SendMessage(hEdit, EM_LIMITTEXT, (WPARAM)32, 0);
	return;




}

Player::~Player()
{
}

void Player::M_Update()
{
	//캐릭터 이동 샘플

	//텍스트박스- 정답처리 및 방어처리
	HWND hEdit = GetWindow(GameLogic::GetInstance()->M_Get_MainWindow(), GW_CHILD);
	SetFocus(hEdit);
	if (KeyManager::GetInstance()->M_Get_KeyState(KEY::ENTER) == KEYSTATE::TAP)
	{
		M_Clear_m_str();
		M_String_Copy(m_str, KeyManager::GetInstance()->m_copytext);
		
	
		if (!wcsncmp(m_str, L"탈출!",4))
		{
			if (m_current_Scene == SCENETYPE::STAGE1)
			{
				ChangeScene(SCENETYPE::RESTART1);
			}
			else if (m_current_Scene == SCENETYPE::STAGE2)
			{ 
				ChangeScene(SCENETYPE::RESTART2);
			}
			else if (m_current_Scene == SCENETYPE::STAGE3)
			{
				ChangeScene(SCENETYPE::RESTART3);
			}
		}

		if (!wcsncmp(m_str, L"Selic!", 6))
		{
			SoundManager::GetInstance()->M_PlayEffect(SOUND_LIST::ATTACKGIRL, SOUND_CHANNEL::SOUND_CHANNEL_GIRL, 0.8f);
			Missile* missile = new Missile;
			missile->M_Set_Position(Vec2(600.f, 360.f));
			missile->M_Set_m_Damage(999);
			missile->M_Set_Name(L"Missile");
			CreateObject(missile, GROUPTYPE::MISSILE);
		}

		//정답 및 방어 처리
		if (M_Can_Shield())
		{
			SoundManager::GetInstance()->M_PlayEffect(SOUND_LIST::SHIELD_START, SOUND_CHANNEL::SOUND_CHANNEL_SHIELD, 1.3f);
			//정답 시 텍스트 변경 및 표시.
			KeywordManager::GetInstance()->M_SetShieldWord();
			SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_DelateGroup(GROUPTYPE::SHIELDKEYWORD);
			KeyWord* shieldKeyWord = new KeyWord;
			shieldKeyWord->M_Set_Keyword(KeywordManager::GetInstance()->M_GetShieldWord());
			shieldKeyWord->M_Set_Position(Vec2(750, 120));
			CreateObject(shieldKeyWord, GROUPTYPE::SHIELDKEYWORD);

			SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_DelateGroup(GROUPTYPE::SHIELD);
			Shield* _shield = new Shield;
			_shield->M_Set_Name(L"SHIELD");
			CreateObject(_shield, GROUPTYPE::SHIELD);
		}
		else
		{
			SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_DelateGroup(GROUPTYPE::SHIELD);
			//정답 판정
			for (size_t i = 0; i < KeywordManager::GetInstance()->M_Get_m_vectorAnswer().size(); i++)
			{
				size_t size = wcslen(KeywordManager::GetInstance()->M_Get_m_vectorAnswer()[i]);

				if (!wcsncmp(m_str, KeywordManager::GetInstance()->M_Get_m_vectorAnswer()[i], size + 1))
				{
					M_animeintance->M_SetAnimation(ANIMESTATUS::ATTACK, LOOPSTATUS::ONCETOIDLE);

					// 키워드 생성
					SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_DelateGroup(GROUPTYPE::KEYWORD);
					KeywordManager::GetInstance()->M_ResetAnswerKeyword();
					for (size_t i = 0; i < MAX_KEWORD; i++)
					{
						KeyWord* key_Word_1 = new KeyWord;
						key_Word_1->M_Set_Position(Vec2( + KEYWORDPOSFX,  + KEYWORDPOSY + KEYWORDPOSINTERVAL * i));
						key_Word_1->M_Set_Keyword(KeywordManager::GetInstance()->M_GetFkeyword(i));
						CreateObject(key_Word_1, GROUPTYPE::KEYWORD);
					}
					for (size_t i = 0; i < MAX_KEWORD; i++)
					{
						KeyWord* key_Word_1 = new KeyWord;
						key_Word_1->M_Set_Position(Vec2( + KEYWORDPOSSX,  + KEYWORDPOSY + i * KEYWORDPOSINTERVAL));
						key_Word_1->M_Set_Keyword(KeywordManager::GetInstance()->M_GetSkeyword((size_t)i));
						CreateObject(key_Word_1, GROUPTYPE::KEYWORD);
					}

					for (size_t i = 0; i < SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object_Array(GROUPTYPE::ENEMY).size(); i++)
					{
						if (SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::ENEMY, i)->M_get_Name() == L"Enemy")
						{
							if (size > 15)
							{
								size = size * 2;
							}

							SoundManager::GetInstance()->M_PlayEffect(SOUND_LIST::ATTACKGIRL, SOUND_CHANNEL::SOUND_CHANNEL_GIRL, 0.8f);
							Missile* missile = new Missile;
							missile->M_Set_Position(Vec2(600.f, 360.f));
							missile->M_Set_m_Damage((size_t)size);
							missile->M_Set_Name(L"Missile");
							CreateObject(missile, GROUPTYPE::MISSILE);
							break;
						}
					}
					break;
				}
			}
		}

		//한글자 남는걸 없애기 위해 에디트박스를 파괴하고 새로 만든다
		DestroyWindow(hEdit);
		hEdit = CreateWindowW(L"edit",
			NULL,
			WS_CHILD |
			WS_VISIBLE |
			/*WS_BORDER |*/
			ES_AUTOHSCROLL,
			300, 1500, 300, 1500, GameLogic::GetInstance()->M_Get_MainWindow(), (HMENU)100,
			NULL, NULL);
		SendMessage(hEdit, EM_LIMITTEXT, (WPARAM)32, 0);
		return;
	}
	GetWindowTextW(hEdit, m_str, TEXTMAXLENGTH);




	//=======================
	// 플레이어 애니메이터
	if (SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object_Array(GROUPTYPE::SHIELD).size()&& m_shieldON==false)
	{
		M_animeintance->M_SetAnimation(ANIMESTATUS::SHIELDSTART, LOOPSTATUS::NOTLOOP);

		m_shieldON = true;
	}
	else if (!SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object_Array(GROUPTYPE::SHIELD).size()&& m_shieldON == true)
	{
		M_animeintance->M_SetAnimation(ANIMESTATUS::IDLE, LOOPSTATUS::LOOP);
		m_shieldON = false;

	}

	if (M_animeintance->M_Get_m_current_status()==ANIMESTATUS::SHIELDSTART&& M_animeintance->M_Get_Current_Frame()== M_animeintance->M_Get_Current_m_imageInfo(DATA_LIST::FRAME)-1)
	{
		M_animeintance->M_SetAnimation(ANIMESTATUS::SHIELD, LOOPSTATUS::LOOP);
	}

	if (M_GetOnhit()==true)
	{
		SoundManager::GetInstance()->M_PlayEffect(SOUND_LIST::HITGIRL, SOUND_CHANNEL::SOUND_CHANNEL_GIRL, 1.5f);
		M_animeintance->M_SetAnimation(ANIMESTATUS::HIT, LOOPSTATUS::ONCETOIDLE);
		M_SetOnhit(false);
	}
}





void Player::M_Render(HDC hdc)
{
	M_animeintance->M_PlayAnimation((int)M_Get_Position().x, (int)M_Get_Position().y, hdc);

	int left_top_x = +500;
	int left_top_y = + 1000;

	int offset = 40;

	//Rectangle(hdc, left_top_x, left_top_y, right_bottom_x, right_bottom_y);

	//폰트 지정
	HFONT hFont, OldFont;
	int font_Size = 28;

	hFont = CreateFont(font_Size, 0, 0, 0, FW_BOLD, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0,
		VARIABLE_PITCH | FF_ROMAN, TEXT("경기천년제목 Medium"));
	OldFont = (HFONT)SelectObject(hdc, hFont);

	TextOutW(hdc, left_top_x + offset, left_top_y-8, m_str, wcslen(m_str));

	SelectObject(hdc, OldFont);
	DeleteObject(hFont);
}

void Player::M_String_Copy(wchar_t* destination, wchar_t* copytext)
{
	while (*copytext)
	{
		*destination = *copytext;
		destination++;
		copytext++;
	}
}