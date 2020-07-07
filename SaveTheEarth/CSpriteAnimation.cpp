#include "framework.h"

CSpriteAnimation::CSpriteAnimation()
{
	CurAnimTime = timeGetTime();
	OldAnimTime = 0;
	sequence = 0;
}

CSpriteAnimation::~CSpriteAnimation()
{
}

INT CSpriteAnimation::OnAnimRender(DWORD DelayTime, INT StartFrame, INT EndFrame)
{
	if (CurAnimTime - OldAnimTime > DelayTime)
	{
		sequence++;
		if (sequence == EndFrame)
			sequence = StartFrame;
		OldAnimTime = CurAnimTime;
	}
	else
	{
		CurAnimTime = timeGetTime();
	}
	return sequence;
}
