#pragma once
class CSpriteAnimation
{
private:
	DWORD CurAnimTime;
	DWORD OldAnimTime;
	INT sequence;

	BOOL EndCheck;
public:
	CSpriteAnimation();
	~CSpriteAnimation();

	void InitSequence() { 
		sequence = 0;
		EndCheck = FALSE;
	};
	BOOL IsEndFrame() {
		return EndCheck;
	}
	INT OnAnimRender(DWORD DelayTime, INT StartFrame, INT EndFrame);
};

