
#include "Player.h"
#include "TestRenderer.h"
#include <memory>

void Player::VInit() {
	//shapeRenderer = m_pOwner->GetComponent<ShapeRenderer>("ShapeRenderer");
	//shapeRenderer = std::shared_ptr<ShapeRenderer>(m_pOwner->GetComponent<ShapeRenderer>("ShapeRenderer"));
	//shapeRenderer = m_pOwner->GetComponent<ShapeRenderer>("ShapeRenderer");
	//std::shared_ptr<ShapeRenderer> pTransformComponent = std::shared_ptr<ShapeRenderer>(m_pOwner->GetComponent<TransformComponent>("");
}

void Player::VUpdate(int deltaMs) {
	HandleInput();
}

void Player::HandleInput() {

	Matrix4 *matrix = &m_pOwner->transform.transformMatrix;
	if (playerNumber == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			const float *m = m_pOwner->worldTransform.get();
			if (m[7] > 0) {
				matrix->translate(Vector3(0, -3, 0));
			}
			//printf("W = %f, %f\n", m[3], m[7]);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			const float *m = m_pOwner->worldTransform.get();
			if (m[7] < 727) {
				matrix->translate(Vector3(0, 3, 0));
			}
			//printf("S = %f, %f\n", m[3], m[7]);
		}
	} else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			const float *m = m_pOwner->worldTransform.get();
			if (m[7] > 0) {
				matrix->translate(Vector3(0, -3, 0));
			}
			//printf("W = %f, %f\n", m[3], m[7]);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			const float *m = m_pOwner->worldTransform.get();
			if (m[7] < 727) {
				matrix->translate(Vector3(0, 3, 0));
			}
			//printf("S = %f, %f\n", m[3], m[7]);
		}
	}

	std::shared_ptr<Ball> ball = MakeStrongPtr(ballGameObject->GetComponent<Ball>("Ball"));
	if (ball) {
		std::shared_ptr<TestRenderer> ballRender = MakeStrongPtr(ballGameObject->GetComponent<TestRenderer>("TestRenderer"));
		if (ballRender) {
			std::shared_ptr<TestRenderer> playerRender = MakeStrongPtr(m_pOwner->GetComponent<TestRenderer>("TestRenderer"));

			if (playerNumber == 1 && ball->xVelocity < 0) {
				if (playerRender->shape->getGlobalBounds().intersects(ballRender->shape->getGlobalBounds())) {
					ball->HitVertical();
					ballRender->shape->setFillColor(playerColor);
				}
			}
			if (playerNumber != 1 && ball->xVelocity > 0) {
				if (playerRender->shape->getGlobalBounds().intersects(ballRender->shape->getGlobalBounds())) {
					ball->HitVertical();
					ballRender->shape->setFillColor(playerColor);
				}
			}
		}
		//testRenderer->shape->setPosition(m[3], m[7]);
	}


	//	printf("Attempting to call RotateY() on actor with no trnasform component\n");
	//testRenderer->circle.setPosition(m[3], m[7]);
}
