
#include "Scene.h"

void Scene::RegisterDrawable(DrawableRenderer *spriteRenderer) {
	drawables.push_back(spriteRenderer);
}

void Scene::RegisterDrawable(ShapeRenderer *spriteRenderer) {
	drawables1.push_back(spriteRenderer);
}

void Scene::ClearDrawables() {
	drawables.clear();
}