#include "pc.h"

#include "BackGround.h"

#include "PathManager.h"

void BackGround::M_Update()
{

}

void BackGround::M_Render(HDC hdc)
{
	/*Gdiplus::Graphics G(hdc);
	G.DrawImage(m_pbackgroundImage, 0, 0, 1920, 1080);*/

	HDC hdcMem = CreateCompatibleDC(hdc);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hdcMem, m_hBitmap);

	BITMAP bitmap;
	GetObject(m_hBitmap, sizeof(BITMAP), &bitmap);

	int width = bitmap.bmWidth;
	int height = bitmap.bmHeight;

	BitBlt(hdc, 0, 0, width, height, hdcMem, 0, 0, SRCCOPY);

	SelectObject(hdcMem, hOldBitmap);
	DeleteDC(hdcMem);
}

void BackGround::M_SetFileName(const wchar_t* _filename)
{
	//m_pbackgroundImage = Gdiplus::Image::FromFile(_filename);
	if (m_hBitmap != nullptr) {
		DeleteObject(m_hBitmap);
		m_hBitmap = nullptr;
	}
	m_hBitmap = (HBITMAP)LoadImage(nullptr, _filename/* PathManager::GetInstance()->M_GetBMPRelativePath(_filename)*/, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

BackGround::BackGround()
	:
m_pbackgroundImage()
{
}

BackGround::~BackGround()
{
}
