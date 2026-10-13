#include "TextBox.h"
#include "pc.h"
#include "GameLogic.h"
#include "KeyManager.h"
#include "Scene.h"
#include "SceneManager.h"
#include "KeywordManager.h"
#include "KeyWord.h"
#include "func.h"
#include "GameLogic.h"
#include "Game.h"
#include "PlayerHP.h"
#include "Shield.h"
#include "func.h"
#include "Missile.h"

void TextBox::M_Update()
{
	HWND hEdit = GetWindow(GameLogic::GetInstance()->M_Get_MainWindow(), GW_CHILD);
	SetFocus(hEdit);
	if (KeyManager::GetInstance()->M_Get_KeyState(KEY::ENTER) == KEYSTATE::TAP)
	{
		M_Clear_m_str();
		M_String_Copy(m_str, KeyManager::GetInstance()->m_copytext);


		//정답 및 방어 처리
		if (!wcsncmp(m_str, L"카피 카피 룸룸 카피 카피 룸룸", 18))
		{
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
					SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_DelateGroup(GROUPTYPE::KEYWORD);
					KeywordManager::GetInstance()->M_ResetAnswerKeyword();
					// 키워드 생성
					for (size_t i = 0; i < 5; i++)
					{
						KeyWord* key_Word_1 = new KeyWord;
						key_Word_1->M_Set_Position(Vec2(400.f, 780.f + i * 40));
						key_Word_1->M_Set_Keyword(KeywordManager::GetInstance()->M_GetFkeyword(i));
						CreateObject(key_Word_1, GROUPTYPE::KEYWORD);
					}
					for (size_t i = 0; i < 5; i++)
					{
						KeyWord* key_Word_1 = new KeyWord;
						key_Word_1->M_Set_Position(Vec2(1120.f, 780.f + i * 40));
						key_Word_1->M_Set_Keyword(KeywordManager::GetInstance()->M_GetSkeyword(i));
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
							Missile* missile = new Missile;
							missile->M_Set_Position(Vec2(630.f, 300.f));
							missile->M_Set_m_Damage(size);
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
		SendMessage(hEdit, EM_LIMITTEXT, (WPARAM)60, 0);
		return;
	}

	GetWindowTextW(hEdit, m_str, TEXTMAXLENGTH);
}


void TextBox::M_Render(HDC hdc)
{
	int left_top_x = 300;
	int left_top_y = 950;
	int right_bottom_x = 1920 - left_top_x;
	int right_bottom_y = 1080;
	int offset = 60;

	//Rectangle(hdc, left_top_x, left_top_y, right_bottom_x, right_bottom_y);

	//폰트 지정
	HFONT hFont, OldFont;
	int font_Size = 20;

	hFont = CreateFont(font_Size, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0,
		VARIABLE_PITCH | FF_ROMAN, TEXT("궁서"));
	OldFont = (HFONT)SelectObject(hdc, hFont);

	TextOutW(hdc, left_top_x+ offset, 1000, m_str, wcslen(m_str));

	SelectObject(hdc, OldFont);
	DeleteObject(hFont);
}

void TextBox::M_String_Copy(wchar_t* destination, wchar_t* copytext)
{
	while (*copytext)
	{
		*destination = *copytext;
		destination++;
		copytext++;
	}
}


TextBox::TextBox() 
{

}

TextBox::~TextBox()
{

}



void TextBox::M_Clear_m_str()
{
	for (size_t i = 0; m_str[i] != '\0'; i++)
	{
		m_str[i] = '\0';
	}
}