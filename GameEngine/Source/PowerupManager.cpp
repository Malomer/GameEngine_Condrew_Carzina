
#include "PowerupManager.h"
#include "SlowDownPowerup.h"
#include "SpeedUpPowerup.h"

PowerupManager::PowerupManager() {

}

void PowerupManager::SpawnRandomPowerup() {
	Powerup *powerup;

	int r = ((double)rand() / (RAND_MAX)) + 1;
	if (r == 0) {
		//powerup = new SlowDownPowerup();
	} else {
		// Move right
	}
}

void PowerupManager::VOnDestroy() {

}
