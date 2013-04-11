#pragma once
#include "vec2.h"
#include "blitz3dsdk.h"


class Verlet
{
public:
	Vec2 position;
	Vec2 velocity;
	Vec2 prevPosition;

	Verlet(float x, float y, float vx, float vy) : position(x, y), velocity(vx, vy), prevPosition(x, y)
	{

	}

	void draw()
	{
		bbColor(255,255,255);
		bbPlot(position.x, 599 - position.y);
	}

	void update()
	{
		velocity.y -= 0.05f;
		position.y += velocity.y;
		position.x += velocity.x;
		if (position.y < 50)
		{
			position.y = 50;
			velocity.y *= -0.5;
			velocity.x *= 0.5;
		}
		prevPosition = position;
		
	}

	void updatePost()
	{
		Vec2 addedVelocity(position.x - prevPosition.x, position.y - prevPosition.y);
		velocity.x += addedVelocity.x; 
		velocity.y += addedVelocity.y; 
	}


};