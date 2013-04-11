#include "bullet.h"


BBImage Bullet::bullet = 0;

void Bullet::Update(World* world)
{
	bbDrawImage(bullet, position.x, position.y, 0);
	//position += velocity;
	position.y -= 2;
	position.x += shotOffset;

			
		/*if (nearest->getPosition().x > position.x)
		{
			position.x++;
		}
		else
		{
			position.x--;
		}*/


}

void Bullet::onCollision(GameObject* other)
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

bool Bullet::isOnScreen()
{
	if (position.y < 0 || position.y > 800)
	{
		return false;
	}
	return true;
}

bool Bullet::NeedsDestruction()
{
	return needsDestruction || !isOnScreen();
}

void Bullet::initializeBullets()
{
	bullet = bbLoadImage("bullet.png");
}

GameObjectType Bullet::type()
{
	return GameObjectTypes::Bullet;
}

BBImage Bullet::getImage()
{
	return bullet;
}

