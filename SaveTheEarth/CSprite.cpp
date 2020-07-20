#include "framework.h"


CSprite::CSprite(LPCWSTR filename, CGraphics* gfx, int sprWidth, int sprHeight)
{
	this->m_gfx = gfx;
	m_bmp = NULL;
	HRESULT res;
	IWICImagingFactory* wicFactory = NULL;
	res = CoCreateInstance(
		CLSID_WICImagingFactory,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IWICImagingFactory,
		(LPVOID*)&wicFactory

	);

	IWICBitmapDecoder* wicDecoder = NULL;
	res = wicFactory->CreateDecoderFromFilename(
		filename,
		NULL,
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad,
		&wicDecoder
	);

	IWICBitmapFrameDecode* wicFrame = NULL;
	res = wicDecoder->GetFrame(0, &wicFrame);

	IWICFormatConverter* wicConverter = NULL;
	res = wicFactory->CreateFormatConverter(&wicConverter);


	res = wicConverter->Initialize(
		wicFrame,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		NULL,
		0.0f,
		WICBitmapPaletteTypeCustom
	);

	res = gfx->GetRenderTarget()->CreateBitmapFromWicBitmap(
		wicConverter,
		NULL,
		&m_bmp
	);

	m_imageWidth = (int)m_bmp->GetSize().width;
	m_imageHeight = (int)m_bmp->GetSize().height;


	if (sprWidth) {
		m_sprWidth = m_imageWidth;
		m_sprHeight = m_imageHeight;
	}
	else {
		m_sprWidth = sprWidth;
		m_sprHeight = sprHeight;
	}

	if (wicFactory)
		wicFactory->Release();
	if (wicDecoder)
		wicDecoder->Release();
	if (wicConverter)
		wicConverter->Release();
	if (wicFrame)
		wicFrame->Release();
}

CSprite::~CSprite()
{
}


void CSprite::Draw()
{
	m_gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());

	m_gfx->GetRenderTarget()->DrawBitmap(
		m_bmp,
		D2D1::RectF(0.0f, 0.0f,
			m_bmp->GetSize().width, m_bmp->GetSize().height),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		D2D1::RectF(0.0f, 0.0f,
			m_bmp->GetSize().width, m_bmp->GetSize().height)
	);

}

void CSprite::Draw(D2D1_POINT_2F Pos)
{
	m_gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());

	m_gfx->GetRenderTarget()->DrawBitmap(
		m_bmp,
		D2D1::RectF(Pos.x, Pos.y,
			Pos.x + m_bmp->GetSize().width, Pos.y + m_bmp->GetSize().height),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		D2D1::RectF(0.0f, 0.0f,
			m_bmp->GetSize().width, m_bmp->GetSize().height)
	);
}

void CSprite::Draw(D2D1_POINT_2F Pos, FLOAT overlay)
{
	m_gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());

	m_gfx->GetRenderTarget()->DrawBitmap(
		m_bmp,
		D2D1::RectF(Pos.x, Pos.y,
			Pos.x + m_bmp->GetSize().width, Pos.y + m_bmp->GetSize().height),
		overlay,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		D2D1::RectF(0.0f, 0.0f,
			m_bmp->GetSize().width, m_bmp->GetSize().height)
	);
}

void CSprite::Draw(D2D1_POINT_2F Pos, D2D1_RECT_F* src)
{
	m_gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());


	m_gfx->GetRenderTarget()->DrawBitmap(
		m_bmp,
		D2D1::RectF(Pos.x + src->left, Pos.y + src->top,
			Pos.x + m_bmp->GetSize().width + src->right, Pos.y + m_bmp->GetSize().height + src->bottom),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(0 + src->left, 0 + src->top,
			m_bmp->GetSize().width + src->right, m_bmp->GetSize().height + src->bottom)
	);
	m_gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
}


void CSprite::Draw(D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center)
{
	if (center == NULL) {
		D2D1_POINT_2F ct = { (Pos.x + m_bmp->GetSize().width / 2) , (Pos.y + m_bmp->GetSize().height / 2) };
		center = &ct;
	}
	m_gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Scale(Scale,*center));

	m_gfx->GetRenderTarget()->DrawBitmap(
		m_bmp,
		D2D1::RectF(Pos.x, Pos.y,
			Pos.x + m_bmp->GetSize().width, Pos.y + m_bmp->GetSize().height),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		D2D1::RectF(0.0f, 0.0f,
			m_bmp->GetSize().width, m_bmp->GetSize().height)
	);
	m_gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
}

void CSprite::Draw(D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center, float angle)
{
	if (center == NULL) {
		D2D1_POINT_2F ct = { (Pos.x + m_bmp->GetSize().width / 2) , (Pos.y + m_bmp->GetSize().height / 2) };
		center = &ct;
	}
	D2D1_MATRIX_3X2_F Mat_Rot = D2D1::Matrix3x2F::Rotation(angle, *center);
	D2D1_MATRIX_3X2_F Mat_Scale = D2D1::Matrix3x2F::Scale(Scale, *center);

	D2D1_MATRIX_3X2_F Matrix = Mat_Scale * Mat_Rot;
	m_gfx->GetRenderTarget()->SetTransform(Matrix);

	m_gfx->GetRenderTarget()->DrawBitmap(
		m_bmp,
		D2D1::RectF(Pos.x, Pos.y,
			Pos.x + m_bmp->GetSize().width, Pos.y + m_bmp->GetSize().height),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		D2D1::RectF(0.0f, 0.0f,
			m_bmp->GetSize().width, m_bmp->GetSize().height)
	);

	m_gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
}

void CSprite::MaskDraw(D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center, float angle, OpacityBrush BrushType)
{
	m_gfx->GetRenderTarget()->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED);

	m_gfx->GetRenderTarget()->FillOpacityMask(
		m_bmp,
		CGameManager::m_Gfx->GetSolidColorBrush(BrushType),
		D2D1_OPACITY_MASK_CONTENT_GRAPHICS,
		D2D1::RectF(Pos.x, Pos.y,
			Pos.x + m_bmp->GetSize().width, Pos.y + m_bmp->GetSize().height),
		D2D1::RectF(0.0f, 0.0f,
			m_bmp->GetSize().width, m_bmp->GetSize().height)
	);

	m_gfx->GetRenderTarget()->SetAntialiasMode(D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
}

void CSprite::MaskDraw(D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center, float angle, float overlay, D2D1_COLOR_F color, OpacityBrush BrushType)
{
	m_gfx->GetRenderTarget()->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED);
	D2D1_BRUSH_PROPERTIES property = { overlay , D2D1::Matrix3x2F::Identity() };
	ID2D1SolidColorBrush* brush = CGameManager::m_Gfx->GetSolidColorBrush((INT)BrushType);
	CGameManager::m_Gfx->GetRenderTarget()->CreateSolidColorBrush(color, property, &brush);
	m_gfx->GetRenderTarget()->FillOpacityMask(
		m_bmp,
		brush,
		D2D1_OPACITY_MASK_CONTENT_GRAPHICS,
		D2D1::RectF(Pos.x, Pos.y,
			Pos.x + m_bmp->GetSize().width, Pos.y + m_bmp->GetSize().height),
		D2D1::RectF(0.0f, 0.0f,
			m_bmp->GetSize().width, m_bmp->GetSize().height)
	);

	m_gfx->GetRenderTarget()->SetAntialiasMode(D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
}

void CSprite::Draw(D2D1_POINT_2F Pos, D2D1_SIZE_F Scale, D2D1_POINT_2F* center, float angle, float overlay)
{
	if (center == NULL) {
		D2D1_POINT_2F ct = { (Pos.x + m_bmp->GetSize().width / 2) , (Pos.y + m_bmp->GetSize().height / 2) };
		center = &ct;
	}
	D2D1_MATRIX_3X2_F Mat_Rot = D2D1::Matrix3x2F::Rotation(angle, *center);
	D2D1_MATRIX_3X2_F Mat_Scale = D2D1::Matrix3x2F::Scale(Scale, *center);

	D2D1_MATRIX_3X2_F Matrix = Mat_Scale * Mat_Rot;
	m_gfx->GetRenderTarget()->SetTransform(Matrix);

	m_gfx->GetRenderTarget()->DrawBitmap(
		m_bmp,
		D2D1::RectF(Pos.x, Pos.y,
			Pos.x + m_bmp->GetSize().width, Pos.y + m_bmp->GetSize().height),
		overlay,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		D2D1::RectF(0.0f, 0.0f,
			m_bmp->GetSize().width, m_bmp->GetSize().height)
	);

	m_gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
}

void CSprite::Draw(D2D1_RECT_F* src, D2D1_POINT_2F pos, D2D1_POINT_2F Scale, D2D1_POINT_2F* center, float angle)
{
	if (center == NULL) {
		D2D1_POINT_2F ct = { (pos.x + m_bmp->GetSize().width / 2) , (pos.y + m_bmp->GetSize().height / 2) };
		center = &ct;
	}
	m_gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());

	D2D1_RECT_F dest = D2D1::RectF(
		pos.x,
		pos.y,
		pos.x + m_sprWidth * Scale.x,
		pos.y + m_sprHeight * Scale.y
	);

	if (center != NULL)
		m_gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Rotation(angle, *center));

	m_gfx->GetRenderTarget()->DrawBitmap(
		m_bmp,
		dest,
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		src
	);
}
