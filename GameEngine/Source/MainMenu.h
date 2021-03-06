#pragma once

#include "Scene.h"

class MainMenu : public Scene {
	using Scene::Scene;

public:

	virtual void Start();
	virtual void End();
	virtual void draw();
	virtual bool update(INT32 time);
	virtual bool handleEvent(const sf::Event& event);

	std::string GetScreenType() {
		return "MainMenu";
	}
};
