# Selic!
https://github.com/user-attachments/assets/d4c54c95-a2e0-4226-9d61-5157c9173d70

주어진 단어를 조합하여 마법을 입력하며, 제한시간안에 적을 물리치는 게임입니다.<br>
프로젝트에서 게임의 메인 루프와 타자입력처리를 구현했습니다.

## 프로젝트 개요

| 항목 | 내용 |
| --- | --- |
| **프로젝트명** | Selic! |
| **플랫폼** | PC |
| **개발 언어** | C++ |
| **사용 기술** | Win32 API, GDI+ |
| **담당 작업** | 게임 루프 및 프레임워크 구현<br>키 입력 상태 관리 및 문자열 입력 처리 |

## 구현 상세

### 1. [키 입력 처리 시스템](./Game/KeyManager.h)
짧은 시간 안에 정확한 입력 처리가 중요한 게임이었기 때문에, 프레임 단위 입력 상태를 관리할 수 있는 `KeyManager`를 설계했습니다.
단순 Key 입력 여부만 처리하는 것이 아니라, 입력 상태를 분리해 프레임 기반 입력 흐름을 관리했습니다.

<table>
<tr>
<th>구현 설명</th>
<th>상태정의 코드</th>
</tr>
<tr>
<td width="50%" valign="top">

키 입력 상태를 구분하고 정의했습니다.<br><br>
- TAP
- HOLD
- AWAY
- NONE

</td>
<td width="50%" valign="top">

```cpp
enum class KEYSTATE
{
    NONE,
    TAP,
    HOLD,
    AWAY
};

struct KEYINFO
{
	KEYSTATE keystate;	//키 상태
	bool is_KeyDown;	//이전 프레임에 눌렸는지
}
```

</td>
</tr>
</table>

정의한 키를 바탕으로 KeyManager는 매프레임 키 입력에대한 상태를 갱신합니다.
[KeyManager::M_Update()](./Game/KeyManager.cpp#L34)
```cpp
void KeyManager::M_Update()
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
```

### 2. 게임 메인 구조
