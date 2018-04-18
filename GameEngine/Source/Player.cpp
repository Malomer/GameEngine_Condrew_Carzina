
#include "Player.h"

void Player::VUpdate(int deltaMs) {
	HandleInput();
}

void Player::HandleInput() {
	if(playerNumber == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

		}

	} else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

		}
	}
}