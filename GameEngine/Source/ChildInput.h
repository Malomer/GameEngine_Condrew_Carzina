#pragma once

#include "InputComponent.h"
#include "Matrices.h"
#include "Vectors.h"

class ChildInput : public InputComponent {

public:
	const int speed = 4;

	sf::CircleShape circle;
	sf::RenderWindow *mainWindow;

	ChildInput(sf::RenderWindow &mainWindow) {
		this->mainWindow = &mainWindow;

		circle.setRadius(20);
		circle.setFillColor(sf::Color::Red);
	}

	virtual void VUpdate(int deltaMs) {
		Matrix4 *matrix = &m_pOwner->transform.transformMatrix;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			matrix->translate(Vector3(0, -3, 0));

		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			matrix->translate(Vector3(0, 3, 0));

		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			matrix->translate(Vector3(-3, 0, 0));

		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			matrix->translate(Vector3(3, 0, 0));

		}

		const float *m = m_pOwner->worldTransform.get();
		circle.setPosition(m[3], m[7]);
		printf("%f %f\n", m[3], m[7]);
	
		mainWindow->draw(circle);
	}
};