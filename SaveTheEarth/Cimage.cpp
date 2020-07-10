#include "framework.h"

BOOL Cimage::AddImage(string key, CSprite* sprite)
{
	auto iter = m_images.find(key);

	if (iter == m_images.end())		//맵에 해당 키가 없을 때
	{
		m_images.insert(make_pair(key, sprite));
		return TRUE;
	}
	
	return FALSE;
	
}

BOOL Cimage::FindImage(string key)
{
	auto iter = m_images.find(key);
	if (iter == m_images.end())
		return TRUE;
	return FALSE;
}

BOOL Cimage::AddMultiImage(string key, vector<CSprite*> sprite)
{
	auto iter = m_multiImages.find(key);

	if (iter == m_multiImages.end())		//맵에 해당 키가 없을 때
	{
		m_multiImages.insert(make_pair(key, sprite));
		return TRUE;
	}
	return FALSE;
}

BOOL Cimage::FindMultiImage(string key)
{
	auto iter = m_multiImages.find(key);
	if (iter == m_multiImages.end())
		return TRUE;
	return FALSE;
}

BOOL Cimage::Render(string key)
{
	for (auto m : m_images)
	{
		if (m.first == key)
			m.second->Draw();
	}
	return 0;
}

