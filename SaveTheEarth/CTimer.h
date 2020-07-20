#pragma once
class CTimer
{
private:
	DWORD CurTime;
	DWORD OldTime;
	DWORD DestTime;
	BOOL IsLoop;
	BOOL IsOnce;
public:
	CTimer(DWORD DestTime);
	~CTimer();
	VOID LoopCheck(BOOL IsLoop) { this->IsLoop = IsLoop; }
	BOOL OnTimer();
};

