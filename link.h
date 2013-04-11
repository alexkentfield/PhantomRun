#pragma once
#include "verlet.h"
#include "blitz3dsdk.h"

class Link
{
public:

	Verlet* a;
	Verlet* b;
	float length;

	Link (Verlet* _a, Verlet* _b)
	{
		a = _a;
		b = _b;

		Vec2 difference(a->position.x - b->position.x, a->position.y - b->position.y);
		length = difference.length();
	}

	void draw()
	{
		bbColor(255,255,255);
		bbLine(a->position.x, 599 - a->position.y, b->position.x, 599 - b->position.y);


			//bbLine((int)start.x, 599 - (int)start.y, (int)end.x, 599 - (int)end.y);
	}

	void constrain()
	{
		Vec2 difference(b->position.x - a->position.x, b->position.y - a->position.y);
		float currentLength = difference.length();

		float multiplier = length / currentLength;
		difference.scale(multiplier);
		

		Vec2 center((a->position.x + b->position.x) / 2, (a->position.y + b->position.y) / 2);
		//bbColor(0,0,255);
		//bbPlot(center.x, 599 - center.y);
		Vec2 newB(center.x + difference.x * 0.5, center.y + difference.y * 0.5);
		Vec2 newA(center.x - difference.x * 0.5, center.y - difference.y * 0.5);

		if (newA.y < 50)
		{
			newA.y = 50;
		}
		if (newB.y < 50)
		{
			newB.y = 50;
		}
		a->position = newA;
		b->position = newB;

		//bbColor(255,0,0);
		//bbPlot(newA.x, 599 - newA.y);
		//bbPlot(newB.x, 599 - newB.y);


	}

};
