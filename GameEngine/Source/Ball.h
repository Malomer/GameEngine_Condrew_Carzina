#pragma once

#include "Component.h"
#include "Player.h"

class Ball : public Component {

public:

	virtual const char *VGetName() const { return "Ball"; }

	sf::CircleShape circle;
	Player lastHit = NULL; // This could be null

	Ball() {
		circle.setRadius(2);
		circle.setFillColor(sf::Color::Red);
		circle.setPosition(0.f, 0.f);
	}

	void VUpdate(int deltaMs);
	void SpawnBall();
};
