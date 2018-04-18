#pragma once

#include "Component.h"
#include "Player.h"

class Ball : public Component {

public:

	virtual const char *VGetName() const { return "Ball"; }

	Player lastHit = NULL; // This could be null

	void VUpdate(int deltaMs);
	void SpawnBall();
};
