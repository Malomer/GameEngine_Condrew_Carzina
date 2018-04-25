
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

	/*
	Scene *newScene = GetScene(name);
	printf("Starting to load: %s\n", newScene->GetScreenType().c_str());
	newScene->Start();
	printf("%s loaded!\n", newScene->GetScreenType().c_str());
	activeScene = newScene;
	printf("%s is now active!\n", newScene->GetScreenType().c_str());
	*/
	//activeScene->Start();

	
	activeScene = GetScene(name);
	printf("Loading: %s\n", activeScene->GetScreenType().c_str());
	activeScene->Start();
	
}

Scene* SceneManager::GetScene(std::string name) {
	return scenes[name];
}

Scene* SceneManager::GetActiveScene() {
	return activeScene;
}
