#pragma once
#include "gameObject.h"
#include "blitz3dsdk.h"

class WeaponUpgrade : public GameObject
{
protected:
	// Placeholder for image
	static BBImage weaponPickup;

	// Placeholder for sound
	static BBSound pickupSound;

public:
	// Constructor
	WeaponUpgrade(float x, float y) : GameObject(x, y, 15)
	{
		
	}

	// Update function for this object
	virtual void Update(World* world);

	// Returns true if the object is on the screen
	bool isOnScreen();
	
	// Returns true if the object needs to be destroyed
	bool NeedsDestruction();

	// What happens on collision for this object
	void onCollision(GameObject* other);

	// Initialize image and sound
	static void initializeWeaponUpgrade();

	// Returns current position of this object
	Vec2 getPosition();

	// Returns image of this object
	BBImage getImage();

	// Returns the type of this object
	GameObjectType type();
};

