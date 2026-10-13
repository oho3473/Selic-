#include "pc.h"
#include "PathManager.h"

// SoundMgr보다 빨리
PathManager::PathManager()
	: m_BMPContentPath{}
	, m_BMPRelativePath{}
	, m_SoundContentPath{}
	, m_SoundRelativePath{}
{
}
PathManager::~PathManager()
{
}

void PathManager::M_Init()
{
	// 상대경로를 아스키 코드로 받는 함수
	GetCurrentDirectoryA(255, m_SoundContentPath);
	GetCurrentDirectory(255, m_BMPContentPath);
}

char* PathManager::M_GetSoundRelativePath(const char* _filepath)
{
	// 경로상에 한글파일이 있으면 문제가 생기므로 한글파일을 영어로 바꿔서 사용해 주세요

	// 첫번째 문자를 \0 초기화해서 문자열이 텅빈것처럼 행돔함
	m_SoundRelativePath[0] = '\0';

	strcat_s(m_SoundRelativePath, sizeof(m_SoundRelativePath), m_SoundContentPath);

	strcat_s(m_SoundRelativePath, sizeof(m_SoundRelativePath), _filepath);

	return m_SoundRelativePath;
}


wchar_t* PathManager::M_GetBMPRelativePath(const wchar_t* _filepath)
{
	// 경로상에 한글파일이 있으면 문제가 생기므로 한글파일을 영어로 바꿔서 사용해 주세요
	// 첫번째 문자를 \0 초기화해서 문자열이 텅빈것처럼 행돔함
	m_BMPRelativePath[0] = L'\0';

	wcscat_s(m_BMPRelativePath, sizeof(m_BMPRelativePath), m_BMPContentPath);
	wcscat_s(m_BMPRelativePath, sizeof(m_BMPRelativePath), _filepath);

	return m_BMPRelativePath;
}


