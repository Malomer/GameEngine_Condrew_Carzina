#pragma once

#include "Component.h"
#include "SFML/Graphics.hpp"

class InputComponent : public Component {

public:

	sf::Keyboard::Key key;
	virtual const char *VGetName() const { return "Input"; }

	InputComponent(sf::Keyboard::Key key) {
		this->key = key;
	}

	virtual void VUpdate(int deltaMs) {
		if (sf::Keyboard::isKeyPressed(key)) {
			std::cout << "Yo pressing the Q key dawg" << std::endl;
		}
	}
};
