#pragma once
class cSoundManager
{
private:
	FMOD_SYSTEM *g_system;
	map<string, FMOD_SOUND*> m_sounds;
	FMOD_CHANNEL* m_channel;			// 일반 채널
	FMOD_CHANNEL* m_effectChannel;			//효과음 채널

	vector<string> m_SoundList;
	vector<string> m_EffectList;
	FLOAT m_volume;
public:
	FMOD_RESULT InitSound();
	FMOD_RESULT UpdateSound();
	FMOD_RESULT ReleaseSound();

	VOID AppendSoundList();
	BOOL AppendSound(string soundKey, FMOD_SOUND* sound);
	FMOD_SOUND* FindSound(string soundKey);
	FMOD_RESULT PlaySoundFunc(string soundKey);
	FMOD_RESULT PlayEffectFunc(string soundKey);

	FMOD_RESULT StopSoundChannelFunc();
};

