#include "framework.h"

CTimer::CTimer(DWORD DestTime)
{
	CurTime = timeGetTime();
	OldTime = timeGetTime();
	this->DestTime = DestTime;
}

CTimer::~CTimer()
{
}

BOOL CTimer::OnTimer()		//Please Put Update or Render Function
{
	if (CurTime - OldTime > DestTime)
	{
		OldTime = CurTime;
		return TRUE;
	}
	else {
		CurTime = timeGetTime();
		return FALSE;
	}
	
}
