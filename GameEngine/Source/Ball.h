#pragma once

#include "Component.h"

class Ball : public Component {

public:

	virtual const char *VGetName() const { return "Ball"; }

	void VUpdate(int deltaMs);
	//void ChangeColor(Player *player);
	void SpawnBall();
	void HitHorizontal(); // ------
	void HitVertical(); // ||||

	float xVelocity = 2.f;
	float yVelocity = 2.f;
};
