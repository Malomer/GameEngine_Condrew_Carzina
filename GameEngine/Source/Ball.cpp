
#include "Ball.h"
#include "SceneManager.h"

void Ball::VUpdate(int deltaMs) {
	//m_pOwner->

	Matrix4 *matrix = &m_pOwner->transform.transformMatrix;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		matrix->translate(Vector3(0, -3, 0));

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		matrix->translate(Vector3(0, 3, 0));

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		matrix->translate(Vector3(-3, 0, 0));

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		matrix->translate(Vector3(3, 0, 0));

	}
	SceneManager::GetActiveScene()->mainWindow->draw(circle);
}

void Ball::SpawnBall() {
	// Pick number between 0 and 1
	// If 1, move left, else move right
}