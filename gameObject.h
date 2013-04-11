#pragma once
#include <iostream>
#include "vec2.h"
#include "blitz3dsdk.h"

using namespace std;

// List of all types of objects
namespace GameObjectTypes
{
	enum GameObjectType
	{
		Player,
		Enemy,
		BigEnemy,
		BigEnemyBullet,
		Bullet,
		HomingBullet,
		CarrierEnemy,
		HealthPickup,
		WeaponUpgrade,
		CarrierDrone
	};

}

typedef int BBObject;
typedef BBObject BBImage;
typedef GameObjectTypes::GameObjectType GameObjectType;
class World;

class GameObject
{
private:
	// Whether or not an object was killed
	bool m_wasKilled;

protected:
	// Position of current object
	Vec2 position;

	// If true, queues object for destruction
	bool needsDestruction;
	
	// Radius of the object
	float radius;
	
public:
	// Return type for each class
	virtual GameObjectType type() = 0;

	// Update function for each class
	virtual void Update(World* world) = 0;

	// Return image for each class
	virtual BBImage getImage() = 0;

	// Default constructor
	GameObject()
	{

	}

	// Constructor
	GameObject(float posX, float posY, float rad)
	{
		m_wasKilled = false;
		position.x = posX;
		position.y = posY;
		radius = rad;
		needsDestruction = false;
	}

	// Returns current position of object
	Vec2 getPosition();

	// What happens on collision for specific object
	virtual void onCollision(GameObject* other);

	// Fire function for each ship
	virtual void fire(World* world);

	// Spawn function for each class
	virtual void spawn(World* world);

	// Returns true if killed
	bool wasKilled();

	// Set object to killed
	void setKilled();

	// Returns true if colliding with another object
	bool isCollidingWith(GameObject* other);

	// Return the radius of an object
	float getRadius();

	// Queue object for destruction
	void queueForDestruction();

	// Set true to queue for destruction 
	virtual bool NeedsDestruction();
};