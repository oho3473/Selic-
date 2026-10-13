#include "MagicBox.h"
#include "pc.h"
#include "GameLogic.h"
#include "KeyManager.h"


void MagicdBox::M_Update()
{
	//키워드 업데이트 필요
}

void MagicdBox::M_Render(HDC hdc)
{
	int left_top_x = 10;
	int left_top_y = 700;
	int right_bottom_x = 1920 - left_top_x - 8;
	int right_bottom_y = 1080;


	Rectangle(hdc, left_top_x+ right_bottom_x, left_top_y, right_bottom_x / 2, right_bottom_y);

}

void MagicdBox::M_String_Copy(wchar_t* destination, wchar_t* copytext)
{
	while (*copytext)
	{
		*destination = *copytext;
		destination++;
		copytext++;
	}
}

MagicdBox::MagicdBox()
{

}

MagicdBox::~MagicdBox()
{

}
