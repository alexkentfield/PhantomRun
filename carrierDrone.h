#pragma once
#include <iostream>
#include "world.h"
#include "gameObject.h"
#include "blitz3dsdk.h"
#include "vec2.h"
#include "query.h"

using namespace std;

class CarrierDrone : public GameObject
{
private:
	// Velocity is the ships next position towards its target
	Vec2 velocity;

	// Placeholder for image
	static BBImage carrierDrone;

	// Placeholder for sound
	static BBSound explosionSound;

public:
	CarrierDrone(float x, float y) : GameObject(x, y, 25)
	{
		
	}

	// Initializes image and sound
	static void initializeCarrierDrone();

	// Update function for this class
	virtual void Update(World* world);

	// What happens on collision for this class
	virtual void onCollision(GameObject* other);

	// Returns the type of this class
	virtual GameObjectType type();

	// Returns true if this object is on screen
	bool isOnScreen();

	// Queues this object for destruction
	bool NeedsDestruction();

	// Returns the image variable of this class
	virtual BBImage getImage();
};

