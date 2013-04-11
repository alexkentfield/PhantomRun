#pragma once
#include <iostream>
#include "world.h"
#include "gameObject.h"

class Query 
{
private:
	World* m_world;

	// Holds the results of the current query
	GameObjectVector m_results;

public:
	// Constructor
	Query(World* world)
	{
		m_world = world;
	}

	// Select specific types of game objects
	Query& select(GameObjectType types[]);

	// Return results of the query
	GameObjectVector getResults();

	// Whether or not the specific object is located in a target rectangle
	Query& inRect(float left, float right, float top, float bottom);

	// Return nearest game object
	GameObject* nearest(Vec2 position);
};