#include "framework.h"

CSpriteAnimation::CSpriteAnimation()
{
	CurAnimTime = timeGetTime();
	OldAnimTime = 0;
	sequence = 0;
	EndCheck = FALSE;
	IsLoop = TRUE;
}

CSpriteAnimation::~CSpriteAnimation()
{
}

INT CSpriteAnimation::OnAnimRender(DWORD DelayTime, INT StartFrame, INT EndFrame)
{
	if (CurAnimTime - OldAnimTime > DelayTime)
	{
		if (EndCheck && !IsLoop) return sequence;
		else sequence++;
		if (sequence == EndFrame) {
			if (IsLoop)
				sequence = StartFrame;
			EndCheck = TRUE;
		}
		OldAnimTime = CurAnimTime;
	}
	else
	{
		EndCheck = FALSE;
		CurAnimTime = timeGetTime();
	}
	return sequence;
}
