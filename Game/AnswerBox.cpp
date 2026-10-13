//#include "AnswerBox.h"
//#include "pc.h"
//#include "GameLogic.h"
//#include "KeyManager.h"
//#include "KeywordManager.h"
//#include "SceneManager.h"
//#include "Keyword.h"
//#include "func.h"
//#include "Scene.h"
//
//void AnswerBox::M_Update()
//{
//
//	if (KeyManager::GetInstance()->M_Get_KeyState(KEY::ENTER) == KEYSTATE::TAP)
//	{
//		//이거는 m_str에 있는 모든 데이터 삭제. 이거 아래에다 옮기면 렌더에서 문제생기더라
//		M_Clear_m_str();
//		M_String_Copy(m_str, KeyManager::GetInstance()->m_copytext);
//		// 얘는 그 안 비워줬더니 배열 중간 중간에 ' ' 이 값이 들어가서 가끔 이미지 오류 나오 ㅇㅇ
//		KeyManager::GetInstance()->M_Reset_m_copytext();
//
//		for (size_t i = 0; i < KeywordManager::GetInstance()->M_Get_m_vectorAnswer().size(); i++)
//		{
//			size_t size = wcslen(KeywordManager::GetInstance()->M_Get_m_vectorAnswer()[i]);
//
//			if (!wcsncmp(m_str, KeywordManager::GetInstance()->M_Get_m_vectorAnswer()[i], size + 1))
//			{
//				SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_DelateGroup(GROUPTYPE::KEYWORD);
//				KeywordManager::GetInstance()->M_ResetAnswerKeyword();
//				// 키워드 생성
//				for (size_t i = 0; i < 5; i++)
//				{
//					KeyWord* key_Word_1 = new KeyWord;
//					key_Word_1->M_Set_Position(Vec2(60.f, 550.f + i * 40));
//					key_Word_1->M_Set_Keyword(KeywordManager::GetInstance()->M_GetFkeyword(i));
//					CreateObject(key_Word_1, GROUPTYPE::KEYWORD);
//				}
//				for (size_t i = 0; i < 5; i++)
//				{
//					KeyWord* key_Word_1 = new KeyWord;
//					key_Word_1->M_Set_Position(Vec2(300.f, 550.f + i * 40));
//					key_Word_1->M_Set_Keyword(KeywordManager::GetInstance()->M_GetSkeyword(i));
//					CreateObject(key_Word_1, GROUPTYPE::KEYWORD);
//				}
//
//				for (size_t i = 0; i < SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object_Array(GROUPTYPE::ENEMY).size(); i++)
//				{
//					if (SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::ENEMY, i)->M_get_Name() == L"Enemy")
//					{
//						int hp = SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::ENEMY, i)->M_get_hp();
//						if (size > 15)
//						{
//							size = size * 2;
//						}
//						hp = hp - size;
//						SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_Get_Object((UINT)GROUPTYPE::ENEMY, i)->M_Set_hp(hp);
//						break;
//					}
//				}
//				break;
//			}
//		}
//	}
//}
//
//void AnswerBox::M_Render(HDC hdc)
//{
//	HFONT hFont, OldFont;
//	int font_Size = 30;
//
//	hFont = CreateFont(font_Size, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0,
//		VARIABLE_PITCH | FF_ROMAN, TEXT("궁서"));
//	OldFont = (HFONT)SelectObject(hdc, hFont);
//	
//	TextOutW(hdc, 500, 200, m_str, wcslen(m_str));
//
//	SelectObject(hdc, OldFont);
//	DeleteObject(hFont);
//}
//
//void AnswerBox::M_String_Copy(wchar_t* destination, wchar_t* copytext)
//{
//	while (*copytext)
//	{
//		*destination = *copytext;
//		destination++;
//		copytext++;
//	}
//}
//
//
//
//AnswerBox::AnswerBox()
//{
//
//}
//
//AnswerBox::~AnswerBox()
//{
//
//}
//
//
//
