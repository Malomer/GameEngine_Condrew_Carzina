#pragma once

#include <string>
#include "Scene.h"

class SceneManager {

public:

	
	static void RegisterScene(Scene *scene) {
		scenes[scene->GetScreenType()] = scene;
	}
	/*
	static void LoadScene(std::string name) {
		if (activeScene != nullptr) {
			activeScene->End();
		}

		activeScene = GetScene(name);
		printf("Loading: %s", activeScene->GetScreenType().c_str());
		activeScene->Start();
	}
	
	static Scene* GetScene(std::string name) {
		return scenes[name];
	}
	
	static Scene* GetActiveScene() {
		return activeScene;
	}
	*/
	static std::map<std::string, Scene*> scenes;
	static Scene *activeScene;
	
};
