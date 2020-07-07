#pragma once
class CSpriteAnimation
{
private:
	DWORD CurAnimTime;
	DWORD OldAnimTime;
	INT sequence;
public:
	CSpriteAnimation();
	~CSpriteAnimation();

	INT OnAnimRender(DWORD DelayTime, INT StartFrame, INT EndFrame);
};

