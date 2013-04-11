#pragma once
#include "gameObject.h"
#include "blitz3dsdk.h"

class HealthPickup : public GameObject
{
protected:
	// Placeholder for image
	static BBImage healthPickup;

	// Placeholder for sound
	static BBSound pickupSound;

public:
	// Constructor
	HealthPickup(float x, float y) : GameObject(x, y, 15)
	{
		
	}

	// Update function for this object
	virtual void Update(World* world);

	// Returns true if object is on the screen
	bool isOnScreen();

	// Returns true if object needs to be destroyed
	bool NeedsDestruction();

	// What happens on collision for this object
	void onCollision(GameObject* other);

	// Initialize image and sound
	static void initializeHealthPickup();

	// Returns current position of object
	Vec2 getPosition();

	// Returns the image variable of this class
	BBImage getImage();

	// Returns the type of this class
	GameObjectType type();
};

