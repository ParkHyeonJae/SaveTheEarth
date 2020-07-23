#include "framework.h"
#include "CFadeInOut.h"

CFadeInOut::CFadeInOut(INT BlinkCnt, FLOAT dTime)
{
	this->BlinkCnt = tempCnt = BlinkCnt;
	this->dTime = dtemp = dTime;
	tTime = 0.0f;
	overlay = 1.0f;
	EndCheck = FALSE;
}

CFadeInOut::~CFadeInOut()
{
}

INT CFadeInOut::Initialize()
{
	tTime = 0.0f;
	overlay = 1.0f;
	EndCheck = FALSE;
	BlinkCnt = tempCnt;
	dTime = dtemp;
	return 0;
}

FLOAT CFadeInOut::Blinking()
{
	if (BlinkCnt >= 0)
	{
		overlay = Mathf::Lerp(0.0f, 1.0f, tTime);
		
		if (tTime + dTime > 1.0f || tTime + dTime < 0.0f) {
			BlinkCnt--;
			dTime *= -1;
		}
		tTime += dTime;
		return overlay;
	}
	else {
		EndCheck = TRUE;
	}
	
	return overlay;
}

BOOL CFadeInOut::IsFinish()
{
	return EndCheck;
}
