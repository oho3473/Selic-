#pragma once
#include "Vec2.h"


class KeywordManager
{
	SINGLE(KeywordManager)


public:

private:
	const wchar_t* m_ShieldWords[16] =
	{
		L"카피 카피 룸룸 카피 카피 룸룸",
		L"카피 카피 룸룸 카피 커피 룸룸",
		L"카피 카피 룸룸 커피 카피 룸룸",
		L"카피 카피 룸룸 커피 커피 룸룸",
		L"카피 커피 룸룸 카피 카피 룸룸",
		L"카피 커피 룸룸 카피 커피 룸룸",
		L"카피 커피 룸룸 커피 카피 룸룸",
		L"카피 커피 룸룸 커피 커피 룸룸",
		L"커피 카피 룸룸 카피 카피 룸룸",
		L"커피 카피 룸룸 카피 커피 룸룸",
		L"커피 카피 룸룸 커피 카피 룸룸",
		L"커피 카피 룸룸 커피 커피 룸룸",
		L"커피 커피 룸룸 카피 카피 룸룸",
		L"커피 커피 룸룸 카피 커피 룸룸",
		L"커피 커피 룸룸 커피 카피 룸룸",
		L"커피 커피 룸룸 커피 커피 룸룸",
	};


	const wchar_t* m_firstword[25] =
	{
		L"강한",
		L"힘찬",
		L"냉철한",
		L"단단한",
		L"무거운",
		L"신비한",
		L"신성한",
		L"싸늘한",
		L"죽음의",
		L"찬란한",
		L"혼돈의",
		L"환상의",
		L"타오르는",
		L"폭발적인",
		L"해방하라",
		L"날카로운",
		L"밤의 심장",
		L"이글거리는",
		L"반짝거리는",
		L"신의 은총으로",
		L"어둠보다 어두운",
		L"태양보다 밝게 타오르는",
		L"바다의 지배자의 이름으로",
		L"숲의 마법 아래, 나타나라",
		L"천둥의 포효 속에서 일어나라"
	};
	const wchar_t* m_secondword[81] =
	{
		L"메라",
		L"기라",
		L"이오",
		L"햐드",
		L"바기",
		L"쟈키",
		L"데인",
		L"후울",
		L"인테",
		L"바하",
		L"자력",
		L"투석",
		L"정화",
		L"듀로",
		L"녹스",
		L"랭록",
		L"윈드",
		L"스웜",
		L"커즈",
		L"발록",
		L"듀란",
		L"메라미",
		L"베기라곤",
		L"이오라",
		L"햐달코",
		L"마햐드",
		L"바기마",
		L"도르마",
		L"마단테",
		L"라리호",
		L"디센도",
		L"루모스",
		L"파이어",
		L"아이스",
		L"스톤 볼",
		L"플레어",
		L"메테오",
		L"록 스톰",
		L"컨퓨징",
		L"베누스",
		L"데스 룰",
		L"메라조마",
		L"바기무쵸",
		L"이오나즌",
		L"라인데인",
		L"기가데인",
		L"지고데인",
		L"미나데인",
		L"도르크마",
		L"도르모아",
		L"도르마돈",
		L"코랄레인",
		L"미나단테",
		L"록 애로우",
		L"윈드 커터",
		L"스톤 엣지",
		L"블리자드",
		L"매드니스",
		L"블라인드",
		L"다크 핸드",
		L"헬파이어",
		L"메라가이아",
		L"지고 플래시",
		L"이오그랑데",
		L"진 이오나즌",
		L"마햐데도스",
		L"바기크로스",
		L"메일 스트롬",
		L"마나스티스",
		L"파이어 볼트",
		L"아이스 볼트",
		L"윈드 애로우",
		L"아이스 티스",
		L"윈드 피스트",
		L"프로미넌스",
		L"익스플로젼",
		L"에이징 커즈",
		L"에너지 서클",
		L"플레임 캐논",
		L"플라즈마 볼",
		L"파이어 레인",
	};

	const wchar_t* m_shield[1]
	{
		L"카피카피 룸룸~ 카피카피 룸룸~ 이루어져라~~~"
	};


	//수식어 5개 저장
	const wchar_t* m_saveFWord[MAX_KEWORD];

	//마법 공격 5개 저장
	const wchar_t* m_saveSWord[MAX_KEWORD];

	const wchar_t* m_ShieldWord;

	//랜덤 int 저장
	int Word1_index[MAX_KEWORD];
	//랜덤 int 저장
	int Word2_index[MAX_KEWORD];
	//정답지 저장
	std::vector<const wchar_t*> m_vectorAnswer;


public:
	void M_ResetAnswerKeyword();
	void M_Update();
	void M_SetShieldWord();
	void M_Init();
	std::vector<const wchar_t*> M_Get_m_vectorAnswer();
	const wchar_t* M_GetShieldWord() { return m_ShieldWord; }
	const wchar_t* M_GetFkeyword(int num) { return m_saveFWord[num]; }
	const wchar_t* M_GetSkeyword(int num) { return m_saveSWord[num]; }
};
