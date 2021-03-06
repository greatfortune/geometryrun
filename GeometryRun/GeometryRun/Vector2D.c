/**
 * Project:		GeometryRun
 * File Name:	Vector2D.c
 * Author:		王晶，黄涧水（补充Vector2DAngle）
 * Date:		2017-4-22
 * Purpose:		Vector2D.c
 */


#include "Vector2D.h"

#define EPSILON 0.0001
#define PI      3.1415926535897932384626433832795

// ---------------------------------------------------------------------------
/*
将2维向量pResult的两个坐标值设置为0
*/
void Vector2DZero(Vector2D *pResult)
{
	pResult->x = 0.0f;
	pResult->y = 0.0f;
}

// ---------------------------------------------------------------------------
/*
分别将2维向量pResult的两个值设置为x和y
*/
void Vector2DSet(Vector2D *pResult, float x, float y)
{
	pResult->x = x;
	pResult->y = y;
}

// ---------------------------------------------------------------------------
/*
pResult设置为pVec0的反方向
*/
void Vector2DNeg(Vector2D *pResult, Vector2D *pVec0)
{
	pResult->x = pVec0->x * -1;
	pResult->y = pVec0->y * -1;
}

// ---------------------------------------------------------------------------
/*
pResult = pVec0 + pVec1
*/
void Vector2DAdd(Vector2D *pResult, Vector2D *pVec0, Vector2D *pVec1)
{
	pResult->x = pVec0->x + pVec1->x;
	pResult->y = pVec0->y + pVec1->y;
}

// ---------------------------------------------------------------------------
/*
pResult = pVec0 - pVec1
*/
void Vector2DSub(Vector2D *pResult, Vector2D *pVec0, Vector2D *pVec1)
{
	pResult->x = pVec0->x - pVec1->x;
	pResult->y = pVec0->y - pVec1->y;
}

// ---------------------------------------------------------------------------
/*
pResult设置为向量pVec0的单位向量
*/
void Vector2DNormalize(Vector2D *pResult, Vector2D *pVec0)
{
	float length = sqrtf(pVec0->x * pVec0->x + pVec0->y * pVec0->y);
	if (length <= EPSILON)
	{
		pResult->x = pResult->y = 0;
	}
	else
	{
		pResult->x = pVec0->x / length;
		pResult->y = pVec0->y / length;
	}
}

// ---------------------------------------------------------------------------
/*
pResult设置为向量pVec0缩放c倍的结果
*/
void Vector2DScale(Vector2D *pResult, Vector2D *pVec0, float c)
{
	pResult->x = pVec0->x * c;
	pResult->y = pVec0->y * c;
}

// ---------------------------------------------------------------------------
/*
pResult = 向量pVec0缩放c倍 + pVec1
*/
void Vector2DScaleAdd(Vector2D *pResult, Vector2D *pVec0, Vector2D *pVec1, float c)
{
	pResult->x = pVec0->x * c + pVec1->x;
	pResult->y = pVec0->y * c + pVec1->y;
}

// ---------------------------------------------------------------------------
/*
pResult = 向量pVec0缩放c倍 - pVec1
*/
void Vector2DScaleSub(Vector2D *pResult, Vector2D *pVec0, Vector2D *pVec1, float c)
{
	pResult->x = pVec0->x * c - pVec1->x;
	pResult->y = pVec0->y * c - pVec1->y;
}

// ---------------------------------------------------------------------------
/*
计算向量pVec0的长度
*/
float Vector2DLength(Vector2D *pVec0)
{
	return sqrtf(pVec0->x * pVec0->x + pVec0->y * pVec0->y);
}

// ---------------------------------------------------------------------------
/*
计算向量pVec0长度的平方，避免平方根运算
*/
float Vector2DSquareLength(Vector2D *pVec0)
{
	return pVec0->x * pVec0->x + pVec0->y * pVec0->y;
}

// ---------------------------------------------------------------------------
/*
pVec0和pVec1是2维空间的两个点，计算这两个点的距离
*/
float Vector2DDistance(Vector2D *pVec0, Vector2D *pVec1)
{
	float dx = pVec0->x - pVec1->x;
	float dy = pVec0->y - pVec1->y;
	return sqrtf(dx * dx + dy * dy);
}

// ---------------------------------------------------------------------------
/*
pVec0和pVec1是2维空间的两个点，计算这两个点的距离的平方，避免平方根运算
*/
float Vector2DSquareDistance(Vector2D *pVec0, Vector2D *pVec1)
{
	float dx = pVec0->x - pVec1->x;
	float dy = pVec0->y - pVec1->y;
	return dx * dx + dy * dy;
}

// ---------------------------------------------------------------------------
/*
计算pVec0和pVec1的点积
*/
float Vector2DDotProduct(Vector2D *pVec0, Vector2D *pVec1)
{
	return pVec0->x * pVec1->x + pVec0->y * pVec1->y;
}

// ---------------------------------------------------------------------------
/*
极坐标到直角坐标下单位向量的转换，angle为度数，如30度
*/
void Vector2DFromAngleDeg(Vector2D *pResult, float angle)
{
	pResult->x = 1.0f * cosf(angle * PI / 180);
	pResult->y = 1.0f * sinf(angle * PI / 180);
}

// ---------------------------------------------------------------------------
/*
极坐标到直角坐标下单位向量的转换，angle为弧度
*/
void Vector2DFromAngleRad(Vector2D *pResult, float angle)
{
	pResult->x = 1.0f * cosf(angle);
	pResult->y = 1.0f * sinf(angle);
}

// ---------------------------------------------------------------------------
/*
计算两个点之间的角度，第一个点作为原点，单位为角度数
*/
float Vector2DAngle(Vector2D *pVec0, Vector2D *pVec1)
{
	float dx = pVec1->x - pVec0->x;
	float dy = pVec1->y - pVec0->y;
	if (dx == 0)
	{
		if (dy > 0)
			return 90;
		else if (dy == 0)
			return 0;
		else
			return -90;
	}
	else if (dx > 0)
		return atanf(dy / dx) * 180 / PI;
	else
		return atanf(dy / dx) * 180 / PI + 180;
}

// ---------------------------------------------------------------------------