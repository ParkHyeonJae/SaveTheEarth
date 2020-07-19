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
	if (iter != m_images.end())
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
	if (iter != m_multiImages.end())
		return TRUE;
	return FALSE;
}

BOOL Cimage::MultiRender(string key, INT sequence, D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center, float angle)
{
	for (auto m : m_multiImages)
	{
		if (m.first == key)
			m.second[sequence]->Draw(Pos, Scale, center, angle);
	}
	return 0;
}

BOOL Cimage::MultiRender(string key, INT sequence, D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center, float angle, float overlay)
{
	for (auto m : m_multiImages)
	{
		if (m.first == key)
			m.second[sequence]->Draw(Pos, Scale, center, angle, overlay);
	}
	return 0;
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

BOOL Cimage::Render(string key, D2D1_POINT_2F Pos, FLOAT overlay)
{
	for (auto m : m_images)
	{
		if (m.first == key)
			m.second->Draw(Pos, overlay);
	}
	return 0;
}

BOOL Cimage::Render(string key, D2D1_POINT_2F Pos, D2D1_RECT_F* src)
{
	for (auto m : m_images)
	{
		if (m.first == key)
			m.second->Draw(Pos, src);
	}
	return 0;
}

BOOL Cimage::Render(string key, D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center)
{
	for (auto m : m_images)
	{
		if (m.first == key)
			m.second->Draw(Pos, Scale, center, 0.0f);
	}
	return 0;
}

BOOL Cimage::Render(string key, D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center, float angle)
{
	for (auto m : m_images)
	{
		if (m.first == key)
			m.second->Draw(Pos, Scale, center, angle);
	}
	return 0;
}

BOOL Cimage::Render(string key, D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center, float angle, float overlay)
{
	for (auto m : m_images)
	{
		if (m.first == key)
			m.second->Draw(Pos, Scale, center, angle, overlay);
	}
	return 0;
}

BOOL Cimage::Render(string key, D2D1_RECT_F* src, D2D1_POINT_2F pos, D2D1_POINT_2F Scale, D2D1_POINT_2F* center, float angle)
{
	for (auto m : m_images)
	{
		if (m.first == key)
			m.second->Draw(src, pos, Scale, center, angle);
	}
	return 0;
}

CSprite* Cimage::GetSprite(const string& Key)
{
	if (FindImage(Key)) {
		return m_images.find(Key)->second;
	}
	return NULL;
}

vector<CSprite*> Cimage::GetMultiSprite(const string& Key)
{
	if (FindMultiImage(Key))
	{
		return m_multiImages.find(Key)->second;
	}
	return vector<CSprite*>();
}

CSprite* Cimage::GetMultiSprite(const string& Key, INT Sequence)
{
	if (FindMultiImage(Key))
	{
		return m_multiImages.find(Key)->second[Sequence];
	}
	return NULL;
}

