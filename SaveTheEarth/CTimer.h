#pragma once
/*
타이머 클래스
*/
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

	BOOL CoolTimer();
	VOID InitCool();

	VOID LoopCheck(BOOL IsLoop) { this->IsLoop = IsLoop; }
	DWORD GetDestTime() { return DestTime; }
	VOID SetTimer(DWORD DestTime) { this->DestTime = DestTime; }
	BOOL OnTimer();
};

