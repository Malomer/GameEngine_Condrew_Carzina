#pragma once

#include "PowerupType.h"
#include "Player.h"
#include "Component.h"

class Powerup : public Component {

public:

	int duration;
	PowerupType type;

	Powerup();

	virtual const char *VGetName() const { return "Powerup"; }
	void OnActivate();
	void OnDeactivate();
};
