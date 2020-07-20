#include "framework.h"

CTimer::CTimer(DWORD DestTime)
{
	CurTime = timeGetTime();
	OldTime = timeGetTime();
	this->DestTime = DestTime;
	IsLoop = TRUE;
	IsOnce = FALSE;
}

CTimer::~CTimer()
{
}

BOOL CTimer::OnTimer()		//Please Put Update or Render Function
{
	if (IsOnce)
		return FALSE;
	if (CurTime - OldTime > DestTime)
	{
		OldTime = CurTime;
		if (!IsLoop)
			IsOnce = TRUE;
		return TRUE;
	}
	else {
		CurTime = timeGetTime();
	}
	return FALSE;
}
