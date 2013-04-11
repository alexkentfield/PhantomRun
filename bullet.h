#pragma once
#include <iostream>
#include "gameObject.h"
#include "world.h"
#include "blitz3dsdk.h"
#include "query.h"

using namespace std;

class Bullet : public GameObject
{
private:
	// Holds offset value to shoot diagonally
	float shotOffset;

	// Placeholder for image
	static BBImage bullet;
	
public:
	// Constructor
	Bullet(float x, float y, float offset) : GameObject(x, y, 15)
	{
		shotOffset = offset;
	}

	// Update function for this class
	virtual void Update(World* world);

	// What happens on collision for this class 
	virtual void onCollision(GameObject* other);

	// Returns true if this object is on screen
	bool isOnScreen();

	// Initializes image and sound
	static void initializeBullets();

	// Queues this object for destruction
	virtual bool NeedsDestruction();

	// Returns the type of this class
	virtual GameObjectType type();

	// Returns the image variable of this class
	virtual BBImage getImage();

};

