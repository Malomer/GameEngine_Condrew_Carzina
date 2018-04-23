
#include "ShapeRenderer.h"
#include "SceneManager.h"

ShapeRenderer::ShapeRenderer(sf::Shape *shape) {
	this->shape = shape;
	SceneManager::activeScene->RegisterDrawable(this);
}

void ShapeRenderer::VUpdate(int deltaMs) {
	const float *m = m_pOwner->worldTransform.get();
	shape->setPosition(m[3], m[7]);
}

void ShapeRenderer::Draw() {
	SceneManager::activeScene->mainWindow->draw(*shape);
	const float *m = m_pOwner->worldTransform.get();
	printf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n", m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8], m[9], m[10], m[11], m[12], m[13], m[14], m[15]);
}
