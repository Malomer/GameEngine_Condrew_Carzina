#pragma once

#include "Powerup.h"

class SpeedUpPowerup : public Powerup {

	virtual const char *VGetName() const { return "SpeedUpPowerup"; }

public:
	virtual void OnActivate();
	virtual void OnDeactivate();

	virtual PowerupType GetPowerupType() {
		return PowerupType::Speedup;
	}
};
