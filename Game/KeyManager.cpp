#include "KeyManager.h"
#include <windows.h>
#include "GameLogic.h"
#include "STAGE1.h"


int g_KeyArray[(int)KEY::LAST] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,
	VK_SPACE,
	VK_RETURN,
	VK_BACK,
	VK_ESCAPE
};

KeyManager::KeyManager()
{
}

KeyManager::~KeyManager()
{}

void KeyManager::M_Init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		m_key.push_back(KEYINFO{ KEYSTATE::NONE,false });
	}
}

void KeyManager::M_Update()
{
	//윈도 포커싱 알아내기
	HWND hWnd = GetFocus();

	//포커싱 중일때 키 이벤트
	if (hWnd != nullptr)
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			//키가 눌려있다
			if (GetAsyncKeyState(g_KeyArray[i]) & 0x8000)
			{
				//이전에도 눌렸다
				if (m_key[i].is_KeyDown)
				{
					m_key[i].keystate = KEYSTATE::HOLD;
				}
				else
				{
					//이전에도 안눌려있었다
					m_key[i].keystate = KEYSTATE::TAP;
				}

				m_key[i].is_KeyDown = true;
			}
			//안눌렸다
			else
			{
				if (m_key[i].is_KeyDown)
				{
					//이전에 눌려있었다
					m_key[i].keystate = KEYSTATE::AWAY;
				}
				else
				{
					//이전에도 안눌려있었다
					m_key[i].keystate = KEYSTATE::NONE;
				}
				m_key[i].is_KeyDown = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			m_key[i].is_KeyDown = false;

			if (KEYSTATE::TAP == m_key[i].keystate || KEYSTATE::HOLD == m_key[i].keystate)
			{
				m_key[i].keystate = KEYSTATE::AWAY;
			}
			else if (KEYSTATE::AWAY == m_key[i].keystate)
			{
				m_key[i].keystate = KEYSTATE::NONE;
			}
		}
	}
}



KEYSTATE KeyManager::M_Get_KeyState(KEY key)
{
	return m_key[(int)key].keystate;
}

void KeyManager::M_Reset_m_copytext()
{
	for (size_t i = 0; i < 40; i++)
	{
		m_copytext[i] = '\0';

	}
}
