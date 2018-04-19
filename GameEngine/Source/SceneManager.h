#pragma once

#include <string>
#include "Scene.h"

namespace SceneManager {

	extern std::map<std::string, Scene*> scenes;
	extern Scene *activeScene;

	void RegisterScene(Scene *scene);
	void LoadScene(std::string name);
	Scene* GetScene(std::string name);
	Scene* GetActiveScene();
}

/*
class SceneManager {

public:

	
	static void RegisterScene(Scene *scene) {
		scenes[scene->GetScreenType()] = scene;
	}
	
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
	
	static std::map<std::string, Scene*> scenes;
	static Scene *activeScene;
	
};
*/
