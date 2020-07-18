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

	D2D1_SIZE_F GetImageSize(const string Key) { 
		if (m_Images->GetSprite(Key) != NULL)
			return m_Images->GetSprite(Key)->GetBmp()->GetSize();
		return D2D1_SIZE_F();
	}
	D2D1_SIZE_F GetMultiImageSize(const string Key, const INT Seqnece) { return m_Images->GetMultiSprite(Key)[Seqnece]->GetBmp()->GetSize(); }
};

