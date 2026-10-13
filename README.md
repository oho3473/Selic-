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

키 입력을 네 가지 상태로 구분했습니다.<br><br>
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

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	SPACE,
	ENTER,
	BACK,
	ESCAPE,

	LAST
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

### 2. 게임 메인 구조
