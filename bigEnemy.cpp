#include "bigEnemy.h"

BBImage BigEnemy::m_bigEnemyShip = 0;
BBSound BigEnemy::m_explosionSound = 0;

void BigEnemy::Update(World* world)
{
	bbDrawImage(m_bigEnemyShip, position.x, position.y, 0);

	if (position.y < 80)
	{
		position.y += 0.5f;
	}

	if (position.y == 80)
	{
		position.x += m_speed * m_direction;
	}
		
	if (position.x < 0 || position.x > 730)
	{
		m_direction *= -1;
	}

	fire(world);
}

void BigEnemy::onCollision(GameObject* other)
{
	if (other->type() == GameObjectTypes::Bullet)
	{
		m_health--;
		if (m_health <= 0)
		{
			setKilled();
			queueForDestruction();
			bbPlaySound(m_explosionSound);
		}
	}
}

void BigEnemy::fire(World* world)
{
	if (m_shotCooldown == 0)
	{
		BigEnemyBullet* cb = new BigEnemyBullet(position.x, position.y, 0);
		world->AddGameObject(cb);
		BigEnemyBullet* rb = new BigEnemyBullet(position.x, position.y, 0.3f);
		world->AddGameObject(rb);
		BigEnemyBullet* lb = new BigEnemyBullet(position.x, position.y, -0.3f);
		world->AddGameObject(lb);
		m_shotCooldown += 350;
	}
	if (m_shotCooldown > 0)
	{
		m_shotCooldown--;
	}
}

void BigEnemy::initializeBigEnemy()
{
	m_bigEnemyShip = bbLoadImage("bigEnemyShip.png");
	m_explosionSound = bbLoadSound("explosion1.wav");
}

GameObjectType BigEnemy::type()
{
	return GameObjectTypes::BigEnemy;
}

BBImage BigEnemy::getImage()
{
	return m_bigEnemyShip;
}