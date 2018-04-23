#pragma once

#include "Powerup.h"
#include <vector>

class PowerupManager {

public:
	std::vector<Powerup> activePowerups;

	PowerupManager();

	void Shutdown();
};
