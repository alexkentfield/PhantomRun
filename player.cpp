#include "player.h"


BBImage Player::player = 0;
BBImage Player::playerLife = 0;
BBImage Player::gameOverImage = 0;

BBSound Player::fireSound = 0;
BBSound Player::hitSound = 0;

void Player::Update(World* world)
	{
		bbDrawImage(player, position.x, position.y, 0);
		movement();
		updateLives();
		if (weaponLevel == 1)
		{
			fire(world);
		}
		else if (weaponLevel == 2)
		{
			fireDouble(world);
		}
		else if (weaponLevel == 3)
		{
			fireTriple(world);
		}
		if (weaponLevel >= 3)
			weaponLevel = 3;
	}

void Player::onCollision(GameObject* other)
{
	if (other->type() == GameObjectTypes::Enemy)
	{
		loseLife();
		bbPlaySound(hitSound);
		weaponLevel--;
	}
	else if (other->type() == GameObjectTypes::BigEnemyBullet)
	{
		loseLife();
		bbPlaySound(hitSound);
		weaponLevel--;
	}
	else if (other->type() == GameObjectTypes::CarrierEnemy)
	{
		loseLife();
		bbPlaySound(hitSound);
		weaponLevel--;
	}
	else if (other->type() == GameObjectTypes::CarrierDrone)
	{
		loseLife();
		bbPlaySound(hitSound);
		weaponLevel--;
	}
	else if (other->type() == GameObjectTypes::HealthPickup)
	{
		gainLife();
	}
	else if (other->type() == GameObjectTypes::WeaponUpgrade)
	{
		weaponLevel++;
	}
	if (weaponLevel <= 0)
		weaponLevel = 1;

}

void Player::movement()
{
	// Move left
	if (bbKeyDown(203))
	{
		position.x -= 1.0f;

		if (position.x < 0)
		{
			position.x = 0;
		}
	}
	
	// Move Right
	if (bbKeyDown(205))
	{
		position.x += 1.0f;

		if (position.x > 744)
		{
			position.x = 744;
		}
	}

	// Move up
	if (bbKeyDown(200))
	{
		position.y -= 1.0f;

		if (position.y < 550)
		{
			position.y = 550;
		}
	}

	// Move down
	if (bbKeyDown(208))
	{
		position.y += 1.0f;

		if (position.y > 775)
		{
			position.y = 775;
		}
	}
}

void Player::fire(World* world)
{
	// Fire
	if (bbKeyDown(57))
	{
		if (playerShotCooldown == 0)
		{
		Bullet* a = new Bullet(position.x, position.y, 0);
		world->AddGameObject(a);
		bbPlaySound(fireSound);
		playerShotCooldown += 45;
		}
	}
	if (playerShotCooldown > 0)
	{
		playerShotCooldown--;
	}
}

void Player::fireDouble(World* world)
{
	// Fire
	if (bbKeyDown(57))
	{
		if (playerShotCooldown == 0)
		{
		Bullet* a = new Bullet(position.x - 10, position.y, 0);
		world->AddGameObject(a);
		Bullet* b = new Bullet(position.x + 10, position.y, 0);
		world->AddGameObject(b);
		bbPlaySound(fireSound);
		playerShotCooldown += 45;
		}
	}
	if (playerShotCooldown > 0)
	{
		playerShotCooldown--;
	}
}

void Player::fireTriple(World* world)
{
	// Fire
	if (bbKeyDown(57))
	{
		if (playerShotCooldown == 0)
		{
		Bullet* a = new Bullet(position.x, position.y, 0);
		world->AddGameObject(a);
		Bullet* b = new Bullet(position.x + 10, position.y, 0.2);
		world->AddGameObject(b);
		Bullet* c = new Bullet(position.x - 10, position.y, -0.2);
		world->AddGameObject(c);
		bbPlaySound(fireSound);
		playerShotCooldown += 45;
		}
	}
	if (playerShotCooldown > 0)
	{
		playerShotCooldown--;
	}
}

void Player::updateLives()
{
	if (livesLeft == 5)
	{
		bbDrawImage(playerLife, 768, 15, 0);
		bbDrawImage(playerLife, 736, 15, 0);
		bbDrawImage(playerLife, 704, 15, 0);
		bbDrawImage(playerLife, 672, 15, 0);
		bbDrawImage(playerLife, 640, 15, 0);

	}
	if (livesLeft == 4)
	{
		bbDrawImage(playerLife, 768, 15, 0);
		bbDrawImage(playerLife, 736, 15, 0);
		bbDrawImage(playerLife, 704, 15, 0);
		bbDrawImage(playerLife, 672, 15, 0);
	}
	if (livesLeft == 3)
	{
		bbDrawImage(playerLife, 768, 15, 0);
		bbDrawImage(playerLife, 736, 15, 0);
		bbDrawImage(playerLife, 704, 15, 0);
	}
	else if (livesLeft == 2)
	{
		bbDrawImage(playerLife, 768, 15, 0);
		bbDrawImage(playerLife, 736, 15, 0);
	}
	else if (livesLeft == 1)
	{
		bbDrawImage(playerLife, 768, 15, 0);
	}
	if (livesLeft >=5)
	{
		livesLeft = 5;
	}
}

void Player::loseLife()
{
	livesLeft--;
}

void Player::gainLife()
{
	livesLeft++;
}

int Player::getLives()
{
	return livesLeft;
}

Vec2 Player::getPosition()
{
	return position;
}

void Player::initializePlayer()
{
	player = bbLoadImage("PlayerShip.png");
	playerLife = bbLoadImage("heart.png");
	gameOverImage = bbLoadImage("GameOver.png");
	hitSound = bbLoadSound("blip1.wav");
	fireSound = bbLoadSound("minigun1.wav");
}

GameObjectType Player::type()
{
	return GameObjectTypes::Player;
}

bool Player::NeedsDestruction()
{
	return false;
}

BBImage Player::getImage()
{
	return player;
}

