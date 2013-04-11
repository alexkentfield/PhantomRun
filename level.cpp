#include "level.h"

BBImage Level::lvlOne = 0;
BBImage Level::lvlTwo = 0;
BBImage Level::lvlThree = 0;
BBImage Level::lvlFour = 0;
BBImage Level::lvlFive = 0;
BBImage Level::winGame = 0;
BBImage Level::gameTitle = 0;
BBImage Level::spaceBegin = 0;
BBImage Level::gameOver = 0;

void Level::Update()
{
	GameObjectType targetTypes[] = {GameObjectTypes::Enemy, GameObjectTypes::BigEnemy, GameObjectTypes::CarrierEnemy, GameObjectTypes::CarrierDrone};
	enemyCount = Query(myWorld).select(targetTypes).getResults().size();
		
	Player* playerOne = (Player*)myWorld->GetGameObjects(GameObjectTypes::Player)[0];

	updateScore();

	if (currentLevel == 0)
	{
		titleScreen();
		if (bbKeyDown(57))
		{
			bbCls();
			currentLevel++;
		}
	}
	else if (currentLevel == 1)
	{
		levelOne();
	}
	else if (currentLevel == 2)
	{
		levelTwo();
	}
	else if (currentLevel == 3)
	{
		levelThree();
	}
	else if (currentLevel == 4)
	{
		levelFour();
	}
	else if (currentLevel == 5)
	{
		levelFive();
	}
	else if (currentLevel == 6)
	{
		bbCls();
		bbDrawImage(winGame, 400, 200, 0);
		bbDelay(4000);
		exit(1);
	}

	if(playerOne->getLives() <= 0)
	{
		bbCls();
		bbDrawImage(gameOver, 400, 200, 0);
		bbDelay(4000);
		exit(1);
	}

}

void Level::updateScore()
{
	char scoreBuffer [50];
		
	score = myWorld->getKillCount(GameObjectTypes::Enemy) * 10;
	score += myWorld->getKillCount(GameObjectTypes::BigEnemy) * 30;
	score += myWorld->getKillCount(GameObjectTypes::CarrierEnemy) * 50;
	score += myWorld->getKillCount(GameObjectTypes::CarrierDrone) * 10;

	int printScore = sprintf(scoreBuffer, "Score: %d", score);
	bbText(0, 5, scoreBuffer);
}

void Level::spawnEnemies()
{
	if (enemySpawnCooldown == 0)
	{
		Enemy* e = new Enemy(rand() % 710 + 20, -80);
		myWorld->AddGameObject(e);

		enemySpawnCooldown += enemySpawnRate;
	}
	if (enemySpawnCooldown > 0)
	{
		enemySpawnCooldown--;
	}
}


void Level::spawnBigEnemies()
{
	if (bigEnemySpawnCooldown == 0)
	{
		BigEnemy* be = new BigEnemy(rand() % 710 + 20, -80);
		myWorld->AddGameObject(be);

		bigEnemySpawnCooldown += bigEnemySpawnRate;
	}
	if (bigEnemySpawnCooldown > 0)
	{
		bigEnemySpawnCooldown--;
	}
}

void Level::spawnCarriers()
{
	if (carrierSpawnCooldown == 0)
	{
		CarrierEnemy* ce = new CarrierEnemy(rand() % 710 + 20, -80);
		myWorld->AddGameObject(ce);

		carrierSpawnCooldown += carrierSpawnRate;
	}
	if (carrierSpawnCooldown > 0)
	{
		carrierSpawnCooldown--;
	}
}

void Level::spawnPickups()
{
	if (healthPickupSpawnCooldown == 0)
	{
		HealthPickup* h = new HealthPickup(rand() % 710 + 20, -80);
		myWorld->AddGameObject(h);

		healthPickupSpawnCooldown += healthPickupSpawnRate;
	}
	if (healthPickupSpawnCooldown > 0)
	{
		healthPickupSpawnCooldown--;
	}
}

void Level::spawnUpgrades()
{
	if (weaponUpgradeSpawnCooldown == 0)
	{
		WeaponUpgrade* p = new WeaponUpgrade(rand() % 710 + 20, -80);
		myWorld->AddGameObject(p);

		weaponUpgradeSpawnCooldown += weaponUpgradeSpawnRate;
	}
	if (weaponUpgradeSpawnCooldown > 0)
	{
		weaponUpgradeSpawnCooldown--;
	}
}

void Level::initializelvlImages()
{
	lvlOne = bbLoadImage("level1.png");
	lvlTwo = bbLoadImage("level2.png");
	lvlThree = bbLoadImage("level3.png");
	lvlFour = bbLoadImage("level4.png");
	lvlFive = bbLoadImage("level5.png");
	gameOver = bbLoadImage("gameOver.png");
	winGame = bbLoadImage("youWin.png");
	gameTitle = bbLoadImage("phantomTitle.png");
	spaceBegin = bbLoadImage("spacetobegin.png");
}

void Level::titleScreen()
{
	bbDrawImage(gameTitle, 400, 150, 0);
	bbDrawImage(spaceBegin, 400, 450, 0);
}

void Level::levelOne()
{
	if (lvlChange == 0)
	{
		bbDrawImage(lvlOne, 400, 200, 0);
		bbDelay(3000);
		bbCls();
		lvlChange++;
	}
	myWorld->update();
	enemySpawnRate = 150;
	bigEnemySpawnRate = 900;
	healthPickupSpawnRate = 2000;
	weaponUpgradeSpawnRate = 2000;
	spawnEnemies();
	spawnBigEnemies();
	spawnPickups();
	spawnUpgrades();

	if (score >= 200)
	{
		currentLevel++;
	}
}

void Level::levelTwo()
{
	if (lvlChange == 1)
	{
		bbDrawImage(lvlTwo, 400, 200, 0);
		bbDelay(3000);
		bbCls();
		lvlChange++;
	}
	myWorld->update();
	enemySpawnRate = 100;
	bigEnemySpawnRate = 800;
	carrierSpawnRate = 2000;
	healthPickupSpawnRate = 2000;
	weaponUpgradeSpawnRate = 2000;

	spawnEnemies();
	spawnBigEnemies();
	spawnCarriers();
	spawnPickups();
	spawnUpgrades();
		
	if (score >= 500)
	{
		currentLevel++;
	}
}

void Level::levelThree()
{
	if (lvlChange == 2)
	{
		bbDrawImage(lvlThree, 400, 200, 0);
		bbDelay(3000);
		bbCls();
		lvlChange++;
	}
	myWorld->update();
	enemySpawnRate = 75;
	bigEnemySpawnRate = 600;
	carrierSpawnRate = 1600;
	healthPickupSpawnRate = 2000;
	weaponUpgradeSpawnRate = 2000;
		
	spawnEnemies();
	spawnBigEnemies();
	spawnCarriers();
	spawnPickups();
	spawnUpgrades();
		
	if (score >= 1000)
	{
		currentLevel++;
	}
}

void Level::levelFour()
{
	if (lvlChange == 3)
	{
		bbDrawImage(lvlFour, 400, 200, 0);
		bbDelay(3000);
		bbCls();
		lvlChange++;
	}
	myWorld->update();
	enemySpawnRate = 50;
	bigEnemySpawnRate = 500;
	carrierSpawnRate = 1400;
	healthPickupSpawnRate = 2000;
	weaponUpgradeSpawnRate = 2000;
		
	spawnEnemies();
	spawnBigEnemies();
	spawnCarriers();
	spawnPickups();
	spawnUpgrades();
		
	if (score >= 2000)
	{
		currentLevel++;
	}
}

void Level::levelFive()
{
	if (lvlChange == 4)
	{
		bbDrawImage(lvlFive, 400, 200, 0);
		bbDelay(3000);
		bbCls();
		lvlChange++;
	}
	myWorld->update();
	enemySpawnRate = 25;
	bigEnemySpawnRate = 250;
	carrierSpawnRate = 900;
	healthPickupSpawnRate = 2000;
	weaponUpgradeSpawnRate = 2000;

	spawnEnemies();
	spawnBigEnemies();
	spawnCarriers();
	spawnPickups();
	spawnUpgrades();
		
	if (score >= 3000)
	{
		currentLevel++;
	}
}