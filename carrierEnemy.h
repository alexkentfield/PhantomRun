#pragma once
#include <iostream>
#include "world.h"
#include "blitz3dsdk.h"
#include "vec2.h"
#include "gameObject.h"
#include "carrierDrone.h"

using namespace std;

class CarrierEnemy : public GameObject
{
protected:
	// Amount of hit points
	int health;

	// Fires when shotcooldown reaches zero
	int shotCooldown;

	// Placeholder for image
	static BBImage carrierShip;

	// Placeholder for sound
	static BBSound explosionSound;


public:
	// Constructor
	CarrierEnemy(float x, float y) : GameObject(x, y, 25)
	{
		shotCooldown = 0;
		health = 10;
	}

	// Initializes image and sound
	static void initializeCarrierEnemy();

	// This ship's fire function
	void fire(World* world);

	// Update function for this class
	virtual void Update(World* world);

	// What happens on collision for this class
	virtual void onCollision(GameObject* other);

	// Returns true if this object is on screen
	bool isOnScreen();

	// Queues this object for destruction
	bool NeedsDestruction();

	// Returns the type of this class
	virtual GameObjectType type();

	// Returns the image variable of this class
	virtual BBImage getImage();
};

