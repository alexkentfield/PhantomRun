#include "homingBullet.h"

BBImage HomingBullet::homingBullet = 0;

void HomingBullet::Update(World* world)
{
	bbDrawImage(homingBullet, position.x, position.y, 0);
	position += velocity;

	GameObjectType targetTypes[] = {GameObjectTypes::Enemy, GameObjectTypes::BigEnemy, GameObjectTypes::CarrierEnemy, GameObjectTypes::CarrierDrone};
	
	GameObject* target = Query(world).select(targetTypes).inRect(0.0f, 800.0f, 0.0f, 500.0f).nearest(position);

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
		velocity.y -= 0.1f;
	}

}

void HomingBullet::onCollision(GameObject* other)
{
	if (other->type() == GameObjectTypes::Enemy)
	{
		queueForDestruction();
	}

	if (other->type() == GameObjectTypes::BigEnemy)
	{
		queueForDestruction();
	}

	if (other->type() == GameObjectTypes::CarrierEnemy)
	{
		queueForDestruction();
	}

}

bool HomingBullet::isOnScreen()
{
	if (position.y < 0 || position.y > 600)
	{
		return false;
	}
	return true;
}

bool HomingBullet::NeedsDestruction()
{
	return needsDestruction || !isOnScreen();
}

void HomingBullet::initializeHomingBullets()
{
	homingBullet = bbLoadImage("bullet.png");
}

GameObjectType HomingBullet::type()
{
	return GameObjectTypes::HomingBullet;
}

BBImage HomingBullet::getImage()
{
	return homingBullet;
}