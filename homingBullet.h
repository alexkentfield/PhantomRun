#pragma once
#include <iostream>
#include "gameObject.h"
#include "blitz3dsdk.h"
#include "query.h"

class HomingBullet : public GameObject
{
private:
	// Velocity is the ships next position towards its target
	Vec2 velocity;

	// Placeholder for image
	static BBImage homingBullet;
public:
	// Update function for this class
	void Update(World* world);

	// What happens on collision for this class
	void onCollision(GameObject* other);

	// Returns true if object is on the screen
	bool isOnScreen();

	// Returns true if object needs to be destroyed
	bool NeedsDestruction();

	// Initialize image and sound
	void initializeHomingBullets();

	// Return the type of this class
	GameObjectType type();

	// Return image variable for this class
	BBImage getImage();
};













