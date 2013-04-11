#include "carrierDrone.h"

BBImage CarrierDrone::carrierDrone = 0;
BBSound CarrierDrone::explosionSound = 0;

void CarrierDrone::initializeCarrierDrone()
{
	carrierDrone = bbLoadImage("carrierDrone.png");
	explosionSound = bbLoadSound("explosion1.wav");
}

void CarrierDrone::Update(World* world)
{
	bbDrawImage(carrierDrone, position.x, position.y, 0);
	position += velocity;

	GameObjectType targetTypes[] = {GameObjectTypes::Player};
	
	GameObject* target = Query(world).select(targetTypes).inRect(0.0f, 800.0f, 0.0f, 800.0f).nearest(position);

	velocity.scale(0.99f);

	if (target)
	{
		Vec2 nearestDifference = target->getPosition() - position;
		nearestDifference.normalize();
		nearestDifference.scale(0.02f);
		velocity += nearestDifference;
	}
	else
	{
		velocity.y += 0.1f;
	}
}

void CarrierDrone::onCollision(GameObject* other)
{
	if (other->type() == GameObjectTypes::Bullet)
	{
		setKilled();
		queueForDestruction();
		bbPlaySound(explosionSound);
	}
	if (other->type() == GameObjectTypes::Player)
	{
		setKilled();
		queueForDestruction();
		bbPlaySound(explosionSound);
	}
}

GameObjectType CarrierDrone::type()
{
	return GameObjectTypes::CarrierDrone;
}

bool CarrierDrone::isOnScreen()
{
	if (position.y < -90 || position.y > 800)
	{
		return false;
	}
	return true;
}

bool CarrierDrone::NeedsDestruction()
{
	return needsDestruction || !isOnScreen();
}

BBImage CarrierDrone::getImage()
{
	return carrierDrone;
}
