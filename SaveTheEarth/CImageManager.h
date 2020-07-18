#pragma once
class CImageManager
{
private:
	Cimage* m_Images;
public:
	CImageManager();
	~CImageManager();

	INT ImageInit();

	Cimage* GetImages() { return m_Images; }
};

