#pragma once
class cSoundManager
{
private:
	FMOD_SYSTEM *g_system;
	map<string, FMOD_SOUND*> m_sounds;
	FMOD_CHANNEL* m_channel;

	vector<string> m_SoundList;
	FLOAT m_volume;
public:
	FMOD_RESULT InitSound();
	FMOD_RESULT UpdateSound();
	FMOD_RESULT ReleaseSound();

	VOID AppendSoundList();
	BOOL AppendSound(string soundKey, FMOD_SOUND* sound);
	FMOD_SOUND* FindSound(string soundKey);
	FMOD_RESULT PlaySoundFunc(string soundKey);

};

