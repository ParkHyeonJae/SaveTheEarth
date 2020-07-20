#pragma once
namespace Score
{
	class CScoreManager
	{
	public:
		static FLOAT m_Score;
	public:
		static FLOAT GetScore() { return m_Score; }		//현재 Score
		static VOID SetScore(FLOAT Score) { m_Score = Score; }		//Score 적용

		static VOID ApplyScore(FLOAT ApplyScore) { m_Score += ApplyScore; }		//Score 증가
	};
#define GETSCORE CScoreManager::GetScore()
}

