#pragma once
namespace Score
{
	class CScoreManager
	{
	public:
		static FLOAT m_Score;
	public:
		static FLOAT GetScore() { return m_Score; }		//���� Score
		static VOID SetScore(FLOAT Score) { m_Score = Score; }		//Score ����

		static VOID ApplyScore(FLOAT ApplyScore) { m_Score += ApplyScore; }		//Score ����
	};
#define GETSCORE CScoreManager::GetScore()
}

