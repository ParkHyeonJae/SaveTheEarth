#include "framework.h"

CGraphics::CGraphics()
{
	m_factory = NULL;
	m_renderTarget = NULL;
	m_Redbrush = NULL;
}

CGraphics::~CGraphics()
{
}

INT CGraphics::Init(HWND hWnd, RECT rcWin)
{
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_factory);
	if (res != S_OK) return -1;

	res = m_factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
			hWnd, D2D1::SizeU(rcWin.right - rcWin.left, rcWin.bottom - rcWin.top)),
		&m_renderTarget);
	if (res != S_OK) return -1;

	res = m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red), &m_Redbrush);
	res = m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &m_Blackbrush);
	res = m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &m_Whitebrush);

	res = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&m_writeFactory));

	m_writeFactory->CreateTextFormat(
		L"Comic Sans MS",
		NULL,
		DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		30.0f, // font size
		L"", //locale
		&m_format);
	return 0;
}

void CGraphics::CleanUp()
{
	if (m_format)
		m_format->Release();
	if (m_Redbrush)
		m_Redbrush->Release();
	if (m_Whitebrush)
		m_Whitebrush->Release();
	if (m_Blackbrush)
		m_Blackbrush->Release();
	if (m_renderTarget)
		m_renderTarget->Release();
	if (m_writeFactory)
		m_writeFactory->Release();
	if (m_factory)
		m_factory->Release();
}

void CGraphics::ClearScreen(float r, float g, float b, float a)
{
	m_renderTarget->Clear(D2D1::ColorF(r, g, b, a));
}

void CGraphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a)
{
	m_Redbrush->SetColor(D2D1::ColorF(r, g, b, a));
	m_renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius),
		m_Redbrush, 3.0f);
}

void CGraphics::DrawTextOut(LPCWSTR text, D2D1_POINT_2F Pos)
{
	m_renderTarget->DrawTextW(text, lstrlen(text), m_format, D2D1::RectF(Pos.x, Pos.y, MAX_WIN_WIDTH, MAX_WIN_HEIGHT), m_Whitebrush);
}
