#include "framework.h"

FLOAT Mathf::Radian = 180 / PI;
FLOAT Mathf::Lerp(FLOAT a, FLOAT b, FLOAT t)
{
	return a + ((b - a) * t);
}

//확률 구하는 함수(prob : 0 ~ 10)
BOOL Mathf::Probability(INT prob)
{
	if (rand() % 100 <= prob)
		return TRUE;
	return FALSE;
}

INT Mathf::RandomIntValue(INT start, INT End)
{
	return (rand() % End) + start;
}
