#pragma once
/*
���а��� Ŭ����
*/
class Mathf
{
public:
	static FLOAT Lerp(FLOAT a, FLOAT b, FLOAT t);
	static BOOL Probability(INT prob);
	static INT RandomIntValue(INT start, INT End);
	static FLOAT Radian;
	static Vector2 PointOnCubicBezier(Vector2* cp, float t);

};

