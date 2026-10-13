#pragma once
#include "pc.h"


class PathManager
{
	SINGLE(PathManager)

private:
	char m_SoundContentPath[256];
	char m_SoundRelativePath[256];
	wchar_t m_BMPContentPath[256];
	wchar_t m_BMPRelativePath[256];


public:

	void M_Init();
	char* M_GetSoundRelativePath(const char* _filepath);


	wchar_t* M_GetBMPRelativePath(const wchar_t* _filepath);
};
