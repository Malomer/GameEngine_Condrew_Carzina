#pragma once

#include "Component.h"
#include "ShapeRenderer.h"
#include "Ball.h"
#include "SFML/Graphics.hpp"

#include <memory>

class Player : public Component {

public:

	virtual const char *VGetName() const { return "Player"; }

	GameObject* ballGameObject;
	int playerNumber;
	int score;
	sf::Color playerColor;

	Player(int playerNumber, GameObject* ballGameObject) {
		this->playerNumber = playerNumber;

		score = 0;
		if (playerNumber == 1) {
			playerColor = sf::Color::Blue;
		} else {
			playerColor = sf::Color::Red;
		}
		this->ballGameObject = ballGameObject;
	}

	void VInit();
	void VUpdate(int deltaMs);
	void HandleInput();
	void IsInAABB(sf::Vector2u min, sf::Vector2u max);
};
