#include "carrierEnemy.h"

BBImage CarrierEnemy::carrierShip = 0;
BBSound CarrierEnemy::explosionSound = 0;

void CarrierEnemy::initializeCarrierEnemy()
{
	carrierShip = bbLoadImage("carrierEnemy.png");
	explosionSound = bbLoadSound("explosion1.wav");
}

void CarrierEnemy::fire(World* world)
{
	if (shotCooldown == 0)
	{
		CarrierDrone* a = new CarrierDrone(position.x + 50, position.y);
		world->AddGameObject(a);
		CarrierDrone* b = new CarrierDrone(position.x - 50, position.y);
		world->AddGameObject(b);
		shotCooldown += 600;
	}
	if (shotCooldown > 0)
	{
		shotCooldown--;
	}
}

void CarrierEnemy::Update(World* world)
{
	bbDrawImage(carrierShip, position.x, position.y, 0);
	position.y += 0.3f;
	fire(world);
}

void CarrierEnemy::onCollision(GameObject* other)
{
	if (other->type() == GameObjectTypes::Bullet)
	{
		health--;
		if (health <= 0)
		{
			setKilled();
			queueForDestruction();
			bbPlaySound(explosionSound);
		}
	}
}

bool CarrierEnemy::isOnScreen()
{
	if (position.y < -90 || position.y > 800)
	{
		return false;
	}
	return true;
}

bool CarrierEnemy::NeedsDestruction()
{
	return needsDestruction || !isOnScreen();
}

GameObjectType CarrierEnemy::type()
{
	return GameObjectTypes::CarrierEnemy;
}

BBImage CarrierEnemy::getImage()
{
	return carrierShip;
}