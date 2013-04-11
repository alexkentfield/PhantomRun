#pragma once
#include <iostream>
#include "world.h"
#include "gameObject.h"
#include "bigEnemyBullet.h"

using namespace std;

class BigEnemy : public GameObject
{
private:
	// Amount of hit points
	int m_health;

	// Direction is changed back and forth to keep the big enemy straffing
	int m_direction;

	// Straffing speed of the ship
	float m_speed;

	// Fires when shotcooldown reaches zero
	int m_shotCooldown;

	// Placeholder for image
	static BBImage m_bigEnemyShip;

	// Placeholder for sound
	static BBSound m_explosionSound;	

public:
	// Constructor
	BigEnemy(float x, float y) : GameObject(x, y, 5)
	{
		m_health = 4;
		m_shotCooldown = 0;
		m_direction = 1;
		m_speed = 0.5f;
	}

	// Update function for this class
	virtual void Update(World* world);

	// What happens on collision for this class
	virtual void onCollision(GameObject* other);

	// This ship's fire function
	void fire(World* world);

	// Initializes image and sound
	static void initializeBigEnemy();

	// Returns the type of this class
	virtual GameObjectType type();

	// Returns the image variable of this class
	virtual BBImage getImage();
};


