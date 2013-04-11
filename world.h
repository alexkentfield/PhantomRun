#pragma once
#include <vector>
#include <iostream>
#include <map>
#include "gameObject.h"

using namespace std;

typedef vector<GameObject*> GameObjectVector;
typedef map<GameObjectType, GameObjectVector> GameObjectMap;
typedef map<GameObjectType, int> GameObjectsIntMap;

class World
{
private:
	// Game objects that have just been added, gets put into all game objects
	GameObjectVector newGameObjects;

	// All the objects in the world
	GameObjectVector allGameObjects;
	GameObjectMap gameObjects;

	// Game Objects that have been destroyed
	GameObjectsIntMap gameObjectsKilled;

	// Delete objects that are queued for destruction
	void collectGarbage();

	void keepScore();
	
	// Update all game objects
	void updateAllGameObjects();

	// Identify collisions between each possible type
	void handleAllCollisions();

	// Runs onCollision for both objects
	void handleCollisions(GameObjectType a, GameObjectType b);

public:
	// Adds a game object to the world
	void AddGameObject(GameObject* obj);

	// Adds game objects to the correct vector
	void AddNewGameObjects();

	// Returns multiple objects that are closest
	GameObject* getNearestGameObjectOfTypes(Vec2 position, GameObjectType types[]);

	// Returns the object that is closest
	GameObject* getNearestGameObjectOfType(Vec2 position, GameObjectType type);

	// Returns all objects of specific type
	vector<GameObject*>& GetGameObjects(GameObjectType objType);

	// Returns the amount of enemies killed from a specific type
	int getKillCount(GameObjectType type);

	// Update function for this class
	void update();
};
