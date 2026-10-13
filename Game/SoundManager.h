#pragma once
#include <string>

enum class SOUND_CHANNEL
{
	SOUND_CHANNEL_BGM,
	SOUND_CHANNEL_KEYBOARDCHANNEL,
	SOUND_CHANNEL_MOSTERATTACK,
	SOUND_CHANNEL_MOSTERHIT,
	SOUND_CHANNEL_GIRL,
	SOUND_CHANNEL_SHIELD,
	SOUND_CHANNEL_MISSILE,

	SOUND_CHANNEL_END
};
enum class SOUND_LIST
{
	TITLEBGM,
	STAGE1BGM,
	STAGE2BGM,
	STAGE3BGM,
	ENDBGM,
	CLEARBGM,
	SOUND_LIST_BGM07,
	SOUND_LIST_BGMEND,

	KEYBOARDEFFECT,
	ATTACKGIRL,
	HITGIRL,
	MISSILEBOMB,
	GOBLIN_ATTACK,
	GOBLIN_HIT,
	ENT_ATTACK,
	ENT_HIT,
	GOLEM_ATTACK,
	GOLEM_HIT,
	SHIELD_HIT,
	SHIELD_START,


	SOUND_LIST_EFFECTEND,


	SOUND_LIST_END
};





//
//typedef struct _tagSoundInfo
//{
//	FMOD::Sound* pSound ;
//	bool bLoop;
//}SOUNDINFO, * PSOUNDINFO;
//
//

class SoundManager
{
	SINGLE(SoundManager)
private:
	FMOD::System* m_pSystem;
	FMOD::Channel* m_pChannel[(UINT)SOUND_CHANNEL::SOUND_CHANNEL_END];
	FMOD::Sound* m_pSound_Arr[(UINT)SOUND_LIST::SOUND_LIST_END];
	float m_volumeData[(UINT)SOUND_CHANNEL::SOUND_CHANNEL_END];

	SOUND_LIST m_Bgm_Current_Play;
	//소리 천천히 바뀌기
	bool m_Init_Change;
	float m_Current_Time_Change;
	float m_Init_Time_Change;
	float m_BGM_Volume_Change;
	bool m_SoundUP;



public:

	void M_Init();
	void M_Update();

	//음악 재생
	void M_PlayEffect(SOUND_LIST _list, SOUND_CHANNEL _channel, float _volume);
	void M_PlayBGM(SOUND_LIST _list,float _volume, float _time);
	void M_STOPBGM(  float _time);


	//소리 정지 : 재생채널
	void M_Stop_Music(SOUND_CHANNEL _channel);
	//소리 크기 설정: 재생채널, 소리크기
	void M_Set_Volume(SOUND_CHANNEL _channel, float _volume);

	//채널 소리 크기 가져오기: 재생채널
	float M_Get_Sound_Volume(SOUND_CHANNEL _channel);

	SOUND_LIST M_Get_Bgm_Current_Play();
};
