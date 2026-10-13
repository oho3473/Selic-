#include "pc.h"
#include "SoundManager.h"

#include <cassert>

#include "PathManager.h"
#include "TimeManager.h"


SoundManager::SoundManager()
	: m_pSystem()
	, m_pChannel{}
	, m_pSound_Arr{}
	, m_Init_Change(false)
	,m_Current_Time_Change()
	, m_volumeData{}
	, m_Bgm_Current_Play(SOUND_LIST::SOUND_LIST_BGMEND)
	, m_BGM_Volume_Change()
{
}
SoundManager::~SoundManager()
{
	m_pSystem->release();
	m_pSystem->close();
}

void SoundManager::M_Init()
{
	//초기화
	System_Create(&m_pSystem);
	m_pSystem->init(10, FMOD_INIT_NORMAL, 0);
	//BGMList

	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\bgm\\Title.wav"), FMOD_LOOP_NORMAL, 0, &m_pSound_Arr[(UINT)SOUND_LIST::TITLEBGM]);
	//노래 들어가는지 체크용 코드-한국어가 들어가면 연결 안됨!!
	assert(m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\bgm\\Title.wav"), FMOD_LOOP_NORMAL, 0, &m_pSound_Arr[(UINT)SOUND_LIST::TITLEBGM])==NULL);

	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\bgm\\Stage1.mp3"), FMOD_LOOP_NORMAL, 0, &m_pSound_Arr[(UINT)SOUND_LIST::STAGE1BGM]);
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\bgm\\Stage2.mp3"), FMOD_LOOP_NORMAL, 0, &m_pSound_Arr[(UINT)SOUND_LIST::STAGE2BGM]);
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\bgm\\Stage3.mp3"), FMOD_LOOP_NORMAL, 0, &m_pSound_Arr[(UINT)SOUND_LIST::STAGE3BGM]);
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\bgm\\End.mp3"), FMOD_LOOP_NORMAL, 0, &m_pSound_Arr[(UINT)SOUND_LIST::ENDBGM]);
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\bgm\\Clear.wav"), FMOD_LOOP_NORMAL, 0, &m_pSound_Arr[(UINT)SOUND_LIST::CLEARBGM]);

	//Effect List
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\effect\\Keyboard.wav"), FMOD_LOOP_OFF, 0, &m_pSound_Arr[(UINT)SOUND_LIST::KEYBOARDEFFECT]);
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\effect\\AttackGirl.wav"), FMOD_LOOP_OFF, 0, &m_pSound_Arr[(UINT)SOUND_LIST::ATTACKGIRL]);
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\effect\\MissileBomb.wav"), FMOD_LOOP_OFF, 0, &m_pSound_Arr[(UINT)SOUND_LIST::MISSILEBOMB]);
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\effect\\HitGirl.wav"), FMOD_LOOP_OFF, 0, &m_pSound_Arr[(UINT)SOUND_LIST::HITGIRL]);

	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\effect\\Goblin_Attack.wav"), FMOD_LOOP_OFF, 0, &m_pSound_Arr[(UINT)SOUND_LIST::GOBLIN_ATTACK]);
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\effect\\Goblin_Hit.wav"), FMOD_LOOP_OFF, 0, &m_pSound_Arr[(UINT)SOUND_LIST::GOBLIN_HIT]);
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\effect\\Ent_Attack.wav"), FMOD_LOOP_OFF, 0, &m_pSound_Arr[(UINT)SOUND_LIST::ENT_ATTACK]);
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\effect\\Ent_Hit.wav"), FMOD_LOOP_OFF, 0, &m_pSound_Arr[(UINT)SOUND_LIST::ENT_HIT]);
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\effect\\Golem_Attack.wav"), FMOD_LOOP_OFF, 0, &m_pSound_Arr[(UINT)SOUND_LIST::GOLEM_ATTACK]);
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\effect\\Golem_Hit.wav"), FMOD_LOOP_OFF, 0, &m_pSound_Arr[(UINT)SOUND_LIST::GOLEM_HIT]);

	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\effect\\Shield_Hit.wav"), FMOD_LOOP_OFF, 0, &m_pSound_Arr[(UINT)SOUND_LIST::SHIELD_HIT]);
	m_pSystem->createSound(PathManager::GetInstance()->M_GetSoundRelativePath("\\Resources\\music\\effect\\Shield_Start.wav"), FMOD_LOOP_OFF, 0, &m_pSound_Arr[(UINT)SOUND_LIST::SHIELD_START]);
}

void SoundManager::M_Update()
{

	if (TimeManager::GetInstance()->M_Get_Frame_Time_Float() < 1)
	{
		if (m_Init_Change)
		{
			m_Current_Time_Change = m_Current_Time_Change + (TimeManager::GetInstance()->M_Get_Frame_Time_Float());

			if (m_SoundUP)
			{
				m_pChannel[(UINT)SOUND_CHANNEL::SOUND_CHANNEL_BGM]->setVolume(m_BGM_Volume_Change * (m_Current_Time_Change / m_Init_Time_Change));

				if (m_Current_Time_Change > m_Init_Time_Change)
				{
					m_pChannel[(UINT)SOUND_CHANNEL::SOUND_CHANNEL_BGM]->setVolume(m_BGM_Volume_Change);
					m_Init_Change = false;
				}

			}
			else
			{
				m_pChannel[(UINT)SOUND_CHANNEL::SOUND_CHANNEL_BGM]->setVolume(m_BGM_Volume_Change * (1.f - m_Current_Time_Change / m_Init_Time_Change));


				if (m_Current_Time_Change > m_Init_Time_Change)
				{
					m_pChannel[(UINT)SOUND_CHANNEL::SOUND_CHANNEL_BGM]->setVolume(0);
					m_Init_Change = false;
				}
			}
		}

	}
}



//소리 재생 : 제목, 재생채널, 소리크기
void SoundManager::M_PlayEffect(SOUND_LIST _list, SOUND_CHANNEL _channel, float _soundVolume)
{
	m_pChannel[(UINT)_channel]->stop();
	m_volumeData[(UINT)_channel] = _soundVolume;
	m_pChannel[(UINT)_channel]->setVolume(m_volumeData[(UINT)_channel]);
	m_pSystem->playSound(m_pSound_Arr[(UINT)_list], NULL, 0, &m_pChannel[(UINT)_channel]);
	m_pChannel[(UINT)_channel]->setVolume(m_volumeData[(UINT)_channel]);
}

void SoundManager::M_PlayBGM(SOUND_LIST _list, float _volume, float _time)
{
	if (_list <= SOUND_LIST::SOUND_LIST_BGMEND && _list != m_Bgm_Current_Play)
	{
		m_pChannel[(UINT)SOUND_CHANNEL::SOUND_CHANNEL_BGM]->stop();
		m_pChannel[(UINT)SOUND_CHANNEL::SOUND_CHANNEL_BGM]->setVolume(0);
		m_pSystem->playSound(m_pSound_Arr[(UINT)_list], NULL, 0, &m_pChannel[(UINT)SOUND_CHANNEL::SOUND_CHANNEL_BGM]);
		m_pChannel[(UINT)SOUND_CHANNEL::SOUND_CHANNEL_BGM]->setVolume(0);
		m_BGM_Volume_Change = _volume;
		m_Bgm_Current_Play = _list;
		m_Current_Time_Change = 0;
		m_Init_Time_Change = _time;
		m_Init_Change = true;
		m_SoundUP = true;
	}
}

void SoundManager::M_STOPBGM( float _time)
{
	
		m_Bgm_Current_Play = SOUND_LIST::SOUND_LIST_BGMEND;
		m_Current_Time_Change = 0;
		m_Init_Time_Change = _time;
		m_Init_Change = true;
		m_SoundUP = false;

}

//소리 정지 : 재생채널
void SoundManager::M_Stop_Music(SOUND_CHANNEL _channel)
{
	m_pChannel[(UINT)_channel]->stop();
}

//소리 크기 설정: 재생채널, 소리크기
void SoundManager::M_Set_Volume(SOUND_CHANNEL _channel, float _volume)
{

	m_pChannel[(UINT)_channel]->setVolume(_volume);
}

//채널 소리 크기 가져오기: 재생채널
float SoundManager::M_Get_Sound_Volume(SOUND_CHANNEL _channel)
{
	float _getVolume = 0.0f;
	m_pChannel[(UINT)_channel]->getVolume(&_getVolume);
	return _getVolume;
}


SOUND_LIST SoundManager::M_Get_Bgm_Current_Play()
{
	return SOUND_LIST(m_Bgm_Current_Play);
}
