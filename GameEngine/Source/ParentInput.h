#pragma once

#include "InputComponent.h"

class ParentInput : public InputComponent {

public:
	const int speed = 4;

	sf::CircleShape circle;
	sf::RenderWindow *mainWindow;

	ParentInput(sf::RenderWindow &mainWindow) {
		this->mainWindow = &mainWindow;

		circle.setRadius(40);
		circle.setFillColor(sf::Color::Blue);
	}

	virtual void VUpdate(int deltaMs) {
		Matrix4 *matrix = &m_pOwner->transform.transformMatrix;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			matrix->translate(Vector3(0, -3, 0));

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			matrix->translate(Vector3(0, 3, 0));

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			matrix->translate(Vector3(-3, 0, 0));

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			matrix->translate(Vector3(3, 0, 0));

		}

		//const float *m = matrix->get();
		const float *m = m_pOwner->worldTransform.get();
		circle.setPosition(m[3], m[7]);
		printf("%f %f\n", m[3], m[7]);

		mainWindow->draw(circle);
	}
};
