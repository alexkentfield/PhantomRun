#pragma once
#include "gameObject.h"
#include "blitz3dsdk.h"
#include <iostream>

using namespace std;

class BigEnemyBullet : public GameObject
{
private:
	// Placeholder for image
	static BBImage bigBullet;

	// Holds offset value to shoot diagonally
	float shotOffset;

public:
	// Constructor
	BigEnemyBullet(float x, float y, float offset) : GameObject(x, y, 5)
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
	static void initializeBigBullets();

	// Returns a vec2 of this ships current position
	Vec2 getPosition();

	// Queues this object for destruction
	bool NeedsDestruction();

	// Returns the type of this class
	virtual GameObjectType type();

	// Returns the image variable of this class
	virtual BBImage getImage();
};

