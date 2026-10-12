#include "Animation.h"
#include "TimeManager.h"
#include "pc.h"

void Animation::M_AddAnimation(const wchar_t* _filename, int _frame, float _time, ANIMESTATUS _status)
{
	m_pTestImage[(UINT)_status] = Gdiplus::Image::FromFile(_filename);
	m_imageInfo[DATA_LIST::FRAME][(UINT)_status] = (float)_frame;
	m_imageInfo[DATA_LIST::TAKETIME][(UINT)_status] = _time;
}

void Animation::M_SetAnimation(ANIMESTATUS _status, LOOPSTATUS _LOOPSTATUS)
{
	//현재상태
	m_current_status = _status;
	m_flowing_time = 0;
	m_framePose_List.clear();
	m_currentFrame = 0;
	m_loop = _LOOPSTATUS;
	m_aniFinished = false;
	for (int i = 0; i < (int)m_imageInfo[DATA_LIST::FRAME][(UINT)_status]; i++)
	{
		m_framePose_List.push_back({ (int)(m_pTestImage[(UINT)m_current_status]->GetWidth() / m_imageInfo[DATA_LIST::FRAME][(UINT)_status]) * i,0 });
	}
	m_frametime = m_imageInfo[DATA_LIST::TAKETIME][(UINT)m_current_status] / m_imageInfo[DATA_LIST::FRAME][(UINT)m_current_status];
	m_lastframe = (int)m_imageInfo[DATA_LIST::FRAME][(UINT)m_current_status] - 1;
}

void Animation::M_PlayAnimation(int _initX, int _initY, HDC _hdc)
{
	//HDC
	Gdiplus::Graphics Grapic(_hdc);

	//시간 흐름.
	m_flowing_time = m_flowing_time + TimeManager::GetInstance()->M_Get_Frame_Time_Float();

	//프레임 흐름
	if (m_flowing_time > m_frametime)
	{
		switch (m_loop)
		{
		case LOOPSTATUS::NOTLOOP:
		{
			if (m_currentFrame == m_lastframe)
			{
				m_currentFrame = m_lastframe;
				m_aniFinished = true;
			}
			else
			{
				m_currentFrame++;
				m_currentFrame = m_currentFrame % (int)m_imageInfo[DATA_LIST::FRAME][(UINT)m_current_status];
			}
		}
		break;
		case LOOPSTATUS::ONCETOIDLE:
		{
			if (m_currentFrame == m_lastframe)
			{
				M_SetAnimation(ANIMESTATUS::IDLE, LOOPSTATUS::LOOP);
			}
			else
			{
				m_currentFrame++;
				m_currentFrame = m_currentFrame % (int)m_imageInfo[DATA_LIST::FRAME][(UINT)m_current_status];
			}
		}
		break;
		case LOOPSTATUS::LOOP:
		{
			m_currentFrame++;
			m_currentFrame = m_currentFrame % (int)m_imageInfo[DATA_LIST::FRAME][(UINT)m_current_status];
		}
		break;
		default:;
		}

		m_flowing_time = 0;
	}
	Gdiplus::Rect rect_size(_initX, _initY, (int)((m_pTestImage[(UINT)m_current_status]->GetWidth() / m_imageInfo[DATA_LIST::FRAME][(UINT)m_current_status])), (int)m_pTestImage[(UINT)m_current_status]->GetHeight());


	//그리기
	Grapic.DrawImage(
		m_pTestImage[(UINT)m_current_status],
		rect_size,
		m_framePose_List[m_currentFrame].x,
		m_framePose_List[m_currentFrame].y,
		(int)(m_pTestImage[(UINT)m_current_status]->GetWidth() / m_imageInfo[DATA_LIST::FRAME][(UINT)m_current_status]),
		m_pTestImage[(UINT)m_current_status]->GetHeight(), Gdiplus::UnitPixel);



}

Animation::Animation()
	: m_current_status()
	, m_imageInfo{}
	, m_currentFrame()
	, m_pTestImage{}
	, m_framePose_List()
	, m_loop()
	, m_aniFinished(false)
	, m_frametime()
	, m_lastframe()
{
}

Animation::~Animation()
{

}
