#pragma once
/*
CSpriteAnimation : 애니메이션 순서를 관리해주는 클래스
*/
class CSpriteAnimation
{
private:
	DWORD CurAnimTime;
	DWORD OldAnimTime;
	INT sequence;

	BOOL EndCheck;
	BOOL IsLoop;
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
	void SetLoop(BOOL IsLoop) { this->IsLoop = IsLoop; }
	INT OnAnimRender(DWORD DelayTime, INT StartFrame, INT EndFrame);
};

