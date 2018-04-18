#pragma once

#include "Component.h"
#include "SFML/Graphics.hpp"

class Player : public Component {

public:

	virtual const char *VGetName() const { return "Player"; }

	int playerNumber;
	int score;

	Player(int playerNumber) {
		this->playerNumber = playerNumber;

		score = 0;
	}

	void VUpdate(int deltaMs);
	void VRender();
	void HandleInput();
};
