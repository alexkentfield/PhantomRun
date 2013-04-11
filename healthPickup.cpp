#include "healthPickup.h"

BBImage HealthPickup::healthPickup = 0;
BBSound HealthPickup::pickupSound = 0;

void HealthPickup::Update(World* world)
{
	bbDrawImage(healthPickup, position.x, position.y, 0);
	position.y+= 0.5;
	spawn(world);
}

bool HealthPickup::isOnScreen()
{
	if (position.y < -90 || position.y > 800)
	{
		return false;
	}
	return true;
}

bool HealthPickup::NeedsDestruction()
{
	return needsDestruction || !isOnScreen();
}

void HealthPickup::onCollision(GameObject* other)
{
	if (other->type() == GameObjectTypes::Player)
	{
		queueForDestruction();
		bbPlaySound(pickupSound);
	}
}

void HealthPickup::initializeHealthPickup()
{
	healthPickup = bbLoadImage("healthPickup.png");
	pickupSound = bbLoadSound("pickup1.wav");
}

Vec2 HealthPickup::getPosition()
{
	return position;
}

BBImage HealthPickup::getImage()
{
	return healthPickup;
}

GameObjectType HealthPickup::type()
{
	return GameObjectTypes::HealthPickup;
}