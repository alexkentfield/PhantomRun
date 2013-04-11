#include "enemy.h"

BBImage Enemy::enemyShip = 0;
BBSound Enemy::explosionSound = 0;

void Enemy::onCollision(GameObject* other)
{
	if (other->type() == GameObjectTypes::Bullet)
	{
		setKilled();
		queueForDestruction();
		bbPlaySound(explosionSound);
	}
	else if (other->type() == GameObjectTypes::Player)
	{
		queueForDestruction();
		bbPlaySound(explosionSound);
	}
}

void Enemy::initializeEnemies()
{
	enemyShip = bbLoadImage("EnemyShip.png");
	explosionSound = bbLoadSound("explosion1.wav");
}

Vec2 Enemy::getPosition()
{
	return position;
}

bool Enemy::isOnScreen()
{
	if (position.y < -90 || position.y > 800)
	{
		return false;
	}
	return true;
}

bool Enemy::NeedsDestruction()
{
	return needsDestruction || !isOnScreen();
}

BBImage Enemy::getImage()
{
	return enemyShip;
}

GameObjectType Enemy::type()
{
	return GameObjectTypes::Enemy;
}