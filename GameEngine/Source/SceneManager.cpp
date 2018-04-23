
#include "SceneManager.h"

std::map<std::string, Scene*> SceneManager::scenes;
Scene *SceneManager::activeScene;

void SceneManager::RegisterScene(Scene *scene) {
	scenes[scene->GetScreenType()] = scene;
}

void SceneManager::LoadScene(std::string name) {
	if (activeScene != nullptr) {
		activeScene->End();
	}

	activeScene = GetScene(name);
	printf("Loading: %s", activeScene->GetScreenType().c_str());
	activeScene->Start();
}

Scene* SceneManager::GetScene(std::string name) {
	return scenes[name];
}

Scene* SceneManager::GetActiveScene() {
	return activeScene;
}
