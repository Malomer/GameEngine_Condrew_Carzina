
#include "ImageRenderer.h"
#include "SceneManager.h"

void ImageRenderer::VUpdate(int deltaMs) {
	const float *m = m_pOwner->worldTransform.get();
	image.setPosition(m[3], m[7]);
}

void ImageRenderer::Draw() {
	SceneManager::activeScene->mainWindow->draw(image);
}
