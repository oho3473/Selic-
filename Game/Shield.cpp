#include "Shield.h"


void Shield::M_Render(HDC hdc)
{
	//GameObject::M_Render(hdc);
#ifdef _DEBUG
	Rectangle(hdc, 30, 30, 60, 60);
#endif

}

void Shield::M_Update()
{
}

Shield::Shield()
{
}

Shield::~Shield()
{
}
