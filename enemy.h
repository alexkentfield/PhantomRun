#pragma once
#include <iostream>
#include "vec2.h"
#include "gameObject.h"
#include "blitz3dsdk.h"
#include "world.h"
#include "player.h"

using namespace std;

class Enemy : public GameObject
{
protected:
	// Placeholder for image
	static BBImage enemyShip;

	// Placeholder for sound
	static BBSound explosionSound;

public:
	Enemy(float x, float y) : GameObject(x, y, 15)
	{
		
	}

	// Update function for this class
	virtual void Update(World* world)
	{
		bbDrawImage(enemyShip, position.x, position.y, 0);
		position.y++;
		spawn(world);
	}

	// Returns true if this object is on the screen
	bool isOnScreen();

	// Queues object for destruction
	bool NeedsDestruction();

	// What happens on collision for this class
	virtual void onCollision(GameObject* other);

	// Initializes image and sound
	static void initializeEnemies();

	// Returns a vector of ships current position
	Vec2 getPosition();

	// Returns the image variable of this class
	virtual BBImage getImage();

	// Returns the type of this class
	virtual GameObjectType type();
};


