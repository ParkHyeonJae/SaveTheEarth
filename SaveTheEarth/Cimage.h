#pragma once

class Cimage
{
private:
	map<string, CSprite*> m_images;
	map<string, vector<CSprite*>> m_multiImages;
public:

	BOOL AddImage(string key,CSprite* sprite);
	BOOL FindImage(string key);


	BOOL AddMultiImage(string key, vector<CSprite*> sprite);
	BOOL FindMultiImage(string key);

	BOOL MultiRender(string key, INT sequence, D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center, float angle);
	BOOL MultiRender(string key, INT sequence, D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center, float angle, float overlay);
	BOOL Render(string key);
	BOOL Render(string key, D2D1_POINT_2F Pos, FLOAT overlay);
	BOOL Render(string key, D2D1_POINT_2F Pos, D2D1_RECT_F* src);
	BOOL Render(string key, D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center);
	BOOL Render(string key, D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center, float angle);
	BOOL Render(string key, D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center, float angle, float overlay);
	BOOL Render(string key, D2D1_RECT_F* src, D2D1_POINT_2F pos, D2D1_POINT_2F Scale, D2D1_POINT_2F* center, float angle);

	CSprite* GetSprite(const string& Key);
	vector<CSprite*> GetMultiSprite(const string& Key);
	CSprite* GetMultiSprite(const string& Key, INT Sequence);
};

