
#include "DrawableRenderer.h"
#include "SceneManager.h"

DrawableRenderer::DrawableRenderer() {
	//circle.setRadius(40);
	//circle.setFillColor(sf::Color::Green);
	//circle.setPosition(10.f, 10.f);
	SceneManager::activeScene->RegisterDrawable(this);
}

void DrawableRenderer::VUpdate(int deltaMs) {
	/*
	Matrix4 *matrix = &m_pOwner->transform.transformMatrix;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		matrix->translate(Vector3(0, -1, 0) * deltaMs * 2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		matrix->translate(Vector3(0, 1, 0) * deltaMs * 2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		matrix->translate(Vector3(-1, 0, 0) * deltaMs * 2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		matrix->translate(Vector3(1, 0, 0) * deltaMs * 2);
	}

	const float *m = m_pOwner->worldTransform.get();
	circle.setPosition(m[3], m[7]);
	*/
}

void DrawableRenderer::Draw() {
	//SceneManager::activeScene->mainWindow->draw(circle);
	SceneManager::activeScene->mainWindow->draw(*this);
}
