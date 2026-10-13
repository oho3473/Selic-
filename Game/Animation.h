#pragma once
#include "pc.h"

class Animation
{
private:

	//애니메이션의 흐르는 시간
	float m_flowing_time = 0;
	//프레임 
	int m_currentFrame = 0;
	//스프라이트 이미지 프레임별 위치
	std::vector<POINT> m_framePose_List;
	//현재의 애니메이션 상태
	ANIMESTATUS m_current_status;
	//애니메이션 정보: 프레임/걸린시간
	float m_imageInfo[DATA_LIST::DATA_LIST_END][(UINT)ANIMESTATUS::ANIMESTATUS_END];
	//이미지 저장위치.
	Gdiplus::Image * m_pTestImage[(UINT)ANIMESTATUS::ANIMESTATUS_END];
	float m_frametime;
	int m_lastframe;
	//루프 시스템
	LOOPSTATUS  m_loop;


	//끝남처리
	bool m_aniFinished;


public:

	//Player 같은 애니메이션이 필요한 것들이 생성될 때. 다 추가하기. 파일명,프레임수(스프라이트개수),걸리는시간,상태
	void M_AddAnimation(const wchar_t* _filename, int _frame, float _time, ANIMESTATUS _status);
	//실행할 애니메이션 선택: ANIMESTATUS enum
	void M_SetAnimation(ANIMESTATUS _status, LOOPSTATUS _LOOPSTATUS);
	//애니메이션 실행: x위치, y위치, hdc
	void M_PlayAnimation(int _initX, int _initY, HDC _hdc);
	ANIMESTATUS M_Get_m_current_status() { return m_current_status; }
	int M_Get_Current_Frame() {return m_currentFrame;}
	float M_Get_Current_m_imageInfo(DATA_LIST _DATA_LIST) {return m_imageInfo[_DATA_LIST][(UINT)m_current_status];}
	


	Animation();
	~Animation();

};

