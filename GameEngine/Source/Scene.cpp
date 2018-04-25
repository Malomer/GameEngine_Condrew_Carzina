
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

std::string Scene::ExePath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}