#pragma once

#include "Powerup.h"

class SlowDownPowerup : public Powerup {

	virtual const char *VGetName() const { return "SlowDownPowerup"; }

public:
	virtual void OnActivate();
	virtual void OnDeactivate();

	virtual PowerupType GetPowerupType() {
		return PowerupType::Slowdown;
	}
};
