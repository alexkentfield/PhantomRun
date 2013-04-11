#pragma once
#include <iostream>
#include "gameObject.h"
#include "blitz3dsdk.h"
#include "bullet.h"
#include "world.h"

using namespace std;

class Player : public GameObject
{
private:
	// Amount of hit points
	int livesLeft;

	// Player shot cooldown
	int playerShotCooldown;

	// Current level of weapon upgrades
	int weaponLevel;

	// Placeholders for images
	static BBImage player;
	static BBImage playerLife;
	static BBImage gameOverImage;
	static BBSound fireSound;
	static BBSound hitSound;

public:
	// Constructor
	Player() : GameObject(390, 750, 15)
	{
		livesLeft = 3;
		playerShotCooldown = 0;
		initializePlayer();
		weaponLevel = 1;
	}

	// Update function for the player
	virtual void Update(World* world);

	// What happens on collision for the player
	virtual void onCollision(GameObject* other);

	// Player movement
	void movement();

	// Fire functions for the player
	virtual void fire(World* world);
	virtual void fireDouble(World* world);
	virtual void fireTriple(World* world);

	// Update current amount of hit points of the player
	void updateLives();

	// Reduces player hit points by 1
	void loseLife();

	// Increase player hit points by 1
	void gainLife();

	// Return current amount of hit points
	int getLives();

	// Return current position of the player
	Vec2 getPosition();

	// Initialize player images and sounds
	static void initializePlayer();

	// Return type of this class
	virtual GameObjectType type();

	// Return true if object needs to be destroyed
	virtual bool NeedsDestruction();

	// Return image variable of this class
	virtual BBImage getImage();
};
