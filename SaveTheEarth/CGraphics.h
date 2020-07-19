#pragma once
class CGraphics
{
	ID2D1Factory* m_factory;
	ID2D1HwndRenderTarget* m_renderTarget;

	IDWriteFactory* m_writeFactory;
	ID2D1SolidColorBrush* m_Redbrush;
	ID2D1SolidColorBrush* m_Blackbrush;
	ID2D1SolidColorBrush* m_Whitebrush;
	IDWriteTextFormat* m_format;

public:
	CGraphics();
	~CGraphics();

	inline ID2D1HwndRenderTarget* GetRenderTarget() { return m_renderTarget; }
	INT Init(HWND hWnd, RECT rcWin);
	void CleanUp();

	void BeginDraw() { m_renderTarget->BeginDraw(); }
	void EndDraw() { m_renderTarget->EndDraw(); }
	void ClearScreen(float r, float g, float b, float a);
	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a);

	void DrawTextOut(LPCWSTR text, D2D1_POINT_2F Pos);

	ID2D1SolidColorBrush* GetSolidColorBrush(INT n) { switch (n) { 
	case 0: return m_Redbrush;
	case 1: return m_Blackbrush;
	case 2: return m_Whitebrush;
	} }
};

