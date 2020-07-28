#include "framework.h"

FLOAT Mathf::Radian = 180 / PI;
FLOAT Mathf::Lerp(FLOAT a, FLOAT b, FLOAT t)
{
	return a + ((b - a) * t);
}

//Ȯ�� ���ϴ� �Լ�(prob : 0 ~ 10)
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


Vector2 Mathf::PointOnCubicBezier(Vector2* cp, float t)
{
    float ax, bx, cx;
    float ay, by, cy;
    float tSquared, tCubed;
    Vector2 result;

    /* ���׽� ����� ����Ѵ� */
    cx = 3.0 * (cp[1].x - cp[0].x);
    bx = 3.0 * (cp[2].x - cp[1].x) - cx;
    ax = cp[3].x - cp[0].x - cx - bx;

    cy = 3.0 * (cp[1].y - cp[0].y);
    by = 3.0 * (cp[2].y - cp[1].y) - cy;
    ay = cp[3].y - cp[0].y - cy - by;

    /* �Ű����� �� t���� � ���� ����Ѵ� */
    tSquared = t * t;
    tCubed = tSquared * t;

    result.x = (ax * tCubed) + (bx * tSquared) + (cx * t) +
        cp[0].x;
    result.y = (ay * tCubed) + (by * tSquared) + (cy * t) +
        cp[0].y;

    return result;
}
