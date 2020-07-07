#pragma once
class CTimer
{
private:
	DWORD CurTime;
	DWORD OldTime;
	DWORD DestTime;
public:
	CTimer(DWORD DestTime);
	~CTimer();

	BOOL OnTimer();
};

