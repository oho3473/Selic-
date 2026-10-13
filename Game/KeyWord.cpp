#include "KeyWord.h"

void KeyWord::M_Update()
{
}

void KeyWord::M_Render(HDC hdc)
{
	int left_top_x = (int)M_Get_Position().x; //30
	int left_top_y = (int)M_Get_Position().y; //750

	int charsize = wcslen(m_Keyword);

	//폰트 지정
	HFONT hFont, OldFont;
	int font_Size = 30;

	hFont = CreateFont(font_Size, 0, 0, 0, FW_BOLD, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0,
		VARIABLE_PITCH | FF_ROMAN, TEXT("경기천년제목 Medium"));
	OldFont = (HFONT)SelectObject(hdc, hFont);

	//글자투명
	SetBkMode(hdc, TRANSPARENT);
	TextOutW(hdc, left_top_x, left_top_y, m_Keyword,charsize);

	SelectObject(hdc, OldFont);
	DeleteObject(hFont);
}

void KeyWord::M_Set_Keyword(const wchar_t* _keyword)
{
	m_Keyword = _keyword;
}

const wchar_t* KeyWord::M_Get_KeyWord()
{
	return m_Keyword;
}
KeyWord::KeyWord()
{
	
}

KeyWord::~KeyWord()
{
}
