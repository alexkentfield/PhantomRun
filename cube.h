#pragma once
#include "verlet.h"
#include "link.h"
#include "vec2.h"

class Cube
{

public:
	vector<Verlet*> dots;
	vector<Link*> links;


	void create(float x, float y)
	{
		Verlet* squareDot1 = new Verlet(x-25, y-25, 5, 0);
		Verlet* squareDot2 = new Verlet(x-25, y+25, 0, 0);
		Verlet* squareDot3 = new Verlet(x+25, y-25, 0, 0);
		Verlet* squareDot4 = new Verlet(x+25, y+25, 0, 0);

		dots.push_back(squareDot1);
		dots.push_back(squareDot2);
		dots.push_back(squareDot3);
		dots.push_back(squareDot4);
				
		links.push_back(new Link(squareDot1, squareDot2));
		links.push_back(new Link(squareDot1, squareDot3));
		links.push_back(new Link(squareDot2, squareDot4));
		links.push_back(new Link(squareDot2, squareDot3));
		links.push_back(new Link(squareDot1, squareDot4));
		links.push_back(new Link(squareDot3, squareDot4));
	}

	void update()
	{
		for (int i = 0; i < dots.size(); i++)
		{

			dots[i]->update();
		}

		for (int cnt = 0; cnt < 8; cnt++)
		{
			for (int i = 0; i < links.size(); i++)
			{
				links[i]->constrain();
			}
		}

		for (int i = 0; i < dots.size(); i++)
		{
			dots[i]->updatePost();
			dots[i]->draw();
		}
		for (int i = 0; i < links.size(); i++)
		{
			links[i]->draw();
		}
	}
};