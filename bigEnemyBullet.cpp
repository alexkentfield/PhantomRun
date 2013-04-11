#include "bigEnemyBullet.h"

BBImage BigEnemyBullet::bigBullet = 0;

void BigEnemyBullet::Update(World* world)
{
	bbDrawImage(bigBullet, position.x, position.y, 0);
	position.y++;
	position.x += shotOffset;
}

void BigEnemyBullet::onCollision(GameObject* other)
{
	if (other->type() == GameObjectTypes::Player)
	{
		queueForDestruction();
	}
}

bool BigEnemyBullet::isOnScreen()
{
	if (position.y < 0 || position.y > 800)
	{
		return false;
	}
	return true;
}

void BigEnemyBullet::initializeBigBullets()
{
	bigBullet = bbLoadImage("bigBullet.png");
}

Vec2 BigEnemyBullet::getPosition()
{
	return position;
}

bool BigEnemyBullet::NeedsDestruction()
{
	return needsDestruction || !isOnScreen();
}

GameObjectType BigEnemyBullet::type()
{
	return GameObjectTypes::BigEnemyBullet;
}

BBImage BigEnemyBullet::getImage()
{
	return bigBullet;
}