#pragma once

#include "Powerup.h"
#include <vector>

class PowerupManager : public Component {

public:

	virtual const char *VGetName() const { return "PowerupManager"; }

	std::vector<Powerup> activePowerups;

	PowerupManager();

	void SpawnRandomPowerup();
	virtual void VOnDestroy();
};
