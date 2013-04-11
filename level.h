#pragma once
#include <iostream>
#include "world.h"
#include "query.h"
#include "player.h"
#include "enemy.h"
#include "bigEnemy.h"
#include "carrierEnemy.h"
#include "healthPickup.h"
#include "weaponUpgrade.h"

using namespace std;

class Level
{
private:
	World* myWorld;

	// Images for loading and level screens
	static BBImage lvlOne;
	static BBImage lvlTwo;
	static BBImage lvlThree;
	static BBImage lvlFour;
	static BBImage lvlFive;
	static BBImage gameOver;
	static BBImage winGame;
	static BBImage gameTitle;
	static BBImage spaceBegin;
	
	// Cooldowns and spawn rates for all the ships
	int currentLevel;
	int enemySpawnCooldown;
	int bigEnemySpawnCooldown;
	int carrierSpawnCooldown;
	int healthPickupSpawnCooldown;
	int healthPickupSpawnRate;
	int weaponUpgradeSpawnCooldown;
	int weaponUpgradeSpawnRate;
	int enemySpawnRate;
	int bigEnemySpawnRate;
	int carrierSpawnRate;
	int score;
	int enemyCount;
	int lvlChange;


public:
	// Constructor
	Level()
	{
		myWorld = new World();
		score = 0;
		lvlChange = 0;
		currentLevel = 0;
		myWorld->AddGameObject(new Player);
		myWorld->AddNewGameObjects();
		carrierSpawnCooldown = 0;
		enemySpawnCooldown = 0;
		bigEnemySpawnCooldown = 0;
		healthPickupSpawnCooldown = 2000;
		weaponUpgradeSpawnCooldown = 1000;
	}

	// Update function for this class
	void Update();

	// Updates score for the player
	void updateScore();

	// Spawns basic enemies
	void spawnEnemies();

	// Spawns big enemies
	void spawnBigEnemies();

	// Spawns carriers
	void spawnCarriers();

	// Spawn health pickups
	void spawnPickups();

	// Spawn weapon upgrades
	void spawnUpgrades();

	// Initialize images and sounds
	static void initializelvlImages();

	// Displays title screen
	void titleScreen();

	// Controls level one
	void levelOne();

	// Controls level two
	void levelTwo();

	// Controls level three
	void levelThree();

	// Controls level four
	void levelFour();

	// Controls level five
	void levelFive();
};

