#pragma once

#include "Component.h"
#include "SFML/Graphics.hpp"

class RenderComponent : public Component {

public:

	sf::CircleShape circle;
	sf::RenderWindow *mainWindow;

	virtual const char *VGetName() { return "Render"; }

	RenderComponent(sf::RenderWindow &mainWindow, sf::Color color) {
		this->mainWindow = &mainWindow;

		circle.setRadius(40);
		circle.setFillColor(color);
	}

	virtual void VUpdate(int deltaMs) {
		mainWindow->draw(circle);
	}
};
