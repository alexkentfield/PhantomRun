#pragma once
#include <math.h>

class Vec2
{
public:
	float x, y;

	Vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}
	Vec2 operator+ (Vec2 param)
	{
		Vec2 temp;
		temp.x = x + param.x;
		temp.y = y + param.y;
		return (temp);
	}

	Vec2 operator- (Vec2 param)
	{
		Vec2 temp;
		temp.x = x - param.x;
		temp.y = y - param.y;
		return (temp);
	}

	Vec2& operator-= (Vec2 param)
	{
		x -= param.x;
		y -= param.y;
		return (*this);
	}

	Vec2& operator+= (Vec2 param)
	{
		x += param.x;
		y += param.y;
		return (*this);
	}

	float length()
	{
		return sqrtf(x * x + y * y);
	}

	void scale(float s)
	{
		x*= s;
		y*= s;
	}

	Vec2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	void normalize()
	{
		float l = length();
		x = x / l;
		y = y / l;
	}

};


