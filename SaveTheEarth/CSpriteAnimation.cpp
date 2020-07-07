#include "framework.h"

CSpriteAnimation::CSpriteAnimation()
{
	CurAnimTime = timeGetTime();
	OldAnimTime = 0;
	sequence = 0;
	EndCheck = FALSE;
}

CSpriteAnimation::~CSpriteAnimation()
{
}

INT CSpriteAnimation::OnAnimRender(DWORD DelayTime, INT StartFrame, INT EndFrame)
{
	if (CurAnimTime - OldAnimTime > DelayTime)
	{
		sequence++;
		if (sequence == EndFrame) {
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
