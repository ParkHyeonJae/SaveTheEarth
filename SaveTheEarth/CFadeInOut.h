#pragma once
class CFadeInOut
{
private:
	FLOAT overlay;
	FLOAT tTime;
	FLOAT dTime;
	FLOAT dtemp;
	INT BlinkCnt;
	INT tempCnt;
	BOOL EndCheck;
public:
	CFadeInOut(INT BlinkCnt, FLOAT dTime);
	~CFadeInOut();

	INT Initialize();
	FLOAT Blinking();
	BOOL IsFinish();
};

