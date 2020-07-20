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
	DWORD GetDestTime() { return DestTime; }
	VOID SetTimer(FLOAT DestTime) { this->DestTime = DestTime; }
	BOOL OnTimer();
};

