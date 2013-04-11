#include "world.h"

// Delete objects that are queued for destruction
void World::collectGarbage() 
{
	bool tryAgain = true;
	while (tryAgain)
	{
		tryAgain = false;
		for (GameObjectVector::iterator it = allGameObjects.begin() ; it != allGameObjects.end(); ++it)
		{
			if ((*it)->NeedsDestruction())
			{
				allGameObjects.erase(it);
				tryAgain = true;
				break;
			}
		}
	}

	for (GameObjectMap::iterator gameObjectVector = gameObjects.begin(); gameObjectVector != gameObjects.end(); ++gameObjectVector)
	{
		tryAgain = true;
		while (tryAgain)
		{
			tryAgain = false;
			for (GameObjectVector::iterator it = gameObjectVector->second.begin() ; it != gameObjectVector->second.end(); ++it)
			{
				if ((*it)->NeedsDestruction())
				{
					delete *it;
					gameObjectVector->second.erase(it);
					tryAgain = true;
					break;
				}
			}
		}
	}
}

void World::keepScore()
{
		for (GameObjectVector::iterator it = allGameObjects.begin() ; it != allGameObjects.end(); ++it)
		{
			if ((*it)->NeedsDestruction() && (*it)->wasKilled())
			{
				gameObjectsKilled[(*it)->type()]++;
			}
		}
}
	
// Update all game objects
void World::updateAllGameObjects() 
{
	for (GameObjectVector::iterator it = allGameObjects.begin() ; it != allGameObjects.end(); ++it)
	{
		(*it)->Update(this);
	}
}

// Identify collisions between each possible type
void World::handleAllCollisions()
{
	handleCollisions(GameObjectTypes::Bullet, GameObjectTypes::Enemy);
	handleCollisions(GameObjectTypes::Player, GameObjectTypes::Enemy);
	handleCollisions(GameObjectTypes::Player, GameObjectTypes::BigEnemyBullet);
	handleCollisions(GameObjectTypes::Bullet, GameObjectTypes::BigEnemy);
	handleCollisions(GameObjectTypes::Bullet, GameObjectTypes::CarrierEnemy);
	handleCollisions(GameObjectTypes::Bullet, GameObjectTypes::CarrierDrone);
	handleCollisions(GameObjectTypes::Player, GameObjectTypes::CarrierDrone);
	handleCollisions(GameObjectTypes::Player, GameObjectTypes::CarrierEnemy);
	handleCollisions(GameObjectTypes::Player, GameObjectTypes::HealthPickup);
	handleCollisions(GameObjectTypes::Player, GameObjectTypes::WeaponUpgrade);
}

// Runs onCollision for both objects
void World::handleCollisions(GameObjectType a, GameObjectType b)
{
	GameObjectVector objectsOfA = GetGameObjects(a);
	GameObjectVector objectsOfB = GetGameObjects(b);

	for (GameObjectVector::iterator objA = objectsOfA.begin(); objA != objectsOfA.end(); ++objA)
	{
		for (GameObjectVector::iterator objB = objectsOfB.begin(); objB != objectsOfB.end(); ++objB)
		{
			if ((*objA)->isCollidingWith(*objB))
			{
				(*objA)->onCollision(*objB);
				(*objB)->onCollision(*objA);
			}
		}
	}
}

void World::AddGameObject(GameObject* obj)
{
	newGameObjects.push_back(obj);
}

void World::AddNewGameObjects()
{
	for(GameObjectVector::iterator obj = newGameObjects.begin(); obj != newGameObjects.end(); ++obj)
	{
		gameObjects[(*obj)->type()].push_back(*obj);
		allGameObjects.push_back(*obj);
	}
	newGameObjects.clear();
}

GameObject* World::getNearestGameObjectOfTypes(Vec2 position, GameObjectType types[])
{
	GameObject* nearest;
	float nearestDistance = 9999.9f;

	for (int i = 0; i < sizeof(types); i++)
	{
		GameObject* object = getNearestGameObjectOfType(position, types[i]);

		if (object)
		{
			float dist = (position - object->getPosition()).length();

			if (dist < nearestDistance)
			{
				nearest = object;
				nearestDistance = dist;
			}
		}
	}

	return nearest;
}

GameObject* World::getNearestGameObjectOfType(Vec2 position, GameObjectType type)
{
	GameObject* nearest = 0;
	float nearestDistance = 9999.9f;

	GameObjectVector objects = GetGameObjects(type);
	for (GameObjectVector::iterator obj = objects.begin(); obj != objects.end(); ++obj)
	{
		float dist = (position - (*obj)->getPosition()).length();

		if (dist < nearestDistance)
		{
			nearest = *obj;
			nearestDistance = dist;
		}
	}
	return nearest;
}

vector<GameObject*>& World::GetGameObjects(GameObjectType objType)
{
	return gameObjects[objType];
}

int World::getKillCount(GameObjectType type)
{
	return gameObjectsKilled[type];
}

void World::update()
{
	AddNewGameObjects();
	updateAllGameObjects();
	handleAllCollisions();
	keepScore();
	collectGarbage();
}