#include "framework.h"

FMOD_RESULT cSoundManager::InitSound()
{
	m_volume = 1.0f;
	FMOD_RESULT result;
	result = FMOD_System_Create(&g_system);
	result = FMOD_System_Init(g_system, 32, FMOD_INIT_NORMAL, NULL);

	AppendSoundList();

	for (INT i = 0; i < m_SoundList.size(); i++)
	{
		FMOD_SOUND* sound;
		char str[256] = "\0";
		sprintf(str, "../Sounds/%s.mp3", m_SoundList[i].c_str());
		FMOD_RESULT result = FMOD_System_CreateSound(g_system, str, FMOD_DEFAULT, 0, &sound);
		AppendSound(m_SoundList[i], sound);
	}
	FMOD_Channel_SetVolume(m_channel, m_volume);

	return result;
}

FMOD_RESULT cSoundManager::UpdateSound()
{
	return FMOD_System_Update(g_system);
}

FMOD_RESULT cSoundManager::ReleaseSound()
{
	FMOD_RESULT result;
	for (int i = 0; i < m_SoundList.size(); i++)
		result = FMOD_Sound_Release(m_sounds[m_SoundList[i]]);
	

	result = FMOD_System_Close(g_system);

	result = FMOD_System_Release(g_system);
	return result;
}

VOID cSoundManager::AppendSoundList()
{
	m_SoundList.push_back("Alan Walker - Fade");
	return VOID();
}

BOOL cSoundManager::AppendSound(string soundKey, FMOD_SOUND* sound)
{
	auto iter = m_sounds.find(soundKey);

	if (iter == m_sounds.end())		//맵에 해당 키가 없을 때
	{
		m_sounds.insert(make_pair(soundKey, sound));
		return TRUE;
	}
	return FALSE;
}

FMOD_SOUND* cSoundManager::FindSound(string soundKey)
{
	auto iter = m_sounds.find(soundKey);

	if (iter != m_sounds.end())		//맵에 해당 키가 았을 때
	{
		return m_sounds[soundKey];
	}
	return nullptr;
}

FMOD_RESULT cSoundManager::PlaySoundFunc(string soundKey)
{
	return FMOD_System_PlaySound(g_system, m_sounds[soundKey], 0, 0, &m_channel);
}
