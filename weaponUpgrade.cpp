#include "weaponUpgrade.h"

BBImage WeaponUpgrade::weaponPickup = 0;
BBSound WeaponUpgrade::pickupSound = 0;

void WeaponUpgrade::Update(World* world)
{
	bbDrawImage(weaponPickup, position.x, position.y, 0);
	position.y+= 0.5;
	spawn(world);
}

bool WeaponUpgrade::isOnScreen()
{
	if (position.y < -90 || position.y > 800)
	{
		return false;
	}
	return true;
}

bool WeaponUpgrade::NeedsDestruction()
{
	return needsDestruction || !isOnScreen();
}

void WeaponUpgrade::onCollision(GameObject* other)
{
	if (other->type() == GameObjectTypes::Player)
	{
		queueForDestruction();
		bbPlaySound(pickupSound);
	}
}

void WeaponUpgrade::initializeWeaponUpgrade()
{
	weaponPickup = bbLoadImage("weaponUpgrade.png");
	pickupSound = bbLoadSound("pickup1.wav");
}

Vec2 WeaponUpgrade::getPosition()
{
	return position;
}

BBImage WeaponUpgrade::getImage()
{
	return weaponPickup;
}

GameObjectType WeaponUpgrade::type()
{
	return GameObjectTypes::WeaponUpgrade;
}