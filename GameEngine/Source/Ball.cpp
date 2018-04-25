
#include "Ball.h"
#include "SceneManager.h"
#include "TestRenderer.h"

void Ball::VUpdate(int deltaMs) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		std::shared_ptr<TestRenderer> testRenderer = MakeStrongPtr(m_pOwner->GetComponent<TestRenderer>("TestRenderer"));
		if (testRenderer) {
			testRenderer->shape->setFillColor(sf::Color::Green);
		}
	}

	Matrix4 *matrix = &m_pOwner->transform.transformMatrix;
	const float *m = m_pOwner->worldTransform.get();

	//m[3], m[7]

	//printf("%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n\n",
	//	m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8], m[9], m[10], m[11], m[12], m[13], m[14], m[15]);

	if (m[3] >= 1000) {
		xVelocity = -xVelocity;
	} else if (m[3] <= 0) {
		xVelocity = -xVelocity;
	}

	if (m[7] >= 750) {
		yVelocity = -yVelocity;
	}
	else if (m[7] <= 0) {
		yVelocity = -yVelocity;
	}

	matrix->translate(Vector3(xVelocity, yVelocity, 0));
}

void Ball::HitHorizontal() { // ------
	//printf("HitHorizontal\n");
	yVelocity = -yVelocity;
}

void Ball::HitVertical() { // ||||
	//printf("HitVertical\n");
	xVelocity = -xVelocity;
}

void Ball::SpawnBall() {
	int r = ((double)rand() / (RAND_MAX)) + 1;
	if (r == 0) {
		// Move left
	} else {
		// Move right
	}
}

/*
void Ball::ChangeColor(Player &player) {

		std::shared_ptr<TestRenderer> testRenderer = MakeStrongPtr(m_pOwner->GetComponent<TestRenderer>("TestRenderer"));
		if (testRenderer) {
			testRenderer->shape->setFillColor(player.playerColor);
		}
	
}
*/
