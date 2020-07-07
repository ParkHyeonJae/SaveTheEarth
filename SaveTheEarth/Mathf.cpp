#include "framework.h"

FLOAT Mathf::Lerp(FLOAT a, FLOAT b, FLOAT t)
{
	return a + ((b - a) * t);
}

INT Mathf::RandomIntValue(INT start, INT End)
{
	return (rand() % End) + start;
}
