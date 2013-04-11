#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <vector>
#include "blitz3dsdk.h"
#include "vec2.h"
#include "bullet.h"
#include "enemy.h"
#include <cstdlib>
#include <time.h>
#include "player.h"
#include "carrierEnemy.h"
#include "carrierDrone.h"
#include "bigEnemy.h"
#include "healthPickup.h"
#include "weaponUpgrade.h"
#include "world.h"
#include "level.h"

using namespace std;

int main ()
{
	// Create window
	bbBeginBlitz3D();
	bbGraphics(800,800,0,2);
	bbAutoMidHandle(true);

	// Initialize all images and sounds
	Bullet::initializeBullets();
	Enemy::initializeEnemies();
	Player::initializePlayer();
	BigEnemy::initializeBigEnemy();
	CarrierEnemy::initializeCarrierEnemy();
	CarrierDrone::initializeCarrierDrone();
	BigEnemyBullet::initializeBigBullets();
	Level::initializelvlImages();	
	HealthPickup::initializeHealthPickup();
	WeaponUpgrade::initializeWeaponUpgrade();

	// Play music
	static BBSound music;
	music = bbLoadSound("music.ogg");
	bbLoopSound(music);
	bbSoundVolume(music, 0.4f); 
	bbPlaySound(music);

	// 
	int frameTime = 0;
	float frameTimeAverage = 0;
	char buffer [50];

	// Create all levels
	Level allLevels;
	
	srand(time(NULL));

	while (true)
	{
		
		int timeStart = bbMilliSecs();

		bbCls();
		bbColor(0, 255, 0);

		allLevels.Update();

		int printThis = sprintf(buffer, "Time per frame: %f", frameTimeAverage);
		bbText(0, 20, buffer);

		bbFlip(1);

		int timeFinished = bbMilliSecs();
		frameTime = timeFinished - timeStart;
		frameTimeAverage = frameTimeAverage * 0.95f + frameTime * 0.05f;
	}

	bbEndBlitz3D();
	return 0;

}